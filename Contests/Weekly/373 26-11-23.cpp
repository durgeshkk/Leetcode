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
// YE DIL MAANGE MORE!!

ll rgtShift(vector<ll> &v,ll k){
    vector<ll> tmp(v);
    deque<ll> q;
    for(auto it:v){
        q.push_back(it);
    }

    while(k--){
        ll ele = q.back();q.pop_back();
        q.push_front(ele);
    }

    vector<ll> x;
    while(!q.empty()){
        x.push_back(q.front());q.pop_front();
    }
    return tmp==x;
}

ll lftShift(vector<ll> &v,ll k){
    vector<ll> tmp(v);
    deque<ll> q;
    for(auto it:v){
        q.push_back(it);
    }

    while(k--){
        ll ele = q.front();q.pop_front();
        q.push_back(ele);
    }

    vector<ll> x;
    while(!q.empty()){
        x.push_back(q.front());q.pop_front();
    }

    return tmp==x;
}

bool areSimilar(vector<vector<int>>& v, int k) {
    ll n = v.size(),m = v[0].size();
    ll f = 1,row = 0;
    for(ll i = 0;i<n;++i){
        vector<ll> odd,even;
        forj(m){
            if(row){
                even.push_back(v[i][j]);
            }else{
                odd.push_back(v[i][j]);
            }
        }   
        if(row){
            f &= rgtShift(even,k);
        }else{
            f &= lftShift(odd,k);
        }
        row ^= 1;
    }
    return f;
} 

int beautifulSubstrings1(string s, int k) {
    ll ans= 0,n = s.size();
    string tmp = "aeiou";
    for(ll i = 0;i<n;++i){
        ll v = 0,c = 0;
        char ch = s[i];
        for(auto it:tmp){
            if(ch == it){++v;}
        }
        if(!v){++c;}

        for(ll j = i+1;j<n;++j){
            char ch = s[j];
            for(auto it:tmp){
                if(ch == it){++v;}
            }
            if(!v){++c;}

            if((v == c) and ((v*c)%k == 0)){++ans;}
        }
    }
    return ans;
}

vector<ll> lexicographicallySmallestArray(vector<int>& v, int k) {
    ll n = v.size();vector<ll> ans(n,0);

    vector<pair<ll,ll>> tmp;
    ll j =0;
    for(auto it:v){tmp.push_back({it,j});++j;}
    sort(all(tmp));

    vector<vector<pair<ll,ll>>> dk;
    vector<pair<ll,ll>> mv;
    
    mv.push_back(tmp[0]);
    for(ll i = 1;i<n;++i){
        if((tmp[i].first-tmp[i-1].first) <= k){
            mv.push_back(tmp[i]);
        }else{
            dk.push_back(mv);
            mv.clear();mv.push_back(tmp[i]);
        }
    }

    if(mv.size()){dk.push_back(mv);}

    ll grp = 0;
    for(auto it:dk){
        vector<ll> idx;
        for(auto x:it){
            idx.push_back(x.second);
        }
        sort(all(idx));
        ll m = 0;
        for(auto x:idx){
            ans[x] = dk[grp][m].first;++m;
        }
        ++grp;
    }
    return ans;
}

// Upsolve
long long beautifulSubstrings(string s, int k) {
    ll ans= 0,n = s.size();
    string tmp = "aeiou";
    ll v = 0,c = 0;
    map<ll,vector<ll>> dict;
    dict[0] = {-1};
    forj(n){
        ll f = 0;
        for(auto it:tmp){
            if(s[j] == it){f = 1;++v;}
        }
        if(!f){++c;}

        if(dict.find(v-c) != dict.end()){
            for(auto &it:dict[v-c]){
                ll dig = (j-it)/2;
                if(!((dig*dig)%k)){++ans;}
            }
        }

        dict[v-c].push_back(j);
    }
    return ans;
    /*
    for(ll i = 0;i<n;++i){
        ll v = 0,c = 0;
        char ch = s[i];
        for(auto it:tmp){
            if(ch == it){++v;}
        }
        if(!v){++c;}

        for(ll j = i+1;j<(i+2*k);++j){
            char ch = s[j];ll cntr = 0;
            for(auto it:tmp){
                if(ch == it){++v;++cntr;}
            }
            if(!cntr){++c;}
            
            if((v == c) and ((v%k == 0) || (c%k==0))){ans += ();break;}
            if((v == c) and ((v*c)%k == 0)){ans += 1;}
        }
    }
    return ans;*/
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