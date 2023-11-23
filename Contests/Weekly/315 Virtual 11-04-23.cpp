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
int findMaxK(vector<int>& v) {
    multiset<ll> ms(all(v));
    ll ans = -1;
    for(ll i = 0;i<v.size();++i){
        if(ms.find(-v[i]) != ms.end()){
            ans = max(ans,v[i]*1ll);
        }
    }
    return ans;
} 

int countDistinctIntegers(vector<int>& v) {
    set<ll> tmp(all(v));
    for(ll i = 0;i<v.size();++i){
        string s = to_string(v[i]);
        reverse(all(s));
        ll ele = stoi(s);
        tmp.insert(ele);
    }
    ll ans = tmp.size();
    return ans;
}

bool sumOfNumberAndReverse(int n) {
    for(ll i = 1;i<n;++i){
        string s = to_string(i);
        string t = s;
        reverse(all(t));
        ll ele = stoi(s)+stoi(t);
        if(ele == n){return 1;}
    }
    return 0;
}

long long countSubarrays(vector<int>& v, int mn, int mx) {
    ll n = v.size();
        set<ll> bg_idx,sm_idx,mnk,mxk;
        for(ll i = 0;i<n;++i){
            if(v[i] == mx){mxk.insert(i);}
            if(v[i] == mn){mnk.insert(i);}
            if(v[i] > mx){bg_idx.insert(i);}
            if(v[i] < mn){sm_idx.insert(i);}
        }

        ll ans = 0;
        for(ll i = 0;i<n;++i){
            if(v[i] > mx){bg_idx.erase(i);}
            if(v[i] < mn){sm_idx.erase(i);}

            // Start the subarray from idx = i
            if(v[i] == mx){
                mxk.erase(i);
                // Find big ele & also min. must include small ele
                // So range from small ele to big element
                if(!mnk.empty()){
                    ll s = *mnk.begin(),e = n;
                    if(!bg_idx.empty()){e = *bg_idx.begin();}
                    if(!sm_idx.empty()){e = min(e,*sm_idx.begin());}

                    if(s <= e){ans += (e-s);}
                }
                
                if(v[i] == mn){
                    mnk.erase(i);
                }
            }else if(v[i] == mn){
                mnk.erase(i);
                if(!mxk.empty()){
                    ll s = *mxk.begin(),e = n;
                    if(!bg_idx.empty()){e = *bg_idx.begin();}
                    if(!sm_idx.empty()){e = min(e,*sm_idx.begin());}
                    if(s <= e){ans += (e-s);}
                }
                
                if(v[i] == mx){
                    mxk.erase(i);
                }
            }else{
                if(!mnk.empty()){
                    if(!mxk.empty()){
                        ll s = *mnk.begin();
                        ll e = *mxk.begin();
                        ll f = n,g = n;
                        // Check if any small ele or big ele lies in b/w
                        if(!sm_idx.empty()){f = *sm_idx.begin();}
                        if(!bg_idx.empty()){g = *bg_idx.begin();}

                        if(f < max(s,e) || g < max(s,e)){continue;}

                        s = max(s,e);
                        e = min(f,g);
                        if(e >= s){ans += (e-s);}
                    }
                }
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