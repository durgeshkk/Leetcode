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
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
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
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
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
 
 
ll fact[100005];
ll powfact[100005];
void precomputefact(){
    fact[0] = 1;
    ll ans = 1;
    for(ll i = 1;i<=100005;++i){
         ans = (ans*i)%mod;
         fact[i] = ans;
         powfact[i] = power(fact[i],mod-2,mod);
    }
}
 
ll nCr(ll n,ll r){
     ll at = powfact[r];
     ll at2 = powfact[n-r];
     return ((fact[n]*((at*at2)%mod))%mod);
}
 
vector<ll> adj[100004];
 
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({1,0});
 
    while(!q.empty()){
        auto it = q.front();
        q.pop();
 
        ll node = it.first;
        ll par = it.second;
 
        cout<<node<<" ";
 
        for(auto it:adj[node]){
            if(it != par){
                q.push({it,node});
            }
        }
    }
}
 
ll height;
ll subtree[100005];
ll lev[100005];
ll parent[200005];
 
void dfs(ll node, ll par, ll level=1){

    cout<<node<<" ";
    lev[node] = level;
    height = max(height,level);
 
    ll sm = 0;
 
    parent[node] = par;
    for(auto it:adj[node]){
        if(it != par){
            dfs(it,node,level+1);
            sm += subtree[it];
        }
    }
    subtree[node] = 1+sm;
}
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
// Q1 
int countTime(string s) {

    map<int,int> m1,m2;
    m1[0] = 10;
    m1[1] = 10;
    m1[2] = 4;
    for(int i= 0;i<=3;++i){
        m2[i] = 3;
    }

    for(int i= 4;i<=9;++i){
        m2[i] = 2;
    }
    
    int ans = 1;
    if((s[0] == '?') and (s[1] == '?')){
        ans *= 24;
    }
    else if((s[0] == '?')){
        int num = (s[1]-'0');
        int val = m2[num];
        ans *= val;
    }
    else if((s[1] == '?')){
        int num = (s[0]-'0');
        int val = m1[num];
        ans *= val;
    }else{
        ans *= 1;
    }

    if((s[3] == '?') and (s[4] == '?')){
        ans *= 60;
    }
    else if((s[3] == '?')){
        ans *= 6;
    }
    else if((s[4] == '?')){
        ans *= 10;
    }else{
        ans *= 1;
    }

    return ans;
}

// Q2
int mod_mul(int a, int b, int m) 
{
    a = a % m; 
    b = b % m; 
    ll val = (1ll*a*b);
    return (((val) % m) + m) % m;
}

int power(int x, int n){
    int result = 1;
    while (n > 0) {
        if (n & 1 == 1){
            result = mod_mul(result,x,mod);
        }
        x = mod_mul(x,x,mod);  
        n = n >> 1; // y=y/2;
    }
    return result;
}

vector<int> productQueries(int n, vector<vector<int>>& q) {
    vector<int> store;
    int idx = -1;
    // cout<<b<<endl;

    bitset<32> b(n);
    map<int,int> mp;
    int j = 0;
    for(int i = 0;i<32;++i){
        if(b[i] == 1){
            mp[j] = i;
            ++j;
        }
    }

    // for(auto it:mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    
    vector<int> ans;
    for(int i = 0;i<q.size();++i){
        int a = q[i][0], b = q[i][1];
        int sm = 0;
        for(int j = a;j<=b;++j){
            sm += mp[j];
        }

        int dk = power(2,sm);
        ans.push_back(dk);
    }
    return ans;

                // int val = pow(2,i);
            // store.push_back(val);
            // idx = i;

    // show(store);

    // int sz = store.size();
    // vector<int> pref(sz,1);
    // pref[0] = store[0];
    // for(int i = 1;i<sz;++i){
    //     pref[i] = mod_mul(pref[i-1],store[i],mod);
    // }

    // show(pref);
    // cout<<q.size()<<endl;
    // cout<<q[0].size()<<endl;


        // if(a == 0){
        //     ans.push_back(pref[b]);
        //     continue;
        // }

        // --a;
        // int dk = pref[b]/pref[a];

}

// Q3
int minimizeArrayValue(vector<int>& nums) {
    int n = nums.size();
    vector<ll> pref(n,0);
    pref[0] = nums[0] ;

    for(int i = 1;i<n;++i){
        pref[i] = (nums[i]+pref[i-1]);
    }

    int mx = *max_element(nums.begin(),nums.end());
    ll ans = -1;

    if(nums[0] == mx){
        return mx;
    }
    
    vector<ll> v;
    for(int i = 0;i<n;++i){
        v.push_back(1LL*nums[i]);
    }

    for(int i = 1;i<n;++i){
        ll val = ceil(1.0*pref[i]/(i+1));
        v[i] = min(1LL*v[i],val);
    }

    ans = *max_element(v.begin(),v.end());
    return (int)ans;
    // show(v);
    // int ans = -1;
    /*
    int prev = -1;
    int mn = INT16_MIN;
    for(int i=0;i<n;++i){
        if(nums[i] == mx){
            if(prev == -1){
                int ak = ceil(1.0*pref[i]/(i+1));
                // cout<<ak<<endl;
                mn = max(mn,ak);
                prev = i;
                continue;
            }
            int ak = ceil(1.0*pref[i]/(i+1));

            int a = (i-prev);
            int sm = (pref[i]-pref[prev]);
            int ag = ceil(1.0*sm/(a));
            prev = i;
            ak = min(ak,ag);
            mn = max(mn,ak);
        }
    }*/
    // return ans;
}



void solve()
{
 
    // Q1
    // string s;cin>>s;
    // int ans = countTime(s);
    // cout<<ans<<endl;

    // Q2
    // int n;cin>>n;
    // vector<vector<int>> q;
    // for(int i = 0;i<1;++i){
    //     int a,b;
    //     cin>>a>>b;
    //     vector<int> ak;
    //     ak.push_back(a);
    //     ak.push_back(b);
    //     q.push_back(ak);
    // }
    // vector<int> ans = productQueries(n,q);
    // show(ans);

    // Q3
    // int n;cin>>n;
    // vector<int> v(n);enter(v);
    // int ans = minimizeArrayValue(v);
    // cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
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