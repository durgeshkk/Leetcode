#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
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
void google(ll t) {cout << "Case #" << t << ": ";}
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
ll minNumber(vector<ll>& v, vector<ll>& v2) {
    ll n = v.size();
    map<ll,ll> mp;
    for(auto it:v2){
        mp[it]++;
    }

    sort(all(v));
    sort(all(v2));
    for(ll i = 0;i<n;++i){
        if(mp.find(v[i]) != mp.end()){
            return v[i];
        }
    }

    ll ans = 0;
    ans += (10*v[0]);
    ans += (v2[0]);

    ll ans2 = 0;
    ans2 += (10*v2[0]);
    ans2 += (v[0]);
    ans = min(ans,ans2);
    return ans;
}

ll maximumCostSubstring(string s, string chars, vector<ll>& vals) {
    ll ans = 0;
    map<char,ll> mp;
    for(ll i = 0;i<26;++i){
        mp['a'+i] = (i+1);
    }

    ll sz = chars.size();
    for(ll i = 0;i<sz;++i){
        mp[chars[i]] = vals[i];
    }

    vector<ll> v;
    for(ll i = 0;i<s.size();++i){
        v.push_back(mp[s[i]]);
    }

    ll dk = LLONG_MIN, ak = 0;
 
    for(ll i = 0; i < v.size();++i) {
        ak = ak + v[i];
        if (dk < ak)
            dk = ak;
 
        if (ak < 0)
            ak = 0;
    }
    ans = max(dk,1ll*0);
    return ans;     
}   

vector<ll> dk,baap;
ll ans = LLONG_MAX;
void shortest_cycle(ll i,ll n){
    dk[i] = 0;
    queue<ll> q;
    q.push(i);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (auto it : adj[x]) {
            if (dk[it] == (50000*1ll)) {
                dk[it] = (1 + dk[x]);
                baap[it] = x;
                q.push(it);
            }else if (baap[x] != it and baap[it] != x){
                ans = min(ans, dk[x] + dk[it] + 1);
            }
        }
    }
}

int findShortestCycle(int n, vector<vector<int>>& edges) {
    for(auto &it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    for (ll i = 0; i < n; i++) {
        dk.assign(n,50000*1ll);
        baap.assign(n,-1);
        shortest_cycle(i,n);
    }

    if (ans != LLONG_MAX){
       return ans;
    }else{
        return -1;
    }
}

long long makeSubKSumEqual(vector<ll>& arr, ll k) {
    // I need to make factors of k
    if(k & 1){
        // Make all ele equal
    }else{

    }

    ll ans = 0;
    vector<ll> v = arr;
    ll sm = 0;
    for(ll i = 0;i<k;++i){
        v.push_back(arr[i]);
        sm += arr[i];
    }
    vector<ll> pref;
    pref.push_back(sm);
    ll l = 0,r = k-1,n = v.size();
    while(r < n){
        if(r+1 < n){
            sm -= v[l];
            sm += v[r+1];
            v.push_back(sm);
        }
        ++l,++r;
    }

    ll mn = *min_element(all(pref));
    ll mx = *max_element(all(pref));
    ll l = mn,h = mx;
    while(l <= h){
        ll mid = (l+h)/2;

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
 
ll main()
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