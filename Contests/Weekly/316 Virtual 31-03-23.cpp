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
bool haveConflict(vector<string>& et, vector<string>& tt) {
    ll t1,t2;
    string st;       
    string e = et[0];
    st += e[0];st += e[1];
    t1 = stoll(st);t1 *= 60;
    st.clear();
    st += e[3];st += e[4];
    ll x = stoll(st);t1 += x;
    e.clear();
    e = et[1];
    st += e[0];st += e[1];
    t2 = stoll(st);t2 *= 60;
    st.clear();
    st += e[3];st += e[4];
    x = stoll(st);t2 += x;


    ll t3,t4;
    st.clear();e.clear();    
    e = tt[0];
    st += e[0];st += e[1];
    t3 = stoll(st);t3 *= 60;
    st.clear();
    st += e[3];st += e[4];
    x = stoll(st);t3 += x;
    e.clear();
    e = tt[1];
    st += e[0];st += e[1];
    t4 = stoll(st);t4 *= 60;
    st.clear();
    st += e[3];st += e[4];
    x = stoll(st);t4 += x;

    if(t3 <= t2 and t3>=t1){
        return 1;
    }

    if(t4 <= t2 and t4>=t1){
        return 1;
    }

    if(t3 <= t2 and t4>=t2){
        return 1;
    }

    if(t3 <= t1 and t4>=t1){
        return 1;
    }
    return 0;
}

int subarrayGCD(vector<int>& v, int k) {
    ll n =v.size(),ans = 0;
    for(ll i = 0;i<n;++i){
        ll ele = v[i];
        for(ll j = i;j<n;++j){
            ele = __gcd(v[i]*1ll,ele);
            if(ele == k){++ans;}
        }
    }
    return ans;
}

long long makeSimilar(vector<int>& v, vector<int>& t) {
    ll n = v.size(),ans = 0;
    vector<ll> odd1,even1;
    vector<ll> odd2,even2;
    for(ll i = 0;i<n;++i){
        if(v[i] & 1){odd1.push_back(v[i]);}
        else{even1.push_back(v[i]);}
    }

    for(ll i = 0;i<n;++i){
        if(t[i] & 1){odd2.push_back(t[i]);}
        else{even2.push_back(t[i]);}
    }

    sort(all(odd1));sort(all(odd2));
    sort(all(even1));sort(all(even2));

    for(ll i = 0;i<odd1.size();++i){
        ll diff = odd1[i]-odd2[i];
        if(diff > 0){ans += (diff/2);}
    }

    for(ll i = 0;i<even1.size();++i){
        ll diff = even1[i]-even2[i];
        if(diff > 0){ans += (diff/2);}
    }
    return ans;
}

// Contest Pick :
/*
THANK YOU IIT-JEE!!!
THANK YOU CENTRE OF MASS
*/
long long minCost(vector<int>& v, vector<int>& c) {
    ll mixi = 0,sm_mass = 0;
    vector<int> tmp = v;
    sort(tmp.begin(),tmp.end());

    for(ll i= 0;i<v.size();++i){
        mixi += (1ll*v[i]*c[i]);
        sm_mass += c[i];
    }

    ll x = mixi/sm_mass;
    ll y = x+1;
    ll z = x-1;
    ll a = lower_bound(all(tmp),x)-tmp.begin();
    if(a == tmp.size()){a = -1;}
    ll b = upper_bound(all(tmp),x)-tmp.begin();
    if(b == tmp.size()){b = -1;}

    ll ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0,ans5 = 0;
    for(ll i= 0;i<v.size();++i){
        ll diff = abs(v[i]-x);
        ans1 += diff*c[i];

        diff = abs(v[i]-y);
        ans2 += diff*c[i];

        diff = abs(v[i]-z);
        ans3 += (diff*c[i]);

        if(a != -1){
            diff = abs(v[i]-a);
            ans4 += (diff*c[i]);
        }

        if(b != -1){
            diff = abs(v[i]-b);
            ans5 += (diff*c[i]);
        }
    }

    if(a == -1){ans4 = LLONG_MAX;}
    if(b == -1){ans5 = LLONG_MAX;}

    return min({ans1,ans2,ans3,ans4,ans5});
}

// Upsolve {Help}:
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/solutions/2734477/python-o-nlogn-gradient-descent-easy-to-understand-if-you-re-familiar-with-ml-concepts/
ll paisa(vector<int> &v,vector<int> &cst,ll x){
    ll ans = 0;
    for(ll i= 0;i<v.size();++i){
        ll diff = abs(v[i]-x);
        ans += (1ll*diff*cst[i]);
    }
    return ans;
}

long long minCost(vector<int>& v, vector<int>& c) {
    vector<int> tmp = v;
    sort(all(tmp));
    ll mn = tmp[0],mx = tmp[v.size()-1];
    ll l = mn,h = mx;
    while(l <= h){
        ll mid = (l+h)/2;
        ll cst_left = paisa(v,c,mid-1);
        ll cst_pos = paisa(v,c,mid);
        ll cst_right = paisa(v,c,mid+1);

        // If cst_pos is min then it's global min. & return it
        if((cst_pos <= cst_left) and (cst_pos <= cst_right)){
            return mid;
        }
        else if((cst_pos > cst_left)){
            // now left can be the minima
            h = mid-1;
        }
        else{ // cst_pos > cst_right
            l = mid+1;
        }
    }
    return l;
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