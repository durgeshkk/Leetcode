#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll int
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
 
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
vector<int> findColumnWidth(vector<vector<int>>& grid) {
    vector<int> ans(grid[0].size(),0);
    for(ll i = 0;i<grid.size();++i){
        for(ll j = 0;j<grid[0].size();++j){
            string s = to_string(grid[i][j]);
            int len = s.size();
            ans[j] = max(ans[j],len);
        }
    }
    return ans;
}

vector<long long> findPrefixScore(vector<int>& v) {
    vector<long long> ans(v.size(),0);
    ll mx = 0,sm = 0;
    for(ll i = 0;i<v.size();++i){
        mx = max(mx,v[i]*1ll);sm += v[i];
        ans[i] = (mx+v[i]);
    }
    for(ll i = 1;i<v.size();++i){
        ans[i] += ans[i-1];
    }
    return ans;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* dk = NULL;
TreeNode* clone(TreeNode* root)
{
    if (!root) {
        return NULL;
    }
    TreeNode* root_naya = new TreeNode(root->val);
    root_naya->left = clone(root->left);
    root_naya->right = clone(root->right);
    return root_naya;
}

map<ll,ll> mp;
map<TreeNode*,ll> ak;

void dfs(TreeNode *root){
    if(root == NULL){return;}
    if(root->left != NULL){dfs(root->left);}
    if(root->right != NULL){dfs(root->right);}

    root->val = ak[root];
}


TreeNode* replaceValueInTree(TreeNode* root) {
    if(root == NULL){return NULL;}

    queue<TreeNode*> q;    
    q.push(root);
    ll lvl =  0;
    while(!q.empty()){
        ll sz = q.size(),sm = 0;
        while(sz--){
            ll smallans = 0;
            auto p = q.front();q.pop();
            sm += p->val;
            if(p->left != NULL){q.push(p->left);smallans += p->left->val;}
            if(p->right != NULL){q.push(p->right);smallans += p->left->val;}
            if(p->left != NULL){ak[p->left] = smallans;}
            if(p->right != NULL){ak[p->right] = smallans;}
        }
        mp[lvl++] = sm;
    }

    TreeNode* dk = clone(root);
    q.push(dk);
    while(!q.empty()){
        ll sz = q.size(),ss = 0;
        while(sz--){
            auto p = q.front();q.pop();
            if(p->left != NULL){q.push(p->left);}
            if(p->right != NULL){q.push(p->right);}
            p->val = ak[p];
        }
    }
    if(dk->left != NULL){dk->left->val = 0;}
    if(dk->right != NULL){dk->right->val = 0;}
    dk->val = 0;
    return dk;
}

void solve()
{
 
    ll n = -15;
    string s = to_string(n);
    cout<<s<<endl;
    return;
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