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
bool hasMatch(string s, string p) {
    string x,y;
    int f = 0;
    for(int i = 0;i<p.size();++i){
        if(p[i] == '*'){
            f = 1;
            continue;
        }

        if(f){
            y += p[i];
        }else{
            x += p[i];
        }
    }

    int idx1 = -1,idx2 = -1;
    if(x.size() == 0 and y.size() == 0){
        return true;
    }else if(x.size() == 0){
        if(s.find(y) != string::npos){
            return true;
        }else{
            return false;
        }
    }else if(y.size() == 0){
        if(s.find(x) != string::npos){
            return true;
        }else{
            return false;
        }
    }else{
        int idx = -1,idx2=-1;
        size_t pos = s.find(x); // Use `find` to get the index of the first occurrence
        if (pos != std::string::npos) {
            idx = static_cast<int>(pos); // Return the position if found
        }

        size_t pos2 = s.rfind(x); // Use `rfind` to get the last occurrence index
        if (pos2 != std::string::npos) {
            idx2 = static_cast<int>(pos2); // Return the position if found
        }

        if(idx==-1 || idx2==-1){return 0;}
        idx += (x.size()-1);
        if(idx < idx2){
            return 1;
        }else{
            return 0;
        }
    }
}

class TaskManager {
public:
    multiset<vector<ll>> ms; // {pid,tid,uid}
    map<ll,pair<ll,ll>> mp; // tid - {uid,pid}
    
    TaskManager(vector<vector<ll>>& tasks) {
        for(auto it:tasks){
            vector<ll> v=it;
            ms.insert({it[2],it[1],it[0]});
            mp[it[1]] = {it[0],it[2]};
        }
        // print();
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId,priority};
        ms.insert({priority,taskId,userId});
        // print();
    }
    
    void edit(int tid, int np) {
        pair<ll,ll> p = mp[tid];
        mp[tid] = {p.first,np};
        
        vector<ll> v({p.second,tid,p.first});
        ms.erase(ms.find(v));
        v.clear();
        v.push_back(np);
        v.push_back(tid);
        v.push_back(p.first);
        ms.insert(v);
    }
    
    void rmv(int tid) {
        pair<ll,ll> p = mp[tid];
        mp.erase(mp.find(tid));
        vector<ll> v({p.second,tid,p.first});
        ms.erase(ms.find(v));
    }
    
    int execTop() {
        if(ms.empty()){return -1;}
        
        vector<ll> v;
        v = *ms.rbegin();
        ms.erase(ms.find(v));
        mp.erase(mp.find(v[1]));
        return v[2];
    }
    
    void print(){
        cout<<"*------MS*------"<<endl;
        for(auto it:ms){
            show(it);
        }
        cout<<"*------MP*------"<<endl;
        for(auto it:mp){
            cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        }
    }
};

vector<vector<ll>> dp;
ll n;
vector<ll> v;
ll recur(ll idx,ll prev){
    if(idx == n){return 0;}

    ll diff = abs(v[idx]-prev);
    
    for(ll i = 0;i<=diff;++i){

    }
}

int longestSubsequence(vector<int>& tmp) {
        
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