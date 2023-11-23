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
vector<double> sampleStats(vector<int>& count) {

    ll mn = -1,mx = -1,sm = 0,fr = 0,ele = 0;
    double mode = 0.0;
    for(ll i = 0;i<count.size();++i){
        if(mn == -1 and count[i] != 0){mn = i;}
        if(count[i] != 0){mx = i;}
        sm += 1.0*(count[i]*i);
        ele += count[i];
        if(fr > count[i]){
            fr = count[i];
            mode = i;
        }
    }
    double mean = 1.0*sm/ele;
    double med = 0.0;
    if(ele & 1){
        ll need = ceil(1.0*ele/2);
        for(ll i = 0;i<count.size();++i){
            need -= count[i];
            if(need <= 0){
                med = i;
            }
        }
    }else{
        ll need = ceil(1.0*ele/2);
        ll need2 = (need+1);
        double ok =  0.0;
        for(ll i = 0;i<count.size();++i){
            need -= count[i];
            need2 -= count[i];
            if(need <= 0){
                med = i;
            }
            if(need <= 0){
                ok = i;
            }
        }
        med = (med+ok)/2.0;
    }

    /*
    vector<ll> freq(256,0);
    for(auto it:count){
        freq[it]++;
        sm += it;
    }
    for(ll i = 0;i<256;++i){
        if(mn == -1 and freq[i] != 0){mn = i;}
        if(freq[i] != 0){mx = i;}
        if(fr < freq[i]){
            fr = freq[i];ele = i;
        }
    }
    ll n = count.size();
    double mean = 1.0*sm/n;
    sort(all(count));
    double med = 1.0*count[n/2];
    if(n & 1){
    }else{
        double med = 1.0*(count[n/2]+count[n/2-1])/2;
    }*/
    return {(1.0*mn,1.0*mx,mean,med,1.0*ele)};
} 

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<vector<ll>> v;
    ll n = trips.size(),mx = 0;
    vector<ll> pref(mx+2,0);
    for(ll i = 0;i<n;++i){
        vector<ll> tmp;
        tmp.push_back(trips[i][1]);
        pref[trips[i][1]] = trips[i][0];
        pref[trips[i][2]+1] = -1*trips[i][0];
        tmp.push_back(trips[i][2]);
        mx = max(mx,1ll*trips[i][2]);
        tmp.push_back(trips[i][0]);
        v.push_back(tmp);
    }
    for(ll i = 1;i<pref.size();++i){
        pref[i] += pref[i-1];
        if(pref[i] > capacity){return false;}
    }
    return true;
}

class MountainArray {
  public:
    int get(int index);
    int length();
};

int findInMountainArray(int target, MountainArray &v) {
    ll l = 0,r = MountainArray.length()-1;  
    ll mnt_val = 0,idx = 0; 
    while(l <= r){
        ll k = (l+r)/2;
        ll a = MountainArray.get(k);
        ll b = MountainArray.get(k+1);
        ll c = MountainArray.get(k-1);
        if(a > b and a > c){
            // it's mountain
            mnt_val = a;
            idx = k;
            break;
        }else if(a > c and b > a){
            // Inc. Slope
            l = k+1;
        }else{
            // Dec. Slope
            r = k-1;
        }
    }

    // Search left for Target
    ll l = 0,r = k;
    while(l <= r){
        ll k = (l+r)/2;
        ll a = MountainArray.get(k);
        if(a == target){
            return k;
        }else if(a > target){
            r = k-1;
        }else{
            l = k+1;
        }
    }

    // Search right for Target
    ll l = k+1,r = MountainArray.length()-1;
    while(l <= r){
        ll k = (l+r)/2;
        ll a = MountainArray.get(k);
        if(a == target){
            return k;
        }else if(a > target){
            l = k+1;
        }else{
            r = k-1;
        }
    }
    return -1;
}

vector<string> braceExpansionII(string expression) {
    vector<string> ans;
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