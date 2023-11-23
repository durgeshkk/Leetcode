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
int minimizedStringLength(string s) {
    set<char> st(s.begin(),s.end());
    int ans = st.size();
    return ans;
}

int semiOrderedPermutation(vector<int>& v) {
    ll idx = -1,idx2 =  -1;
    ll n = v.size();
    for(ll i = 0;i<n;++i){
        if(v[i] == 1){idx = i;}
        else if(v[i] == n){idx2 = i;}
    }

    ll ans = 0;
    if(idx2 > idx){
        ans += (n-1-idx2)+(idx);
    }else{
        ans += (n-1-idx2)+(idx-1);
    }
    return ans;
}

long long matrixSumQueries(int n, vector<vector<int>>& q) {
    // vector<vector<>> row(n,vector<ll>(n,0));
    // vector<vector<ll>> col(n,vector<ll>(n,0));
    /*
    pair<ll,ll> row[n][n];
    pair<ll,ll> col[n][n];

    for(ll i = 0;i<n;++i){
        forj(n){
            row[i][j] = {0,0};
            col[i][j] = {0,0};
        }
    }

    ll sm = 0,cntr = 0;
    for(auto it:q)  {
        ll t = it[0],idx = it[1],val = it[2];
        if(!t){
            row[idx][0] = {val,cntr};
            row[idx][n-1] = {val,cntr};
        }else{
            col[0][idx] = {val,cntr};
            col[n-1][idx] = {val,cntr};
        }
        ++cntr;
    }

    for(ll i = 0;i<n;++i){
        for(ll j = 1;j<n;++j){
            row[i][j] = row[i][j-1];
        }
    }

    for(ll i = 1;i<n;++i){
        forj(n){
            col[i][j] = col[i-1][j];
        }
    }

    vector<vector<ll>> ans(n,vector<ll>(n,0));
    for(ll i = 0;i<n;++i){
        forj(n){
            if(row[i][j].second > col[i][j].second){
                ans[i][j] = row[i][j].first;
            }else if(row[i][j].second == col[i][j].second){
                ans[i][j] = max(row[i][j].first,col[i][j].first);
            }else{
                ans[i][j] = col[i][j].first;
            }
            sm += ans[i][j];
        }
    }
    return sm;*/

    vector<vector<ll>> dk(n,vector<ll>(2,0));

    ll row = 0,col = 0,ans = 0;
    for(ll i = q.size()-1;i>=0;--i){
        ll t = q[i][0],idx = q[i][1],val = q[i][2];
        if(!dk[idx][t]){
            if(t){
                ++col;
            }else{
                ++row;
            }
            ll sa = row;
            if(!t){sa = col;}
            ans += (n-sa)*val;
            dk[idx][t] = 1;
        }
    }
    return ans;
}

#define ll long long int
#define forj(n) for (ll j = 0; j < n; j++)
ll mod = (ll)(1e9+7);
ll mn,mx;
string s,t;
ll dp[2][405][25];

ll recur(ll f,ll curr_sm,ll idx){
    if(idx == t.size() and f){
        if(curr_sm >= mn and curr_sm <= mx){
            return 1;
        }
        return 0;
    }
    if(curr_sm > mx || idx > t.size()){return 0;}

    ll &sa = dp[f][curr_sm][idx];
    if(sa != -1){return sa;}
    sa = 0;
    forj(10){
        // if(idx == 0 and j == 0){continue;}
        ll ch = (t[idx]-'0');
        if(f){
            sa += recur(f,curr_sm+j,idx+1);
            sa %= mod;
        }else{
            if(j > ch){break;}
            if(j == ch){
                sa += recur(0,curr_sm+j,idx+1);
                sa %= mod;
            }else{
                sa += recur(1,curr_sm+j,idx+1);
                sa %= mod;
            }
            sa %= mod;
        }
    }
    return sa;
}

ll recur2(ll f1,ll curr_sm,ll idx){
    if(idx == t.size() and f1){
        if(curr_sm >= mn and curr_sm <= mx){
            return 1;
        }
        return 0;
    }

    if(curr_sm > mx || idx > t.size()){return 0;}

    ll &sa = dp[f1][curr_sm][idx];
    if(sa != -1){return sa;}
    sa = 0;

    forj(10){
        ll ch = (t[idx]-'0');
        if(f1){
            sa += recur(f1,curr_sm+j,idx+1);
            sa %= mod;
        }else{
            if(j > ch){break;}
            if(j == ch){
                sa += recur(0,curr_sm+j,idx+1);
                sa %= mod;
            }else{
                sa += recur(1,curr_sm+j,idx+1);
                sa %= mod;
            }
            sa %= mod;
        }
    }
    return sa;
}

int count(string num1, string num2, int min_sum, int max_sum) {
    s = num1,t = num2;
    mn = 1ll*min_sum,mx = 1ll*max_sum;
    for(ll i = 0;i<405;++i){
        forj(25){
            dp[0][i][j] = -1;
            dp[1][i][j] = -1;
        }
    }

    ll ans = recur(0,0,0);
    ++ans;
    ans %= mod;
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