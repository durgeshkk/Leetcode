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
ll isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool isValid(string word) {
    ll n = word.size();
    
    if(n < 3)
        return false;
    
    ll vow = 0, consonant = 0, num = 0;
    
    for(auto i: word) {
        if(isVowel(i))
            vow++;
        
        else if(i >= 'a' && i <= 'z')
            consonant++;
        else if(i >= 'A' && i <= 'Z')
            consonant++;
        
        else if(i >= '0' && i <= '9')
            num++;
        
        else
            return false;
    }
    
    return (vow > 0 && consonant > 0);
}

int minimumOperationsToMakeKPeriodic(string s, int k) {
    map<string,ll> mp;
    string tmp;
    for(ll i = 0;i<s.size();++i){
        if(!(i%k)){
            mp[tmp]++;
            tmp.clear();
        }else{
        }
        tmp += s[i];
    }
    mp[tmp]++;
    
    ll freq = 0;
    for(auto it:mp){
        freq = max(freq,it.second);
    }
    ll n = s.size();
    return (n/k)-freq;
}

int minAnagramLength(string s) {
    map<char,ll> mp;
    for(auto &it:s){
        mp[it]++;
    }
    
    ll g = 0;
    for(auto &it:mp){
        g = __gcd(it.second,g);
    }
    // cout<<gcd<<endl;
    ll ans = 0;
    for(auto &it:mp){
        ans += it.second/g;
    }
    return ans;
}

ll solve(vector<ll> &v, ll sm, ll inc, ll c1, ll c2){ // v is diff array
    // Total we need to club up to reach (mx+inc) that will be sm + (n*inc)
    ll n = v.size();
    ll needed = sm + (n*inc);
    ll mx_reach = v[n-1]+inc;

    ll sa = needed*c1;
    // Consider the case when we need to increment only one index for all other indices like 
    // INC ARRAY = {7,2,2,0}  => So, anytime we need to decrement this 7 we can only use 2+2 = 4 
    // but for other 3 ops we need to use c1
    ll other_than_last_ele = sm+(n)*inc-mx_reach;
    ll sa2 = 0;
    if(other_than_last_ele < mx_reach){
        // Perform c2 ops :
        sa2 += c2*(other_than_last_ele);
        // Later perform c1 ops : 
        sa2 += c1*(mx_reach-other_than_last_ele);
    }else{
        sa2 += (needed/2)*c2+(needed%2)*c1;
    }
    return min(sa,sa2); 
}

int minCostToEqualizeArray(vector<ll>& v, int c1, int c2) {
    ll n = v.size(),mx = *max_element(all(v)),ans = 0;
    sort(all(v));
    vector<ll> diff;
    for(auto it:v){diff.push_back(mx-it);}

    sort(all(diff));
    ll sm = accumulate(all(diff),0ll);

    ans = solve(diff,sm,0,c1,c2);
    for(ll inc = 1;inc <= 1e6;++inc){
        ans = min(ans,solve(diff,sm,inc,c1,c2));
    }
    return (ans%mod);
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