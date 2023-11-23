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
 
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
/*
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
int countBeautifulPairs(vector<int>& v) {
    ll n = v.size(),ans = 0;    
    for(ll i = 0;i<n;++i){
        string s = to_string(v[i]);
        ll ele = (s[0]-'0');
        for(ll j = i+1;j<n;++j){
            ll rem = v[j]%10;
            if(__gcd(ele,rem) == 1){++ans;}
        }
    }
    return ans;
}

ll b;
vector<ll> ok;
void fun(){
    ok.assign(61,1);
    for(ll i = 1;i<=60;++i){
        ok[i] = 2*ok[i-1];
    }
}

ll recur(ll a){
    ll x = (a-b);
    if(a == 0){return 0;}
    if(x <= 0){return -1;}
    ll sa = LLONG_MAX;
    for(ll i = 0;i<=60;++i){
        ll ele = recur(a-b-ok[i]);
        if(ele != -1){
            sa = min(sa,1+ele);
        }
    }
    return sa;
}

int makeTheIntegerZero(int num1, int num2) {
    b = num2;   
    if(num1 < num2){return -1;}
    forj(65){
        ll diff = num1-j*num2;
        bitset<70> b(diff);
        ll st = 0;
        for(ll k= 0;k<70;++k){if(b[k]){++st;}}

        if(0<j and j>=st){return j;}
    }
    return -1;
}

int numberOfGoodSubarraySplits(vector<int>& nums) {
    ll f = 0;
    vector<ll> v;
    for(ll i = 0;i<nums.size();++i){
        if(nums[i]){
            f = 1;
        }
        if(f){v.push_back(nums[i]);}
    }
    while(v.size() and !v[v.size()-1]){v.pop_back();}
    if(!v.size()){return 0;}

    ll ans = 1;
    for(ll i = 0;i<v.size();++i){
        if(v[i]){
            // ll cntr = 0;
            // while(i<v.size() and v[i]){
            //     ++i;++cntr;
            // }
            // --cntr,--i;
            // ll ok = power(2,cntr,mod);
            // ans = mod_mul(ans,ok,mod);
        }else{
            ll cntr = 0;
            while(i<v.size() and !v[i]){
                ++i;++cntr;
            }
            ++cntr,--i;
            ans = mod_mul(ans,cntr,mod);
        }
    }
    return ans;
}

/*
Simply add the right moving to some DS which can give fast retrieval of the 
last nearest element!!!
*/
vector<ll> survivedRobotsHealths(vector<int>& ok, vector<int>& h, string d) {
    ll n = ok.size();
    vector<ll> v(n,0);
    vector<vector<ll>> adj;
    for(ll i = 0;i<n;++i){
        adj.push_back({ok[i],h[i],d[i]});
    }

    sort(all(adj));
    for(ll i = 0;i<n;++i){
        v[i] = adj[i][0];
        h[i] = adj[i][1];
        d[i] = adj[i][2];
    }

    stack<pair<ll,ll>> lft,rght;
    for(ll i = 0;i<n;++i){
        if(d[i] == 'R'){
            // Add to DS
            rght.push({h[i],v[i]});
        }else{
            // Remove the closest
            ll ele = rght.top().first;
            while(!rght.empty() and rght.top().first < h[i]){
                rght.pop();
                --h[i];
            }

            if(!rght.empty()){
                auto p = rght.top();rght.pop();
                if(p.first == rght.top().first){
                }else{
                    --p.first;
                    rght.push(p);
                }
            }else{
                lft.push({h[i],v[i]});
            }
        }
    }


    vector<pair<ll,ll>> ans;
    map<ll,ll> mp;
    while(!lft.empty()){
        auto ele = lft.top();lft.pop();
        mp[ele.second] = ele.first;
    }

    while(!rght.empty()){
        auto ele = rght.top();rght.pop();
        mp[ele.second] = ele.first;
    }

    vector<ll> ak;
    for(ll i = 0;i<n;++i){
        if(mp.find(v[i]) != mp.end()){
            ak.push_back(mp[v[i]]);
        }
    }

    return ak;
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