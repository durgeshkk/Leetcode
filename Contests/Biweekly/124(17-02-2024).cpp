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
int maxOperations(vector<int>& v) {
    ll sm = -1,ans = 0;
    for(ll i = 0;i<v.size();i+=2){
        if(i+1<v.size()){
            ll ele = v[i]+v[i+1];
            if(sm == -1){
                sm = ele;
                ++ans;
            }else{
                if(sm == ele){++ans;}
                else{break;}
            }
        }
    }
    return ans;
}

string lastNonEmptyString(string s) {
    ll n = s.size(),mx = 0;
    map<char,ll> mp;
    for(auto it:s)  {
        mp[it]++;
        mx = max(mx,mp[it]);
    }
    set<char> st;
    for(auto it:mp){
        if(it.second == mx){
            st.insert(it.first);
        }
    }

    string ans;
    for(ll i = n-1;i>=0;--i){
        if(st.find(s[i]) != st.end()){
            ans += s[i];
            st.erase(st.find(s[i]));
        }
    }
    reverse(all(ans));
    return ans;
}

vector<vector<ll>> dp; 
ll recur(vector<int> &v,ll i,ll j,ll &sm){
    if(i>=j){return 0;}
    ll &sa = dp[i][j];
    if(sa != -1){return sa;}
    sa = 0;
    if(v[i]+v[j] == sm){
        sa = 1+recur(v,i+1,j-1,sm);
    }
    if(v[i]+v[i+1] == sm){
        sa = max(sa,1+recur(v,i+2,j,sm));
    }
    if(v[j]+v[j-1] == sm){
        sa = max(sa,1+recur(v,i,j-2,sm));
    }
    return sa;
}

int maxOperations(vector<int>& v) {
    ll n = v.size();
// dp.assign(n+1,vector<ll> (n+1,-1));
    set<ll> s;
    s.insert(v[0]+v[1]);
    s.insert(v[0]+v[n-1]);
    s.insert(v[n-2]+v[n-1]);
    ll ans = 0;
    for(auto it:s){
        dp.assign(n+1,vector<ll> (n+1,-1));
        // cout<<it<<" ";
        ans = max(ans,recur(v,0,n-1,it));
    }
    return ans;
}


// Failed Approach :
/*

int maxSelectedElements(vector<int>& v) {
    ll n = v.size();
    dp.assign(n+1,vector<ll> (n+1,-1));
    set<ll> s;
    s.insert(v[0]+v[1]);
    s.insert(v[0]+v[n-1]);
    s.insert(v[n-2]+v[n-1]);
    ll ans = 0;
    for(auto it:s){
        ans = max(ans,recur(v,0,n-1,it));
    }
    return ans;
}

int maxSelectedElements(vector<int>& v) {
    ll mx = *max_element(all(v));
    vector<ll> freq(mx+5,0);
    for(auto it:v){freq[it]++;}
    ll ex = 0,sa = 0,ans = 0;
    forj(mx+2){
        if(!j){continue;}
        if(freq[j]){
            ++sa;
            ex = max(1ll,freq[j]-1);
        }
        else{
            if(ex){
                ex = 0;++sa;
            }else{
                ans = max(ans,sa);
                sa = 0;
            }
        }
    }
    return ans;
    
    map<ll,ll> mp;
    vector<ll> tmp;
    for(auto it:mp){
        tmp.push_back(it.first);
    }

    vector<vector<ll>> grps;
    vector<ll> dk;dk.push_back(tmp[0]);
    for(ll j = 1;j<tmp.size();++j){
        if(tmp[j] == 1+tmp[j-1]){
            dk.push_back(tmp[j]);
        }else{
            grps.push_back(dk);
            dk.clear();dk.push_back(tmp[j]);
        }
    }

    if(!dk.empty()){
        grps.push_back(dk);
    }

    ll ans = 0;
    vector<pair<ll,ll>> mv;
    for(auto it:grps){
        vector<ll> dk = it;
        ll freq = 0,sa = dk.size();
        for(auto x:dk){
            freq += min(2ll,mp[x]);
        }
        if(freq > dk.size()){
            mv.push_back({dk[0],1+dk[dk.size()-1]});
            ans = max(ans,sa+1);
        }else{
            mv.push_back({dk[0],dk[dk.size()-1]});
            ans = max(ans,sa);
        }
    }

    vector<ll> till;
    till.push_back(mv[0].second-mv[0].first);
    for(ll i = 1;i<mv.size();++i){
        ll sa = 0;
        auto p = mv[i-1],p1 = mv[i];
        if(p1.first == p.second+2){
            till.push_back(mv[i].second-mv[i].first+mv[i-1].second-mv[i-1].first);
        }else if(p1.first == p.second+1){
            till.push_back(mv[i].second-mv[i].first+till[till.size()-1]);
        }else{
            till.push_back(mv[i].second-mv[i].first);
        }
    }
    for(auto it:till){
        ans = max(ans,it);
    }
    return ans;
}

*/

// Failed TC : 
/*
[2,1,5,1,1]
[1,4,7,10]
[5]
[8,10,6,12,8,12,2,3,13,19,11,18,10,16,5,7]
[8,10,6,12,9,12,2,3,13,19,11,18,10,16]
*/
int maxSelectedElements(vector<int>& v) {
    ll mx = *max_element(all(v)),ans = 0;
    vector<ll> freq(mx+15,0);
    for(auto it:v){freq[it]++;}
    // show(freq);
    sort(all(v));
    map<ll,ll> mp;
    for(auto it:v){
        ll same = max(mp[it],1+mp[it-1]);
        ll inc = max(1+mp[it],mp[it+1]);
        ans = max({ans,same,inc});
        mp[it] = same;
        mp[it+1] = inc;
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