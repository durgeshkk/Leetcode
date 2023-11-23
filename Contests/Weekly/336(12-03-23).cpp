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
int vowelStrings(vector<string>& words, int left, int right) {
    set<char> s = {'a','e','i','o','u'}   ;
    vector<ll> pref(words.size(),0);
    for(ll i = 0;i<words.size();++i){
        string st = words[i];
        if(s.find(st[0]) != s.end()){
            if(s.find(st[st.size()-1]) != s.end()){
                pref[i] = 1;
            }
        }
    }

    for(ll i = 1;i<pref.size();++i){
        pref[i] += pref[i-1];
    }

    if(left > 0){--left;left = pref[left];}
    else{left = 0;}
    ll ans = pref[right]-left;
    return ans;
}

int maxScore(vector<int>& v) {
    sort(all(v));
    reverse(all(v));
    vector<ll> sm(v.size());
    for(ll i = 0;i<v.size();++i){
        if(i == 0){
            sm[i] = v[i];
        }else{
            sm[i] = v[i]+sm[i-1];
        }
    }

    ll ans = 0;
    for(ll i = 0;i<v.size();++i){
        if(sm[i] > 0){
            ++ans;
        }else{
            break;
        }
    }
    return ans;
}

long long beautifulSubarrays(vector<int>& v) {
    ll xr = 0;
    map<ll,ll> mp;
    for(auto it:v){
        xr ^= it;
        mp[xr]++;
    }

    ll ans = 0;
    for(auto it:mp){
        ll freq = it.second;
        if(it.first == 0){
            ll sa = freq*(freq+1)/2;
            ans += sa;
        }else{
            ll sa = freq*(freq-1)/2;
            ans += sa;
        }
    }
    return ans;
}

ll recur(ll idx,vector<ll> v,ll sm){
    if(idx >= 2001){
        return 0;
    }

    v[idx] = 1;
    sm += 1;
    ll a = recur(idx+1,v,sm);
    
    v[idx] = 0;
    sm -= 1;
    ll b = recur(idx+1,v,sm);
    return min(a,b);
}

// Upsolve :
/*
https://www.youtube.com/watch?v=yw9l_BXKpno
Intuition :
We will try to fill the 1st task at the end of duration & so the upcoming task
coming will be overlapping with the 1st task & then the remaining sec of this curr
task can be put at the last again leaving the overlapping ones
Jo overap kr rhe start se usse pehle bharo aur baki ke last mein bharo taki anne
wale tasks overlap kr paye!!!
*/
int findMinimumTime(vector<vector<int>>& tasks) {
    // Sort on basis of end time 
    for(auto &it:tasks){
        swap(it[0],it[1]);
    }
    sort(all(tasks));
    
    vector<ll> ontime(2001,0);
    for(auto &it:tasks){
        ll start = it[1],end = it[0],dur = it[2];
        for(ll i = start;i<=end;++i){
            if(ontime[i]){dur--;}
        }

        for(ll i = end;dur>0;--i){
            if(!ontime[i]){--dur;ontime[i] = 1;}
        }
    }

    ll ans = accumulate(all(ontime),0ll);
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