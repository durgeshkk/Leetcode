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
void duplicateZeros(vector<int>& arr) {
    vector<ll> v;
    ll n = arr.size();
    for(ll i = 0;i<n;++i){
        if(arr[i] == 0){
            v.push_back(0);
            v.push_back(0);
        }else{
            v.push_back(arr[i]);
        }
    }
    for(ll i = 0;i<n;++i){
        arr[i] = v[i];
    }

} 

int largestValsFromLabels(vector<int>& values, vector<int>& labels, int k, int useLimit) {
    map<ll,ll> mp;
    vector<pair<ll,ll>> v;
    for(ll i = 0;i<values.size();++i){
        v.push_back({values[i],labels[i]});
    }
    sort(all(v));
    ll ans=0,j = v.size()-1;
    while(k>0){
        ll &freq = mp[v[j].second];
        if(freq < useLimit){
            ++freq;
            ans += v[j].first;
            --k;
        }
        --j;
    }
    return ans;
}

bool issafe(ll x,ll y,ll n){
    if(x < 0 || y < 0 || x>=n || y>=n){return false;}
    return true;
}

ll bfs(vector<vector<int>>& v){
    ll ans = 0,n = v.size();
    vector<vector<int>> vis(n+1,vector<int>(n+1,0));
    
    queue<pair<ll,ll>> q;
    q.push({0,0});
    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            auto p = q.front();q.pop();
            ll i = p.first,j = p.second;
            if(p.first == n-1 and p.second == n-1){
                return ans;
            }

            if(issafe(i+1,j,n) and !v[i+1][j] and !vis[i+1][j]){
                q.push({i+1,j});vis[i+1][j] = 1;
            }

            if(issafe(i-1,j,n) and !v[i-1][j] and !vis[i-1][j]){
                q.push({i-1,j});vis[i-1][j] = 1;
            }

            if(issafe(i-1,j+1,n) and !v[i-1][j+1] and !vis[i-1][j+1]){
                q.push({i-1,j+1});vis[i-1][j+1] = 1;
            }

            if(issafe(i-1,j-1,n) and !v[i-1][j-1] and !vis[i-1][j-1]){
                q.push({i-1,j-1});vis[i-1][j-1] = 1;
            }

            if(issafe(i+1,j-1,n) and !v[i+1][j-1] and !vis[i+1][j-1]){
                q.push({i+1,j-1});vis[i+1][j-1] = 1;
            }

            if(issafe(i+1,j+1,n) and !v[i+1][j+1] and !vis[i+1][j+1]){
                q.push({i+1,j+1});vis[i+1][j+1] = 1;
            }

            if(issafe(i,j+1,n) and !v[i][j+1] and !vis[i][j+1]){
                q.push({i,j+1});vis[i][j+1] = 1;
            }

            if(issafe(i,j-1,n) and !v[i][j-1] and !vis[i][j-1]){
                q.push({i,j-1});vis[i][j-1] = 1;
            }
        }
        ++ans;
    }
    return -1;
}
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    return bfs(grid);
}


string longcs(string X, string Y, int m, int n)
{
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    int index = L[m][n];
 
    char lcs[index + 1];
    lcs[index] = '\0';
 
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
 
    // Print the lcs
    return lcs;
}

string shortestCommonSupersequence(string s1, string s2) {
    string lcs = longcs(s1,s2,s1.size(),s2.size());
    if(lcs.empty()){
        string s = s1+s2;
        return s;
    }

    ll i = 0,j = 0,k = 0;string ans;
    while(k < lcs.size()){
        while(s1[i] != lcs[k]){
            ans += s1[i];
            ++i;
        }

        while(s2[j] != lcs[k]){
            ans += s2[j];
            ++j;
        }
        ans += lcs[k];
        ++i,++j;
        ++k;
    }

    // add ending characters
    while(i < s1.size()){
        ans += s1[i];
        ++i;
    }

    while(j < s2.size()){
        ans += s2[j];
        ++j;
    }
    return ans;
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