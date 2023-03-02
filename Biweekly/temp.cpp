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
 
bool isPrime(int n){
   if(n<2 || n%2==0 || n%3==0){
       return false;
   }
   
   for(int i=5; i*i <= n; i+=6){
      if(n%i==0 || n%(i+2)==0){
         return false;
      }
   }
   return true;
}
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
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
 
 
ll fact[100005];
ll powfact[100005];
void precomputefact(){
    fact[0] = 1;
    ll ans = 1;
    for(ll i = 1;i<=100005;++i){
         ans = (ans*i)%mod;
         fact[i] = ans;
         powfact[i] = power(fact[i],mod-2,mod);
    }
}
 
ll nCr(ll n,ll r){
     ll at = powfact[r];
     ll at2 = powfact[n-r];
     return ((fact[n]*((at*at2)%mod))%mod);
}
 
vector<ll> adj[100004];
 
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({1,0});
 
    while(!q.empty()){
        auto it = q.front();
        q.pop();
 
        ll node = it.first;
        ll par = it.second;
 
        cout<<node<<" ";
 
        for(auto it:adj[node]){
            if(it != par){
                q.push({it,node});
            }
        }
    }
}
 
ll height;
ll subtree[100005];
ll lev[100005];
ll parent[200005];
 
void dfs(ll node, ll par, ll level=1){

    cout<<node<<" ";
    lev[node] = level;
    height = max(height,level);
 
    ll sm = 0;
 
    parent[node] = par;
    for(auto it:adj[node]){
        if(it != par){
            dfs(it,node,level+1);
            sm += subtree[it];
        }
    }
    subtree[node] = 1+sm;
}
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
vector<int> separateDigits(vector<int>& nums) {
    ll n = nums.size();
    vector<int> ans;
    for(ll i = 0;i<n;++i){
        string s = to_string(nums[i]);
        for(ll j = 0;j<s.size();++j){
            ans.push_back(s[j]-'0');
        }
    }       
    return ans;
}

int maxCount(vector<int>& v, int n, int maxSum) {
    set<int> s(v.begin(),v.end());   
    set<int> st;
    for(ll i = 0;i<n;++i){
        st.insert(i+1);
    }    

    for(auto it:s){
        if(st.find(it) != st.end()){
            st.erase(st.find(it));
        }
    }

    ll cnt = 0,sm = 0;
    while(sm <= maxSum){
        if(st.size() == 0){break;}
        ll ele = *st.begin();
        st.erase(st.find(ele));
        if(sm + ele > maxSum){break;}
        sm += ele;++cnt;
    }
    return cnt;
}










bool issafe(int i,int j,int n,int m){
    if(i <0 || j < 0 || i>= n || j>=m){
        return false;
    }return true;
}

vector<vector<int>> vis,dp;
bool recur(vector<vector<int>> &grid,int n,int m,int i,int j){
    if(!issafe(i,j,n,m)){return false;}
    if(i == n-1 and j == m-1){
        // cout<<i<<" "<<j<<endl;
        vis[i][j] += 1;
        return true;
    }

    // if(dp[i][j] != -1){return dp[i][j];}
    // cout<<i<<" "<<j<<endl;

    bool a = false,b = false;
    if(i+1<n and grid[i+1][j]){
        a = recur(grid,n,m,i+1,j);
    }

    if(j+1<m and grid[i][j+1]){
        b = recur(grid,n,m,i,j+1);
    }

    if((a|b) == true){vis[i][j] += 1;}
    return dp[i][j] = (a|b);
}

/*
3 paths to destiny & gets that 3 in vis then ans is true
*/
bool isPossibleToCutPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vis.assign(n+1,vector<int> (m+1,0));
    dp.assign(n+1,vector<int> (m+1,-1));

    bool z = recur(grid,n,m,0,0);

    int cnt = 0;
    int alpha = vis[n-1][m-1];
    for(ll i = 0;i<n;++i){
        forj(m){
            if(i == 0 and j == 0){continue;}
            if(i == n-1 and j == m-1){continue;}

            if(i+1 < n and j+1 < m){
                if((vis[i][j] >= vis[i+1][j]) and (vis[i][j] >= vis[i][j+1])){
                    return true;
                }
            }
            else if(i+1 < n){
                if((vis[i][j] >= vis[i+1][j])){
                    return true;
                }
            }
            // if(vis[i][j] == alpha){++cnt;}
        }
    }
    if(z == false || cnt >= 1){
        return true;
    }
    return false;
}


int maximizeWin(vector<int>& v, int k) {
    ll n = v.size();
    ll ans = 0;
    ll s = 0,e = 0;
    for(ll i = 0;i<n;++i){
        ll ele = (v[i]+k);
        ll up = upper_bound(v.begin(), v.end(), ele)-v.begin();
        --up;
        // cout<<v[i]<<" "<<ele<<" "<<up<<endl;
        if(ans < (up-i+1)){
            ans = max(ans,up-i+1);
            s = v[i],e = ele;
        }
    }   
    // cout<<"---\n";
    // cout<<s<<" "<<e<<" ";
    // cout<<ans<<endl;
    // cout<<"---\n";

    vector<int> tmp;
    for(ll i = 0;i<n;++i){
        if(v[i] < s || v[i] > e){
            tmp.push_back(v[i]);
        }
    }
    // show(tmp);
    ll dk = 0;
    for(ll i = 0;i<tmp.size();++i){
        ll ele = (tmp[i]+k);
        ll up = upper_bound(tmp.begin(), tmp.end(), ele)-tmp.begin();
        --up;
        // cout<<tmp[i]<<" "<<ele<<" "<<up<<endl;
        if(dk < (up-i+1)){
            dk = max(dk,up-i+1);
        }
    }  
    return ans+dk;
}

void solve()
{
    ll n,k;cin>>n>>k;
    vector<int> v(n);enter(v);
    cout<<maximizeWin(v,k)<<endl;
    /*
    int n,m;cin>>n>>m;
    // vis.assign(n+1,vector<int> (m+1,0));
    // dp.assign(n+1,vector<int> (m+1,-1));
    // ll k;cin>>k;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(ll i = 0;i<n;++i){
        forj(m){
            cin>>grid[i][j];
        }
    }

    cout<<isPossibleToCutPath(grid)<<endl;

    for(ll i = 0;i<n;++i){
        forj(m){
            cout<<vis[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;*/

    /*
    vector<ll> v(n);
    enter(v);
    ll ans = 0;
    for(ll i = 0;i<n;++i){
        ll ele = (v[i]+k);
        ll up = upper_bound(v.begin(), v.end(), v[0]+2)-v.begin();
        --up;
        ans = max(ans,up-i);
    }       
    cout<<ans<<endl;*/
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