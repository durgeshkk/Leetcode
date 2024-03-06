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
int maxSum(vector<int>& v) {
    ll sm = -1;
    ll n = v.size();
    for(ll i = 0;i<n;++i){
        ll ok = -1;
        for(ll j = i+1;j<n;++j){
            string s = to_string(v[i]);string t = to_string(v[j]);
            sort(all(s));sort(all(t));
            if(s[s.size()-1] == t[t.size()-1]){
                ok = v[i]+v[j];
            }
        }
        sm = max(sm,ok);
    }
    return sm;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int doubleItHelper(ListNode* newHead)
{
    if(!newHead)
        return 0;
    int carry = doubleItHelper(newHead->next);
    
    int curSum = newHead->val;
    curSum*=2;
    curSum+=carry;
    
    int reminder = curSum%10;
    int newCarry = curSum/10;
    
    newHead->val = reminder;
    
    return newCarry;
}
ListNode* doubleIt(ListNode* head)
{
    ListNode* newHead = head;
    int carry = doubleItHelper(newHead);
    if(carry!=0)
    {
        ListNode* temp = new ListNode(carry);
        temp->next = newHead;
        newHead = temp;
    }
    return newHead;
}

int minAbsoluteDifference(vector<int>& v, int x) {
    multiset<ll> ms;
    ll n = v.size();
    for(int i = x;i<n;++i){
        ms.insert(v[i]);
    }

    ll ans = 1e10;
    ll i = 0,j = x;
    while(j < n){
        auto lb = ms.lower_bound(v[i]);
        auto ub = ms.lower_bound(v[i]);
        --lb;

        ll a = 1e10,b = 1e10;
        if(ub != ms.end()){a = (*ub)-v[i];}
        if(ub != ms.begin()){b = abs(*lb -v[i]);}
        ans = min({ans,a,b});
        ms.erase(ms.find(v[j]));
        ++i,++j;
    }
    return ans;
}

#define MAXN 100001
int spf[MAXN];
void sieve(){
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
 
ll getFactorization(int x)
{
    set<int> ret;
    while (x != 1) {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    ll sz = ret.size();
    return sz;
}

int maximumScore(vector<int>& v, int k) {
    ll n = v.size();sieve();
    multiset<ll> ms(all(v));
    vector<ll> dist(n,0);
    ll ans = 1;
    for(int i = 0;i<n;++i){dist[i] = getFactorization(v[i]);}
    vector<ll> lft(n,0),right(n,0);

    // In Left we need equal or gr8
    set<ll> s;map<ll,ll> mp;
    s.insert(dist[0]);
    mp[dist[0]] = 0;
    for(int i = 1;i<n;++i){
        auto lb = s.lower_bound(dist[i]);
        if(lb != ms.end()){
            lft[i] = mp[*lb];
        }else{
            lft[i] = 0;
        }
        s.insert(dist[i]);
        mp[dist[i]] = i;
    }
    s.clear();mp.clear();

    // In rght we need only gr8
    s.insert(dist[n-1]);mp[dist[n-1]] = (n-1);

    for(int i = n-2;i>=0;--i){
        auto ub = s.upper_bound(dist[i]);
        if(ub != ms.end()){
            lft[i] = mp[*ub];
        }else{
            lft[i] = n-1;
        }
        s.insert(dist[i]);
        mp[dist[i]] = i;
    }

    while(k--){
        
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