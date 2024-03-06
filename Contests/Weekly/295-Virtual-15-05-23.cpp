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
int rearrangeCharacters(string s, string target) {
    map<ll,ll> need,mp;
    for(auto it:target){need[it]++;}
    for(auto it:s){mp[it]++;}

    ll mn = INT_MAX;
    for(auto it:need){
        ll req = it.second;
        ll have = mp[it.first];
        ll frm = have/req;
        mn = min(mn,frm);
    }
    return mn;
}
/*
string discountPrices(string s, int discount) {
    string ans;
    ll n = s.size();
    for(ll i = 0;i<n;++i){
        if(s[i] == '$'){
            ans += s[i];
            ++i;
            string val;
            while(i<n and (s[i] >='0' and s[i] <='9')){
                val += s[i];
                ++i;
            }
            if(i == n){
                ll ele = stoll(val);
                ll new_val = 
            }else{
                if(s[i] == ' '){

                }else{
                }
            }
            --i;
        }else{
            ans += s[i];
        }
    }
}
*/

double round(double var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}

string discountPrices(string s, int discount) {
    string ans,tmp;
    ll n = s.size();
    for(ll i = 0;i<n;++i){
        if(s[i] == ' '){
            if(tmp.size() <= 11){
                if(tmp[0] == '$'){
                    ll f = 1;
                    string ak;
                    for(ll j = 1;j<tmp.size();++j){
                        if(tmp[j] <= '9' and tmp[j] >='0'){
                            ak += tmp[j];
                        }else{f = 0;}
                    }

                    if(f){
                        long double num = stold(tmp);
                        num -= num*discount*0.01;
                        num = abs(num);
                        string st = to_string(num);
                        st.pop_back();
                        st.pop_back();
                        st.pop_back();
                        st.pop_back();
                        ans += st;
                    }else{
                        ans += tmp;
                    }
                }else{
                    ans += tmp;
                }
            }else{
                ans += tmp;
            }
            ans += ' ';
            tmp = "";
        }else{
            tmp += s[i];
        }
    }

    if(tmp.size() <= 11){
        if(tmp[0] == '$'){
            ll f = 1;
            string ak;
            for(ll j = 1;j<tmp.size();++j){
                if(tmp[j] <= '9' and tmp[j] >='0'){
                    ak += tmp[j];
                }else{f = 0;}
            }

            if(f){
                long double num = stold(tmp);
                num -= num*discount*0.01;
                num = abs(num);
                string st = to_string(num);
                st.pop_back();
                st.pop_back();
                st.pop_back();
                st.pop_back();
                ans += st;
            }else{
                ans += tmp;
            }
        }else{
            ans += tmp;
        }
    }else{
        ans += tmp;
    }

    return ans;
}  


int totalSteps(vector<int>& v) {
    ll ans = 0,mx = 0;
    ll n = v.size();vector<int> vis(n+1,0);
    ll curr = v[0];
    for(ll i = 1;i<n;++i){
        if(v[i] >= curr){
            curr = v[i];
            vis[i] = 1;
        }
    }

    ll f = 0;
    for(ll i = 1;i<n;++i){
        if(vis[i]){
            if(f){
                ans = max(ans,mx+1);
            }else{
                ans = max(ans,mx);
            }
            mx = 0;
        }else{
            if(v[i] >= v[i-1]){
                ++mx;
            }else{
            }
            f = 1;
        }
    }

    if(f){
        ans = max(ans,mx+1);
    }else{
        ans = max(ans,mx);
    }
    return ans;
}

// Upsolve :
ll n,m;
vector<vector<ll>> v,vis,dp;
bool issafe(ll i,ll j){
    if(i >=n || j>=m || i<0 || j<0){return 0;}
    return 1;
}

vector<pair<ll,ll>> coor = {{1,0},{0,1},{-1,0},{0,-1}};
ll bfs(){
    queue<pair<ll,ll>> q;
    q.push({0,0});
    vis[0][0] = 1;
    dp[0][0] = v[0][0];

    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            auto p = q.front();q.pop();
            ll x = p.first,y = p.second;
            for(auto it:coor){
                ll nx = x+it.first,ny = y+it.second;
                if(issafe(nx,ny) and dp[x][y]+v[nx][ny] < dp[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                    dp[nx][ny] = dp[x][y]+v[nx][ny];
                }
            }
        }
    }
    return dp[n-1][m-1];
}

int minimumObstacles(vector<vector<ll>>& grid) {
    n = grid.size(),m = grid[0].size();
    v.assign(n,vector<ll> (m,0));
    vis.assign(n,vector<ll> (m,0));
    dp.assign(n,vector<ll> (m,INT_MAX));
    v = grid;
    return bfs();
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
 
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
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