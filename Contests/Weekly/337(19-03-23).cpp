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
vector<int> evenOddBit(int n) {
    bitset<64> b(n);
    int o = 0,e = 0;
    for(int i = 0;i<64;++i){
        if(b[i]){
            if(i & 1){++o;}
            else{
                ++e;
            }
        }
    }
    return {e,o};
}

vector<vector<ll>> vis;
ll n;

bool issafe(ll i,ll j){
    if(i < 0||j<0||i>=n||j>=n){return false;}
    return true;
}

bool dfs(ll i,ll j,ll cnt,vector<vector<int>>& v){
    if(cnt == n*n-1){return 1;}

    ll k = cnt+1;
    ll a = 0;
    if(issafe(i-2,j+1) and !vis[i-2][j+1] and v[i-2][j+1] == k){
        vis[i-2][j+1] = 1;
        a |= dfs(i-2,j+1,cnt+1,v);
    }

    if(issafe(i+2,j+1) and !vis[i+2][j+1] and v[i+2][j+1] == k){
        vis[i+2][j+1] = 1;
        a |= dfs(i+2,j+1,cnt+1,v);
    }

    if(issafe(i-1,j+2) and !vis[i-1][j+2] and v[i-1][j+2] == k){
        vis[i-1][j+2] = 1;
        a |= dfs(i-1,j+2,cnt+1,v);
    }

    if(issafe(i+1,j-2) and !vis[i+1][j-2] and v[i+1][j-2] == k){
        vis[i+1][j-2] = 1;
        a |= dfs(i+1,j-2,cnt+1,v);
    }

    if(issafe(i-2,j-1) and !vis[i-2][j-1] and v[i-2][j-1] == k){
        vis[i-2][j-1] = 1;
        a |= dfs(i-2,j-1,cnt+1,v);
    }

    if(issafe(i+2,j-1) and !vis[i+2][j-1] and v[i+2][j-1] == k){
        vis[i+2][j-1] = 1;
        a |= dfs(i+2,j-1,cnt+1,v);
    }

    if(issafe(i-1,j-2) and !vis[i-1][j-2] and v[i-1][j-2] == k){
        vis[i-1][j-2] = 1;
        a |= dfs(i-1,j-2,cnt+1,v);
    }

    if(issafe(i+1,j+2) and !vis[i+1][j+2] and v[i+1][j+2] == k){
        vis[i+1][j+2] = 1;
        a |= dfs(i+1,j+2,cnt+1,v);
    }

    return a;
}


bool checkValidGrid(vector<vector<int>>& grid) {
    n = grid.size();
    vis.assign(n+1,vector<ll>(n+1,0));
    return dfs(0,0,0,grid);
}


ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

int findSmallestInteger(vector<int>& v, int val) {
    for(ll i = 0;i<v.size();++i){
        v[i] = mod_add(v[i],0,val);
    }
    sort(all(v));

    map<ll,ll> mp;
    for(ll i = 0;i<v.size();++i){
        if(mp.find(v[i]) == mp.end()){
            mp[v[i]]++;
        }else{
            v[i] += (mp[v[i]]*val);
            mp[v[i]]++;
        }
    }

    sort(all(v));
    ll cnt = 0;
    for(ll i = 0;i<v.size();++i){
        if(v[i] == cnt){
            ++cnt;
        }
    }
    return cnt;
}

ll recur(ll idx,vector<ll>& v, ll k,unordered_map<ll,ll> &mp){
    if(idx == v.size()){return 1;}

    ll a = 0;
    if(mp[v[idx]-k] == 0){
        mp[v[idx]]++;
        a += recur(idx+1,v,k,mp);
    }

    mp[v[idx]] = 0;
    a += recur(idx+1,v,k,mp);
    return a;
}

int beautifulSubsets(vector<ll>& v, int k) {
    sort(all(v));
    unordered_map<ll,ll> mp;
    ll ans = 0;
    ans = recur(0,v,k,mp);
    return (ans-1);
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