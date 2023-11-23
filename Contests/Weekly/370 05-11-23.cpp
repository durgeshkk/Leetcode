/*
Once in a LifeTime,
Will never let you Down!!
*/
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
// YE DIL MAANGE MORE!!
vector<ll> vis,subtree,v;
ll dfs(ll i){
    vis[i] = 1;
    ll sm = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            sm += dfs(it);
        }
    }
    subtree[i] = sm;
    return (sm+v[i]);
}

ll recur(ll i){
    vis[i] = 1;
    ll sa = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            vis[it]=1;
            sa += recur(it);
        }
    }
    return min(v[i],sa);
}

long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
    ll ans=  0,n = values.size();
    forj(n+1){adj[j].clear();}vis.assign(n+2,0);subtree.assign(n+2,0);
    for(auto it:edges){
        ll u=it[0],v=it[1];adj[u].push_back(v);
        adj[v].push_back(u);
    }

    forj(n){
        v.push_back(values[j]);
    }

    vis.clear();
    ll sa = recur(0);
    ll tot = accumulate(all(v),0ll);
    tot-=sa;
    return tot;
}
/*
[3,3,5,6]
[5,-1,-3,8]
[-2,-1]
[-1,0]
[-1,-2]
[-43,23,-49]
*/
// My Approach :
/*
vector<ll> dp;
vector<ll> subsm;
ll durg(ll i,ll n,vector<ll> &v){
    if(dp[i] != -1){return dp[i];}

    ll sa = 0;
    for(ll j = i-1;j>=0;--j){
        if(v[j] <= v[i]){
            sa = max(sa,durg(j,n,v));
        }
    }
    return dp[i]=(sa+v[i]+i);
}

ll n;
vector<ll> v;
ll mv(ll i){
    if(i == n){return 0;}

    ll mx = v[i];
    for(ll j = i+1;j<n;++j){
        if(v[j] >= v[i]){
            
        }
    }
}

long long maxBalancedSubsequenceSum(vector<int>& tmp) {
    n = v.size();
    forj(n){tmp[j] -= j;}
    vector<ll> v;for(auto it:tmp){v.push_back(1ll*it);}

    dp.assign(n+5,-1);

    ll ans = durg(n-1,n,v);
    return ans;
}*/

void buildTree(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode) {
    // Base Case when start == end since we know the ans of that idx
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }

    ll mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

// Update O(log n)
void update(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode, ll idx, ll val) {
    if(idx<start || idx>end){return;}
    if(start == end){
        tree[treeNode] = max(val,tree[treeNode]);
        return;
    }

    ll mid = (start+end)/2;
    if(idx > mid){// move to right
        update(arr,tree,mid+1,end,2*treeNode+1,idx,val);
    }else{
        update(arr,tree,start,mid,2*treeNode,idx,val);
    }

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

/*
Query : log(n)
*/
ll query(vector<ll> &tree, ll start,ll end, ll treeNode, ll left, ll right){

    // 1.completely outside : return 0
    if(start > right || end < left){
        return 0;
    }

    // 2.completely inside : return val
    if(start >= left and end <= right){
        return tree[treeNode];
    }

    // 3.partially inside : call recursion on left & right
    ll mid = (start+end)/2;
    ll ans1 = query(tree,start,mid,2*treeNode,left,right);
    ll ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);

    return ans1+ans2;
}

// query(treeN=1,start=0,end=m-1,left=0,right=arr[i],tree);
// update(1,0,m-1,idx=arr[i],val=nums[i]+val,tree);
long long maxBalancedSubsequenceSum(vector<int>& nums) {
    ll n = nums.size();vector<ll> v(n,0);set<ll> s;
    forj(n){
        v[j] = 1ll*nums[j]-j;
        s.insert(1ll*nums[j]-j);
    }

    map<ll,ll> mp;
    ll cnt = 0;
    while(!s.empty()){
        mp[*s.begin()]=cnt;++cnt;
        s.erase(s.begin());
    }

    forj(n){
        v[j] = mp[v[j]];
    }
    vector<ll> tree(4*cnt+5,0);
    ll ans = (1ll)*(*max(all(nums)));
    forj(n){
        if(nums[j]<0){continue;}
        // query(treeN=1,start=0,end=m-1,left=0,right=arr[i],tree);
        // update(1,0,m-1,idx=arr[i],val=nums[i]+val,tree);
        ll sa = query(tree,0,cnt-1,1,0,v[j]);
        ans=max(ans,sa);
        update(v,tree,0,cnt-1,1,v[j],v[j]+sa);
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