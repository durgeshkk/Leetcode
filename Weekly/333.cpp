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

vector<vector<int>> mergeArrays(vector<vector<int>>& v1, vector<vector<int>>& v2) {
    int maxi = 0;
    vector<vector<int>> ans;
    map<int,int> mp;
    for(ll i = 0;i<v1.size();++i){
        if(mp.find(v1[i][0]) == mp.end()){
            mp[v1[i][0]] = mp[v1[i][1]];
        }else{
            mp[v1[i][0]] = mp[v1[i][0]]+ mp[v1[i][1]];
        }
    }
    for(ll i = 0;i<v2.size();++i){
        if(mp.find(v2[i][0]) == mp.end()){
            mp[v2[i][0]] = mp[v2[i][1]];
        }else{
            mp[v2[i][0]] = mp[v2[i][0]]+ mp[v2[i][1]];
        }
    }
    for(auto it:mp){
        vector<int> z = {it.first,it.second};
        ans.push_back(z);
    }
    return ans;
}
 
vector<vector<ll>> dp;
ll recur(ll idx,vector<ll> &v,ll c,ll sm){
    if(idx == v.size()){
        if(c == 1){return 1;}
        return 0;
    }

    if(dp[idx][c] != -1){return dp[idx][c];}

    ll a = LLONG_MAX,b = LLONG_MAX;
    if(c == 1){
        // Back is pending
        if(v[idx] == 1){
            a = recur(idx+1,v,c,sm);
        }else{
            // Pass ahead
            a = 1+recur(idx+1,v,c,sm);
            // Clear
            b = 2+recur(idx+1,v,0,sm);
        }
    }else{
        if(v[idx]){
            // Make it 0
            a = 1+recur(idx+1,v,0,sm);
            // Pass
            b = 1+recur(idx+1,v,1,sm);
        }else{
            a = recur(idx+1,v,c,sm);
        }
    }
    return dp[idx][c] = min(a,b);
}

int minOperations(int n) {
    bitset<32> b(n);
    int ans = 0,ans2 = 0,idx = -1;
    vector<ll> v;
    dp.assign(n+1,vector<ll> (2,-1));
    for(ll i = 31;i>=0;--i){
        if(b[i] == 1){++ans;
            if(idx == -1){idx = i;}
        }
    }

    for(ll i = 0;i<=idx;++i){
        v.push_back(b[i]);
        /*
        ll cnt = 0;
        if(b[i]){
            while(i<=idx and b[i]){
                ++i;++cnt;
            }
            if(cnt >= 2){
                ans2 += 2;
            }else{
                ans2++;
            }
            --i;
        }*/
    }
    ans = recur(0,v,0,0);
    // ans = min(ans,ans2);
    return ans;
}

void precompute(){

}

int squareFreeSubsets(vector<int>& nums) {
    map<ll,ll> mp;
    for(auto it:nums){

    }
}

string findTheString(vector<vector<int>>& lcp) {
    vector<char> v(lcp.size()+1);
    ll n = lcp.size();
    ll m = lcp[0].size();
    char ch = 'a';
    for(ll i = 0;i<n;++i){
        for(ll j = i+1;j<m;++j){
            if(lcp[i][j] == 0){
                ++ch;
                v[]
            }
        }
    }

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