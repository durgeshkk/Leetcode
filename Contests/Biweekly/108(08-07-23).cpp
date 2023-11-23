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
 int ans=-1;
for(int i=0;i<nums.size();i++)
{
    int count=1;
    int flag=0;
    for(int j=i+1;j<nums.size();j++)
    {
        if(flag==0 and nums[j]==nums[i]+1)
            count++,flag=1;
        else if(flag==1 and nums[i]==nums[j])
            count++,flag=0;
        else
            break;
    }
    if(count>1)
        ans=max(ans,count);
}
return ans;
*/
int alternatingSubarray(vector<int>& v) {
    ll n = v.size(),ans = 0;
    forj(n){
        ll x = 0,f = 0,flag = 1;
        for(ll i = j+1;i<n;++i){
            ll diff = v[i]-v[i-1];
            if((diff == 1) and !f){f = 1;++x;}
            else if(f and !diff){++x;f = 0;}
            else{flag = 0;}
            if(!flag){break;}
        }
        if(!x){}
        else{ans = max(ans,x+1);}
    }
    if(!ans){return -1;}
    return ans;
}

vector<ll> relocateMarbles(vector<int>& v, vector<int>& a, vector<int>& b) {
    ll n = v.size();
    set<ll> s;
    for(ll i = 0;i<n;++i){s.insert(v[i]);}
    for(ll i = 0;i<a.size();++i){
        ll x = a[i],y = b[i];
        if(s.find(x) != s.end()){
            s.erase(s.find(x));
            s.insert(y);
        }
    }
    vector<ll> ans(all(s));
    return ans;
}

set<ll> ms = {1,5,25,125,625,3125,15625,78125};
set<string> ok = {"1","101","11001","1111101","1001110001","110000110101","11110100001001","10011000100101101"};
string s;ll n;
ll recur(ll idx){
    if(idx == n){return 0;}
    string tmp;
    ll sa = LLONG_MAX;

    for(ll i = idx;i<n;++i){
        tmp += s[i];
        if(ok.find(tmp) != ok.end()){
            ll dk = recur(i+1);
            if(dk != LLONG_MAX){
                sa = min(sa,dk+1);
            }
        }
    }
    return sa;
}

int minimumBeautifulSubstrings(string st) {
    s = st;n = st.size();
    ll sa = recur(0);
    if(sa == LLONG_MAX){return -1;}
    return sa;
}
/*
for(ll i = 0;i<sz;++i){
        ll f = 0;
        forj(sz){
            ll dist = abs(a[j][1]-a[i][1])+abs(a[j][0]-a[i][0]);
            if(dist == 1){
                ll x = 1;
                ll ni = a[i][0],nj = a[i][1];
                ll ni2 = a[j][0],nj2 = a[j][1];

                if(ni+1 == ni2 and nj == nj2){
                    if(s.find({ni,nj+1}) != s.end()){++x;}
                    if(s.find({ni+1,nj+1}) != s.end()){++x;}
                }else if(ni-1 == ni2 and nj == nj2){
                    if(s.find({ni,nj+1}) != s.end()){++x;}
                    if(s.find({ni-1,nj-1}) != s.end()){++x;}
                }else if(nj-1 == nj2){
                    if(s.find({ni-1,nj}) != s.end()){++x;}
                    if(s.find({ni-1,nj-1}) != s.end()){++x;}
                }else{
                    if(s.find({ni+1,nj}) != s.end()){++x;}
                    if(s.find({ni+1,nj+1}) != s.end()){++x;}
                }
                ans[x]++;f = 1;
            }else if(dist == 2){
                // 2 pssbl cases
                ll x = 2;
                ll ni = a[i][0],nj = a[i][1];
                ll ni2 = a[j][0],nj2 = a[j][1];

                if(ni+1 == ni2 and nj+1 == nj2){
                    if(s.find({ni+1,j}) != s.end()){
                        ++x;
                    }
                    if(s.find({ni,nj+1}) != s.end()){
                        ++x;
                    }
                }else if(ni-1 == ni2 and nj+1 == nj2){
                    if(s.find({ni-1,j}) != s.end()){
                        ++x;
                    }
                    if(s.find({ni,nj+1}) != s.end()){
                        ++x;
                    }
                }else if(ni-1 == ni2 and nj-1 == nj2){
                    if(s.find({ni-1,j}) != s.end()){
                        ++x;
                    }
                    if(s.find({ni,nj-1}) != s.end()){
                        ++x;
                    }
                }else{
                    if(s.find({ni+1,j}) != s.end()){
                        ++x;
                    }
                    if(s.find({ni,nj-1}) != s.end()){
                        ++x;
                    }
                }
                ans[x]++;f = 1;
            }else{
            }
        }
        if(!f){ans[1]++;}
    }
*/

vector<pair<ll,ll>> dir = {{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1}};
ll n,m;
bool issafe(ll i,ll j){
    if(i < 0 || j<0 || i>=m || j>=n){
        return 0;
    }
    return 1;
}

vector<long long> countBlackBlocks(int m2, int n2, vector<vector<int>>& a) {
    n = n2,m = m2;
    sort(all(a));
    ll sz = a.size();
    set<pair<ll,ll>> s;
    for(auto it:a){
        pair<ll,ll> p = {it[0],it[1]};
        s.insert(p);
    }

    vector<ll> ans(5,0);
    vector<vector<ll>> dir1 = {{1,1},{0,1},{1,0}};
    vector<vector<ll>> dir2 = {{-1,1},{0,1},{-1,0}};
    vector<vector<ll>> dir3 = {{-1,-1},{0,-1},{-1,0}};
    vector<vector<ll>> dir4 = {{1,-1},{0,-1},{1,0}};
    for(ll i = 0;i<sz;++i){
        ll x = 1;
        for(auto it:dir1){
            if(issafe(it[0],it[1]) and s.find({it[0],it[1]}) != s.end()){++x;}
        }
        ans[x]++;

        x = 1;
        for(auto it:dir2){
            if(issafe(it[0],it[1]) and s.find({it[0],it[1]}) != s.end()){++x;}
        }
        ans[x]++;

        x = 1;
        for(auto it:dir3){
            if(issafe(it[0],it[1]) and s.find({it[0],it[1]}) != s.end()){++x;}
        }
        ans[x]++;

        x = 1;
        for(auto it:dir4){
            if(issafe(it[0],it[1]) and s.find({it[0],it[1]}) != s.end()){++x;}
        }
        ans[x]++;
    }

    ll cntr = 0;
    forj(5){
        if(!j){continue;}
        ans[j] /= j;
        cntr += ans[j];
    }

    ll ok = m+n-cntr-2;
    ans[0] = ok;
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