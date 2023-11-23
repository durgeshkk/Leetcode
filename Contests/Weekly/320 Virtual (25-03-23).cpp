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
/*
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
int unequalTriplets(vector<int>& v) {
    ll n =v.size();
    ll ans =0;
    for(ll i = 0;i<n;++i){
        for(ll j = i+1;j<n;++j){
            for(ll k = j+1;k<n;++k){
                if(v[i] != v[j] and v[j] != v[k] and v[i] != v[k]){++ans;}
            }
        }
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

vector<ll> tmp;
void inorder(TreeNode* root){
    if(!root){return;}
    inorder(root->left);
    tmp.push_back(root->val);
    inorder(root->right);
}

vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
    vector<vector<int>> ans;
    for(auto it:q){
        int a = -1,b = -1;
        ll ele = it;
        ll ub = upper_bound(all(tmp),ele)-tmp.begin();
        if(ub == tmp.size()){}
        else{b = tmp[ub];}
        --ub;
        if(ub == -1){
        }else{a = tmp[ub];}
        ans.push_back({a,b});
    }
    return ans;
}

// Upsolve : {Q3}
vector<ll> adj[100004];
vector<ll> vis;
ll s,ans;
ll dfs(ll i){
    vis[i] = 1;
    ll ppl = 1;
    for(auto it:adj[i]){
        if(!vis[it]){
            ppl += dfs(it);
        }
    }

    ll cars = ppl/s;
    if(ppl%s){++cars;}//in need of 1 more car since it can accomodate passengers

    if(i != 0){ans += cars;}
    return ppl;
}

long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    s = seats,ans=0;   
    if(roads.size() == 0){return 0;}    
    for(auto it:roads){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vis.assign(roads.size()+1,0);
    dfs(0);
    return ans;
}


set<char> v = {'2','3','5','7'};
vector<vector<ll>> dp;
string str;
ll n,k,len;
ll recur(ll idx,ll cntr){
    if(cntr == k){return 1;}
    if(idx == n){return 0;}

    if(dp[idx][cntr] != -1){return dp[idx][cntr];}

    ll ans = 0,sa = 0;
    if(idx+len <= n){
        // Start of new partition && 
        // Check if the idx-1 is not prime
        if(idx == 0){
            for(auto it:v){
                if(str[idx] == it){
                    // tmp.push_back(str[idx]);
                    sa = recur(idx+len,cntr+1);
                    // tmp.pop_back();
                    ans = mod_add(ans,sa,mod);
                }
            }
        }else{
            // Can only start a partition of idx-1 is not prime
            char ch = str[idx-1];
            if(v.find(ch) == v.end()){
                for(auto it:v){
                    if(str[idx] == it){
                        // tmp.push_back(str[idx]);
                        sa = recur(idx+len,cntr+1);
                        // tmp.pop_back();
                        ans = mod_add(ans,sa,mod);
                    }
                }
            }
        }
    }
    if(idx != 0){
        sa = recur(idx+1,cntr);
        ans = mod_add(ans,sa,mod);
    }
    return dp[idx][cntr] = ans;
}

int beautifulPartitions(string st, int kotta, int minLength) {
    str = st;n = str.size(),k = kotta,len = minLength;
    ll f = 0,fl = 0;
    for(auto it:v){
        if(str[0] == it){f = 1;}
        if(str[n-1] == it){fl = 1;}
    }
    if(!f || fl){return 0;}
    dp.assign(n+1,vector<ll>(n+1,-1));
    return recur(0,0);
}

void solve()
{
    string s;cin>>s;
    ll k;cin>>k;
    ll n;cin>>n;
    ll ans = beautifulPartitions(s,k,n);
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