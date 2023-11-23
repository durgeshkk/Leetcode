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
int mostFrequentEven(vector<int>& v) {
    map<ll,ll> mp;
    ll mx = 0;
    for(auto it:v){
        if(it%2 == 0){
            mp[it]++;
            mx = max(mp[it],mx);
        }
    }

    if(mp.size() == 0){return -1;}
    else{
        for(auto it:mp){
            if(it.second == mx){
                return it.first;
            }
        }
    }
}

int partitionString(string s) {
    multiset<char> ms;
    ll ans = 0;
    for(ll i = 0;i<s.size();++i)        {
        if(ms.find(s[i]) != ms.end()){
            ms.clear();
            ++ans;
        }else{
        }
        ms.insert(s[i]);
    }
    return (ans+1);
}

int minGroups(vector<vector<int>>& v) {
    int mx = 0;
    for(auto it:v){
        mx = max(mx,it[1]);
    }

    vector<ll> pref(mx+5,0);
    for(auto it:v){
        pref[it[0]]++;
        pref[it[1]+1]--;
    }

    for(ll i = 1;i<=(mx+1);++i){
        pref[i] += pref[i-1];
    }

    ll ans = *max_element(pref.begin(),pref.end());
    return ans;
}

// Upsolve : 
void buildTree(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode) {
    // Base Case when start == end since we know the ans of that idx
    if(start == end){
        tree[treeNode] = 0;
        return;
    }

    ll mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = max(tree[2*treeNode] , tree[2*treeNode+1]);
}

// Update O(log n)
void update(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode, ll idx, ll val) {
    if(start == end){
        // arr[idx] = val;
        tree[treeNode] = val;
        return;
    }

    ll mid = (start+end)/2;
    if(idx > mid){// move to right
        update(arr,tree,mid+1,end,2*treeNode+1,idx,val);
    }else{
        update(arr,tree,start,mid,2*treeNode,idx,val);
    }

    tree[treeNode] = max(tree[2*treeNode] , tree[2*treeNode+1]);
}

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

    return max(ans1,ans2);
}

ll lengthOfLIS(vector<ll>& v, ll k) {
    ll n = v.size(),mx = *max_element(v.begin(),v.end());

    vector<ll> pref(mx+5,0);
    vector<ll> tree(4*(mx+5)+5,0);
    buildTree(pref,tree,0,pref.size()-1,1);

    ll ans = 0;
    for(ll i = n-1;i>=0;--i){
        ll ele = v[i];
        // Get me ans of [v[i]+1,v[i]+k]
        ll s = (v[i]+1),e = (v[i]+k);
        e = min(e,mx+4);
        ll sm = query(tree,0,pref.size()-1,1,s,e);
        // cout<<s<<" "<<e<<" ";
        // cout<<sm<<endl;
        // show(tree);
        // if(sm > ans){
        //     cout<<i<<endl;
        // }
        ans = max(ans,sm+1);
        // show(tree);
        update(pref,tree,0,pref.size()-1,1,ele,sm+1);
    }
    return (ans);
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