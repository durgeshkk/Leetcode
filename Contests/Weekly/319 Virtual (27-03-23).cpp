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
vector<double> convertTemperature(double c) {
    double k = 273.15+c;   
    double f = (c*1.80 + 32.00);
    return {k,f};
} 

ll gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int subarrayLCM(vector<int>& v, int k) {
    ll ans = 0;
    for(ll i = 0;i<v.size();++i){
        ll lc = v[i];
        if(lc == k){++ans;}
        for(ll j = i+1;j<v.size();++j){
            lc = lcm(lc,v[j]*1ll);
            if(lc == k){++ans;}
            if(lc > k){break;}
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

ll bfs(TreeNode* root){
    ll ans= 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        ll sz = q.size();
        vector<ll> tmp;
        while(sz--){
            auto p = q.front();q.pop();
            tmp.push_back(p->val);
            if(p->left){
                q.push(p->left);
            }
            if(p->right){
                q.push(p->right);
            }
        }
        vector<ll> dk = tmp;
        sort(all(dk));
        map<ll,ll> mp;
        for(ll j = 0;j<tmp.size();++j){
            mp[tmp[j]] = j;
        }
        
        ll sa = 0;
        for(ll j = 0;j<tmp.size();++j){
            if(dk[j] != tmp[j]){
                ll pos = mp[dk[j]];
                mp[tmp[j]] = pos;
                swap(tmp[pos],tmp[j]);
                ++sa;
            }
        }
        ans += sa;
    }
    return ans;
}

int minimumOperations(TreeNode* root) {
    ll ans = 0;
    if(!root){return 0;}
    return bfs(root);
}


bool isPalindrome(string s){
    ll i = 0,j = s.size()-1;
    while(i <= j){
        if(s[i++] == s[j--]){
        }else{return false;}
    }
    return true;
}
ll k;vector<ll> dp,v;
ll recur(ll idx,vector<ll> &v){
    if(idx == v.size()){return 0;}

    ll &ans = dp[idx];
    if(ans != -1){return ans;}
    ans = 0;
    ll a = 0,b = 0;
    // Np
    a += recur(idx+1,v);
    // Pick
    if(v[idx] != 0){
        b = (1+recur(idx+v[idx],v));
    }
    ans = max(a,b);
    return ans;
}

void countSubstrings(string s) {
    vector<vector<ll>> dp(s.length(),vector<ll>(s.length(),0));
    for(ll i=0;i<dp.size();i++){
        dp[i][i]=1;
        if(i+1<s.size() and s[i]==s[i+1])
            dp[i][i+1]=1;
    }

    for(ll j=2;j<dp.size();j++){
        for(ll i=0;i<=j-2;i++){
            if(s[i]==s[j] && dp[i+1][j-1]==1)
                dp[i][j]=1;
        }
    }

    for(ll i=0;i<dp.size();i++){
        for(ll j=0;j<dp.size();j++){
            if(i>j){
                continue;
            }else{
                if(dp[i][j]==1){
                    ll len = abs(j-i+1);
                    if(len >= k){
                        if(v[i] == 0){
                            v[i] = k;
                        }
                    }
                }
            }
        }
    }
}

int maxPalindromes(string s, int K) {
    // 1st check if can we start the palindrome from here
    // Then call recur to get max ans
    v.assign(s.size()+1,0);
    ll n = s.size();k = K;
    dp.assign(n+1,-1);
    countSubstrings(s);
    ll ans = recur(0,v);
    return ans;
}

/*
// for(ll i = 0;i<n;++i){
    //     string tmp;
    //     for(ll j = i;j<n;++j){
    //         tmp += s[j];
    //         if(isPalindrome(tmp)){
    //             if(tmp.size() >= k and v[i] == 0){
    //                 v[i] = tmp.size();
    //             }
    //         }
    //     }
    // }

    
*/
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