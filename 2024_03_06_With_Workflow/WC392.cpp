/*
Once in a LifeTime,
Will never let you Down!!
*/
#include <bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

/*
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
*/

// Fxn call(for ((b/a)%mod)) :
// ll c = (b*power(a,mod-2(prime num in power of a),mod))%mod;
// Also for formula like nCr..
ll power(ll base,ll n,ll mod){
    ll ans = 1;
    while( n!= 0){
        if(n%2){
            n-=1;
            ans = (ans*base)%mod;
        }
        else{
            n /= 2;
            base = (base*base)%mod;
        }
    }
return ans;
}

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

ll sieve[1000005];
void createsieve(){
    ll ntlen = 1000000;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }

    for(ll i = 2;i*i<=ntlen;++i){
        // Set all multiples to 0
        if(sieve[i] == 1){

            for(ll j = i*i;j<=ntlen;j+=i){
                sieve[j] = 0;
            }
        }
    }
}


vector<ll> adj[100004];

void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//  "A" : 65, "a" : 97  (-> |) (<- &(~))
// YE DIL MAANGE MORE!!

int longestMonotonicSubarray(vector<int>& v) {
    ll ans = 0,n = v.size();
    for(ll i = 0;i<n;++i){
        ll ele = v[i],sa = 0;
        for(ll j = i+1;j<n;++j){
            if(v[j] > ele){
                ele = v[j];++sa;
            }else{break;}
        }
        ans = max(ans,sa);
    }
    
    for(ll i = 0;i<n;++i){
        ll ele = v[i],sa = 0;
        for(ll j = i+1;j<n;++j){
            if(v[j] < ele){
                ele = v[j];++sa;
            }else{break;}
        }
        ans = max(ans,sa);
    }
    return ans+1;
}

string getSmallestString(string s, int k) {
    string t = s;
    ll n = s.size();
    for(ll i = 0;i<n;++i) {
        ll diff = min(s[i]-'a',26-(s[i]-'a'));
        if(k >= diff){
            t[i] = 'a';
        }else{
            t[i] -= k;
            break;
        }
    }
    return t;
}

long long minOperationsToMakeMedianK(vector<int>& v, int k) {
    ll ans = 0;
    sort(v.begin(),v.end());
    if(v[v.size()/2] > k){
        for(ll i = (v.size())/2;i>=0;--i){
            ans += max(0ll,1ll*v[i]-k);
        }
    }else if(v[v.size()/2] < k){
        for(ll i = (v.size())/2;i<v.size();++i){
            ans += max(0ll,1ll*k-v[i]);
        }
    }
    return ans;
}

vector<ll> comp,vis;
void bfs(ll i,ll component){
    queue<ll> q;
    q.push(i);
    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            auto p = q.front();q.pop();
            vis[p] = 1;
            comp[p] = component;

            for(auto x:adj[p]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = 1;
                    comp[x] = component;
                }
            }
        }
    }
}

vector<ll> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    comp.assign(n+1,0);vis.assign(n+1,0);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    ll component = 0;
    for(ll i = 0;i<n;++i){
        if(!vis[i]){
            bfs(i,component);++component;
        }
    }

    vector<ll> tmp(component+1,-1);
    for(auto it:edges){
        ll tmp_component = comp[it[0]];
        if(tmp[tmp_component] == -1){
            tmp[tmp_component] = it[2];
        }else{
            tmp[tmp_component] &= it[2];
        }
    }

    vector<ll> ans;
    for(auto it:query){
        ll x = comp[it[0]],y = comp[it[1]];
        if(x == y){
            ans.push_back(tmp[it[0]]);
        }else{
            ans.push_back(-1);
        }
    }
    return ans;
}

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);enter(v);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //setprecision(20);// also use precision with ans now
    // use setprecision before ans
    //precomputefact();
    //createsieve();
    //bfs();//call in solve()
    //dfs(1,0);//call in solve()
    
    ll t=1;
    cin >> t;
    ll i = 1;
    while (t--)
    {
        solve();
        ++i;
    }
    //solve();
    return 0;
}