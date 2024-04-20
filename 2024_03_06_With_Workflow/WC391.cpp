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

int sumOfTheDigitsOfHarshadNumber(int x) {
    int y = x,cntr = 0;
    while(y != 0){
        cntr += (y % 10);
        y /= 10;
    }

    if(x%cntr){return -1;}
    return cntr;
}

int maxBottlesDrunk(int numBottles, int numExchange) {
    int ans = numBottles;
    while(numBottles >= numExchange){
        numBottles -= numExchange;
        numExchange++;
        numBottles++;
        ans++;
    }
    return ans;
}

long long countAlternatingSubarrays(vector<int>& v) {
    ll ans = 0,n = v.size();
    for(ll i = 0;i<n;++i){
        ll curr = v[i],j = i+1;
        while((j<n) and ((1ll*v[j])^curr == 1)){
            ++j;
            curr ^= 1;
        }
        ll ele = (j-i);
        ans+=(ele*(ele+1)/2);
        i = j-1;
    }
    return ans;
}

// [[1,1],[1,1],[1,1]]
// [[5,3],[4,6],[2,4],[1,8],[3,9],[1,6]]

int minimumDistance(vector<vector<int>>& v) {
    sort(all(v));
    ll dist = 0,x1 = 0,y1 = 0,x2 = 0,y2 = 0,n = v.size();

    set<vector<int>> contri;

    dist = abs(v[n-1][0]-v[0][0])+abs(v[n-1][1]-v[0][1]);
    for(ll i = 0,j = 0;i<n;++i){
        while(j<n and (abs(v[j][0]-v[i][0])+abs(v[j][1]-v[i][1])) <= dist){
            ++j;
        }
        ll sa = (abs(v[j-1][0]-v[i][0])+abs(v[j-1][1]-v[i][1]));
        if(dist == sa){
            contri.insert(v[i]);
            contri.insert(v[j]);
        }else if(dist < sa){
            contri.clear();
            contri.insert(v[i]);
            contri.insert(v[j]);
            dist = sa;
        }
    }

    vector<ll> tmp;
    for(auto it:contri){
        ll cntr = 0,x = it[0],y = it[1],sa = 0;
        for(auto it:v){
            if(x == it[0] and y == it[1] and !cntr){++cntr;continue;}
            sa = max(sa,abs(it[0]-x)+abs(it[1]-y));
        }
        tmp.push_back(sa);
    }
    sort(all(tmp));
    return tmp[0];

    x1 = v[1][0],y1 = v[1][1];
    for(ll i = 2;i<n;++i){
        auto it = v[i];
        ll sa = abs(it[0]-x1)+abs(it[1]-y1);
        if(sa >= dist){
            x2 = it[0],y2 = it[1];
            dist = sa;
        }
    }

    ll x = v[n-2][0],y = v[n-2][1];
    for(ll i = 0;i<n-2;++i){
        auto it = v[i];
        ll sa = abs(it[0]-x)+abs(it[1]-y);
        if(sa >= dist){
            x2 = it[0],y2 = it[1];
            x1 = v[n-2][0],y = v[n-2][1];
            dist = sa;
        }
    }

    for(auto &it:v){swap(it[0],it[1]);}
    sort(all(v));
    for(auto &it:v){swap(it[0],it[1]);}
    
    x = v[1][0],y = v[1][1];
    for(ll i = 2;i<n;++i){
        auto it = v[i];
        ll sa = abs(it[0]-x)+abs(it[1]-y);
        if(sa >= dist){
            x2 = it[0],y2 = it[1];
            x1 = v[1][0],y1 = v[1][1];
            dist = sa;
        }
    }

    x = v[n-2][0],y = v[n-2][1];
    for(ll i = 0;i<n-2;++i){
        auto it = v[i];
        ll sa = abs(it[0]-x)+abs(it[1]-y);
        if(sa >= dist){
            x2 = it[0],y2 = it[1];
            x1 = v[n-1][0],y1 = v[n-1][1];
            dist = sa;
        }
    }

    return dist;

    ll ans = dist;
    // If (x1,y1) is removed
    ll cntr = 0,dk = 0;
    for(auto it:v){
        if(x1 == it[0] and y1 == it[1] and !cntr){++cntr;continue;}

        ll sa = abs(it[0]-x2)+ abs(it[1]-y2);
        dk = max(dk,sa);
    }

    // If (x2,y2) is removed
    cntr = 0;
    for(auto it:v){
        if(x2 == it[0] and y2 == it[1] and !cntr){++cntr;continue;}

        ll sa = abs(it[0]-x1)+ abs(it[1]-y1);
        dk = max(dk,sa);
    }
    ans = dk;
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

//     sort(all(v));
//     vector<ll> tmp;
//     ll dist = 0,x1 = 0,y1 = 0,x2 = 0,y2 = 0,n = v.size();
//     x1 = v[1][0],y1 = v[1][1];
//     for(ll i = 2;i<n;++i){
//         auto it = v[i];
//         ll sa = abs(it[0]-x1)+abs(it[1]-y1);
//         if(sa >= dist){
//             x2 = it[0],y2 = it[1];
//             dist = sa;
//         }
//     }
//     tmp.push_back(dist);
    
    
//     ll x = v[n-2][0],y = v[n-2][1];
//     dist = 0;
//     for(ll i = 0;i<n-2;++i){
//         auto it = v[i];
//         ll sa = abs(it[0]-x)+abs(it[1]-y);
//         if(sa >= dist){
//             x2 = it[0],y2 = it[1];
//             x1 = v[n-2][0],y = v[n-2][1];
//             dist = sa;
//         }
//     }
//     tmp.push_back(dist);

//     for(auto &it:v){swap(it[0],it[1]);}
//     sort(all(v));
//     for(auto &it:v){swap(it[0],it[1]);}
    
//     x = v[1][0],y = v[1][1];
//     dist = 0;
//     for(ll i = 2;i<n;++i){
//         auto it = v[i];
//         ll sa = abs(it[0]-x)+abs(it[1]-y);
//         if(sa >= dist){
//             x2 = it[0],y2 = it[1];
//             x1 = v[1][0],y1 = v[1][1];
//             dist = sa;
//         }
//     }
//     tmp.push_back(dist);

//     x = v[n-2][0],y = v[n-2][1];
//     dist = 0;
//     for(ll i = 0;i<n-2;++i){
//         auto it = v[i];
//         ll sa = abs(it[0]-x)+abs(it[1]-y);
//         if(sa >= dist){
//             x2 = it[0],y2 = it[1];
//             x1 = v[n-1][0],y1 = v[n-1][1];
//             dist = sa;
//         }
//     }
//     tmp.push_back(dist);
//     sort(all(tmp));
//     dist = tmp[0];

//     return dist;
    
// //         sort(all(v));
// //     ll dist = 0,x1 = 0,y1 = 0,x2 = 0,y2 = 0,n = v.size();
// //     x1 = v[0][0],y1 = v[0][1];
// //     for(auto it:v){
// //         ll sa = abs(it[0]-x1)+abs(it[1]-y1);
// //         if(sa >= dist){
// //             x2 = it[0],y2 = it[1];
// //             dist = sa;
// //         }
// //     }

// //     ll x = v[n-1][0],y = v[n-1][1];
// //     for(auto it:v){
// //         ll sa = abs(it[0]-x)+abs(it[1]-y);
// //         if(sa >= dist){
// //             x2 = it[0],y2 = it[1];
// //             x1 = v[n-1][0],y1 = v[n-1][1];
// //             dist = sa;
// //         }
// //     }

// //     for(auto &it:v){swap(it[0],it[1]);}
// //     sort(all(v));
// //     for(auto &it:v){swap(it[0],it[1]);}
    
// //     x = v[0][0],y = v[0][1];
// //     for(auto it:v){
// //         ll sa = abs(it[0]-x)+abs(it[1]-y);
// //         if(sa >= dist){
// //             x2 = it[0],y2 = it[1];
// //             x1 = v[0][0],y1 = v[0][1];
// //             dist = sa;
// //         }
// //     }

// //     x = v[n-1][0],y = v[n-1][1];
// //     for(auto it:v){
// //         ll sa = abs(it[0]-x)+abs(it[1]-y);
// //         if(sa >= dist){
// //             x2 = it[0],y2 = it[1];
// //             x1 = v[n-1][0],y1 = v[n-1][1];
// //             dist = sa;
// //         }
// //     }

// //     ll ans = dist;
// //     // If (x1,y1) is removed
// //     ll cntr = 0,dk = ans+1;
// //     for(auto it:v){
// //         if(x1 == it[0] and y1 == it[1] and !cntr){++cntr;continue;}

// //         ll sa = abs(it[0]-x2)+ abs(it[1]-y2);
// //         dk = max(dk,sa);
// //     }

// //     // If (x2,y2) is removed
// //     cntr = 0;
// //     for(auto it:v){
// //         if(x2 == it[0] and y2 == it[1] and !cntr){++cntr;continue;}

// //         ll sa = abs(it[0]-x1)+ abs(it[1]-y1);
// //         dk = max(dk,sa);
// //     }
// //     ans = dk;
// //     return ans;