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
 
long long findTheArrayConcVal(vector<int>& nums) {
    ll i = 0,j = nums.size()-1;
    ll ans = 0;
    while(i <= j){
        string st;
        if(i == j){
            st += nums[i];
        }else{
            st += nums[i];
            st += nums[j];
        }

        ll cnt = stoll(st);
        ans += cnt;
        ++i,--j;
    }
    return ans;
}

long long countFairPairs(vector<int>& v, int lower, int upper) {
    ll ans = 0;
    sort(v.begin(),v.end());
    ll n = v.size();

    for(ll i = 0;i<n;++i){
        if(v[i] > upper){break;}

        if(lower > v[i]) {
            ll ele = lower-v[i];
            ll ele2 = upper-v[i];
            // Search element greater than ele & less than ele2
            ll lb = lower_bound(v.begin(),v.end(),ele)-v.begin();
            lb = max(lb,i+1);

            ll up = lower_bound(v.begin(),v.end(),ele2+1)-v.begin();
            // --up;

            if(lb > up){continue;}
            ans += (up-lb);
        }else{
            ll ele = upper-v[i];
            if(ele >= v[i]){
                ll up = lower_bound(v.begin(),v.end(),ele+1)-v.begin();
                ans += (up-i-1);
            }
        }
    }
    return ans;
}


#define ll int
vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
    map<ll,pair<ll,ll>> mp;
    ll n = s.size();
    for(ll i = 0;i<n;++i){
        if(s[i] == '0'){
            if(mp.find(0) == mp.end()){                
            mp[0] = {i,i};}
            continue;
        }
        string st;
        st += s[i];
        // Convert into decimal
        bitset<32> b1(st);
        long long val = b1.to_ulong();
        if(mp.find(val) == mp.end()){
            mp[val] = {i,i};
        }

        for(ll j = i+1;j<min(n,i+32);++j){
            // Generate all pssbl sequence
            st += s[j];
            bitset<32> b2(st);
            long long z = b2.to_ulong();
            if(mp.find(z) == mp.end()){
                mp[z] = {i,j};
            }
        }

    }
        vector<vector<int>> ans;
        for(ll i = 0;i<queries.size();++i){
            ll l = queries[i][0],r = queries[i][1];
            ll xr = (l^r);
            if(mp.find(xr) != mp.end()){
                auto p = mp[xr];
                ans.push_back({p.first,p.second});
                // ans.push_back();
            }else{
                ans.push_back({-1,-1});
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