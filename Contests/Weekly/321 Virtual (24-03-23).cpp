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
int pivotInteger(int n) {
    ll sm = 0;
    for(ll i = 1;i<=n;++i){
        sm += i;
        ll ok = 0;
        for(ll j = i;j<=n;++j){
            ok += j;
        }
        if(sm == ok){
            return i;
        }
    }
    return -1;
} 

int appendCharacters(string s, string t) {
    ll i = 0,j = 0;
    while(i<s.size()){
        if(j<t.size() and s[i] == t[j]){
            ++i,++j;
        }
    }

    ll ans = t.size()-j;
    return ans;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNodes(ListNode* head) {
    stack<ll> s;    
    ListNode* tmp = head;
    while(tmp != NULL){
        if(!s.empty()){
            while(tmp->val > s.top()){
                s.pop();
                if(s.empty()){break;}
            }
        }
        s.push(tmp->val);
        tmp = tmp->next;
    }

    stack<ll> ok;
    while(!s.empty()){
        ok.push(s.top());s.pop();
    }

    if(ok.empty()){return NULL;}
    ListNode* head2 = new ListNode(ok.top());ok.pop();
    ListNode* tmp2 = head2;
    while(!ok.empty()){
        ListNode* dk = new ListNode(ok.top());
        ok.pop();
        tmp2->next = dk;
        tmp2 = dk;
    }
    return head2;
}

int countSubarrays(vector<int>& v, int k) {
    ll idx = -1,n = v.size();
    for(ll i = 0;i<n;++i){if(v[i] == k){idx=i;}}
    map<ll,ll> aft,bef;
    ll j = idx+1,bg = 0,sm = 0;
    while(j < n){
        if(v[j] > k){
            ++bg;
        }else{
            ++sm;
        }
        aft[bg-sm]++,++j;
    }

    j = idx-1,bg = 0,sm = 0;
    while(j >= 0){
        if(v[j] > k){
            ++bg;
        }else{
            ++sm;
        }
        bef[bg-sm]++,--j;
    }
    cout<<"BEF : \n";
    for(auto it:bef){
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<"After : \n";
    for(auto it:aft){
        cout<<it.first<<" "<<it.second<<endl;
    }

    ll ans = 1;
    ans += (bef[0]+aft[0]+bef[1]+aft[1]);

    for(auto it:aft){
        if(it.first == 0){
            ll freq = (bef[0]+bef[1]);
            ans += (it.second*freq);
        }else if(it.first > 0){
            // 1 will search -1 & 0
            ll freq = (bef[-it.first]+bef[-it.first+1]);
            ans += (it.second*freq);
        }else{
            // Get ele bigger than k,i.e. diff must be greater
            ll freq = bef[-it.first]+bef[-it.first+1];
            ans += (it.second*freq);
        }
    }
    return ans;
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    ll ans = countSubarrays(v,6);
    cout<<ans<<endl;
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