#include<bits/stdc++.h>
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
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
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
vector<int> leftRigthDifference(vector<int>& nums) {
    ll n = nums.size();
    ll sm = accumulate(all(nums),0ll);
    vector<int> right(n,0);
    vector<int> left(n,0);
    vector<int> ans(n,0);
    ll lft = 0;
    for(ll i = 0;i<n;++i){
        left[i] = lft;
        lft += nums[i];
        sm -= nums[i];
        right[i] = sm;
    }

    for(ll i = 0;i<n;++i){
        ans[i] = abs(left[i]-right[i]);
    }
    return ans;
}

bool check(string &n, long long k) {
    long long rem = 0;
    for (auto i : n)
        rem = ((rem * 10) + i - '0') % k;
    return rem == 0;
}

vector<int> divisibilityArray(string s, int m) {
    ll ans = 0;
    vector<int> div(s.size(),0);
    for(ll i=0;i<s.size();++i){
        ans = ((ans*10) + (s[i]-'0'))%m;
        if(ans == 0){
            div[i] = 1;
        }
    }
    return div;
}

int maxNumOfMarkedIndices(vector<int>& v) {
    sort(all(v));
    ll n = v.size();
    vector<ll> half;
    ll ans = 0;half.clear();
    vector<ll> tmp;
    if(n & 1){
        for(ll i = n/2;i<v.size();++i){
            tmp.push_back(v[i]);
            half.push_back(v[i]/2);
        }
        // show(tmp);
        // cout<<endl;

        ll i = 0,j = 0;
        while(j <= n/2){
            if(v[i] <= half[j]){
                // cout<<v[i]<<" -> "<<tmp[j]<<endl;
                ans += 2;
                ++i;
            }
            if(i == n/2){break;}
            ++j;
        }
    }else{
        for(ll i = n/2;i<v.size();++i){
            half.push_back(v[i]/2);
        }

        ll i = 0,j = 0;
        while(j < half.size()){
            if(v[i] <= half[j]){
                ans += 2;
                ++i;
            }
            ++j;
        }
    }
    return ans;
}

ll n,m;
bool issafe(ll i,ll j){
    if(i >=n||j>=m||i<0||j<0){return 0;}return 1;
}

ll bfs(ll i,ll j,vector<vector<int>> &v){
    queue<pair<ll,ll>> q;
    q.push({i,j});
    ll lvl = 0;
    vector<vector<ll>> vis(n+1,vector<ll> (m+1,0));
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        if(p.first == n-1 and p.second == m-1){
            return lvl;
        }

        if(issafe(i+1,j)){
            if(v[i+1][j] <= lvl){
                q.push({i+1,j});
            }
        }

        // if(issafe(i-1,j) and !vis[i-1][j]){
        if(issafe(i-1,j)){
            if(v[i-1][j] <= lvl){
                q.push({i-1,j});
            }
        }

        // if(issafe(i,j+1) and !vis[i][j+1]){
        if(issafe(i,j+1)){
            if(v[i][j+1] <= lvl){
                q.push({i,j+1});
            }
        }

        // if(issafe(i,j-1) and !vis[i][j-1]){
        if(issafe(i,j-1)){
            if(v[i][j-1] <= lvl){
                q.push({i,j-1});
            }
        }

        ++lvl;
    }
    return -1;
}

int minimumTime(vector<vector<int>>& v) {
    n = v.size(),m = v[0].size();
    if(v[0][1] > 1 and v[1][0] > 1){
        return -1;
    }
    // return bfs(0,0,v);

    vector<vector<ll>> vis(n+1,vector<ll> (m+1,m+n+m));    
    for(ll i = n-1;i>=0;--i){
        for(ll j = m-1;j>=0;--j){
            if(i == n-1 and j == m-1){
                vis[i][j] = 0;
            }else{
                ll sa = LLONG_MAX;
                if(issafe(i+1,j)){
                    ll ok = (v[i+1][j]-v[i][j]);
                    if(ok <= 0){
                        ok = 1;
                    }else{
                        if(ok & 1){
                            ok += 1;
                        }
                    }
                    ok += vis[i+1][j];
                    sa = min(sa,ok);
                }

                if(issafe(i,j+1)){
                    ll ok = (v[i][j+1]-v[i][j]);
                    if(ok <= 0){
                        ok = 1;
                    }else{
                        if(ok & 1){
                            ok += 1;
                        }
                    }
                    ok += vis[i][j+1];
                    sa = min(sa,ok);
                }
                vis[i][j] = sa;
            }
        }
    }

    
    // for(ll i = 0;i<n;++i){
    //     forj(m){
    //         cout<<vis[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;
    return vis[0][0];
}

void solve()
{
    ll n;cin>> n;
    vector<int> v(n);
    enter(v);
    // while(1){
    //     int i;cin>>i;
    //     if(i == -1){
    //         break;
    //     }
    //     v.push_back(i);
    // }
    // cout<<v.size()<<endl;
    // show(v);
    cout<<maxNumOfMarkedIndices(v)<<endl;
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
    return;
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