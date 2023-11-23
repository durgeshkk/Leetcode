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
 
 
 

//  "A" : 65, "a" : 97  (-> |) (<- &(~))
int minimumOperations(vector<int>& nums) {
    set<ll> s(nums.begin(),nums.end());
    if(s.find(0) != s.end()){
        s.erase(s.find(0));
    }
    ll ans = s.size();
    return ans;
}
    
int maximumGroups(vector<int>& v) {
    sort(v.begin(),v.end());
    ll ans = 0;
    for(ll i = 0;i<=1e5;++i){
        ll ok = i*(i+1)/2;
        if(ok > v.size()){
            return ans;
        }
        ++ans;
    }
    return ans;
}


vector<ll> adj[100004];
vector<ll> dist1,dist2,vis;
void bfs(ll i,ll f){
    queue<ll> q;q.push(i);
    if(f & 1){
        dist2[i] = 0;
    }else{
        dist1[i] = 0;
    }

    ll lvl = 0;
    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            auto p = q.front();q.pop();vis[p]=1;
            if(f & 1){
                dist2[p] = lvl;
            }else{
                dist1[p] = lvl;
            }

            for(auto it:adj[p]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        ++lvl;
    }
    return;
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    for(ll i=0;i<edges.size();++i){
        if(edges[i] == -1){continue;}
        adj[i].push_back(edges[i]);
    }
    ll n = edges.size();
    dist1.assign(n+1,LLONG_MAX);dist2.assign(n+1,LLONG_MAX);vis.assign(n+1,0);
    bfs(node1,0);
    vis.clear();vis.assign(n+1,0);
    bfs(node2,1);

    ll mn = LLONG_MAX;
    for(ll i = 0;i<n;++i){
        ll a = max(dist1[i],dist2[i]);
        mn = min(mn,a);
    }
    if(mn == LLONG_MAX){
        return -1;
    }
    for(ll i = 0;i<n;++i){
        ll a = max(dist1[i],dist2[i]);
        if(a == mn){
            return i;
        }
    }
    return -1;
}

vector<ll> adj[100004];vector<ll> rev_adj[100004];
vector<ll> vis,rev_vis;
stack<ll> rec_stack;

void dfs(ll i){
    vis[i] = 1;
    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it);
        }
    }
    rec_stack.push(i);
}

void raju(ll i,vector<ll> &comp){
    rev_vis[i] = 1;
    comp.push_back(i);
    for(auto it:rev_adj[i]){
        if(!rev_vis[it]){
            raju(it,comp);
        }
    }
}

bool recur(ll i,ll start,vector<ll> &cycle){
    vis[i] = 1;
    cycle.push_back(i);
    ll sa = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            sa = recur(it,start,cycle);
        }
        if(sa){return 1;}
    }

    cycle.pop_back();
    vis[i] = 0;
    return sa;
}

int longestCycle(vector<int>& edges) {
    for(ll i=0;i<edges.size();++i){
        if(edges[i] == -1){continue;}
        adj[i].push_back(edges[i]);
        rev_adj[edges[i]].push_back(i);
    }

    ll n = edges.size();
    vis.assign(n+1,0);rev_vis.assign(n+1,0);
    for(ll i = 0;i<n;++i){
        if(!vis[i]){
            dfs(i);
        }
    }

    vector<vector<ll>> components;
    while(!rec_stack.empty()){
        ll ele = rec_stack.top();rec_stack.pop();
        if(!rev_vis[ele]){
            vector<ll> comp;// Components
            raju(ele,comp);
            components.push_back(comp);
        }
    }

    ll ans = -1;
    for(auto it:components){
        ll sz = it.size();
        ans = max(ans,sz);
    }
    
    if(ans <= 1){ans = -1;}
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