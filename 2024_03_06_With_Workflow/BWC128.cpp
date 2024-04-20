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




//  "A" : 65, "a" : 97  (-> |) (<- &(~))
// YE DIL MAANGE MORE!!
int scoreOfString(string s) {
    int ans = 0;
    for(int i = 0;i<s.size()-1;++i){
        ans += abs((s[i+1]-'a')-(s[i]-'a'));
    }
    return ans;
}

int minRectanglesToCoverPoints(vector<vector<int>>& v, int w) {
    sort(v.begin(),v.end());
    ll st = -1,ans = 0;
    for(ll i = 0;i<v.size();++i){
        if(st == -1){
            st = w+v[i][0];
            ++ans;
        }else{
            if(st < v[i][0]){
                st = w+v[i][0];
                ++ans;
            }
        }
    }
    return ans;
}

vector<pair<ll,ll>> adj[100004];
struct node{
    int u;
    int time;
};
struct compare{
    bool operator()(const node &a, const node &b){
        return a.time > b.time; // min heap
    }
};

vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
    vector<int> ans(n,-1);
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    vector<int> minTime(n,INT_MAX);
    minTime[0]=0;
    
    priority_queue<node,vector<node>,compare> pq;
    struct node p={0,0};
    pq.push(p);
    
    while(pq.size()>0){ 
        p=pq.top();
        pq.pop();
        
        int u = p.u, curTime = p.time;
        
        if(curTime >= disappear[u] || minTime[u]<curTime) continue;
        
        if(ans[u] == -1 || ans[u] > curTime) ans[u] = curTime;
        
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first, time=adj[u][i].second;
            if(minTime[v] > curTime+time && curTime+time < disappear[v]){
                minTime[v] = curTime+time;
                p={v, minTime[v]};
                pq.push(p);
            }
        }
    }
        
    return ans;
}

/*
2 Concepts : 
1. NGE
2. Binary Search in Array Elements
*/
vector<pair<int,int>> index_mapper;
void printNGE(vector<int> arr, ll n)
{
    stack<pair<ll,ll>> s;
    s.push({arr[0],0});
 
    for (int i = 1; i < n; i++) {
 
        if (s.empty()) {
            s.push({arr[i],i});
            continue;
        }
 
        while (s.empty() == false && s.top().first < arr[i]) {
            index_mapper.push_back({s.top().second,i});
            // cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }
 
        s.push({arr[i],i});
    }
 
    while (s.empty() == false) {
        index_mapper.push_back({s.top().second,-1});
        // cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

long long numberOfSubarrays(vector<int>& v) {
    int n = v.size();
    printNGE(v,n);

    map<ll,vector<int>> mp;
    forj(n){mp[v[j]].push_back(j);}
    sort(all(index_mapper));

    // for(auto it:index_mapper){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    ll ans = 0;
    for(ll i = 0;i<n;++i){
        vector<int> &indices = mp[v[i]];
        // show(indices);
        ll lb = lower_bound(all(indices),i)-indices.begin();
        // cout<<lb<<" ";
        if(index_mapper[i].second == -1){
            ans += 1ll*(indices.size()-1-lb);
        }else{
            ll ub = lower_bound(all(indices),index_mapper[i].second)-indices.begin();
            ans += 1ll*(ub-1-lb);
        }
        // cout<<ans<<" ";
    }
    // cout<<endl;
    ans += (1ll*n);
    return ans;
}

void solve(){
    ll n;cin>>n;
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