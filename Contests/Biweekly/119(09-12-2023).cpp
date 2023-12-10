/*
Once in a LifeTime,
Will never let you Down!!
*/
#include <bits/stdc++.h>
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
// YE DIL MAANGE MORE!!
vector<int> findIntersectionValues(vector<int>& v, vector<int>& t) {
    ll c1 = 0,c2 = 0,n = v.size(),m = t.size();
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            if(v[i] == t[j]){++c1;break;}
        }
    }
    
    for(ll i = 0;i<m;++i){
        for(ll j = 0;j<n;++j){
            if(v[j] == t[i]){++c2;break;}
        }
    }
    return {c1,c2};
}

int removeAlmostEqualCharacters(string s) {
    ll n = s.size(),ans = 0;
    for(ll i = 1;i<n;++i){
        if(abs(s[i]-s[i-1]) <= 1){
            ++ans;++i;
        }
    }
    return ans;
}

int maxSubarrayLength(vector<int>& v, int k) {
    ll l = 0,r = 0,ans = 0,n = v.size();
    
    map<ll,ll> mp;
    while(r<n){
        if(mp[v[r]]+1 > k){
            break;
        }else{
            mp[v[r]]++;
            ++r,++ans;
        }
    }
    
    while(r < n){
        if(mp[v[r]]+1 > k){
            mp[v[l]]--;++l;
        }else{
            mp[v[r]]++;++r;
        }
        ans = max(ans,r-l);
    }
    return ans;
}

ll n;
vector<set<ll>> combos; 
    vector<vector<ll>> graph;
    
void recur(ll i,set<ll> tmp){
    if(i == n){combos.push_back(tmp);return;}

    tmp.insert(i);
    recur(i+1,tmp);
    tmp.erase(tmp.find(i));
    
    recur(i+1,tmp);
}

ll minDistance(vector<ll> dist, bool sptSet[]){
    ll V = 11;
    ll min = INT_MAX, min_index;
    for (ll v = 0; v < V; v++){
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v], min_index = v;
        }
    }
 
    return min_index;
}

vector<ll> dijk(ll src,set<ll> &have_nodes){
    ll V = 11;
    vector<ll> dist(11,0);
    bool sptSet[V];

    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        if(have_nodes.find(count) == have_nodes.end()){continue;}
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
 
        for (int v = 0; v < V; v++){
            if(have_nodes.find(v) == have_nodes.end()){continue;}
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist;
}

int numberOfSets(int nodes, int mD, vector<vector<int>>& v) {
    n = 1ll*nodes;  
    
    graph.assign(11,vector<ll> (11,INT_MAX));
    for(ll i = 0;i<=10;++i){
        forj(11){
            graph[i][j] = INT_MAX;
        }
    }

    for(auto it:v){
        ll i = it[0],j = it[1],k = it[2];
        graph[i][j] = graph[j][i] = min(graph[i][j],k);
    }

    set<ll> tmp;recur(0,tmp);
    
    ll ans=  0;
    for(auto it:combos){
        set<ll> have_nodes = it;
        ll f = 1,cntr = 0,dist = 0;
        for(auto it:have_nodes){
            vector<ll> ok = dijk(it,have_nodes);
            forj(ok.size()){
                if(have_nodes.find(j) != have_nodes.end()){
                    dist = max(dist,ok[j]);
                    if(dist > 1ll*mD){
                        f = 0;break;
                    }
                }
            }
            if(!f){break;}
        }
        
        if(f){++ans;}
    }
    return ans;
}

void solve(){
    ll n;cin>>>n;
    vector<ll> v(n);enter(v);

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