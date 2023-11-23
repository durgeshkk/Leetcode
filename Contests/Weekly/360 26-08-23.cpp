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

int furthestDistanceFromOrigin(string s) {
    int n = s.size();
    int ans = 0,ok = 0;
    for(int i = 0;i<n;++i){
        if(s[i] == 'L'){--ans;}
        else if(s[i] == 'R'){++ans;}else{++ok;}
    }
    
    if(ans >= 0){ans += ok;}
    else{ans -= ok;}
    ans = abs(ans);
    return ans;
}
 
long long minimumPossibleSum(int n, int x) {
    ll ans=  0,sz = n;       
    for(ll i = 1;i<=((x)/2);++i){
        --n;
        ans += i;
        if(!n){return ans;}
    }

    
    while(n--){
        ans += x;
        ++x;
    }
    return ans;
} 

ll n;
ll need[35];
ll have[35];
vector<ll> v,pos;
ll recur(ll idx,vector<ll> tmp){
    if(idx == n){
        
    }

    ll sa = 0,op = 0;
    sa += recur(idx,v);
    while(v[idx] > 1){
        v[idx] /= 2;++op; 
        tmp[log2(v[idx])] -= 1;
        tmp[log2(32)] -= 1;
        sa = min(sa,op+recur(idx,v));
    }
    return sa;
}

/*
int minOperations(std::vector<int>& nums, int target) {
        std::priority_queue<int> pq(nums.begin(), nums.end());
        int total = 0;
        for (int num : nums) {
            total += num;
        }

        int operations = 0;
        while (!pq.empty() && total > target) {
            int num = pqtop();
            pq.pop();
            total -= num / 2;
            pq.push(num / 2);
            operations++;
        }
        if (total == target) {
            return operations;
        } else {
            return -1;
        }
    }
*/

/*
bool isValid(vector<int>& sub_nums, int tar) {
        for (int num : sub_nums) {
            if (num == tar || (num < tar && isValid(vector<int>(sub_nums.begin() + 1, sub_nums.end()), tar - num))) {
                return true;
            }
        }
        return false;
    }

    int minOperations(vector<int>& nums, int target) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int op_count = 0;

        while (op_count <= n) {
            if (accumulate(nums.begin(), nums.end(), 0) < target) {
                return -1;
            }
            if (isValid(nums, target)) {
                return op_count;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < target) {
                    nums.push_back(nums[i]);
                    op_count++;
                    break;
                }
            }
        }
        return op_count;
    }
*/

int minOperations(vector<int>& v, int x) {
    ll ans= 0;
    multiset<ll> ms(all(v));
    bitset<35> b(x);
    if(ms.find(x) != ms.end()){return 0;}
    ll dk = 0;
    for(auto it:v){dk += (1ll*it);}
    if(x > dk){return -1;}

    forj(35){
        if(b[j]){
            ll a = pow(2,j);
            if(ms.find(a) != ms.end()){
                ms.erase(ms.find(a));
                x -= pow(2,j);
                b[j] = 0;
            }
        }
    }

    map<ll,ll> mp;
    ll ele = 1,i=0;
    while(ele <= 1e10){
        mp[ele] = i;++i,ele*=2;
    }

    vector<ll> tmp(all(ms));
    bitset<35> c(x);
    forj(35){
        if(c[j]){need[j] = 1;}
    }
    
    forj(tmp.size()){
        ll pos = mp[tmp[j]];
        ll f = -1;
        while(pos--){
            if(need[pos]){f = pos;}
        }

        if(f == -1){
            ll idx = mp[tmp[j]];
            have[idx] += 1;
        }else{
            ans += (mp[tmp[j]]-f);
            ll diff = (mp[tmp[j]]-f);
            for(ll i = f;i<mp[tmp[j]];++i){
                have[i]++;
            }
        }

        for(ll i = 0;i<=32;++i){
            have[i] -= need[i];
            need[i] = 0;
            if(have[i] >= 2){
                ll s = have[i]/2;
                have[i+1] += s;
            }
        }
    }
    
    forj(35){if(need[j]){return -1;}}
    return ans;
/*
    ll yaar = x;

    ll l = 0,h = 40;
    while(l <= h){
        ll mid = (l+h)/2;
        ll yaar = x,excess = 0;
        forj(tmp.size()){
            ll op = mid;
            ll ele = tmp[j];
            while(ele > 1 and op){
                ele /= 2;--op;
                ll udd = (ele & x);
                yaar -= udd;
            }
        }

        ll rem = (sm-(x-yaar));
        if((rem&yaar) == yaar){yaar=0;}
        if(yaar){
            l = mid+1;
        }else{
            ans = mid;h = mid-1;
        }
    }
    return ans;*/
}   

/*
[1,2,8]
7
[1,32,1,2]
12
[1,32,1]
35
[1,1]
2
[16,32,128]
1
*/

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