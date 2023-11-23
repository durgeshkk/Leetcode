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
int countPairs(vector<int>& v, int x) {
    ll ans = 0,n = v.size();
    for(ll i = 0;i<n;++i){
        for(ll j = i+1;j<n;++j){
            ll a = v[i]+v[j];
            if(a < x){++ans;}
        }
    }
    return ans;
}

bool canMakeSubsequence(string s, string t) {
    string b = s;
    ll n = s.size();
    forj(n){
        b[j] = ('a'+((b[j]-'a'+1)%26));
    }

    ll j = t.size()-1,i = s.size()-1;
    while((j>=0) and (i>=0)){
        if(s[i] == t[j] || b[i] == t[j]){--j;}--i;
    }
    return j<0;
}
/*
ll n;vector<ll> v;
vector<vector<ll>> dp;
ll recur(ll idx,ll prev){
    if(idx == n){return 0;}
    if(dp[idx][prev] != -1){return dp[idx][prev];}
    ll a = n,b = n;
    if(v[idx] >= prev){
        a = recur(idx+1,v[idx]);
        b = recur(idx+1,prev)+1;
    }else{
        b = recur(idx+1,prev)+1;
    }
    return dp[idx][prev] = min(a,b);
}

int minimumOperations(vector<int>& t) {
    for(auto it:t){v.push_back(it);}
    n = v.size();
    dp.assign(n+5,vector<ll>(4,-1));
    return recur(0,0);
}*/

ll n1,n,k;
ll func(string &num, ll a){
    ll res = 0;
    for (ll i = 0; i < num.length(); i++){res = (res * 10 + num[i] - '0') % a;}
    return res;
}

string a,b;
ll recur(ll idx,ll f1,ll f2,string s){
    if(idx == n){
        ll x = func(s,k);
        if(!x){
            ll o = 0,e = 0,fl = 0;
            for(auto it:s){
                if(it != '0'){fl = 1;}
                if((fl) and ((it-'0')&1)){++o;}else if(fl){++e;}
            }
            
            if(o == e){
                // cout<<s<<endl;
                return 1;}
        }
        return 0;
    }

    ll sa = 0;
    if(!f1 and !f2){
        // Not in the Range of Both
        for(char ch = a[idx];ch<=b[idx];++ch){
            if(ch == a[idx] and ch == b[idx]){
                sa += recur(idx+1,f1,f2,s+ch);
            }else if(ch == a[idx]){
                sa += recur(idx+1,f1,1,s+ch);
            }else if(ch == b[idx]){
                sa += recur(idx+1,1,f2,s+ch);
            }else{
                sa += recur(idx+1,1,1,s+ch);
            }
        }
    }else if(f1 and !f2){
        // Already gr8ter than a bt equal to b
        for(char ch = '0';ch<=b[idx];++ch){
            if(ch == b[idx]){
                sa += recur(idx+1,1,f2,s+ch);
            }else{
                sa += recur(idx+1,1,1,s+ch);
            }
        }
    }else if(!f1 and f2){
        // Already less than b bt equal to a
        for(char ch = a[idx];ch<='9';++ch){
            if(ch == a[idx]){
                sa += recur(idx+1,f1,1,s+ch);
            }else{
                sa += recur(idx+1,1,1,s+ch);
            }
        }
    }else{
        for(char ch = '0';ch<='9';++ch){
            sa += recur(idx+1,1,1,s+ch);
        }
    }
    return sa;
}

ll dfs(ll idx,ll tight,string s,ll &x){
    if(idx == n and x){
        ll x = func(s,k);
        if(!x){
            ll o = 0,e = 0,fl = 0;
            for(auto it:s){
                if(it != '0'){fl = 1;}
                if((fl) and ((it-'0')&1)){++o;}else if(fl){++e;}
            }
            if(o == e){return 1;}
        }
        return 0;
    }
    if(idx == n1 and !x){
        ll x = func(s,k);
        if(!x){
            ll o = 0,e = 0,fl = 0;
            for(auto it:s){
                if(it != '0'){fl = 1;}
                if((fl) and ((it-'0')&1)){++o;}else if(fl){++e;}
            }
            if(o == e){return 1;}
        }
        return 0;
    }
    ll sa = 0;
    if(tight){
        // Already small
        for(char ch = '0';ch<='9';++ch){
            sa += dfs(idx+1,1,s+ch,x);
        }
    }else{
        // Still Equal
        if(!x){
            for(char ch = '0';ch<=a[idx];++ch){
                if(ch == a[idx]){
                    sa += dfs(idx+1,tight,s+ch,x);
                }else{
                    sa += dfs(idx+1,1,s+ch,x);
                }
            }
        }else{
            for(char ch = '0';ch<=b[idx];++ch){
                if(ch == b[idx]){
                    sa += dfs(idx+1,tight,s+ch,x);
                }else{
                    sa += dfs(idx+1,1,s+ch,x);
                }
            }
        }
    }
    return sa;
}

ll dp[11][11][2][25][11][2];
ll digitdp(ll idx,ll tight,ll sm_mod,ll odd,ll isZero,ll tot_len,string &s){
    if(idx == s.size()){
        if(!isZero and !sm_mod and (odd == tot_len-odd)){return 1;}
        return 0;
    }

    ll &sa = dp[idx][tot_len][tight][sm_mod][odd][isZero];
    if(sa != -1){return sa;}sa = 0;
    char ch = '9';
    if(tight){
        // Still it's equal
        ch = s[idx];
    }

    for(char i = '0';i<=ch;++i){
        ll ok = isZero and (i=='0');
        sa += digitdp(idx+1,(tight and (ch==i)),(10*sm_mod+(i-'0'))%k,odd+((i-'0')%2),ok,ok ? 0 : (tot_len+1),s);
    }
    return sa;
}

int numberOfBeautifulIntegers(int low, int high, int m) {
    a = to_string(low-1);b = to_string(high);k = (1ll*m);
    memset(dp, -1, sizeof(dp));
    ll pehla = digitdp(0,1,0,0,1,0,a);
    memset(dp, -1, sizeof(dp));
    ll dusra = digitdp(0,1,0,0,1,0,b);
    return (dusra-pehla);
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