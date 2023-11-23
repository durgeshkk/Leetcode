/*
Once in a LifeTime,
Will never let you Down!!
*/
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_i_update>
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

int findKOr(vector<int>& nums, int k) {
    ll ans = 0;
    for(ll i = 0;i<31;++i){
        vector<ll> tmp;
        for(auto it:nums){
            if(it&(1<<i)){
                tmp.push_back(it);
            }
        }
        if(tmp.size() >= k){
            ans += (pow(2,i));
        }
    }
    return ans;
}

long long minSum(vector<int>& v, vector<int>& t) {
    ll sm1 = 0,cntr1 = 0;
    for(auto it:v){
        sm1 += it;
        if(!it){++cntr1;}
    }
    ll sm2 = 0,cntr2 = 0;
    for(auto it:v){
        sm2 += it;
        if(!it){++cntr2;}
    }

    if(!cntr1 and !cntr2){
        if(sm1 == sm2){return sm1;}
        return -1;
    }else if(!cntr1){
        if(sm1 < (cntr2+sm2)){
            return -1;
        }
        return (sm2+cntr2);
    }else if(!cntr2){
        if((sm1+cntr1) > (sm2)){
            return -1;
        }
        return (sm1+cntr1);
    }else{
        return max(sm1+cntr1,sm2+cntr2);
    }
}
/*
ll ans= 0,n,k;
vector<ll> v;
vector<vector<ll>> dp;
ll dfs(ll idx,ll cntr){
    if(idx >= n){return 0;}
    if(dp[idx][cntr] != -1){return dp[idx][cntr];}

    ll sa = 1e18;
    if(cntr == 2){
        // Time to update
        sa = max(k-v[idx],0ll)+dfs(idx+1,0);
    }else{
        // Update 
        sa = max(k-v[idx],0ll)+dfs(idx+1,0);
        // or not
        sa = min(sa,dfs(idx+1,cntr+1));
    }
    
    return dp[idx][cntr] = sa;
}

long long minIncrementOperations(vector<int>& nums, int m) {
    ans = 0;n = nums.size(),k = 1ll*m;
    for(auto it:nums){
        v.push_back(it);
    }
    dp.assign(n+5,vector<ll>(4,-1));
    return dfs(0,0);
}*/

vector<ll> v,powerr;ll n,k;
void dk(){
    forj(25){
        if(j){
            powerr[j] = 2*powerr[j-1];
        }
    }
}

vector<vector<ll>> dp,vis;
ll dfs(ll i,ll cntr){
    vis[i][cntr] = 1;

    if(dp[i][cntr] != -1){return dp[i][cntr];}

    // Either take by way 1 or by way 2
    ll cns = (v[i-1]/powerr[cntr]);
    ll sa = 0;
    for(auto it:adj[i]){
        if(!vis[it][cntr]){
            ll a = 0,b = 0;
            a = (cns-k)+dfs(it,cntr);
            if(cntr+1 <= 25){
                b = (cns/2)+dfs(it,24);
            }else{
                b = (cns/2)+dfs(it,cntr+1);
            }
            sa += max({a,b,0ll});
        }
    }
    return dp[i][cntr] = sa;
}

ll dfs2(ll i,ll par,ll cntr){
    if(dp[i][cntr]!=-1){return dp[i][cntr];}
    
    // Either take by way 1 or by way 2
    ll cns = (v[i]/powerr[cntr]);
    ll sa = 0;
    ll a = cns-k;
    ll b = cns/2;
    
    for(auto it:adj[i]){
        if(it!=i){
            dfs2(it,i,min(24ll,cntr+1));
            dfs2(it,i,cntr);
            a = a+dp[it][cntr];
            b = b+dp[it][min(24ll,cntr+1)];
        }
    }
    return dp[i][cntr]=max(a,b);
}

int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int m) {
    for(auto it:edges){adj[it[0]].push_back(it[1]);adj[it[1]].push_back(it[0]);}
    for(auto it:coins){v.push_back(1ll*it);}n = v.size();k = 1ll*m;
    powerr.assign(25,1);dk();
    vis.assign(n+1,vector<ll> (25,-1));
    dp.assign(n+1,vector<ll> (25,-1));
    return dfs(0,0);
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