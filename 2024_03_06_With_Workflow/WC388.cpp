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
int minimumBoxes(vector<int>& v, vector<int>& t) {
    ll sm = accumulate(all(v),0ll);
    sort(all(t));
    reverse(all(t));
    ll ans = 0;
    for(auto it:t){
        sm -= it;
        ++ans;
        if(sm <= 0){
            break;
        }
    }
    return ans;
}

long long maximumHappinessSum(vector<int>& v, int k) {
    sort(all(v));
    ll ans = 0,cntr = 0;
    for(ll i = v.size()-1;i>=0;--i){
        if(cntr == 1ll*k){break;}
        ans += max(0ll,1ll*v[i]-cntr);
        ++cntr;
    }
    return ans;
}

vector<string> shortestSubstrings(vector<string>& v) {
    ll n = v.size();
    map<string,ll> mp;
    for(ll i = 0;i<n;++i){
        string s = v[i];
        ll sz = s.size();
        forj(sz){
            string tmp;
            for(ll k = j;k<sz;++k){
                tmp += s[k];
                mp[tmp]++;
            }
        }
    }
    
    vector<string> ans;
    for(ll i = 0;i<n;++i){
        // Remove its occurences
        string s = v[i];
        ll sz = s.size();
        forj(sz){
            string tmp;
            for(ll k = j;k<sz;++k){
                tmp += s[k];
                mp[tmp]--;
            }
        }
        
        // Check if its substring in any other string
        string sa = s;sa += 'a';
        
        forj(sz){
            string tmp;
            for(ll k = j;k<sz;++k){
                tmp += s[k];
                if(mp[tmp] == 0){
                    if(tmp.size() < sa.size()){
                        sa = tmp;
                    }else if(tmp.size() == sa.size()){
                        sa = min(sa,tmp);
                    }
                }
            }
        }
        
        if(sa.size() > s.size()){
            sa.clear();
            ans.push_back(sa);
        }else{
            ans.push_back(sa);
        }

        // Add Freq Back
        forj(sz){
            string tmp;
            for(ll k = j;k<sz;++k){
                tmp += s[k];
                mp[tmp]++;
            }
        }
    }
    return ans;
}    

ll n;
vector<ll> v;
vector<vector<vector<vector<ll>>>> dp;

ll recur(ll idx,ll k,ll f,ll cntr){
    if(idx == n){
        if(k){return LLONG_MIN;}
        return 0;
    }

    ll &sa = dp[idx][k][f][cntr];
    if(sa != -1){return sa;}

    sa = 0;
    if(!f){
        // We can start the array 
        ll a = 0,ab = 0;
        if(k > 0){
            if(cntr){
                a = recur(idx+1,k,1,cntr)-(k*v[idx]);
            }else{
                a = k*v[idx]+recur(idx+1,k,1,cntr);
            }

            // Also we can end array here itself
            if(cntr){
                ab = recur(idx+1,k-1,0,cntr^1)-(k*v[idx]);
            }else{
                ab = k*v[idx]+recur(idx+1,k-1,0,cntr^1);
            }
        }

        // we can simply skip the element
        ll b = recur(idx+1,k,0,cntr);
        sa = max({a,ab,b});
    }else{
        // We can end the array
        ll a = 0;
        if(cntr){
            a = recur(idx+1,k-1,0,cntr^1)-(k*v[idx]);
        }else{
            a = k*v[idx]+recur(idx+1,k-1,0,cntr^1);
        }

        // Pick and pass to next
        ll b = v[idx]*k+recur(idx+1,k,f,cntr);
        sa = max(a,b);
    }
    return sa;
}

long long maximumStrength(vector<int>& tmp, int k) {
    for(auto it:tmp){
        v.push_back(1ll*it);
    }
    n = v.size();
    dp.assign(n+5, vector<vector<vector<ll>>> (k+5, vector<vector<ll>> (3, vector<ll> (3,-1))));
    for(ll i = 0;i<n;++i){
        forj(k){
            cout<<dp[i][j][0][0]<<" "<<dp[i][j][0][1]<<" "<<dp[i][j][1][0]<<" "<<dp[i][j][1][1]<<endl;
        }
    }

    ll ans = recur(0,k,0,0);
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