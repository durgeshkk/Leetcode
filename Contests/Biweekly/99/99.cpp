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
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
#define all(a) a.begin(),a.end()
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
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
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
int splitNum(int num) {
    string s = to_string(num);
    sort(all(s));
    string s1,s2;
    for(ll i = 0;i<s.size();++i){
        if(i & 1){
            s2 += s[i];
        }else{
            s1 += s[i];
        }
    }
    ll a = stoll(s1);
    ll b = stoll(s2);
    ll ans = (a+b);
    return ans;
}

long long coloredCells(int n) {
    vector<ll> v(n+1,0);
    v[1] = 1;
    for(ll i = 2;i<=n;++i){
        v[i] = v[i-1] + (i*4);
    }
    return v[n];
}

int countWays(vector<vector<int>>& v) {
    ll distinct = 1;
    sort(all(v));
    ll l = v[0][0],r = v[0][1];
    for(ll i = 1;i<v.size();++i){
        if(v[i][0] >= l and v[i][0] <= r){
            l = min(l,1ll*v[i][0]);
            r = max(r,1ll*v[i][1]);
        }else{
            l = v[i][0];
            r = v[i][1];
            ++distinct;
        }
    }

    ll ans = power(2,distinct,mod);
    return ans;
}

vector<ll> par,vis;
ll recur(ll idx,ll cnt,ll k,vector<vector<int>>& v,vector<vector<int>>& dp){
    if(idx == v.size()){
        if(cnt >= k){return 1;}
        return 0;
    }

    ll a = 0,b = 0;
    if(dp[idx][cnt] != -1){
        return dp[idx][cnt];
    }

    // Pick this guess
    if((par[v[idx][1]] == -1) || (par[v[idx][1]] == v[idx][0])){
        // Now only pick pssbl
        par[v[idx][1]] = v[idx][0];
        a = recur(idx+1,cnt+1,k,v,dp);
        par[v[idx][1]] = -1;
    }

    // Reject this guess,means vice versa is true!!!
    if((par[v[idx][0]] == -1) || (par[v[idx][0]] == v[idx][1])){
        par[v[idx][0]] = v[idx][1];
        b = recur(idx+1,cnt,k,v,dp);
        par[v[idx][0]] = -1;
    }
    return dp[idx][cnt] = (a+b);
}

map<pair<ll,ll>,ll> guess;
ll dfs(ll i,ll papa){
    vis[i] = 1;
    par[i] = papa;

    ll a = 0;
    if(guess.find({papa,i}) != guess.end()){
        ++a;
    }

    for(auto it:adj[i]){
        if(!vis[it]){
            a += dfs(it,i);
        }
    }
    return a;
}

void dfs2(ll i,ll papa,ll small_ans,ll k,ll &ans){
    if(small_ans >= k){
        ++ans;
    }
    vis[i] = 1;
    for(auto it:adj[i]){
        if(!vis[it]){
            dfs2(it,i,small_ans-guess[{i,it}]+guess[{it,i}],k,ans);
        }
    }
}

int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
    for(auto x:edges){
        guess[{x[0],x[1]}]++;
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    vis.assign(edges.size()+1,0);
    ll zero_ans = dfs(0,-1),ans = 0;
    vis.clear();
    vis.assign(edges.size()+1,0);

    ll ans = 0;
    dfs2(0,-1,0,k,ans);
    return ans;

    // vector<vector<int>> dp(edges.size()+1,vector<int> (k+1,-1));
    // vis.assign(edges.size()+1,0);
    // ll ans = recur(0,0,1ll*k,guesses,dp);
    // return ans;
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