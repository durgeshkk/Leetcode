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

int maximumJumps(vector<int>& v, int x) {
    ll n = v.size();
    vector<ll> dp(n+1,0);
    for(ll i = n-1;i>=0;--i){
        for(ll j = i+1;j<n;++j){
            ll diff = v[i]-v[j];
            if((diff  <= x) and (diff >= -x)){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }

    if(!dp[0]){return -1;}
    return dp[0];
}

vector<ll> v,t;
ll n;
ll recur(ll idx,ll prev,ll start,ll mx){
    if(idx == n){return 0;}

    ll sa = 0;
    // Or Continue
    if(v[idx] >= prev){
        sa = max(sa,recur(idx+1,v[idx],start,max(mx,idx-start+1))+1);
    }else if(t[idx] >= prev){
        sa = max(sa,recur(idx+1,t[idx],start,max(mx,idx-start+1))+1);
    }else{
        // Start new
        sa = recur(idx+1,v[idx],idx,max(mx,1ll));
    }
    return mx;
}

ll recur(ll idx,ll mx,ll start,ll prev,ll len){
    if(idx == n){return 0;}
    
    ll sa = recur(idx+1,mx,idx,v[idx],1);
    if(v[idx] >= prev){
        sa = max(idx-start+1,max(sa,recur(idx+1,mx,start,v[idx],len+1));
    }
    if(t[idx] >= prev){
        sa = max(sa,recur(idx+1,mx,start,v[idx],len+1));
    }
    return max(mx,sa);
}

/*
n = len(nums)
        dp = [-1] * n
        dp[0] = 0
    
        for i in range(1, n):
            for j in range(i):
                if abs(nums[i] - nums[j]) <= target:
                    dp[i] = max(dp[i], dp[j] + 1)
        if dp[n-1]==0:
            return -1
    
        return dp[n-1]
*/

/*
int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2));
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            dp[i][0] = dp[i][1] = 1;

            if (i > 0) {
                if (nums1[i] >= nums1[i - 1])
                    dp[i][0] = dp[i - 1][0] + 1;

                if (nums1[i] >= nums2[i - 1])
                    dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);

                if (nums2[i] >= nums1[i - 1])
                    dp[i][1] = dp[i - 1][0] + 1;

                if (nums2[i] >= nums2[i - 1])
                    dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
            }

            maxLength = max(maxLength, max(dp[i][0], dp[i][1]));
        }

        return maxLength;
*/

int maxNonDecreasingLength(vector<int>& v, vector<int>& t) {
    n = v.size();
    vector<vector<ll>> dp(n+1,vector<ll>(3,0));
    forj(n){
        if(j){
            if(v[j] >= v[j-1]){
                dp[j][0] = dp[j-1][0]+1;
            }
            if(t[j] >= t[j-1]){
                dp[j][1] = max(dp[j][1],1+dp[j-1][1]);
            }

            if(v[j] >= t[j-1]){
                dp[j][0] = max(dp[j][0],1+dp[j-1][1]);
            }

            if(t[j] >= v[j-1]){
                dp[j][1] = max(dp[j][1],1+dp[j-1][0]);
            }
        }
    }

    ll ans = 0;
    forj(n){
        ans = max({ans,dp[j][0],dp[j][1]});
    }
    return ans;
    // forj(n){ll x = v[j],y = t[j];v[j] = min(v[j],t[j]);t[j] = max(v[j],t[j]);}

}

bool checkArray(vector<int>& v, int k) {
    ll n = v.size();
    vector<ll> pref(n+1,0);
    ll sm = 0;
    forj(n){
        if(j > 0){
            pref[j] += pref[j-1];
        }

        ll x = v[j]+pref[j];
        if(x < 0){return 0;}
        pref[j] -= x;
        if(j+k > n and x){return 0;}
        else if(j+k > n){continue;}
        pref[j+k] += x;
    }
    forj(n){
        if(v[j]+pref[j]){return 0;}
    }
    return 1;
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