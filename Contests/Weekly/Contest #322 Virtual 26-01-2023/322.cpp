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
 
bool isPrime(int n){
   if(n<2 || n%2==0 || n%3==0){
       return false;
   }
   
   for(int i=5; i*i <= n; i+=6){
      if(n%i==0 || n%(i+2)==0){
         return false;
      }
   }
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
 
bool isCircularSentence(string s) {
    ll n = s.size();
    bool ans = true;
    char prev = s[0];
    for(ll i = 0;i<n;++i){
        if(i == 0){
            if(s[i] == s[n-1]){
            }else{
                ans = false;
            }
        }
        if(s[i] == ' '){
            prev = s[i-1];
            if(i == 0){
                if(s[i] == s[n-1]){
                }else{
                    ans = false;
                }
            }else if(i == n-1){
                continue;
            }else{
                if(s[i-1] != s[i+1]){ans = false;}
            }
            continue;
        }
    }
    return ans;
}

long long dividePlayers(vector<int>& v) {
    ll sm = accumulate(v.begin(),v.end(),0ll);
    ll n = v.size();

    if(sm%(n/2)){
        return -1;
    }

    sort(v.begin(),v.end());
    ll target = sm*2/n;
    ll ans=  0;
    for(ll i = 0;i<n/2;++i){
        if((v[i]+v[n-i-1]) != target){
            return -1;
        }else{
            ans += (v[i]*v[n-i-1]);
        }
    }
    return ans;
}

vector<ll> vis;
ll ans = LLONG_MAX;
map<pair<ll,ll>,ll> wt;
multiset<ll> have;
multiset<vector<ll>> ms;

void dfs(ll i){
    vis[i] = 1;
    have.insert(i);

    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it);
        }
    }
    return;
}

int minScore(int n, vector<vector<int>>& roads) {
    // If traversing from 1 can visit n then ans is min. traversal of all nodes
    vis.assign(n+1,0);
    
    for(auto x:roads){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
        ms.insert({x[2],x[0],x[1]});
    }

    dfs(1);

    for(auto x:ms){
        ll f = x[1],s = x[2];
        if((have.find(f) != have.end()) and ((have.find(s) != have.end()))){
            ans = x[0];break;
        }
    }

    return ans;
}


int magnificentSets(int n, vector<vector<int>>& edges) {
    multiset<ll> ms;
    for(ll i = 1;i<=n;++i){ms.insert(i);adj[i].clear();}

    for(ll i = 0;i<edges.size();++i){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
        if(ms.find(edges[i][0]) != ms.end()){ms.erase(ms.find(edges[i][0]));}
        if(ms.find(edges[i][1]) != ms.end()){ms.erase(ms.find(edges[i][1]));}
    }


    ll ans = 0;
    for(ll i = 1;i<=n;++i){
        if(ms.find(i) != ms.end()){continue;}

        ll mx = 0;
        ll f = 1;
        vector<ll> vis(n+1,0);
        map<ll,ll> mp;

        // Multisource BFS
        queue<ll> q;
        q.push(i);
        vis[i] = 1;
        ll cnt = 1;
        mp[i] = 1;

        while(!q.empty()){
            ll sz = q.size();

            for(ll j = 0;j<sz;++j){
                ll ele = q.front();
                q.pop();

                for(auto it:adj[ele]){
                    if(!vis[it]){
                        vis[it] = 1;++cnt;
                        mp[it] = (mx+1);
                        q.push(it);
                    }
                }
            }
            ++mx;
        }

        for(ll i = 1;i<=n;++i){
            for(auto x:adj[i]){
                // Calculate the grp diff between x & i
                if(abs(mp[x]-mp[i]) != 1){
                    f = 0;break;
                }
            }
        }

        if(f == 0){
        }else{
            ans = max(ans,mx+(n-cnt));
        }
    } 
    if(ans == 0){ans = -1;}
    return (ans+ms.size());
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