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
int numberOfSpecialChars(string s) {
    multiset<ll> st;  ll ans=  0;
    vector<ll> first,last;
    vector<ll> freq1,freq2;
    for(char j = 'a';j<='z';++j){
        ll cntr = 0,idx = -1;
        for(ll i = 0;i<s.size();++i){ 
            if(s[i] == j){
                idx = i;++cntr;
            }
        }
        first.push_back(idx);
        freq1.push_back(cntr);
    }

    for(char j = 'A';j<='Z';++j){
        ll cntr = 0,idx = -1;
        for(ll i = 0;i<s.size();++i){ 
            if(s[i] == j){
                ++cntr;
            }
        }
        freq2.push_back(cntr);
    }

    for(char j = 'A';j<='Z';++j){
        ll cntr = 0,idx = -1;
        for(ll i = 0;i<s.size();++i){ 
            if(s[i] == j){
                idx = i;break;
            }
        }
        last.push_back(idx);
    }

    for(ll i = 0;i<26;++i){
        if(first[i] == -1 || last[i] == -1){continue;}
        if(first[i] < last[i]){
            ll x = min(freq1[i],freq2[i]);
            if(x){++ans;}
        }
    }

    return ans;
}

ll n,m;
vector<vector<ll>> mp,dp;
ll recur(ll idx, ll prev){
    if(idx == m){return 0;}
    if(prev != -1 and dp[idx][prev] != -1){return dp[idx][prev];}

    ll sa = 1e8;
    for(ll i = 0;i<=9;++i){
        if(i == prev){
        }else{
            sa = min(sa,mp[i][idx]+recur(idx+1,i));
        }
    }
    return dp[idx][prev] = sa;
}
int minimumOperations(vector<vector<int>>& v) {
    n = v.size(),m = v[0].size();
    mp.assign(11,vector<ll> (v[0].size(),0));
    mp.assign(n+5,vector<ll> (11,-1));
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            mp[v[i][j]][j]++;
        }
    }
    return recur(0,-1);
}

// void dijkstra(ll src){
//     dist[src] = 0;
//     s.insert({0,src});
//     while(!s.empty()){
//         auto p = *s.begin();s.erase(s.find(p));vis[p.second] = 1;
//         for(auto it:adj[p.second]){
//             if(!vis[it.first]){
//                 ll new_dist = (p.first+it.second);
//                 if(new_dist < dist[it.first]){
//                     s.erase(s.find({dist[it.first],it.first}));
//                     s.insert({new_dist,it.first});
//                     dist[it.first] = new_dist;
//                 }
//             }
//         }
//     }

//     vis.assign(n+1,0);
//     dist.assign(n+1,1e12);
//     for(ll i=0;i<edges;i++){
//         s.insert({1e12,i});// Initially all at max. dist
//         ll u = edges[i][0],v= edges[i][1],cst= edges[i][2];
//         adj[u].push_back({v,cst});adj[v].push_back({u,cst});
//     }  
//     dijkstra(0);
//     show(dist);
// }   

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