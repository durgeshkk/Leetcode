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
/*
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
 
int passThePillow(int n, int time) {
    // ll round = (time)/(n-1);
    // if(round &  1){
    //     return (n-(time%(n-1)));
    // }else{
    //     return (1+(time%(n-1)));
    // }

    ll j = 1,f = 0;
    for(ll i = 0;i<time;++i){
        if(f == 0){
            ++j;
            if(j == n){
                f = 1;
            }
        }else{
            --j;
            if(j == 1){
                f = 0;
            }
        }
    }
    return j;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

long long kthLargestLevelSum(TreeNode* root, int k) {
    queue<TreeNode*> q;
    q.push(root);
    ll maxi = 0;
    vector<ll> v;
    while(!q.empty()){
        ll sz = q.size();
        ll sm = 0;
        while(sz--){
            auto ele = q.front();q.pop();
            sm += (ele->val);
            if(!ele->left){
                q.push(ele->left);
            }
            if(!ele->right){
                q.push(ele->right);
            }
        }
        v.push_back(sm);
        maxi = max(maxi,sm);
    }
    sort(all(v));
    reverse(all(v));
    return v[k-1];
}

void primeFactors(ll a,unordered_map<ll,ll> &mp){
    for(ll i = 2;i*i<=a;++i){
        while (a % i == 0) {
            mp[i]++;
            a /= i;
        }
    }
    if (a > 1)
        mp[a]++;
}

int findValidSplit(vector<int>& v) {
    unordered_map<ll,ll> mp,curr;
    ll n = v.size();
    for(ll i = 0;i<n;++i){
        primeFactors(v[i],mp);
    }

    for(ll i = 0;i<n-1;++i){
        primeFactors(v[i],curr);
        bool f = 1;
        for(auto &x:curr){
            if(mp[x.first]-x.second>0){
                f = 0;break;
            }
        }
        if(f & 1){
            return i;
        }
    }
    return -1;
}

vector<vector<ll>> dp;
ll recur(ll idx,int target, vector<vector<int>>& types,ll sm){
    if(sm == target){return 1;}
    if((idx == types.size()) || (sm > target)){
        return 0;
    }


    ll &a = dp[idx][sm];
    if(a != -1){return a;}
    a = 0;
    for(ll j = 0;j<=types[idx][0];++j){
        if((sm+j*types[idx][1]) <= target){
            ll sa = recur(idx+1,target,types,sm+(j*types[idx][1]));
            a = mod_add(a,sa,mod);
        }
    }
    return a;
}

int waysToReachTarget(int target, vector<vector<int>>& types) {
    dp.assign(types.size()+1,vector<ll>(1005,-1));
    ll ans = recur(0,target,types,0);
    return ans;
}

void solve()
{
 
    // ll n;
    // cin>>n;
    // vector<ll> v(n);
    // enter(v);
    // int ans = findValidSplit(v);
    // cout<<ans<<endl;
    /*
    ll n;cin>>n;ll sm;cin>>sm;
    vector<vector<ll>> v;
    for(ll i=0;i<n;i++){
        vector<ll> z(2,0);enter(z);
        v.push_back(z);
    }
    ll ans = waysToReachTarget(sm,v);
    cout<<ans<<endl;
    */
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