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

int minOperations(vector<int>& v, int k) {
    ll op = 0;
    multiset<ll> ms;
    for(auto it:v){
        ms.insert(it);
    }
    
    while(ms.size() > 1){
        ll a = *ms.begin();
        if(a >= k){break;}
        ms.erase(ms.find(a));
        ++op;
    }
    return op;
}

int minOperations2(vector<int>& v, int k) {
    ll op = 0;
    multiset<ll> ms;
    for(auto it:v){
        ms.insert(it);
    }
    
    while(ms.size() > 1){
        ll a = *ms.begin();
        if(a >= k){break;}
        ms.erase(ms.find(a));
        ll b = *ms.begin();ms.erase(ms.find(b));
        
        ll c = min(a,b)*2+max(a,b);
        ms.insert(c);
        ++op;
    }
    return op;
}

vector<ll> adj[100004];
vector<ll> vis;
vector<vector<ll>> dist;
ll ss = 0;

ll dfs(ll i,ll dis){
    vis[i] = 1;
    ll sa = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            sa += dfs(it,dis+dist[i][it]);
        }
    }
    if(!(dis%ss)){++sa;}
    return sa;
}    
    
vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int t) {
    vector<int> ans;
    ss = 1ll*t;
    ll n = 0;
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
        n = max({n,1ll*it[0],1ll*it[1]});
    }
    ++n;
    dist.assign(n+1, vector<ll>(n+1,0));
    for(auto it:edges){
        dist[it[0]][it[1]] = dist[it[1]][it[0]] = it[2];
    }

    for(ll i = 0;i<n;++i){
        vis.assign(n+1,0);

        vector<ll> dk;
        ll sa = 0,sm = 0;

        for(auto it:adj[i]){
            vis[i] = 1;
            ll sa2 = dfs(it,dist[i][it]);
            sm += sa2;
            dk.push_back(sa2);
        }

        for(auto it:dk){
            sa += it*(sm-it);
        }
        sa /= 2;
        ans.push_back(sa);
    }
    return ans;
}

long long maximumValueSum(vector<int>& v, int k, vector<vector<int>>& edges) {
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    ll n = v.size(); 

    ll ans = accumulate(all(v),0ll);
    ll dk = ans,mn = LLONG_MAX,mx = LLONG_MAX;
    vector<ll> change_nodes;
    forj(n){
        ll it = v[j];
        if((it^k) > it){
            dk += ((it^k)-it);
            mx = min(mx,((it^k)-it));
            change_nodes.push_back(j);
        }else{
            mn = min(mn,it-(it^k));
        }
    }

    if(!change_nodes.size()){return ans;}

    if(change_nodes.size() & 1){
        dk -= min(mn,mx);
    }
    return dk;
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