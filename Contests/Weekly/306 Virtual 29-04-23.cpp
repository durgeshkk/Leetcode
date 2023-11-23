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
vector<vector<int>> largestLocal(vector<vector<int>>& v) {
    ll n = v.size(),m = v[0].size();
    vector<vector<int>> ans(n-2,vector<int> (m-2,0));
    for(ll i = 0;i<n-2;++i){
        for(ll j = 0;j<m-2;++j){
            ans[i][j] = max({v[i][j+1],v[i][j+2],v[i][j],v[i+1][j],v[i+2][j],
            v[i+1][j+1],v[i+1][j+2],v[i+2][j+1],v[i+2][j+2],v[i+2][j]});
        }
    }
    return ans;
}

int edgeScore(vector<int>& v) {
    vector<int> ans(v.size()+1,0);
    for(ll i = 0;i<v.size();++i){
        ans[v[i]] += i;    
    }
    ll dk = *max_element(ans.begin(),ans.end());
    for(ll i = 0;i<ans.size();++i){
        if(ans[i] == dk){return i;}
    }
    return 0;
}

string smallestNumber(string s) {
    string tmp;
    char ch = '0';
    for(ll i = 0;i<=s.size();++i){
        tmp += (ch+i+1);
    }
    // cout<<tmp<<endl;
    string v = tmp;
    string ans = "999999999";

    ll flag = 1;
    for(ll i = 1;i<v.size();++i){
        ll diff = (v[i]-'0')-(v[i-1]-'0');
        if(diff > 0){
            if(s[i-1] == 'I'){
            }else{
                flag = 0;                    
            }
        }else{
            if(s[i-1] == 'I'){
                flag = 0;                    
            }else{
            }
        }
    }
    if(flag){
        ans = min(ans,tmp);
    }
    next_permutation(tmp.begin(),tmp.end());
    // cout<<tmp<<endl;
    
    while(tmp != v){
        ll f = 1;
        for(ll i = 1;i<v.size();++i){
            ll diff = (tmp[i]-'0')-(tmp[i-1]-'0');
            if(diff > 0){
                if(s[i-1] == 'I'){
                }else{
                    f = 0;                    
                }
            }else{
                if(s[i-1] == 'I'){
                    f = 0;                    
                }else{
                }
            }
        }
        if(f){
            ans = min(ans,tmp);
        }
        next_permutation(tmp.begin(),tmp.end());
    }

    if(ans == "999999999"){return "-1";}
    return ans;
}

// Upsolve : 
// DP + Bitmasking!!!

// Check if less is done or not
// If less is done we can include any digit else take less or equal
// flag to maintain small or not
vector<ll> v;
vector<vector<vector<ll>>> dp;
ll recur(ll idx,ll flag,ll mask){
    if(idx == v.size()){return mask != 0;}
    ll &ans = dp[idx][flag][mask];
    if(ans != -1){return ans;}
    ans = 0;

    if(flag){
        for(ll i = 0;i<=v[idx];++i){
            // Check if already used
            if(mask & (1 << i)){
                continue;
            }
            ll newMask = ((mask == 0 and i == 0) ? mask : (mask|1<<i));
            if(i == v[idx]){
                ans += recur(idx+1,1,newMask);
            }else{
                ans += recur(idx+1,0,newMask);
            }
        }
    }else{
        for(ll i = 0;i<=9;++i){
            // Check if already used
            if(mask & (1 << i)){
                continue;
            }
            ll newMask = ((mask == 0 and i == 0) ? mask : (mask|1<<i));
            ans += recur(idx+1,0,newMask);
        }
    }
    return ans;
}

int countSpecialNumbers(int n) {
    ll t = n;
    while(t > 0){
        v.push_back(t%10);
        t /= 10;
    }
    reverse(v.begin(),v.end());
    vector<vector<ll>> tmp(2,vector<ll> (1024,-1));
    dp.assign(v.size()+1,tmp);
    ll ans = recur(0,1,0);
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