/*
Once in a LifeTime,
Will never let you Down!!
*/
#include <bits/stdc++.h>
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
// YE DIL MAANGE MORE!!

string findLatestTime(string s) {
    if(s[0] == '?' and s[1] == '?'){
        s[0] = s[1] = '1';
    }else if(s[0] == '0' and s[1] == '?'){
        s[1] = '9';
    }else if(s[0] == '1' and s[1] == '?'){
        s[1] = '1';
    }else if(s[0] == '?' and s[1] <= '9' and s[1] > '1'){
        s[0] = '0';
    }else if(s[0] == '?' and s[1] <= '1'){
        s[0] = '1';
    }
    
    if(s[3] == '?'){
        s[3] = '5';
    }
    
    if(s[4] == '?'){
        s[4] = '9';
    }
    return s;
}

set<int> primes;
int n = 101;
void fun(){
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.insert(p);
}
    
int maximumPrimeDifference(vector<int>& v) {
    fun();
    primes.insert(2);primes.insert(3);
    // for(auto it:primes){
    //     cout<<it<<" ";
    // }cout<<endl;

    int f = -1,l = -1;
    for(int i = 0;i<v.size();++i){
        if(primes.find(v[i]) != primes.end()){
            l = i;
            if(f == -1){
                f = i;
            }
        }
    }
    // cout<<l<<" "<<f<<endl;
    return (l-f);
}

long long pie(vector<int> &coins, long long x)
{
    int m = coins.size();
    int nn = (1 << m);
    long long cnt = 0;
    for (int i = 1; i < nn; i++)
    {
        long long lcmm = 1;
        for (int j = 0; j < m; j++)
        {
            if (i & (1 << j))
            {
                lcmm = lcm(lcmm, coins[j]);
            }
        }
        if (__builtin_popcount(i) & 1)
            cnt += x / lcmm;
        else
            cnt -= x / lcmm;
    }
    return cnt;
}

long long findKthSmallest(vector<int> &coins, int k)
{
    long long kk = k;
    long long l = 1, r = 1e11, ans = 0;
    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        long long cnt = 0;
        cnt = pie(coins, m);
        if (cnt < kk)
            l = m + 1;
        else
        {
            ans = m;
            r = m - 1;
        }
    }
    return ans;
}

vector<vector<unordered_map<int, int>>> dp;
ll recur(ll i, ll j, ll val, vector<int>& a, vector<int>& b){
    if(i==a.size() and j==b.size()){return 0;}
    if(i==a.size() or j==b.size()){return 1e6;}

    ll tk=1e6, ntk=1e6;
    if(dp[i][j].count(val))return dp[i][j][val];
    
    if((a[i] & val) == b[j]){
        tk = recur(i+1, j+1, (1<<17)-1, a, b) + a[i];
    }
    ntk = recur(i+1, j, (val & a[i]), a, b);
    return dp[i][j][val]=min(tk, ntk);
}

int minimumValueSum(vector<int>& a, vector<int>& b) {
    dp.assign(a.size(), vector<unordered_map<int, int>>(b.size()));
    ll ans=recur(0, 0, (1<<17)-1, a, b);
    if(ans >= 1e6){ans = -1;}
    return ans;
}

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
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