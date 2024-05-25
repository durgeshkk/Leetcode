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
int findPermutationDifference(string s, string t) {
    map<char,ll> mp;       
    ll n = s.size();
    for(ll i = 0;i<n;++i){
        mp[s[i]] = (i);
    }

    ll ans = 0;
    for(ll i = 0;i<n;++i){
        ans += abs(i-mp[t[i]]);
    }
    return ans;
}

int maximumEnergy(vector<int>& v, int k) {
    ll n = v.size(),ans = -1e9;
    vector<ll> tmp;
    for(ll i = 0;i<k;++i){
        ll idx = i,sm = 0;
        while(idx < n){
            sm += v[idx];
            idx += k;
        }
        tmp.push_back(sm);
        ans = max(ans,sm);
    }

    for(ll i = 0;i<n-k;++i){
        ll idx = (i%k);
        tmp[idx] -= v[i];
        ans = max(ans,tmp[idx]);
    }
    return ans;
}

int maxScore(vector<vector<int>>& v) {
    int n = v.size(),m = v[0].size();
    vector<vector<int>> maxi(n,vector<int>(m,0));
    for(ll i = n-1;i>=0;--i){
        for(ll j = m-1;j>=0;--j){
            int x = 0;
            if(i < n-1){
                x = max({x,maxi[i+1][j],v[i+1][j]});
            }
            if(j < m-1){
                x = max({x,maxi[i][j+1],v[i][j+1]});
            }
            maxi[i][j] = x;
        }
    }

    int ans= -3e5;
    for(ll i = n-1;i>=0;--i){
        for(ll j = m-1;j>=0;--j){
            if(i == n-1 and j == m-1){continue;}
            ans = max(ans,maxi[i][j]-v[i][j]);
        }
    } 
    return ans;    
}

// TLE For a Reason : RECURSION
/*
vector<ll> ans;

void dfs(vector<ll> &perm, vector<bool> &used, ll curr_cst,vector<ll> &v, ll &mn_cst){
    ll n = v.size();
    if (perm.size() == n){
        ll final_cost = curr_cst + abs(perm.back() - v[perm[0]]);
        if (final_cost < mn_cst){
            mn_cst = final_cost;
            ans = perm;
        }
        return;
    }

    for (ll i = 0; i < n; ++i){
        if (!used[i]){
            if (!perm.empty()){
                ll next_cost = curr_cst + abs(perm.back() - v[i]); // for the last v[perm[i+1]] is i 
                if (next_cost < mn_cst)
                {
                    used[i] = 1;
                    perm.push_back(i);
                    dfs(perm, used, next_cost, v, mn_cst);
                    perm.pop_back();
                    used[i] = 0;
                }
            }
            else
            {
                used[i] = 1;
                perm.push_back(i);
                dfs(perm, used, 0, v, mn_cst);
                perm.pop_back();
                used[i] = 0;
            }
        }
    }
}

vector<ll> findPermutation(vector<ll> &v){
    ll n = v.size();
    ll mn_cst = INT_MAX;

    vector<bool> used(n, 0);
    vector<ll> perm;

    dfs(perm, used, 0, v, mn_cst);
    return ans;
}
*/

ll n,min_score;
vector<ll> perm;
vector<ll> ans;

ll getScore(ll i, vector<ll>& v){
    if(i < perm.size()-1){
        return abs(perm[i] - v[perm[i+1]]);
    }else{
        return abs(perm[perm.size()-1] - v[perm[0]]);
    }
}

void run(ll idx, ll score, ll bitmask, vector<ll>& v){
    n = v.size();
    if(idx > 0){
        score += getScore(idx-1,v);
    }

    if(idx == perm.size()-1){
        score += getScore(idx,v);
        if(score < min_score){
            min_score = score;
            ans = perm;
        }
        return;
    }

    if(score >= min_score){
        return;
    }
    
    idx++;
    for(ll i=0, cur=1; i<perm.size(); ++i){
        if(bitmask & cur){
            (cur <<= 1);
            continue;
        }
            
        perm[idx] = i;
        run(idx, score, bitmask|cur, v);
        (cur <<= 1);
    }
}

vector<ll> findPermutation(vector<ll>& v) {
    min_score = INT_MAX;perm.clear();ans.clear();

    for(ll i=0; i<v.size(); i++){
        perm.push_back(i);
    }

    run(0, 0, 1, v);    

    return ans;
}


void solve(){
    ll n;cin>>n;
    vector<ll> v(n);enter(v);

}

int main()
{
    ios_base::sync_with_stdio(0);
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