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
string finalString(string s) {
    string ans;
    for(int i = 0;i<s.size();++i){
        if(s[i] != 'i'){
            ans += s[i];
        }else{
            reverse(all(ans));
        }
    }
    return ans;
} 

bool canSplitArray(vector<int>& v, int m) {
    if(v.size() <= 2){
        return 1;
    }
    
    for(ll i = 0;i<v.size()-1;++i){
        ll sm = v[i]+v[i+1];
        if(sm >= m){return 1;}
    }
    return 0;
}

ll n;
vector<vector<ll>> v,dp,vis; 
bool issafe(ll i,ll j){
    if(i < 0 || j<0 || i>=n || j>=n){return 0;}return 1;
}

void multisrc(){
    // cout<<"hi\n";
    queue<pair<ll,ll>> q;
    
    for(ll i = 0;i<n;++i){
            // cout<<i<<" "<<0<<endl;
        forj(n){
            if(v[i][j] == 1){
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }

    ll lvl = 0;
    while(!q.empty()){
        auto sz = q.size();
        while(sz--){
            auto p = q.front();q.pop();
            ll x = p.first,y = p.second;
            dp[x][y] = lvl;
            vis[x][y] = 1;

            if(issafe(x+1,y) and !vis[x+1][y]){
                vis[x+1][y] = 1;
                q.push({x+1,y});
            }
            if(issafe(x-1,y) and !vis[x-1][y]){
                vis[x-1][y] = 1;
                q.push({x-1,y});
            }
            if(issafe(x,y+1) and !vis[x][y+1]){
                vis[x][y+1] = 1;
                q.push({x,y+1});
            }
            if(issafe(x,y-1) and !vis[x][y-1]){
                vis[x][y-1] = 1;
                q.push({x,y-1});
            }
        }
        ++lvl;
    }
}

bool check(ll mid){
    if((dp[0][0] < mid) || (dp[n-1][n-1] < mid)){return 0;}
    vector<pair<ll,ll>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    queue<pair<ll,ll>> q;
    q.push({0,0});
    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            auto p = q.front();q.pop();
            if(p.first == n-1 and p.second == n-1){return 1;}
            vis[p.first][p.second] = 1;

            for(auto it:dir){
                ll x = p.first+it.first,y = p.second+it.second;
                if(issafe(x,y) and !vis[x][y] and dp[x][y] >= mid){
                    q.push({x,y});vis[x][y] = 1;
                }
            }
        }
    }
    return 0;
}

int maximumSafenessFactor(vector<vector<int>>& grid) {
    n = grid.size();
    v.assign(n,vector<ll>(n,0)) ;
    vis.assign(n,vector<ll>(n,0)) ;
    for(ll i = 0;i<n;++i){
        forj(n){
            v[i][j] = 1ll*grid[i][j];
        }
    }

    dp.assign(n+1,vector<ll>(n+1,n+1));
    if(v[0][0] || v[n-1][n-1]){return 0;}
    multisrc();

    ll l = 0,h = 2*n-1,ans = 0;
    while(l <= h){
        ll mid = (l+h)/2;
        vis.clear();vis.assign(n+1,vector<ll>(n+1,0)) ;
        if(check(mid)){
            ans = mid;l = mid+1;
        }else{
            h = mid-1;
        }
    }
    return ans;
}
 
long long findMaximumElegance(vector<vector<int>>& v, int k) {
    sort(all(v));reverse(all(v));
    
    ll sm = 0,ans = 0; 
    vector<ll> dup;
    set<ll> pres;
    for(ll i = 0;i<v.size();++i){
        if(i < k){
            if(pres.find(v[i][1]) != pres.end()){
                dup.push_back(v[i][0]);
            }
            sm += v[i][0];
        }else if(pres.find(v[i][1]) == pres.end()){
            if(dup.empty()){break;}
            sm += v[i][0]-dup.back();
            dup.pop_back();
        }
        pres.insert(v[i][1]);

        ll sz = pres.size();
        ans = max(ans,sm+sz*sz);
    }
    return ans;
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