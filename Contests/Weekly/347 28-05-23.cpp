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
string removeTrailingZeros(string s) {
    ll n = s.size();
    ll i = n-1;
    for(i = n-1;i>=0;--i){
        if(s[i] == '0'){s.pop_back();}
        else{break;}
    }
    string ans;
    for(ll j =0;j<=i;++j){
        ans += s[i];
    }
    return ans;
} 

ll n,m;
bool issafe(ll i,ll j){
    if(i>=n || j>=m || i<0 ||j<0){return 0;}return 1;
}

vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& v) {
    n = v.size(),m = v[0].size();
    vector<vector<int>> ans(n,vector<int> (m,0));

    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            set<ll> tl,br;
            ll x = 1,y = 1;
            while(issafe(i-x,j-y)){
                tl.insert(v[i-x][j-y]);
                --x,--y;
            }

            x = 1,y = 1;
            while(issafe(i+x,j+y)){
                tl.insert(v[i+x][j+y]);
                ++x,++y;
            }

            ll sz = tl.size(),sz2 = br.size();
            ll sa = abs(sz-sz2);
            ans[i][j] = sa;
        }
    }
    return ans;
}

/*
long long minimumCost(string s) {
    ll n = s.size();
    if(n == 1){return 0;}

    vector<vector<ll>> zeroes(n+5,vector<ll> (2,0));
    vector<vector<ll>> ones(n+5,vector<ll> (2,0));

    // Lets try to make all of them as zeroes
    // Move frwd
    ll prevz = -1,prevo = -1;
    for(ll i = 0;i<n;++i){
        if(i>=1){
            if(s[i] == '0'){
                zeroes[i+1][0] = zeroes[i][0];
            }else{
                zeroes[i+1][0] = (1+2*zeroes[i][0]);
                // zeroes[i+1][0] = (i+1+prevz+1+zeroes[i][0]);
            }
        }else{
            if(s[i]=='0'){

            }else{
                zeroes[i+1][0] = 1;
            }
        }
        if(s[i] == '0'){prevz = i;}
        else{prevo = i;}
    }

    // Move back
    ll prevz = -1,prevo = -1;
    for(ll i = n-1;i>=0;--i){
        if(i<(n-1)){
            if(s[i] == '0'){
                zeroes[i+1][1] = zeroes[i][1];
            }else{
                // zeroes[i+1][1] = (n-i+prevz+1+zeroes[i][1]);
                zeroes[i+1][1] = (1+2*zeroes[i][1]);
            }
        }else{
            if(s[i]=='0'){
            }else{
                zeroes[i+1][1] = 1;
            }
        }
        if(s[i] == '0'){prevz = n-i-1;}
        else{prevo = n-i-1;}
    }
    zeroes[1][0] = zeroes[1][1];

    ll ans = LLONG_MAX;
    for(ll i = 0;i<n;++i){
        ll sa = zeroes[0][i]+zeroes[1][i+1];
        ll sa2 = zeroes[1][i]+zeroes[0][i+1];
        ans = min({ans,sa,sa2});
    }

    // Lets try to make all of them as ones
    // Move frwd
    ll prevz = -1,prevo = -1;
    for(ll i = 0;i<n;++i){
        if(i>=1){
            if(s[i] == '0'){
                // ones[i+1][0] = (i+1+prevo+1+2*ones[i][0]);
                ones[i+1][0] = (1+2*ones[i][0]);
            }else{
                ones[i+1][0] = ones[i][0];
            }
        }else{
            if(s[i]=='0'){
                ones[i+1][0] = 1;
            }else{
            }
        }
        if(s[i] == '0'){prevz = i;}
        else{prevo = i;}
    }

    // Move back
    ll prevz = -1,prevo = -1;
    for(ll i = n-1;i>=0;--i){
        if(i<(n-1)){
            if(s[i] == '0'){
                ones[i+1][1] = (n-i+2*prevo+ones[i+2][1]);
            }else{
                ones[i+1][1] = ones[i+2][1];
            }
        }else{
            if(s[i]=='0'){
                ones[i+1][1] = 1;
            }else{
            }
        }
        if(s[i] == '0'){prevz = n-i-1;}
        else{prevo = n-i-1;}
    }
    ones[1][0] = ones[1][1];
}
*/

long long minimumCost(string s) {
    ll n = s.size();

    ll ans = 0;
    for(ll i = 0;i<n-1;++i){
        if(s[i] != s[i+1]){
            ll sa = i+1;
            ll sa2 = n-i-1;
            ans += min(sa,sa2);
        }
    }
    return ans;

    vector<ll> zl(n+1,0),zr(n+1,0);        
    zl.push_back(0);
    ll zero_idx = 0,o_idx = 0;
    for(ll i = 0;i<n;++i){
        if(s[i] == '0'){
            ll cntr = 0;
            while(i<n and s[i] == '0'){
                ++i;
            }
            zero_idx += i;
            --i;
            zl.push_back(zl[zl.size()-1]);
        }else{
            ll cntr = 0;
            while(i<n and s[i] == '1'){
                ++i;
            }
            o_idx += i;
            --i;
            ll sa = o_idx+2*zero_idx;
            zl.push_back(sa);
        }
    }

    for(ll i = n-1;i>=0;--i){
        if(s[i] == '0'){
            ll cntr = 0;
            while(i<n and s[i] == '0'){
                ++i;
            }
            --i;
            zero_idx += (n-i);
            zl.push_back(zl[zl.size()-1]);
        }else{
            ll cntr = 0;
            while(i<n and s[i] == '1'){
                ++i;
            }
            --i;
            o_idx += (n-i);
            ll sa = o_idx+2*zero_idx;
            zl.push_back(sa);
        }
    }
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