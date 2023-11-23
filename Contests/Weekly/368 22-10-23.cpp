/*
Once in a LifeTime,
Will never let you Down!!
*/
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
 
int minimumSum(vector<int>& v) {
    ll n = v.size();
    vector<ll> pref(n),suff(n);
    pref[0] = 1ll*v[0];
    for(ll i = 1;i<n;++i){
        pref[i] = min(pref[i-1],1ll*v[i]);
    }

    suff[n-1] = 1ll*v[n-1];
    for(ll i = n-2;i>=0;--i){
        suff[i] = min(suff[i+1],1ll*v[i]);
    }

    ll ans = 1e9;
    for(ll i= 0;i<n;++i){
        if((1ll*v[i] >=suff[i]) and (1ll*v[i] >=pref[i])){
            ans = min(ans,pref[i]+suff[i]+1ll*v[i]);
        }
    }
    if(ans == 1e9){ans = -1;}
    return ans;
}

int minGroupsForValidAssignment(vector<int>& tmp) {
    map<ll,ll> mp;
    for(auto &it:tmp){
        mp[it]++;
    }

    ll mn = tmp.size();
    vector<ll> v;
    for(auto it:mp){mn = min(mn,it.second);v.push_back(it.second);}

    ll gcd = v[0];
    for(auto it:v){
        gcd = __gcd(gcd,it);
    }

    ll l = 1,h = mn+1,ans = 0;
    forj(v.size()){
        ll low = 1,high = (v[j]/gcd)+1; 
        ll grps = 0,s_cntr = 0;
        while(low <= high){
            // Try to make m2 grps
            ll m2 = (low+high)/2;
            ll ele_used = m2*gcd;
            ll rem = v[j]-ele_used;
            if(rem <= m2){
                high = m2-1;
                grps = m2;
            }else{
                low = m2+1;
            }
        }
        ans+=grps;
    }
    return ans;

    ans = 1;
    while(l <= h){
        ll mid = (l+h)/2;
        // If mid = 3 try for partition of [2,3]

        ll f = 1,cntr = 0,tot_grps = 0;
        forj(v.size()){
            ll low = 1,high = (v[j]/mid)+1; 
            ll grps = 0,s_cntr = 0;
            while(low <= high){
                // Try to make m2 grps
                ll m2 = (low+high)/2;
                ll ele_used = m2*mid;
                ll rem = v[j]-ele_used;
                if(rem <= m2){
                    high = m2-1;
                    grps = m2;
                    s_cntr = 1;
                }else{
                    low = m2+1;
                }
            }

            if(s_cntr){++cntr;tot_grps+=grps;}
            else{f = 0;break;}
        }

        if(f){
            l = mid+1;ans = mid;
        }else{
            h = mid-1;
        }
    }

    ll tot_grps = 0,mid = ans;
    forj(v.size()){
        ll low = 1,high = (v[j]/mid)+1; 
        ll grps = 0,s_cntr = 0;
        while(low <= high){
            // Try to make m2 grps
            ll m2 = (low+high)/2;
            ll ele_used = m2*mid;
            ll rem = v[j]-ele_used;
            if(rem <= m2){
                high = m2-1;
                grps = m2;
            }else{
                low = m2+1;
            }
        }
        tot_grps+=grps;
    }
    return tot_grps;
}

ll ans = -1e9;
vector<ll> dp;
ll recur(ll i,vector<ll> &v){
    if(i < 1){return 0;}

    ll &sa = dp[i];
    if(sa != -1){return sa;}

    sa= 0;
    ll f = 1;
    // Try to check if making grp by i is success
    forj(v.size()){
        ll grp = (v[j]/i);
        ll ex = (v[j]%i);
        if(ex > grp) {
            f = 0;
        }
    }
    if(!f){
        sa |= recur(i/2,v);
        if(i & 1){
            sa |= recur((i+1)/2,v);
        }
    }else{
        if(ans == -1e9){ans = i;}
        return 1;
    }
    return sa;
}

int minGroupsForValidAssignment(vector<int>& tmp) {
    map<ll,ll> mp;
    for(auto &it:tmp){
        mp[it]++;
    }

    ll mn = tmp.size();
    vector<ll> v;
    for(auto it:mp){mn = min(mn,it.second);v.push_back(it.second);}
    
    sort(all(v));
    ll ans = 2e9;
    for(ll i = 1;i<=v[0];++i){
        // Check for i if pssbl
        ll a = i,b = a+1,f = 1,grps= 0;
        forj(v.size()){
            ll curr = v[j],mn = 2e9,cntr = 0;
            while(curr >= 0){
                if(curr%a == 0){mn = cntr+curr/a;}
                curr -= b;
                ++cntr;
            }
            if(mn == 2e9){f = 0;break;}
            grps += mn;
        }

        if(f){
            ans = min(ans,grps);
        }
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