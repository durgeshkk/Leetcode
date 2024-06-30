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
#define pyes cout << "YES" << endl;
#define pno cout << "NO" << endl;
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
double minimumAverage(vector<int>& v) {
    sort(v.begin(),v.end());
    double ans = 51.0;
    for(int i = 0;i<v.size()/2;++i){
        double sa = (1.0*v[i]+v[v.size()-i-1])/2;
        ans = min(ans,sa);
    }
    return ans;
}

int minimumArea(vector<vector<int>>& v) {
    int n = v.size(),m = v[0].size();

    int x1 = -1,y1 = -1,x2 = -1,y2 = -1;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(v[i][j]){
                if(x1 == -1){
                    x1 = i,y1= j;
                }
                x2 = i,y2 = j;
            }
        }
    }

    int x3 = -1,y3 = -1,x4 = -1,y4 = -1;
    for(int j = 0;j<m;++j){
        for(int i = 0;i<n;++i){
            if(v[i][j]){
                if(x3 == -1){
                    x3 = i,y3= j;
                }
                x4 = i,y4 = j;
            }
        }
    }

    ll x5 = min({x1,x2,x3,x4});
    ll y5 = min({y1,y2,y3,y4});
    ll x6 = max({x1,x2,x3,x4});
    ll y6 = max({y1,y2,y3,y4});
    return (x6-x5)*(y6-y5);
}

ll n;vector<ll> v;
vector<vector<ll>> dp;

ll recur(ll idx,ll f){
    if(idx == n){
        return 0;
    }

    ll &sa = dp[idx][f];
    if(sa != -1){return sa;}
    // Split 
    ll sa1 = 0;
    if(f){
        sa1 += recur(idx+1,0)-v[idx];
    }else{
        sa1 += recur(idx+1,0)+v[idx];
    }

    // Continue
    ll sa2 = 0;
    if(f){
        sa2 += recur(idx+1,f^1)-v[idx];
    }else{
        sa2 += recur(idx+1,f^1)+v[idx];
    }
    return sa = max(sa1,sa2);
}

ll recur(ll i,ll f){
    if(i == n){
        return 0;
    }

    ll val = dp[i][f];
    if(dp[i][f] == -1){return dp[i][f];}

    if(val != -1e12){return val;}

    ll a = 0,b = 0;
    if(f){
        a = -v[i]+recur(i+1,0);
    }else{
        a = v[i]+recur(i+1,0);
    }

    if(f){
        b = -v[i]+recur(i+1,0);
    }else{
        b = v[i]+recur(i+1,1);
    }
    return dp[i][f] = max(a,b);
}

long long maximumTotalCost(vector<int>& nums) {
    for(auto it:nums){
        v.push_back(1ll*it);
    }
    n = v.size();
    dp.assign(n+1, vector<ll>(3,-1e12));
    return recur(0,0);
}

ll n,m;
vector<vector<ll>> tmp;
ll recur(ll i,ll j,ll x,ll y,ll f1,ll f2,ll f3){
    if(i == n and j == m){
        return 0;
    }

    if(i>=n || j>=m || i<0 || j<0){

    }

    ll sa = 0;

    if(tmp[i][j]){
        if(f1 != 2){

            if(f1 == 1){
                // End Now
                ll area = abs(i-x+1)*abs(j-y+1);
                sa = area+recur(i+1,j,-1,-1,2,f2,f3);
                sa = area+recur(i,1+j,-1,-1,2,f2,f3);
            }else{
                // Start & End here
                sa = 1+recur(i+1,j,-1,-1,2,f2,f3);
                sa = 1+recur(i,j+1,-1,-1,2,f2,f3);

                // Just Start
                sa = recur(i+1,j,i,j,1,f2,f3);
                sa = recur(i,1+j,i,j,1,f2,f3);
            }

        }else if(f2 != 2){
            if(f2 == 1){
                // End Now
                ll area = abs(i-x+1)*abs(j-y+1);
                sa = area+recur(i+1,j,-1,-1,2,2,f3);
                sa = area+recur(i,1+j,-1,-1,2,2,f3);
            }else{
                // Start & End here
                sa = 1+recur(i+1,j,-1,-1,2,2,f3);
                sa = 1+recur(i,j+1,-1,-1,2,2,f3);

                // Just Start
                sa = recur(i+1,j,i,j,2,1,f3);
                sa = recur(i,1+j,i,j,2,1,f3);
            }
        }else{
            if(f3 == 1){
                // End Now
                ll area = abs(i-x+1)*abs(j-y+1);
                sa = area+recur(i+1,j,x,y,2,2,2);
                sa = area+recur(i,1+j,x,y,2,2,2);
            }else{
                if(f3 == 2){

                }else{

                }

                // Start & End here
                sa = 1+recur(i+1,j,i,j,2,2,2);
                sa = 1+recur(i,j+1,i,j,2,2,2);

                // Just Start
                sa = recur(i+1,j,i,j,2,2,1);
                sa = recur(i,1+j,i,j,2,2,1);
            }
        }
    }else{
        // Call Recur on Next indices

    }
    return sa;
}

int minimumSum(vector<vector<int>>& grid) {
        
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