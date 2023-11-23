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
int countSeniors(vector<string>& details) {
    ll cntr = 0;
    for(auto it:details){
        string s = it;
        ll k = (s[11]-'0')*10;
        k+=(s[12]-'0');
        if(k > 60){++cntr;}
    }
    return cntr;
} 

int matrixSum(vector<vector<int>>& nums) {
    for(auto &it:nums){
        sort(it.begin(),it.end());
    }  

    int m = nums[0].size(),n=  nums.size();
    int ans = 0;
    for(int i = 0;i<m;++i){
        int mx = 0;
        for(int j = 0;j<n;++j){
            mx = max(mx,nums[j][i]);
        }
        ans += mx;
    }
    return ans;
}

// Rejected after contest on case : 
/*
[6,9,8]
1 
O/p = 30 & Exp = 31 : {6,9,16}
*/
ll n,k;
vector<vector<ll>> dp;
vector<ll> v;
ll recur(ll idx,ll j){
    if(idx == n){return 0;}
    ll rem = (k-j);
    ll &ans = dp[idx][j];
    if(ans != -1){return ans;}
    for(ll i = 0;i<=rem;++i){
        ll sa = recur(idx+1,j+i);
        ll adder = (pow(2,i)*v[idx]);
        sa |= adder;
        ans = max(ans,sa);
    }
    return ans;
}

long long maximumOr2(vector<int>& tmp, int ak) {
    n = v.size(),k = ak;
    dp.assign(n+1,vector<ll> (k+1,-1));
    for(auto it:tmp){v.push_back(it);}
    ll ans = recur(0,0);
    return ans;
    /*
    vector<ll> z(50,0);
    for(auto it:v){
        bitset<32> b(it);
        for(ll j = 0;j<32;++j){
            if(b[j]){z[j]++;}
        }
    }

    for(ll j = 49;j>=0;--j){
        if(z[j]){
            --z[j];
            ++z[j+k];
            break;
        }
    }

    ll ans = 0;
    for(ll i = 0;i<50;++i){
        if(z[i]){
            ans += pow(2,i);
        }
    }
    return ans;*/
}

// Upsolve : 
long long maximumOr(vector<int>& v, int ak) {
    n = v.size();
    vector<ll> pref(n),suff(n);
    ll su = 0;
    for(ll i = 0;i<n;++i){
        pref[i] = su;su |= v[i];
    }

    su = 0;
    for(ll i = n-1;i>=0;--i){
        suff[i] = su;su |= v[i];
    }

    ll ans = 0;
    for(ll i = 0;i<n;++i){
        ll sa = pow(2,ak)*v[i]; 
        sa |= pref[i]; 
        sa |= suff[i]; 
        ans = max(ans,sa);
    }
    return ans;
}


/*
nums = [2,1,4]
2 will be involved only if it's max or minimum
*/
int sumOfPower(vector<int>& v) {
    sort(v.begin(),v.end());
    ll n = v.size();
    ll ans = 0,sm = 0;
    for(ll i = 0;i<n;++i){
        ll sa = mod_mul(v[i],v[i],mod);
        sa = mod_mul(sa,sm,mod);
        ans = mod_add(sa,ans,mod);
        sm = mod_mul(2,sm,mod);
        sm = mod_add(sm,v[i],mod);
    }

    for(ll i = 0;i<n;++i){
        ll sa = mod_mul(v[i],v[i],mod);
        sa = mod_mul(sa,v[i],mod);
        ans = mod_add(sa,ans,mod);
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