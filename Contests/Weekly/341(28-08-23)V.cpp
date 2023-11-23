#include<bits/stdc++.h>
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
vector<ll> rowAndMaximumOnes(vector<vector<int>>& v) {
    ll mx = -1,idx = 0;
    ll n = v.size(),m  = v[0].size();
    for(int i = 0;i<n;++i){
        ll cntr = 0;
        forj(m){
            if(v[i][j]){++cntr;}
        }
        if(cntr > mx){
            mx = cntr;idx = i;
        }
    }
    return {idx,mx};
}

int maxDivScore(vector<int>& v, vector<int>& t) {
    int ans = -1,ele = 1e9;
    for(ll i = 0;i<t.size();++i){
        int cntr = 0;
        forj(v.size()){
            if(v[j]%t[i] == 0){++cntr;}
        }
        if(cntr > ans){
            ans = max(ans,cntr);
            ele = t[i];
        }else if(cntr == ans){
            ele = min(ele,t[i]);
        }
    }
    return ans;       
}

int addMinimum(string s) {
    int ans = 0;
    int j = 0,n = s.size();
    string tmp = "abc";

    for(int i = 0;i<n-1;++i){
        if(s[i] == s[i+1]){
            ans += 2;
        }
        if(s[i] == 'b' and s[i+1] == 'a'){
            ++ans;
        }
        if(s[i] == 'c' and s[i+1] == 'b'){
            ++ans;
        }
        if(s[i] == 'a' and s[i+1] == 'c'){
            ++ans;
        }

        if(s[i] == 'a' and s[i+1] == 'b'){
        }
        if(s[i] == 'b' and s[i+1] == 'c'){
        }
        if(s[i] == 'c' and s[i+1] == 'a'){
        }
    }

    if(s[0] == 'b'){
        ++ans;
    }else if(s[0] == 'c'){
        ans += 2;
    }

    if(s[n-1] == 'b'){
        ++ans;
    }else if(s[n-1] == 'a'){
        ans += 2;
    }

    return ans;
}

ll n;
ll dfs(ll src,ll dest,vector<ll> &v){
    vector<ll> vis(n+5,0);
    queue<ll> q;
    q.push(src);
    vector<ll> dp(n+5,LLONG_MAX);
    dp[src] = v[src];

    if(src == dest){return v[src];}

    ll ans = v[src];
    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            ll ele = q.front();q.pop();vis[ele] = 1;
            if(ele == dest){
                return dp[dest];
            }

            for(auto it:adj[ele]){
                if(!vis[it]){
                    dp[it] = min(dp[it],dp[ele]+v[it]);
                }
            }
        }
    }
    return dp[dest];
}

void bfs(vector<ll> &v,ll flag){
    vector<ll> vis(v.size()+5,0);
    queue<ll> q;
    q.push(0);
    ll f = 0;
    if(flag){f = 1;}
    vis[0] = 1;

    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            ll ele = q.front();q.pop();vis[ele] = 1;
            if(f){
                v[ele] /= 2;
            }
            for(auto it:adj[ele]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        f ^= 1;
    }
}

int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
    forj(n){adj[j].clear();}
    for(auto it:edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    n = price.size();
    vector<ll> a(n+5,0);vector<ll> b(n+5,0);
    forj(n){a[j] = b[j] = price[j];}

    bfs(a,1);
    bfs(b,0);

    ll ans1 = 0;
    for(auto it:trips){
        ans1 += dfs(it[0],it[1],a);
    }

    ll ans2 = 0;
    for(auto it:trips){
        ans2 += dfs(it[0],it[1],b);
    }
    return min(ans1,ans2);
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
 
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
    return;
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