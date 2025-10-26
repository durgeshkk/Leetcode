/*
Author : Durgesh Khandelwal
Once in a LifeTime,
Will never let you Down!!
HACKERCUP SELECTION RUINED --> Run Code from Input File : g++ -std=gnu++17 -O2 -pipe main.cpp -o main && ./main < input.txt > output.txt && code output.txt
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
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
/*
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

string lexSmallest(string s) {
    int n=s.size();
    string ans=s;

    for(int i=1;i<=n;++i){
        string tmp = s;
        reverse(tmp.begin(),tmp.begin()+i);
        ans = min(ans,tmp);
        
        tmp=s;
        reverse(tmp.begin() + i - 1, tmp.end());
        ans = min(ans,tmp);
    }
    return ans;

    // vector<int> v;
    // char ch = 'z';
    // int pos = -1;

    // string t=s;
    // sort(t.begin(),t.end());
    // int idx2 = -1;
    // for(int i=0;i<n;++i){
    //     if(s[i]!=t[i]){
    //         idx2 = i;
    //         ch = t[i];break;
    //     }
    // }       
    // if(idx2 == -1){return s;}


    // int idx = -1;
    // for(int i=n-1;i>=0;--i){
    //     if(s[i] == ch){
    //         // idx = i;
    //         v.push_back(i);
    //     }
    // }

    // // Reverse string from [idx2,idx];
    // string ans = s;
    // for(int i=0;i<v.size();++i){
    //     int idx = v[i],idx3 = idx2;
    //     string tmp = s;
    //     while(idx2 < idx){
    //         swap(tmp[idx],tmp[idx3]);
    //         ++idx2,--idx;
    //     }
    //     ans = min(ans,tmp);
    // }
    
    // return ans;
    
}

string maxSumOfSquares(int num, int sum) {
    
    string s;
    for(int j=0;j<num;++j){
        if(sum >= 9){
            sum -= 9;
            s += '9';
        } else {
            s += to_string(sum);
            sum = 0;
        }
    }

    if(sum){return "";}

    return s;
}

long long minOperations(vector<int>& v, vector<int>& t) {
    ll ans = 0;   
    for(int i=0;i<v.size();++i){
        ans += abs(v[i]-t[i]);
    }    

    ll ele = t[t.size()-1];
    ll sa = 1e6;
    for(int i = 0;i<v.size();++i){
        ll mn = min(v[i],t[i]);
        ll mx = max(v[i],t[i]);
        if(ele >= mn && ele <= mx){
            sa = 0;
        } else {
            sa = min({sa,abs(ele-mn),abs(ele-mx)});
        }
    }

    return ans+sa;
}

ll n,m;
vector<vector<ll>> v;
vector<vector<ll>> dp;

ll recur(ll rowNum, ll currGcd){

    if(rowNum >= n){
        if(currGcd == 1){return 1ll;}
        return 0;
    }

    ll &sa = dp[rowNum][currGcd]; 
    if(sa != -1){return sa;}
    sa = 0;
    for(ll i=0;i<m;++i){
        ll sa2 = recur(rowNum+1,__gcd(currGcd,v[rowNum][i]));
        sa = mod_add(sa,sa2,mod);
    }
    return sa;
}

int countCoprime(vector<vector<int>>& mat) {
    n = mat.size(),m = mat[0].size();
    
    v.assign(n,vector<ll> (m,-1));
    ll mx = 0;
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            v[i][j] = 1ll*mat[i][j];
            mx = max(mx,v[i][j]);
        }
    }
    
    dp.assign(mx+5,vector<ll> (mx+5,-1));
    ll sa=0;
    for(ll i = 0;i<m;++i){
        ll sa2 = recur(1,v[0][i]);
        sa = mod_add(sa, sa2,mod);
    }
    return sa;
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