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
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
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
 
// Q 1: 
int similarPairs(vector<string>& v) {
    ll ans = 0;
    map<string,ll> mp;
    for(ll i = 0;i<v.size();++i){
        string st = v[i];
        set<char> s;
        for(auto it:st){
            s.insert(it);
        }
        st.clear();
        for(auto it:s){
            st += it;
        }
        mp[st]++;
    }

    for(auto it:mp){
        ans += (it.second)*(it.second-1)/2;
    }
    return ans;
}

// Q 2:
ll primeFactors(int n)
{
    // Print the number of 2s that divide n
    ll ans = 0;
    while (n % 2 == 0)
    {
        ans += 2;
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            ans += i;
            n = n/i;
        }
    }
 
    if (n > 2)
        ans += n;

    return ans;    
}

int smallestValue(int n) {
    int ans = n;
    while(1){
        ll val = primeFactors(ans);
        if(val == 0 || val == ans){break;}
        ans = val;
    }
    return ans;       
}

// Q 3:
#define no return false;
#define ys return true;

bool isPossible(int n, vector<vector<int>>& edges) {

    vector<vector<int>> adj(n+1);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    set<ll> s;
    for(ll i = 1;i<=n;++i){
        if(adj[i].size() & 1){
            s.insert(i);
        }
    }
    if(s.size() == 0){ys;}

    if(s.size() > 4 || (s.size() & 1)){
        no;
    }

    vector<ll> v(s.begin(),s.end());
    if(s.size() == 4){
        // check edges pssbl
        // 4->5 6->7
        ll f = 1;
        for(auto it:adj[v[0]]){//4->5
            if(it == v[1]){
                f = 0;break;
            }
        }
        
        for(auto it:adj[v[2]]){//6->7
            if(it == v[3]){
                f = 0;break;
            }
        }

        if(f & 1){
            ys;
        }

        f = 1;
        for(auto it:adj[v[0]]){//4->6
            if(it == v[2]){
                f = 0;break;
            }
        }
        
        for(auto it:adj[v[1]]){//5->7
            if(it == v[3]){
                f = 0;break;
            }
        }

        if(f & 1){
            ys;
        }
        
        f = 1;
        for(auto it:adj[v[0]]){//4->7
            if(it == v[3]){
                f = 0;break;
            }
        }
        
        for(auto it:adj[v[1]]){//5->6
            if(it == v[2]){
                f = 0;break;
            }
        }

        if(f & 1){
            ys;
        }
    }else{
        // size is 2
        ll f = 1;
        for(auto it:adj[v[0]]){//4->5
            if(it == v[1]){
                f = 0;break;
            }
        }

        if(f & 1){ys;}

        // Else dono ka edge usse add krro jo already even h aur dono m nhi h
        set<ll> sot;
        for(ll i = 1;i<=n;++i){sot.insert(i);}

        for(auto it:adj[v[0]]){
            if(sot.find(it) != sot.end()){
                sot.erase(sot.find(it));
            }
        }

        for(auto it:adj[v[1]]){
            if(sot.find(it) != sot.end()){
                sot.erase(sot.find(it));
            }
        }

        if(!sot.empty()){ys;}
    }
    no;
}

void solve()
{
 
    ll n;
    cin>>n;
    // int ans = smallestValue(n);
    // cout<<ans<<endl;
    // cout<<n<<endl;return;

    vector<vector<int>> edges;
    ll inp;cin>>inp;
    while(inp--){
        ll a,b;cin>>a>>b;
        vector<ll> v;
        v.push_back(a);
        v.push_back(b);
        edges.push_back(v);
    }

    // return;

    bool ans = isPossible(n,edges);
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