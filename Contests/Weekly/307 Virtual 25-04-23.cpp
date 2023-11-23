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
/*
5
3
[1,4,3,2]
[2,6,3,1]
2
4
[1]
[3]
*/
int minNumberOfHours(int x, int exp, vector<int>& v, vector<int>& t) {
    ll ans= 0;
    for(ll i = 0;i<v.size();++i){
        if(v[i] >= x){
            ans += (v[i]-x+1);
            x = v[i]+1;
        }
        x -= v[i];
    }

    for(ll j = 0;j<t.size();++j){
        if(t[j] >= exp){
            ans += (t[j]-exp+1);
            exp = (t[j]+1);
        }
        exp += t[j];
    }
    return ans;
} 

string largestPalindromic(string num) {
    map<char,ll> mp;
    for(auto it:num){
        mp[it]++;
    }

    string ak,dk;
    char ch = 'a';
    for(auto &it:mp){
        if(it.second >= 2){
            while(it.second >= 2){
                ak += it.first;
                dk += it.first;
                it.second -= 2;
            }
        }

        if(it.second == 1){ch = it.first;}
    }

    ll idx = -1;
    for(ll i = dk.size()-1;i>=0;--i){
        if(dk[i] != '0'){idx = i;break;}
    }

    string tmp;
    for(ll i = 0;i<=idx;++i){
        tmp += dk[i];
    }
    dk = tmp;
    reverse(dk.begin(),dk.end());
    ak = tmp;
    if(ch != 'a'){
        dk += ch;
    }
    dk += ak;
    return dk;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ll dfs(TreeNode* root){
    if(!root){return 0;}
    ll x = 1;
    if(root->left != NULL){
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val);
        x += dfs(root->left);
    }
    if(root->right != NULL){
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
        x += dfs(root->right);
    }
    return x;
}

vector<ll> vis;
ll tot = 0;
ll bfs(ll x){
    queue<ll> q;
    q.push(x);
    ll lvl = 0;
    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            ll dk = q.front();q.pop();vis[dk] = 1;
            for(auto it:adj[dk]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        ++lvl;
    }
    return lvl;
}
int amountOfTime(TreeNode* root, int start) {
    tot = dfs(root);
    vis.assign(tot+1,0);
    ll ans = bfs(start);
    return ans+1;
}

long long kSum(vector<int>& v, int k) {
    sort(all(v));
    reverse(all(v));
    bitset<32> b(k);
    ll ans=  0;
    for(ll i = 0;i<32;++i){
        if(b[i]){
            ans += v[i];
        }
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