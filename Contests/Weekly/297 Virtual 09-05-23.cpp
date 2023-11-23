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
double calculateTax(vector<vector<int>>& v, int income) {
    vector<ll> ans;
    double dk = 0.0;
    for(ll i = 0;i<v.size();++i){
        if(i == 0){
            ll mn = min(income,v[i][0]);
            income -= mn;
            ans.push_back(mn);
        }else{
            ll mn = min(income,v[i][0]-v[i-1][0]);
            income -= mn;
            ans.push_back(mn);
        }
        dk += (1.0*ans[i]*v[i][1]/100);
    }
    return dk;
}

vector<vector<int>> v,cst,dp;
ll n,m;
ll ans = LLONG_MAX;
ll recur(ll idx,ll par){
    if(idx == n){return 0;}

    if(dp[idx][par] != -1){return dp[idx][par];}

    ll a = LLONG_MAX;
    for(ll j = 0;j<m;++j){
        ll sa = recur(idx+1,v[idx][j]);
        ll sm = v[idx][j]+cst[par][j];
        a = min(a,sa+sm);
    }
    return dp[idx][par] = a;
}

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    v = grid,cst = moveCost;
    n = grid.size(),m = grid[0].size();
    dp.assign(n+1,vector<int> (moveCost.size()+5,-1));
    ll ans = LLONG_MAX;
    for(ll i = 0;i<m;++i){
        ll sa = recur(1,v[0][i]);
        ans = min(ans,sa+v[0][i]);
    }
    return ans;
}

ll ans=INT_MAX;
void recur2(int i,vector<int>& v,int k,int n,vector<ll>& a){
    if(i==n){
        ans = min(ans*1ll,1ll*(*max_element(a.begin(),a.end())));
        return;
    }
    for(int j=1;j<=k;j++){
        a[j-1] += v[i];
        recur2(i+1,v,k,n,a);
        a[j-1] -= v[i];
    }
}

int distributevies(vector<int>& v, int k) {
    ll n = v.size();
    vector<ll> a(k,0);
    recur2(0,v,k,n,a);
    return ans;
}

long long distinctNames(vector<string>& v) {
    ll n = v.size();
    ll tot = n*(n-1)/2;
    map<string,ll> mp;for(auto it:v){mp[it]++;}
    map<char,ll> mp2;for(auto it:v){mp2[it[0]]++;}

    set<string> ms(all(v));
    vector<string> tmp(all(ms));

    for(ll i = 0;i<tmp.size();++i){
        string s = tmp[i];
        for(char j = 'a';j<='z';++j){
            s[0] = j;
            ll sa = 0;
            if(tmp[i][0] == j){
                ll freq = mp2[j];
                sa = freq*(freq-1)/2;
            }else{  
                if(ms.find(s) != ms.end()){
                    ll freq = mp2[j];
                    ll freq2 = mp[tmp[i]];
                    sa = freq*freq2;
                }
            }
            tot -= sa;
        }
    }
    return tot;
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