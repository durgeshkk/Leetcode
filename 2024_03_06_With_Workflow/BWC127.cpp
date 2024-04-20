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

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
/*
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

int minimumSubarrayLength(vector<int>& v, int k) {
    int n = v.size();
    ll ans = n+1;
    for(ll i = 0;i<n;++i){
            ll ele = 0;
            for(ll j = i;j<n;++j){
                ele |= v[j];
                if(ele >= k){
                    ans = min(ans,j-i+1);
                }
            }
    }
    if(ans == n+1){ans= -1;}
    return ans;
}

int minimumLevels(vector<int>& v) {
    int n = v.size(),sm = 0;
    for(ll i = 0;i<n;++i){
        if(v[i]){++sm;}
        else{--sm;}
    }
    
    int ans = -1,pre = 0;
    for(ll i = 0;i<n-1;++i){
        if(v[i]){++pre;}
        else{--pre;}
        ll rem = sm-pre;
        if(pre > rem){return (i+1);}
    }
    return ans;
}

int minimumSubarrayLengthC(vector<int>& v, int k) {
    if(!k){return 1;}
    ll n = v.size(),l = 0,h = n,ans = -1;
    while(l <= h){
        ll mid = (l+h)/2;

        ll low = 0,high = mid,sa = 0,f = 0;
        vector<ll> bits(64,0);
        for(ll i = 0;i<high;++i){
            bitset<40> b(v[i]);
            forj(40){
                if(b[j]){bits[j]++;}
            }
        }

        forj(40){
            if(bits[j]){sa += (1<<j);}
        }
        if(sa >= k){
            f = 1;
        }

        while(high < n){
            bitset<40> a(v[low]);
            bitset<40> b(v[high]);

            forj(40){
                if(a[j]){bits[j]--;}
                if(b[j]){bits[j]++;}
            }
            sa = 0;
            forj(40){
                if(bits[j]){sa += (1<<j);}
            }
            if(sa >= k){
                f = 1;break;
            }
            ++low,++high;
        }
        if(f){
            ans = mid;
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}

ll n,k;
map<ll,ll> mp;
ll dp[50][50][2500];
ll recur(ll idx, vector<int> &v,ll eleTaken, ll mnSum){
    if(eleTaken == k-1){
        return mnSum;
    }

    ll &sa = dp[idx][eleTaken][mp[mnSum]];
    if(sa != -1){return sa;}
    sa = 0;
    for(ll i = idx+1;i<n;++i){
        sa = mod_add(sa,recur(i,v,eleTaken+1,min(mnSum,1ll*v[i]-v[idx])),mod);
    }
    return sa;
}

int sumOfPowers(vector<int>& v, int m) {
    sort(all(v));
    n = v.size(),k = 1ll*m;
    ll x = 0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(!mp.count(v[j]-v[i])){
                mp[v[j]-v[i]] = x++;
            }
        }
    }

    for(ll i = 0;i<n;++i){
        forj(n){
            for(ll k = 0;k<n*n;++k){
                dp[i][j][k] = -1;
            }
        }
    }

    mp[INT_MAX] = x;
    ll ans = 0;
    
    for(ll i=0;i<n;i++){
        ans = mod_add(ans,recur(i,v,0,INT_MAX),mod);
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