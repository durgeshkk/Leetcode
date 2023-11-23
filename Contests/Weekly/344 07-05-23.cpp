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
vector<ll> distinctDifferenceArray(vector<int>& v) {
        
    ll n = v.size();
    set<ll> s;
    vector<ll> ans;
    for(ll i = 0;i<n;++i){
        s.insert(v[i]);
        set<ll> s2;
        for(ll j  = i+1;j<n;++j){
            s2.insert(v[j]);
        }

        ll a = s.size(),b = s2.size();
        ans.push_back(a-b);
    }
    return ans;
}

/*
["FrequencyTracker","deleteOne","deleteOne","deleteOne",
"deleteOne","hasFrequency","add","deleteOne","hasFrequency",
"deleteOne","deleteOne","deleteOne","hasFrequency","add",
"hasFrequency","deleteOne","hasFrequency","hasFrequency",
"add","hasFrequency","add","deleteOne","hasFrequency","add",
"hasFrequency","hasFrequency","add"]
[[],[9],[8],[1],
[4],[1],[10],[5],[1],
[10],[9],[10],[1],[4]
,[1],[4],[1],[1]
,[10],[1],[2],[1],[2],[7],
[1],[1],[6]]

[null,null,null,null
,null,false,null,null,true
,null,null,null,false,null,
true,null,false,false,
null,false,null,null,false,null,
true,true,null]

[null,null,null,null,
null,false,null,null,true,
null,null,null,false,null,
true,null,false,false,
null,true,null,null,false,null,
true,true,null].

[null,null,null,null,null,false,null,null,true,null,null,null,false,null,true,null,false,false,null,true,null,null,false,null,true,true,null]
[null,null,null,null,null,false,null,null,true,null,null,null,false,null,true,null,false,false,null,true,null,null,false,null,true,true,null]
*/

class FrequencyTracker {
public:
    multiset<ll> ms;
    map<ll,ll> mp;
    FrequencyTracker() {
        
    }
    
    void add(int num) {
        ll f = mp[num];
        if(ms.find(f) != ms.end()){
            ms.erase(ms.find(f));
        }
        mp[num]++;
        ms.insert(mp[num]);
    }
    
    void deleteOne(int num) {
        if(mp.find(num) == mp.end()){
            return;
        }

        ll f = mp[num];
        if(ms.find(f) != ms.end()){
            ms.erase(ms.find(f));
        }
        mp[num]--;
        if(mp[num] == 0){
            mp.erase(mp.find(num));
        }else{
            ms.insert(mp[num]);
        }
    }
    
    bool hasFrequency(int freq) {
        if(ms.find(freq) != ms.end()) {return 1;}
        return 0;
    }
};

vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    vector<int> ans(n,0);
    vector<int> v(n,-1);

    if(n == 1){
        return ans;
    }

    ll dk = 0;
    for(auto it:queries){
        ll i = it[0],upd = it[1];
        if(v[i] == -1){
            v[i] = upd;
            if(i == 0){
                if(v[i+1] == v[i]){
                    ++dk;
                }
            }else if(i == n-1){
                if(v[i-1] == v[i]){
                    ++dk;
                }
            }else{
                if((i+1<n) and v[i+1] == v[i]){
                    ++dk;
                }
                if((i-1>=0) and v[i-1] == v[i]){
                    ++dk;
                }
            }
        }else{
            if(i == 0){
                if(v[1] == v[0]){--dk;}
                v[0] = upd;
                if(v[1] == v[0]){++dk;}
            }else if(i == n-1){
                if(v[i-1] == v[i]){--dk;}
                v[i] = upd;
                if(v[i-1] == v[i]){++dk;}
            }else{
                if((i+1<n) and v[i+1] == v[i]){--dk;}
                if((i-1>=0) and v[i-1] == v[i]){--dk;}
                v[i] = upd;
                if((i+1<n) and v[i+1] == v[i]){++dk;}
                if((i-1>=0) and v[i-1] == v[i]){++dk;}
            }
        }
        ans[i] = dk;
    }
    return ans;
}

ll n,pathsm;
vector<ll> v,dp;
ll dfs(ll i){
    if(i > n){return 0;}
    ll a = dfs(2*i);
    ll b = dfs(2*i+1);
    return (max(a,b)+v[i]);
}

void dfs2(ll i,ll sm){
    if(i > n){return;}
    sm += v[i];
    // Leaf Node
    if(2*i > n){
        dp[i] += (pathsm-sm);
    }else{
        dp[i] = sm;
        dfs2(2*i,sm);
        dfs2(2*i+1,sm);
    }
    return;
}

ll ans = 0;
ll dfs3(ll i){
    if(i > n){return 0;}
    ll a = dfs3(2*i);
    ll b = dfs3(2*i+1);
    ll mn = min(a,b);
    ans += (a-mn+b-mn);

    ll diff = 0;
    diff = dp[i] - v[i] + mn;
    return diff;
}

int minIncrements(int m, vector<int>& cost) {
    n = m,ans = 0;
    v.assign(n+1,0);
    dp.assign(n+1,0);dp = v;
    for(ll i = 0;i<cost.size();++i){v[i+1]  = cost[i];}

    pathsm = dfs(1);
    dfs2(1,0);
    dfs3(1);
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