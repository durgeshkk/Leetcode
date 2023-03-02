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
 
int minMaxDifference(int num) {
    int ans = 0;
    string s = to_string(num);
    char ch1 = '0';
    char ch2 = '9';

    for(ll i = 0;i<s.size();++i){
        if(s[i] != '9'){
            ch1 = s[i];break;
        }}

    for(ll i = 0;i<s.size();++i){
        if(s[i] != '0'){
            ch2 = s[i];break;
        }
    }

    string mx = s;
    string mn = s;
    for(ll i = 0;i<s.size();++i){
        if(mx[i] == ch1){
            mx[i] = '9';
        }
        if(mn[i] == ch2){
            mn[i] = '0';
        }
    }

    ll maxi = stoll(mx);
    ll mini = stoll(mn);
    ans=  maxi-mini;
    return ans;
}

int minimizeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    ll ans = min({(nums[nums.size()-1]-nums[2]),nums[nums.size()-3]-nums[0],nums[nums.size()-2]-nums[1]});
    return ans;
}

int minImpossibleOR(vector<int>& nums) {
    multiset<ll> ms(nums.begin(),nums.end());
    ll k = 1;
    while(k*2 <= 1e9){
        if(ms.find(k) == ms.end()){
            return k;
        }
        k *= 2;
    }
    return (1073741824);
}

void buildTree(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode) {
    // Base Case when start == end since we know the ans of that idx
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }

    ll mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

// Update O(log n)
void update(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode, ll idx, ll val) {
    if(start == end){
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }

    ll mid = (start+end)/2;
    if(idx > mid){// move to right
        update(arr,tree,mid+1,end,2*treeNode+1,idx,val);
    }else{
        update(arr,tree,start,mid,2*treeNode,idx,val);
    }

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

/*
Query : log(n)
*/
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

    return ans1+ans2;
}

vector<long long> handleQuery(vector<ll>& v1, vector<ll>& v2, vector<vector<ll>>& q) {
    vector<ll> tree(4*v1.size()+4,0);
    buildTree(v1,tree,0,v1.size()-1,1);
    ll sz = q.size();
    ll sm = 0;vector<long long> ans;
    for(ll i = 0;i<q.size();++i){
        vector<ll> x = q[i];
        if(x[0] == 1){
            update(v1,tree,0,v1.size()-1,)
        }else if(x[1] == 2){

        }else{
            ans.push_back(sm);
        }
    }
}   

void solve()
{

    cout<<"[";
    cout<<1;
    ll i = 2;
    for(i=2;i<=(1e9);i*=2){
        cout<<","<<i;
    }
    cout<<"]";
 
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