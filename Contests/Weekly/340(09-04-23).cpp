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
 
bool prime[4000005];
void SieveOfEratosthenes(){
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (ll p = 2; p * p <= 1e6; p++) {
        if (prime[p] == true) {
            for (ll i = p*p; i <= 1e6; i += p)
                prime[i] = false;
        }
    }
}
 

//  "A" : 65, "a" : 97  (-> |) (<- &(~))
bool isPrime(int n){
   if(n<2 || n%2==0 || n%3==0){
       return false;
   }
   
   for(int i=5; i*i <= n; i+=6){
      if(n%i==0 || n%(i+2)==0){
         return false;
      }
   }
   return true;
}
 
int diagonalPrime(vector<vector<int>>& v) {
    int ans = 0;
    for(ll i = 0;i<v.size();++i){
        for(ll j = 0;j<v[0].size();++j){
            if(i == j){
                if(isPrime(v[i][j])){
                    ans = max(ans,v[i][j]);
                }
            }

            // if(i == (v.size() - i - 1)){
                if(isPrime(v[i][v.size() - i - 1])){
                    ans = max(ans,v[i][v.size() - i - 1]);
                }
            // }
        }
    }
    return ans;
} 

vector<long long> distance(vector<int>& v) {
    vector<ll> ans;
    map<ll,ll> mp,dk_f;
    vector<ll> small(v.size() , 0);
    vector<ll> cnt(v.size() , 0);
    for(ll i  = 0;i<v.size();++i){
        small[i] = mp[v[i]];
        mp[v[i]] += i;
        cnt[i] = dk_f[v[i]];
        dk_f[v[i]]++;
    }

    for(ll i  = 0;i<v.size();++i){
        ll sm_till = small[i];
        ll freq_nxt = dk_f[v[i]]-1-cnt[i];

        ll ok_nxt = mp[v[i]]-small[i]-i;
        ll dk = abs(small[i]-cnt[i]*i);
        ll ak = abs(ok_nxt-freq_nxt*i);
        ans.push_back(ak+dk);
    }

    return ans;
}

int minimizeMax(vector<int>& v, int k) {
    sort(all(v));
    ll n = v.size();
    /*
    vector<vector<ll>> dp(n+1,vector<ll> (k+1,0));
    for(ll i = 0;i<v.size();++i){
        dp[0][k] = INT_MAX;
        for(ll p = 1;p<(1+i)/2;++p){
            dp[i][1] = v[i] - v[i-1];
            if(p > 1){
                dp[i][p] = min(dp[i-1][p],v[i]-v[i-1] + dp[i-2][p-1]);
            }else{
                dp[i][p] = dp[i-1][p];
            }
        }
//   where 0 < k ≤ ceil(i / 2)
    }
    return dp[n-1][k];*/

    ll l = 0,h = v[n-1]-v[0],ans = v[n-1]-v[0];
    while(l <= h){
        ll mid = (l+h)/2;
        ll cnt = 0;
        for(ll i = 0;i<n-1;++i){
            ll diff = v[i+1]-v[i];
            if(diff <= mid){
                ++cnt;++i;
            }
        }
        
        if(cnt >= k){
            ans = mid;
            h = mid-1;
        }else{
            l = mid+1;
        }
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