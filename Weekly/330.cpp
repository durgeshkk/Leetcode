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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

int distinctIntegers(int n) {
    if(n == 1){return 1;}
    return (n-1);
}

// ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
// ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll power(ll base,ll n,ll mod){
   ll ans = 1;
   while( n!= 0){
      if(n%2){
          n-=1;
          ans = mod_mul(ans,base,mod);
        //   ans = (ans*base)%mod;
      }
      else{
          n /= 2;
          base = mod_mul(base,base,mod);
        //   base = (base*base)%mod;
      }
   }
   return ans;
}


ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

int monkeyMove(int n) {
    ll ans = expo(2,n,mod);
    ans = mod_sub(ans,2,mod);
    return (ans);
}

long long putMarbles(vector<int>& wt, int k) {

}

/*
At idx j, find ele smaller than v[k] ==> v[i]
At idx k, find ele greater than v[j] ==> v[l]
This can be find in log(n) time using segmented trees but for it we need to fix the
ele for which we need to find greater or smaller
Next option is ordered_set but it gives TLE as it takes O(n)
The easiest & last option is to precompute/dp everytime!! ==> O(1)
*/

int combine(int a, int b)
{
    if (a != 0 && b != 0) {
        return a;
    }
    if (a >= b) {
        return a;
    }
    return b;
}

vector<ll> arr,tree;
// building the tree
void buildTree(int ind, int low, int high, int x)
{
    // leaf node
    if (low == high) {
        if (arr[low] > x) {
            tree[ind] = arr[low];
        }
        else {
            tree[ind] = 0;
        }
        return;
    }
    int mid = (low + high) / 2;
    buildTree(2 * ind + 1, low, mid, x);
    buildTree(2 * ind + 2, mid + 1, high, x);
 
    // merging the nodes while backtracking.
    tree[ind]
        = combine(tree[2 * ind + 1], tree[2 * ind + 2]);
}
// performing query
int query(int ind, int low, int high, int l, int r)
{
    int mid = (low + high) / 2;
    // Out of Bounds
    if (low > r || high < l) {
        return 0;
    }
    // completely overlaps
    if (l <= low && r >= high) {
        return tree[ind];
    }
    // partially overlaps
    return combine(query(2 * ind + 1, low, mid, l, r),
                   query(2 * ind + 2, mid + 1, high, l, r));
}


long long countQuadruplets(vector<int>& v) {

    ll n = v.size();
    arr.assign(n,0);
    tree.assign(4*n,0);
    for(ll j = 0;j<n;++j){arr[j] = v[j];}
    buildTree(0, 0, n - 1, k);

    ll ans = 0;
    ordered_set aj;//after

    for(ll j = 0;j<n;++j){
        aj.insert(v[j]);

        ordered_set o_af;
        for(ll k = j+1;k<n;++k){
            // O(log(n))
            o_af.insert(v[k]);
        }

        // Maintain ordered_set from here
        for(ll k = j+1;k<n;++k){
            if(v[k] < v[j]){ // b > a
                // O(n)

                ll sm = aj.order_of_key(v[k]);//this will give me v[i]
                ll lrge = o_af.size() - o_af.order_of_key(v[j]);//will give v[l]
                ans += (sm*lrge);
            }

            // O(log(n))
            o_af.erase(o_af.find(v[k]));
        }
    }
    return ans;
}

void solve()
{
 
    int n;
    cin>>n;
    ll ans=  monkeyMove(n);
    cout<<ans<<endl;
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