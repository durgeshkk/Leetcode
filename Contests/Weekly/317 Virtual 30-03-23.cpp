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
int averageValue(vector<int>& v) {
    ll n = v.size();
    ll cnt = 0,sm = 0;
    for(ll i = 0;i<n;++i){
        if(v[i]%6 == 0){
            sm += v[i],cnt++;
        }
    }
    if(sm == 0){return 0;}
    return (sm/cnt);
} 

vector<vector<string>> mostPopularCreatorr(vector<string>& creators, vector<string>& ids, vector<int>& views) {
    map<string,ll> vw,mx;
    map<string,string> ans;       
    
    ll n = mx.size();
    for(ll i = 0;i<n;++i){
        vw[creators[i]] += views[i];
        ll &view = mx[creators[i]];
        if(view < views[i]){
            view = views[i];
            ans[creators[i]] = ids[i];
        }
    }

    ll dk = 0;
    for(auto it:vw){
        cout<<it.first<<" "<<it.second<<endl;
        dk = max(it.second,dk);
    }

    vector<vector<string>> ak;
    for(auto it:vw){
        if(it.second == dk){
            vector<string> sa;
            sa.push_back(it.first);
            sa.push_back(ans[it.first]);
            ak.push_back(sa);
        }
    }
    return ak;
}
/*
["alice","bob","alice","chris"]
["one","two","three","four"]
[5,10,5,4]
["alice","alice","alice"]
["a","b","c"]
[1,2,2]
["a"]
["a"]
[0]
["a","a"]
["aa","a"]
[5,5]
*/
vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
    map<string,ll> create;
    ll n = ids.size();
    for(ll i = 0;i<n;++i){
        create[creators[i]] += views[i];
    }
    ll mx = 0;
    for(auto it:create){mx=max(mx,it.second);}

    set<string> tmp;
    for(auto it:create){
        if(it.second == mx){tmp.insert(it.first);}
        else{create.erase(create.find(it.first));}
    }

    map<string,ll> freq;
    map<string,string> dk;
    for(ll i = 0;i<n;++i){
        if(tmp.find(creators[i]) != tmp.end()){
            ll &fr = freq[creators[i]];
            if(fr == 0 || views[i] > fr){
                fr = views[i];
                dk[creators[i]] = ids[i];
            }
        }
    }

    vector<vector<string>> ak;
    for(ll i = 0;i<n;++i){
        if(create.find(creators[i]) != create.end()){
            vector<string> sa;
            sa.push_back(creators[i]);
            sa.push_back(ids[i]);
            ak.push_back(sa);
            create.erase(create.find(creators[i]));
        }
    }
    return ak;
}

long long makeIntegerBeautiful(long long n, int target) {
    ll ans= 0;
    string s = to_string(n);
    string tmp;tmp += '0';tmp += s;s = tmp;
    
    vector<ll> v(s.size()+1,0);
    ll sod = 0;
    for(ll i = 0;i<s.size();++i){
        v[i+1] = (s[i]-'0');
        sod += (s[i]-'0');
    }

    for(ll i = v.size()-1;i>0;--i){
        if(v[i] == 0){continue;}
        ll diff = 10-v[i];
        if(diff == 0){
            v[i-1] += 1;
            sod += 1;
            sod -= 10;
            v[i] = 0;
        }else{
            v[i-1] += 1;
            sod += 1;
            sod -= v[i];
            v[i] = 0;
        }
        if(sod <= target){break;}
    }
    // Check if any v[i] == 10
    for(ll i = v.size()-1;i>0;--i){
        if(v[i] == 10){
            v[i-1] += 1;
            v[i] = 0;
        }
    }

    s.clear();
    if(!v[0]){s+=(v[0]+'0');}
    for(ll i = 1;i<v.size();++i){
        s+=(v[i]+'0');
    }

    ans = stoll(s);
    ans -= n;
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

map<ll,ll> hght;
ll dfs(TreeNode* root){
    if(!root){return;}

    ll l = dfs(root->left);
    ll r = dfs(root->right);
    hght[root->val] = max(l,r);
    return max(l,r)+1;
}



vector<int> treeQueries(TreeNode* root, vector<int>& que) {
    vector<ll> ans;
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