#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
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
ll expo(ll a, ll b, ll mod) {ll ans = 1; while (b > 0) {if (b & 1)ans = (ans * a) % mod; a = (a * a) % mod; b = b >> 1;} return ans;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvrime(ll a, ll b) {return expo(a, b - 2, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvrime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll it1 = fact[n]; ll it2 = ifact[n - r]; ll it3 = ifact[r]; return (((it1 * it2) % m) * it3) % m;}
void google(ll t) {cout << "Case #" << t << ": ";}
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
 
ll expo(ll a, ll b, ll mod) {ll ans = 1; while (b > 0) {if (b & 1)ans = (ans * a) % mod; a = (a * a) % mod; b = b >> 1;} return ans;}
 
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
 
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        
        //create adjacency list
        vector<vector<int>> bAdj(n);
        vector<vector<int>> rAdj(n);
        
        
        //red edges adjacency list
        for(int i=0;i<r.size();i++)
        {
            rAdj[r[i][0]].push_back(r[i][1]);
        }
        
        //blue edges adjacency list
        for(int i=0;i<b.size();i++)
        {
            bAdj[b[i][0]].push_back(b[i][1]);
        }
        
        //use bfs 
        queue<pair<int,int>> q;
        
        vector<pair<int,int>> res(n,{INT_MAX,INT_MAX});
        //pair.first stores the min distance to reach node through blue color
        //pair.second stores the min dist to reach node through red color
        
        res[0]={0,0};
        
        //1 represents the  blue color
        //-1 represents the red color
        q.push({0,-1});
        q.push({0,1});
        
        //currDist is the distance from node 0  to the nodes in the queue
        //in Alternative edges
        int currDist=0;
        while(!q.empty())
        {
            int l=q.size();
            //for every node in q check if a shorter dist exists with alternative manner
            
            for(int m=0;m<l;m++)
            {
                //edge is the color of incoming edge to the node
                auto [node,edge]=q.front();
                q.pop();
                
                //if incoming is red  add the nodes of blue edges and viceversa
                if(edge==1)
                {
                    //blue 
                    //check for red adjacency list
                    for(auto x:rAdj[node])
                    {
                        if(res[x].second > currDist+1)
                        {
                            q.push({x,-1});
                            res[x].second=currDist+1;
                        }
                    }
                }
                else{
                    //red
                    //check for blue adj list
                    for(auto x:bAdj[node])
                    {
                        if(res[x].first > currDist+1)
                        {
                            q.push({x,1});
                            res[x].first=currDist+1;
                        }
                    }
                }
            }
            currDist++;
        }
        
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            int mini=min(res[i].first,res[i].second);
            ans[i]=(mini==INT_MAX) ? -1 : mini;
        }
        return ans;
        
    }
};

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
 
signed main()
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