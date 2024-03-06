#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
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
vector<ll> intersection(vector<vector<ll>>& nums) {
    vector<ll> ans;
    for(ll i = 1;i<=1000;++i){
        ll cntr = 0;
        for(ll j = 0;j<nums.size();++j){
            for(ll k = 0;k<nums[j].size();++k){
                if(nums[j][k] == i){++cntr;break;}
            }
        }
        if(cntr == nums.size()){
            ans.push_back(i);
        }
    }
    return ans;
}
/*
[[2,2,1]]
[[2,2,2],[3,4,1]]
[[34,70,10],[28,89,6],[36,95,18],[51,93,48],[13,50,8],[52,20,14],[64,1,1],[45,90,17],[94,47,3],[12,20,4],[46,1,1],[60,59,54],[32,86,25],[41,51,15],[26,66,20],[76,60,31],[95,56,27],[67,51,13],[18,70,9],[87,63,32],[84,6,6],[25,55,14],[11,74,2],[47,21,7],[57,88,56],[60,4,1],[34,14,14],[51,61,16],[39,38,1],[23,69,14],[79,75,70],[95,80,10],[14,66,4],[69,91,67],[95,18,11],[35,84,7],[9,48,6],[13,72,3],[76,11,5],[14,75,11],[8,94,1],[34,80,21],[53,86,49],[32,15,3],[64,61,58],[62,28,10],[67,22,20],[87,48,46],[3,5,2],[7,48,4],[75,88,68],[81,55,52],[95,74,63],[73,18,17],[17,7,4],[57,38,23],[81,22,10],[47,33,29],[58,33,31],[48,77,15],[56,55,36],[45,77,11],[82,93,22],[61,8,1],[97,58,38],[97,93,92],[53,39,24],[65,25,23],[32,90,4],[17,22,15],[40,98,32],[65,17,4],[10,28,10],[10,65,6],[23,94,3],[43,19,10],[33,90,5],[2,28,2],[96,26,9],[99,98,32]]

*/
int countLatticePoints(vector<vector<int>>& v) {
    ll ans=  0;
    for(ll x = 0;x<=500;++x){
        for(ll y = 0;y<=500;++y){
            // Let the pt be (x,y)
            for(ll i = 0;i<v.size();++i){
                ll xi = v[i][0],yi = v[i][1],r = v[i][2];
                ll x_dist = abs(xi-x),y_dist = abs(yi-y);
                ll dist = (x_dist*x_dist) + (y_dist*y_dist);
                double d = sqrt(1.0*dist);
                if(d <= r){
                    ++ans;break;
                }
            }
        }
    }
    return ans;
}

/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& v) {
    ordered_set os; 
    for(auto it:r){
        os.insert({it[0],it[1]});
    }

    ll sz = r.size();
    vector<ll> ans;
    for(auto it:v){
        pair<ll,ll> p = {it[0],it[1]};
        ll idx;
        if(os.find(p) != os.end()){
            idx = os.order_of_key(p);
        }else{
            os.insert(p);
            idx = os.order_of_key(p);
            os.erase(os.find(p));
        }
        ans.push_back(sz-idx);
    }
    return ans;
}
*/

// Upsolve Q 3:
vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
    vector<vector<int>> adj(101);
    for (auto &r: rectangles) {
        adj[r[1]].push_back(r[0]);
    }

    for (ll i = 0; i < 101; i++) {
        sort(all(adj[i]));
    }

    vector<int> ans;
    for (auto &p: points) {
        ll sm = 0;
        for (ll i = p[1]; i < 101; i++) {
            auto lb = lower_bound(all(adj[i]),p[0]);
            sm += (adj[i].end()) - lb;
        }
        ans.push_back(sm);
    }
    return ans;
}

// Q4 : Upsolve
vector<int> fullBloomFlowers(vector<vector<int>>& v, vector<int>& p) {
    vector<int> ans,start,end;
    for(auto it:v){
        start.push_back(it[0]);
        end.push_back(it[1]);
    }

    sort(all(start));sort(all(end));

    for(auto x:p){
        ll s = upper_bound(all(start),x)-start.begin();
        ll e = lower_bound(all(end),x)-end.begin();
        ans.push_back(s-e);
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