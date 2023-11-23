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
string decodeMessage(string key, string message) {
    map<char,char> mp;
    char ch = 'a';
    for(auto it:key){
        if(mp.find(it) == mp.end()){
            mp[it] = ch;++ch;
        }
    }

    string ans;
    for(auto it:message){
        ans += mp[it];
    }
    return ans;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void formSpiralMatrix(vector<ll> arr, vector<vector<ll>> &mat){   
    ll R = mat.size(),C = mat[0].size();
    int top = 0,bottom = R - 1,left = 0,right = C - 1,n = arr.size();
    int index = 0;
 
    while (1) {
        if (left > right || index == n)
            break;
 
        // print top row
        for (int i = left; i <= right; i++){
            if(index == n){break;}
            mat[top][i] = arr[index++];
        }
        top++;
 
        if (top > bottom || index == n)
            break;
 
        // print right column
        for (int i = top; i <= bottom; i++){
            if(index == n){break;}
            mat[i][right] = arr[index++];
        }
        right--;
 
        if (left > right || index == n)
            break;
 
        // print bottom row
        for (int i = right; i >= left; i--){
            if(index == n){break;}
            mat[bottom][i] = arr[index++];
        }
        bottom--;
 
        if (top > bottom || index == n)
            break;
 
        // print left column
        for (int i = bottom; i >= top; i--){
            if(index == n){break;}
            mat[i][left] = arr[index++];
        }
        left++;
    }
}

vector<vector<ll>> spiralMatrix(int m, int n, ListNode* head) {
    vector<ll> v;
    while(head != NULL){v.push_back(head->val);head = head->next;}

    vector<vector<ll>> ans(m,vector<ll>(n,-1));
    formSpiralMatrix(v,ans);
    return ans;
}

int peopleAwareOfSecret(int n, int d, int f) {
    vector<ll> gene(n+f+5,0);
    gene[d] += 1;gene[f] -= 1;
    for(ll i = d;i<=n;++i){
        gene[i] += gene[i-1];
        ll naya = gene[i];
        // Chugli Start 
        gene[i+d] += naya;
        // Bhula re
        gene[i+f] -= naya;
    }

    gene[1] = 1;
    for(ll i = 1;i<=n;++i){
        gene[i] += gene[i-1];
    }
    return gene[n];
}


// Hint : DP
ll coor[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
vector<vector<ll>> dp,v;
ll n,m;
bool valid(ll i,ll j){
    if(i < 0 || j<0 || i>=n || j>=m){return 0;}return 1;
}

ll recur(ll i,ll j){
    ll &sa = dp[i][j];
    if(sa != -1){return sa;}
    sa = 1;
    for(ll k = 0;k<4;++k){
        ll newi = i+coor[k][0],newj = j+coor[k][1];
        if(valid(newi,newj)){
            if(v[newi][newj] > v[i][j]){
                ll sa2 = recur(newi,newj);
                sa = mod_add(sa,sa2,mod);
            }
        }
    }
    return sa;
}

int countPaths(vector<vector<ll>>& grid) {
    n = grid.size(),m = grid[0].size();
    v.assign(n,vector<ll>(m,-1));dp.assign(n+5,vector<ll>(m+5,-1));
    v = grid;
    ll ans = 0;
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            ll sa = recur(i,j);
            ans = mod_add(sa,ans,mod);
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