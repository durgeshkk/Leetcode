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
int minimumAddedInteger(vector<int>& a, vector<int>& b) {
    ll n=a.size(),m = n-2,ans = 10001;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<n;++j){
            if(i == j){continue;}
            // Try removing i & j
            vector<ll> v;
            for(ll k = 0;k<n;++k){
                if(k == i || k == j){continue;}
                v.push_back(a[k]);
            }

            ll diff = 10001;
            for(ll k = 0;k<m;++k){
                if(diff == 10001){
                    diff = v[k]-a[k];
                }else{
                    if(diff != (v[k]-a[k])){
                        diff == 10001;break;
                    }
                }
            }

            ans = min(ans,diff);
        }
    }
    return ans;
}

long long minEnd(int n, int x) {
    n--;
    if(!n){return x;}
    bitset<64> a(x);
    bitset<64> b(n);
    ll j = 0;
    for(ll i = 0;i<64;++i){
        if(!a[i]){
            if(b[j]){
                a[i] = 1;++j;
            }else{
                ++j;
            }
        }
    }

    ll ans = -1,idx = -1,z = 0;

    for(ll i = 0;i<64;++i){
        if(a[i]){
            ans += (1<<i);
        }
    }
    return ans;
}

// Prerequisite : https://leetcode.com/problems/subarrays-with-k-different-integers/submissions/1217982826/
ll countSubarraysWithAtMostKDistinct(vector<int>& nums, ll k){
    ll n=nums.size();
    unordered_map<ll, ll> mp;
    ll i=0, j=0;
    ll c=0;
    
/*
    Subarray from [i,j] having unique elements = k, will have all the subarrays whose distinct
    elements count will be <= k & will contribute to the answer for (uniqueness <= k)
*/

    while(j<n){
        mp[nums[j]]++;
        
        while(i<=j && mp.size()>k){
            if(--mp[nums[i]] == 0) mp.erase(nums[i]);
            i++;
        }
        c += (j-i+1);
        j++;
    }
    
    return c;
}
int medianOfUniquenessArray(vector<int>& v) {
    ll n = v.size();
    ll l = 1,r = n,total = n*(n+1)/2,ans = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        ll ele = countSubarraysWithAtMostKDistinct(v,mid);
        // If mid is the median of the subarray then there must be atleast ceil(1.0*n/2) elements less equal than mid 
        // So atleast ceil(1.0*n/2) elements in the uniqueness array must be <= mid
        // That is, count of subarrays whose distinct element count <= mid. 
        // And after this I'll get ans as True for all greater elements!
        if(2*ele >= total){ 
            r = mid-1;
        }else{
            l = mid+1;
            ans = mid;
        }
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