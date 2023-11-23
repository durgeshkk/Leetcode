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
/*
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
bool revsort(ll a, ll b) {return a > b;}
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
 
vector<int> findIndices(vector<int>& v, int id, int vd) {
    vector<int> ans = {-1,-1};
    int n = v.size();
    for(int i = 0;i<n;++i){
        for(int j = i;j<n;++j){
            if(abs(j-i) >= id and abs(v[j]-v[i]) >= vd){
                ans.clear();
                ans = {i,j};return ans;
            }
        }
    }
    return ans;
}

string shortestBeautifulSubstring(string s, int k) {
    string ans;
    ll sz = 0;
    for(ll i = 0;i<s.size();++i){
        ll cntr = 0;
        
        string tmp;
        for(ll j = i;j<s.size();++j){
            tmp += s[j];
            if(s[j] == '1'){++cntr;}
                
            if(cntr >= k){
                if(ans==""){
                    ans = tmp;
                    sz = tmp.size();
                }else{
                    if(sz > tmp.size()){
                        sz = tmp.size();
                        ans = tmp;
                    }else if(sz == tmp.size()){
                        ans = min(ans,tmp);
                    }
                }
            }
        }
    }
    return ans;
}

//  "A" : 65, "a" : 97  (-> |) (<- &(~))
vector<int> findIndices(vector<int>& v, int id, int vd) {
    if(!id){
        if(!vd){
            return {0,0};
        }else{
            return {-1,-1};
        }
    }

    multiset<ll> ms;

    int n = v.size();
    for(int i = id;i<n;++i){ms.insert(v[i]);}

    vector<int> ans;
    int j = id;
    int ele = -1,idx = -1;
    for(int i = 0;i<n-id;++i){
        auto lft = ms.lower_bound(v[i]-vd);
        auto right = ms.lower_bound(v[i]+vd);

        if(lft != ms.begin()){
            idx = i;ele = *lft;break;
        }

        if(right != ms.end()){
            idx = i;ele = *right;break;
        }
        ms.erase(ms.find(v[j]));++j;
    }

    if(ele == -1){ans = {-1,-1};}
    else{
        int idx2 = -1;
        for(ll i = n-1;i>idx;--i){
            if(v[i] == ele){
                idx2 = i;
                break;
            }
        }
        ans = {idx,idx2};
    }
    return ans;
} 

vector<vector<int>> constructProductMatrix(vector<vector<int>>& v) {
    ll a = 1,n = v.size(),m = v[0].size();
    vector<ll> pref(n+m,0);
    vector<ll> suff(n+m,0);
    vector<vector<int>> ans(v);

    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            a = mod_mul(a,1ll*v[i][j],mod);
            pref[i*m+j] = a;
        }
    }

    a = 1;ll cntr = 0;
    for(int i = n-1;i>=0;--i){
        for(int j = m-1;j>=0;--j){
            a = mod_mul(a,1ll*v[i][j],mod);
            suff[cntr] = a;++cntr;
        }
    }

    reverse(all(suff));

    cntr = 0;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(!cntr){
                ll ele = suff[n+m-cntr-1];
                ans[i][j] = ele;
            }else if(cntr == (n+m-1)){
                ll ele = pref[cntr-1];
                ans[i][j] = ele;
            }else{
                ll ele = mod_mul(pref[cntr-1],suff[n+m-cntr-1],mod);
                ans[i][j] = ele;
            }
            ++cntr;
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