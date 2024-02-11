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
vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
    vector<vector<int>> ans(matrix);
    ll n = ans.size(),m = ans[0].size();
    for(ll j = 0;j<m;++j){
        int mx = -2;
        for(ll i = 0;i<n;++i){
            mx = max(mx,ans[i][j]);
        }

        for(ll i = 0;i<n;++i){
            if(ans[i][j] == -1){
                ans[i][j] = mx;
            }
        }
    }
    return ans;
}

ll ans;

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(vector<int> pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if (len != 0) {
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(vector<int> pat, vector<int> txt)
{
    int M = pat.size();
    int N = txt.size();
 
    int lps[M];
 
    computeLPSArray(pat, M, lps);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            ++ans;
            j = lps[j - 1];
        }
 
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
 
int countMatchingSubarrays(vector<int>& v, vector<int>& t) {
    int m = t.size(),n = v.size();ans = 0;
    vector<int> txt;
    for(ll i = 1;i<n;++i){
        int x = 0;
        if(v[i] > v[i-1]){
            x = 1;
        }else if(v[i] == v[i-1]){
        }else{
            x = -1;
        }
        txt.push_back(x);
    }

    KMPSearch(t,txt);
    return ans;
}

int maxPalindromesAfterOperations(vector<string>& v) {
    ll n = v.size(),ans = n;
    vector<ll> tmp;

    multiset<ll> odd,even;

    map<ll,ll> mp;
    for(ll i = 0;i<n;++i){
        string s = v[i];
        for(auto it:s){
            mp[it]++;
        }
        if(s.size()%2){odd.insert(s.size());}
        else{even.insert(s.size());}
    }
    
    for(auto &it:mp){
        if(it.second & 1){
            if(odd.size()){
                --it.second;
                ll ele = *odd.rbegin();
                odd.erase(odd.find(ele));
                --ele;
                if(ele){
                    even.insert(ele);
                }
            }
        }
    }

    for(auto it:even){
        tmp.push_back(it);
    }
    for(auto it:odd){
        tmp.push_back(it);
    }

    sort(all(tmp));
    vector<ll> dk(tmp);

    ll j = tmp.size()-1,f = 0;
    for(auto it:mp){
        if(it.second & 1){
            if(!tmp[j]){
                --j;
            }
            tmp[j]--;
        }
    }

    for(ll i = 0;i<tmp.size();++i){
        if(tmp[i] != dk[i]){--ans;}
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