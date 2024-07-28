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
#define pyes cout << "YES" << endl;
#define pno cout << "NO" << endl;
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

ll sieve[100005];
vector<ll> prime;
void createsieve(){
    ll ntlen = 100000;
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
            prime.push_back(i);
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

bool canAliceWin(vector<int>& v) {
    int s = 0,d = 0,tot = 0;
    for(auto it:v){
        string st = to_string(it);
        if(st.size() == 2){
            d += it;
        }else if(st.size() == 1){
            s += it;
        }
        tot += it;
    }

    if(((tot-d) < d) || ((tot-s) < s)){
        return 1;
    }
    return 0;
}

int nonSpecialCount(int l, int r) {
    createsieve();
    int ans = 0;
    for(auto it:prime){
        if(it*it > r){break;}
        ++ans;
    }

    if(l){--l;}

    for(auto it:prime){
        if(it*it > l){break;}
        --ans;
    }
    return ans;
}

int numberOfSubstrings(string s) {
    ll n = s.size(),o = 0;
    vector<ll> zeroes,ones;
    for(int i = 0;i<n;++i){
        if(s[i] == '1'){++o;}
        ones.push_back(o);
        zeroes.push_back(i+1-o);
    }

    ll x = sqrt(o);o = 0;ll z = 0,ans=0;
    for(int i = 0;i<n;++i){
        

        for(int j = 0;j<x;++j){
            ll idx = upper_bound(zeroes.begin(),zeroes.end(),j)-(zeroes.begin());
            --idx;
            if(idx<i){continue;}
            ll req_ones = j*j;

            ll st = lower_bound(ones.begin(),ones.end(),req_ones+o)-ones.begin();
            ll end = lower_bound(zeroes.begin(),zeroes.end(),z+j+1)-zeroes.begin();
            ans += max(0ll,end-st);
        }

        if(s[i] == '1'){++o;}
        else{++z;}
    }
    return ans;
}

/*
5
8
[[4,7,1]]
8
9
[[3,1,1],[1,5,1],[4,8,2]]
*/

vector<ll> vis;    
// map<ll,vector<ll>> mp;
vector<vector<ll>> mp;
ll x,y;

ll bfs(ll i){
    vis[i] = 1;

    queue<ll> q;
    q.push(i);

    ll xl = 0,yl = 0,xr = 0,yr = 0;

    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            auto p = q.front();q.pop();
            vis[p] = 1;
            
            vector<ll> tmp = mp[p];
            xl = min(xl,tmp[0]-tmp[2]);
            xr = max(xr,tmp[0]+tmp[2]);
            yl = min(yl,tmp[1]-tmp[2]);
            yr = max(yr,tmp[1]+tmp[2]);

            for(auto it:adj[p]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    if((xl <= 0) and (xr >= x)){return 0;}
    if((yl <= 0) and (yr >= y)){return 0;}
    if((xl <= 0) and (yl <= 0)){return 0;}
    if((xr >= x) and (yr >= y)){return 0;}

    return 1;
}

bool canReachCorner(int X, int Y, vector<vector<int>>& v) {
    ll n = v.size();
    x = 1ll*X,y = 1ll*Y;
    for(ll i = 0;i<n;++i){
        mp.push_back({v[i][0],v[i][1],v[i][2]});
        for(ll j = i+1;j<n;++j){
            ll xl = v[i][0],xr = v[i][1],r1 = v[i][2]; 
            ll yl = v[i][0],yr = v[i][1],r2 = v[i][2]; 
            ll xdist = abs(yl-xl),ydist=abs(yr-xr),r = r1+r2;
            xdist *= xdist;
            ydist *= ydist;
            double dk = sqrt(1.0*(xdist+ydist));
            if(dk <= (1.0*r)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    ll ans = 1;
    for(ll i = 0;i<n;++i){
        if(!vis[i]){
            ans &= bfs(i);
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