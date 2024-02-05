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

string triangleType(vector<int>& v) {
        set<ll> s(all(v));
        if(s.size() == 1){
            return "equilateral";
        }else if(s.size()==2){
            return "isosceles";
        }else{
            if((v[0]+v[1]<=v[2]) || (v[2]+v[1]<=v[0]) || (v[0]+v[2]<=v[1])){
                return "none";
            }else{
                return "scalene";
            }
        }
    }

static bool compare(vector<int> &a, vector<int> &b){
    if(a[0] < b[0]) return true;
    else if(a[0] > b[0]) return false;
    return a[1] >= b[1];
}

int numberOfPairs(vector<vector<int>>& v) {
    ll n = v.size(),ans = 0;
    sort(v.begin(), v.end(), compare);

    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            if(i != j && v[i][0] <= v[j][0] && v[i][1] >= v[j][1]){
                bool flag = false;
                for(ll k=i+1; k<n; k++){
                    if(k != i && k != j && (v[k][0] >= v[i][0] && v[k][0] <= v[j][0]) && (v[k][1] <= v[i][1] && v[k][1] >= v[j][1])){
                        flag = true;
                        break;
                    }
                }
                if(flag == false) ans++;
            }
        }
    }
    return ans;
}

long long maximumSubarraySum(vector<int>& v, int k) {
    map<ll,set<pair<ll,ll>>> mp;
    ll sm = 0;
    for(ll i = 0;i<v.size();++i){
        sm += v[i];
        mp[v[i]].insert({sm,i});
    }
    
    sm = 0;
    ll n = v.size(),ans = LLONG_MIN;
    
    for(ll i = 0;i<n;++i){
        ll x = v[i]+k,y = v[i]-k;
        if(mp.find(x) != mp.end() and mp[x].size()){
            auto p1 = *mp[x].rbegin();
            ans = max(ans,p1.first-sm);
        }
        if(mp.find(y) != mp.end() and mp[y].size()){
            auto p2 = *mp[y].rbegin();
            ans = max(ans,p2.first-sm);
        }
        
        sm += v[i];
        pair<ll,ll> p = {sm,i};
        mp[v[i]].erase(mp[v[i]].find(p));
    }
    
    if(ans == LLONG_MIN){ans = 0;}
    return ans;
}

int numberOfPairs(vector<vector<int>>& v) {
    sort(all(v),[](const vector<int> &p,const vector<int> &p1){
        if(p[0] == p1[0]){
            return p1[1]<p[1];
        }
        return p[0]<p1[0];
    });
    
//         Find just greater x & just small y, if they are same then ans++
    ll ans= 0,n = v.size();
    
    for(ll i = 0;i<n;++i){
        ll y = LLONG_MIN;
        for(ll j =i+1;j<n;++j){
            if(v[i][1] >= v[j][1] and y<v[j][1]){
                ++ans;
                y = v[j][1];
            }
        }
        
    }
    return ans;
}

void solve(){
    ll n;cin>>>n;
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