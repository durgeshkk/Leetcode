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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
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
bool isGood(vector<int>& v) {
    ll n = v.size();
    sort(all(v));
    for(ll i = 0;i<n;++i) {
        if(v[i] != i+1){return 0;}
    }
    if(v[n] == n){return 1;}return 0;
}

string sortVowels(string s) {
    ll n = s.size();
    multiset<char> ms,sm;
    set<char> a = {'a','e','i','o','u'};
    set<char> b = {'A','E','I','O','U'};
    set<char> c = {'A','E','I','O','U','a','e','i','o','u'};

    for(ll i = 0;i<n;++i){
        for(auto it:a){
            if(it == s[i]){sm.insert(s[i]);}
        }
        for(auto it:b){
            if(it == s[i]){ms.insert(s[i]);}
        }
    }

    for(ll i = 0;i<n;++i){
        for(auto it:c){
            if(it == s[i]){
                if(!ms.empty()){
                    s[i] = *ms.begin();ms.erase(ms.find(s[i]));
                }else{
                    s[i] = *sm.begin();sm.erase(sm.find(s[i]));
                }
            }
        }
    }
    return s;
}

/*
ll x,n;
vector<ll> v;
vector<vector<ll>> dp;

// f is for odd
ll recur(ll idx,ll f){
    if(idx == n){return 0;}

    ll &sa = dp[idx][f];
    if(sa != -1){return sa;}

    sa = 0;
    for(ll j = idx;j<n;++j){
        ll sa1 = 0,sa2 = 0;
        if(f){
            if(v[j] & 1){sa1 = v[j]+recur(j+1,1);}
            else{sa2 = v[j]-x+recur(j+1,0);}
        }else{
            if(v[j] & 1){sa1 = v[j]-x+recur(j+1,1);}
            else{sa2 = v[j]+recur(j+1,0);}
        }
        sa = max({sa,sa1,sa2});
    }
    return sa;
}

long long maxScore(vector<int>& nums, int y) {
    n = nums.size(),x = 1ll*y;
    for(auto it:nums){v.push_back(1ll*it);}
    dp.assign(n+1,vector<ll>(3,-1));

    ll ans = 0,c1 = 0,c2 = 0;
    for(ll i = 0;i<n;++i){
        if(v[i] & 1 and !c1){
            ans = max(ans,v[i]+recur(i+1,1));
            c1 = 1;
        }
        if(v[i]%2 == 0 and !c2){
            ans = max(ans,v[i]+recur(i+1,0));
            c2 = 1;
        }
        if(c1 & c2){break;}
    }
    return ans;
}
*/

long recur(vector<int>& nums,int pos,bool previsodd,int x,vector<vector<long>>&dp){
    if(pos>=nums.size())
        return 0;
    if(dp[pos][previsodd]!=-1)
        return dp[pos][previsodd];
    long take,nottake;
    if((previsodd && nums[pos]%2) || (previsodd==false && nums[pos]%2==0)){
        take=nums[pos]+recur(nums,pos+1,previsodd,x,dp);
    }
    else{
        take=nums[pos]-x+recur(nums,pos+1,!previsodd,x,dp);
    }
    nottake=recur(nums,pos+1,previsodd,x,dp);
    return dp[pos][previsodd]=max(take,nottake);
}
long long maxScore(vector<int>& nums, int x){
    vector<vector<long>>dp(nums.size(),vector<long>(2,-1));
    return nums[0]+recur(nums,1,nums[0]%2,x,dp);
}

vector<vector<ll>> dp;
ll x,n;
ll recur(ll i,ll rem,ll num){
    if(rem < 0){return 0;}
    else if(rem == 0){return 1;}
    if(i == num+1){return 0;}
    
    ll &sa = dp[i][rem];
    if(sa != -1){return sa;}
    sa = 0;
    
    ll np = recur(i+1,rem,num);
    ll p = recur(i+1,rem-pow(i,x),num);
    sa = mod_add(p,np,mod);
    return sa;
}

int numberOfWays(int m, int y) {
    x = 1ll*y;
    n = 1ll*m;
    // v.assign(n+5,vector<ll> (6,-1));
    dp.assign(n+5,vector<ll> (n+5,-1));
    // fxn();
    return recur(1,n,n);
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