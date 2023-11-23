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
// YE DIL MAANGE MORE!!
long long distributeCandies(int n, int limit) {
    ll ans = 0;
    for(ll i = 1;i<=n;++i){
        if(i > limit){break;}
        ll rem_ways = (n-i-1);
        ans += rem_ways;
        ll up = 2*(rem_ways-limit);
        if(up > 0){
            ans -= up;
        }
    }
    return ans;
}

ll fact[1000005];
ll powfact[1000005];
void precomputefact(){
   fact[0] = 1;
   ll ans = 1;
   for(ll i = 1;i<=1000005;++i){
       ans = (ans*i)%mod;
       fact[i] = ans;
       powfact[i] = power(fact[i],mod-2,mod);
   }
   powfact[0] = 1;
}

ll nCr(ll n,ll r){
    ll at = powfact[r];
    ll at2 = powfact[n-r];
    at = mod_mul(at,at2,mod);
    ll ele = mod_mul(at,fact[n],mod);
    return ele;
}

ll n;
/*
vector<vector<ll>> dp;
ll recur(ll idx,ll cnt,vector<ll> freq){
    if((idx >= 26) || (cnt > n)){return 0;}
    if(n == cnt){
        ll f = 0,dk = fact[n];
        forj(26){
            if(j == 4){
                if(freq[j] >= 2){++f;}
            }else if(j == 11){
                if(freq[j]){++f;}
            }else if(j == 19){
                if(freq[j]){++f;}
            }

            dk /= fact[freq[j]];
        }
        if(f == 3){return dk;}
        return 0;
    }

    ll &sa = dp[idx][cnt];
    if(sa != -1){return sa;}sa = 0;
    for(ll i = 0;i<=(n-cnt);++i){
        freq[idx] = i;
        sa += recur(idx+1,cnt+i,freq);
        sa %= mod;
    }
    return sa;
}
*/





long long distributeCandies(int n, int limit) {
    ll ans = 0;
    for(ll i = 0;i<=n;++i){
        if(i > (1ll)*limit){break;}
        ll rem_ways = (1ll*n-i+1);
        ans += rem_ways;
        ll up = 2*(n-i-limit);
        if(up > 0){
            ans -= min(up,rem_ways);
        }
        // cout<<i<<" "<<rem_ways<<" "<<up<<" "<<rem_ways-up<<endl;
    }
    return ans;
}


ll dp[100005][2][2][2][2];
ll dfs(ll i,ll l,ll e1,ll e2,ll t){
    if(i >= n){return (l && e1 && e2 and t);}

    ll &sa = dp[i][l][e1][e2][t];
    if(sa != -1){return sa;}sa = 0;
    forj(26){
        if(j == 4){
            if(e1){
                sa += dfs(i+1,l,e1,1,t);
            }else{
                sa += dfs(i+1,l,1,e2,t);
            }
        }else if(j == 11){
            sa += dfs(i+1,1,e1,e2,t);
        }else if(j == 19){
            sa += dfs(i+1,l,e1,e2,1);
        }else{
            sa += dfs(i+1,l,e1,e2,t);
        }
        sa %= mod;
    }
    return sa;
}

int stringCount(int m) {
    n = 1ll*m;
    for(ll i = 0;i<n;++i){
        forj(2){
            for(ll k = 0;k<2;++k){
                dp[i][j][k][0][0] = dp[i][j][k][0][1] = dp[i][j][k][1][1] = dp[i][j][k][1][0] = -1;
            }
        }
    }
    ll ans = dfs(0,0,0,0,0);
    return ans;
}

long long maxSpending(vector<vector<int>>& v) {
    ll ans=0,n = v.size(),m = v[0].size();
    multiset<vector<ll>>ms;
    for(ll i = 0;i<n;++i){
        ms.insert({1ll*v[i][m-1],i,m-1});
    }

    ll cntr = 1;
    while(!ms.empty()){
        auto p = *ms.begin();ms.erase(ms.find(p));
        ans += (p[0]*cntr);
        if(p[2]){
            ms.insert({v[p[1]][p[2]-1],p[1],p[2]-1});
        }
        ++cntr;
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