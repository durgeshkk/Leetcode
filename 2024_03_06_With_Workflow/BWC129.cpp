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
ll func(ll i,ll j,ll n,ll m,vector<vector<char>>& v){
    if(i+1 < n and j+1<m){
        ll sm = 0;
        if(v[i][j] == 'B'){++sm;}
        if(v[i+1][j] == 'B'){++sm;}
        if(v[i][j+1] == 'B'){++sm;}
        if(v[i+1][j+1] == 'B'){++sm;}
        if(sm != 2){return 1;}
    }else{
        return 0;
    }
    
}
bool canMakeSquare(vector<vector<char>>& grid) {
    ll n = 3,m = 3;
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            if(func(i,j,n,m,grid)){return true;}
        }
    }
    return false;
}

long long numberOfRightTriangles(vector<vector<int>>& v) {
    ll n = v.size(),m = v[0].size(),ans = 0;
    if(n == 1 || m == 1){return 0;}

    if(n == 2){
        forj(m){
            if(v[1][j] and v[0][j]){
                if(j-1 >= 0 and v[1][j-1]){
                    ++ans;
                }else if(j-1 < 0 and v[1][m-1]){
                    ++ans;
                }

                if(j+1 <m and v[1][j+1]){
                    ++ans;
                }else if(j+1 <m and v[1][0]){
                    ++ans;
                }
            }
        }

        forj(m){
            if(v[0][j] and v[1][j]){
                if(j-1 >= 0 and v[1][j-1]){
                    ++ans;
                }else if(j-1 < 0 and v[1][m-1]){
                    ++ans;
                }

                if(j+1 <m and v[1][j+1]){
                    ++ans;
                }else if(j+1 <m and v[1][0]){
                    ++ans;
                }
            }
        }
    }else if(m == 2){

    }

    for(ll i = 0;i<n;++i){
        forj(m){
            if(v[i][j]){

                if(j+1<m and v[i][j+1]){
                    if(i+1<n){
                        if(v[i+1][j]){++ans;}
                    }else{
                        if(v[0][j]){++ans;}
                    }

                    if(i-1 >= 0){
                        if(v[i-1][j]){++ans;}
                    }else{
                        if(v[n-1][j]){++ans;}
                    }
                }else if(j+1>m and v[i][0]){
                    if(i+1<n){
                        if(v[i+1][j]){++ans;}
                    }else{
                        if(v[0][j]){++ans;}
                    }

                    if(i-1 >= 0){
                        if(v[i-1][j]){++ans;}
                    }else{
                        if(v[n-1][j]){++ans;}
                    }
                }
                
                if(j-1>=0 and v[i][j-1]){
                    if(i+1<n){
                        if(v[i+1][j]){++ans;}
                    }else{
                        if(v[0][j]){++ans;}
                    }

                    if(i-1 >= 0){
                        if(v[i-1][j]){++ans;}
                    }else{
                        if(v[n-1][j]){++ans;}
                    }
                }else if(j-1<0 and v[i][m-1]){
                    if(i+1<n){
                        if(v[i+1][j]){++ans;}
                    }else{
                        if(v[0][j]){++ans;}
                    }

                    if(i-1 >= 0){
                        if(v[i-1][j]){++ans;}
                    }else{
                        if(v[n-1][j]){++ans;}
                    }
                }

            }
        }
    }
    return ans;
}













ll z,o,lim,n;
vector<vector<ll>> dp;
ll recur2(ll rem_zeroes,ll idx){
    if(idx < n and !rem_zeroes){
        if(n-idx > lim){return 0;}
        return 1;
    }

    if(idx == n){return rem_zeroes == 0;}

    ll &sa = dp[rem_zeroes][idx];
    if(sa != -1){return sa;}
    sa = 0;
    for(ll i = idx;i<min(n,idx+lim+1);++i){
        if(rem_zeroes){
            sa += recur2(rem_zeroes-1,i+1);
        }
    }
    return sa;
}

int numberOfStableArrays2(int zero, int one, int limit) {
    z = zero,o = one,lim = limit,n = z+o;
    dp.assign(z+1,vector<ll> (n+1,-1));
    return recur2(zero,0);
}

ll recur(ll rem_zeroes,ll idx,vector<ll> x){
    
    if(idx <= n and !rem_zeroes){
        if(n-idx > lim){return 1e10;}
        cout<<"HI "<<idx<<"\n";
        show(x);
        return 1;
    }else if(idx >= n){
        return 1e10;
    }
    
    // if(idx == n){return rem_zeroes == 0;}

    ll &sa = dp[rem_zeroes][idx];
    if(sa != -1){return sa;}
    sa = 0;
    for(ll i = idx;i<min(n,idx+lim+1);++i){
        if(rem_zeroes){
            if(recur(rem_zeroes-1,i+1,x) < 1e10){
                x.push_back(0);
                sa += recur(rem_zeroes-1,i+1,x);
            }
        }
        x.push_back(1);
    }
    return sa;
}

int numberOfStableArrays(int zero, int one, int limit) {
    z = zero,o = one,lim = limit,n = z+o;
    dp.assign(z+1,vector<ll> (n+1,-1));
    ll ans = recur(zero,0,{});
    for(ll i = 0;i<=z;++i){
        show(dp[i]);
    }
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