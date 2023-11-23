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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
/*
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
string largestGoodInteger(string s) {
    ll n = s.size();        
    int ans = -1;
    for(ll i = 0;i<n;++i){
        char ch = s[i];
        ll cntr = 0;
        while(i < n and s[i] == ch){
            ++i,++cntr;
        }
        --i;
        if(cntr >=3){
            ans = max(ans,ch-'0');
        }
    }

    if(ans == -1){return "";}
    string tmp;
    tmp += (ans+'0');
    tmp += (ans+'0');
    tmp += (ans+'0');
    return tmp;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ll ans = 0;
pair<ll,ll> dfs(TreeNode* root){
    if(!root){return {0,0};}
    ll sm = root->val,cntr = 1;
    if(root->left){
        auto p = dfs(root->left);
        sm += p.first,cntr += p.second;
    }

    if(root->right){
        auto p = dfs(root->right);
        sm += p.first,cntr += p.second;
    }

    ll ele = sm/cntr;
    if(ele == root->val){++ans;}
    return {sm,cntr};
}

int averageOfSubtree(TreeNode* root) {
    ans = 0;
    auto p = dfs(root);
    return ans;
}

string s;
ll n;
vector<ll> dp;
ll recur(ll idx){
    if(idx == n){return 1;}

    ll b = 3;
    if(s[idx] == '7' || s[idx] == '9'){++b;}

    ll &ans = dp[idx];
    if(ans != -1){return ans;}
    ans = 0;
    for(ll j = idx;j<n;++j){
        if((s[j] == s[idx]) and ((j-idx+1) <=b)){
            ll sa = recur(j+1);
            ans = mod_add(ans,sa,mod);
        }else{break;}
    }
    return ans;
}

int countTexts(string pressedKeys) {
    s = pressedKeys;n = s.size();   
    dp.assign(n+1,-1);
    return recur(0);
}


ll n,m;
vector<vector<ll>> v,vis;
ll memo[101][101][205];
bool issafe(ll i,ll j){
    if(i < n && j<m && i>=0 && j>=0){return 1;}return 0;
}

ll dfs(ll i,ll j,ll cntr){
    cntr += v[i][j];
    if(cntr < 0){return 0;}
    
    if(i == n-1 and j == m-1){
        if(cntr == 0){return 1;}
        return 0;
    }

    ll &a = memo[i][j][cntr];
    if(a != -1){return a;}
    a = 0;
    
    if(issafe(i+1,j)){
        a |= dfs(i+1,j,cntr);
    }

    if(issafe(i,j+1)){
        a |= dfs(i,j+1,cntr);
    }

    return a;
}


bool hasValidPath(vector<vector<char>>& grid) {
    n = grid.size(),m = grid[0].size();
    v.assign(n,vector<ll> (m,0));
    vis.assign(n+1,vector<ll> (m+1,0));
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            if(grid[i][j] == '('){
                v[i][j] = 1;
            }else{
                v[i][j] = -1;
            }
        }
    }

    for(ll i = 0;i<=n;++i){
        for(ll j = 0;j<=m;++j){
            for(ll k = 0;k<=(n+m);++k){
                memo[i][j][k] = -1;
            }
        }
    }
    // cout<<n<<" "<<m<<" "<<endl;
    if(v[0][0] == -1){return 0;}
    return dfs(0,0,0);
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