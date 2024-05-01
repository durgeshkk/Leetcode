/*
Once in a LifeTime,
Will never let you Down!!
*/
#include <bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
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
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
// YE DIL MAANGE MORE!!

int minimumOperationsToWriteY(vector<vector<int>>& v) {
    ll n = v.size(),m  =n/2;
    map<ll,ll> mp;
    for(ll i = 0;i<=m;++i){
        for(ll j = 0;j<n;++j){
            if((i == j) || (i+j+1 == n)){
                mp[v[i][j]]++;
            }
        }
    }

    for(ll i = m/2;i<n;++i){
        mp[v[i][m]]++;
    }

    mp[v[m][m]] -= 2;
    ll z = 0,o = 0,t = 0;
    for(ll i = 0;i<n;++i){
        forj(n){
            if(!v[i][j]){
                ++z;
            }else if(v[i][j] == 1){++o;
            }else{
                ++t;
            }
        }
    }
    z -= mp[0];
    o -= mp[1];
    t -= mp[2];
    ll ans = n*m+1,rem = z+o+t;
    // Try make Y as 0
    ll change = mp[1]+mp[2]+z+min(o,t);
    
    // Try make Y as 1
    ll change1 = mp[0]+mp[2]+o+min(z,t);

    // Try make Y as 2
    ll change2 = mp[1]+mp[0]+t+min(o,z);
    ans = min({change1,change2,change});
    return ans;
}

int countSubmatrices(vector<vector<int>>& v, int k) {
    ll n = v.size(),m = v[0].size();
    ll ans = 0;
    vector<vector<ll>> dp(n+1,vector<ll> (m+1,0));
    for(ll i = 0;i<n;++i){
        forj(m){
            ll ele = v[i][j],sm = 0;
            if(i){
                sm += dp[i-1][j];
            }
            if(j){
                sm += dp[i][j-1];
            }
            if(i and j){
                sm -= dp[i-1][j-1];
            }
            sm += ele;
            dp[i][j] = sm;
        }
    }

    for(ll i = 0;i<n;++i){
        forj(m){
            if(dp[i][j] >= k){
                ++ans;
            }
        }
    }
    return ans;
}

int lower_bound(int x, ordered_set s)
{
    ll l = 0,h = s.size(),ans = -1;
    while(l <= h){
        ll mid = (l+h)/2;
        ll ele = *s.find_by_order(mid);
        if(ele <= x){
            l = mid+1;
        }else{
            ans = mid;
            h = mid-1;
        }
    }
    return ans;
}

vector<int> resultArray(vector<int>& v) {
    vector<int> v1,v2;
    ordered_set o1,o2;
    v1.push_back(v[0]);v2.push_back(v[1]);
    o1.insert(v[0]);o2.insert(v[1]);
    ll n = v.size();
    for(ll i = 2;i<n;++i){
        ll idx1 = o1.order_of_key(v[i]);
        ll idx2 = o2.order_of_key(v[i]);
        if(idx1 > idx2){
            o1.insert(v[i]);
            v1.push_back(v[i]);
        }else if(idx1 == idx2){
            if(o1.size() > o2.size()){
                o2.insert(v[i]);
                v2.push_back(v[i]);
            }else{
                o1.insert(v[i]);
                v1.push_back(v[i]);
            }
        }else{
            o2.insert(v[i]);
            v2.push_back(v[i]);
        }
    }
    for(auto it:v2){
        v1.push_back(it);
    }
    return v1;
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