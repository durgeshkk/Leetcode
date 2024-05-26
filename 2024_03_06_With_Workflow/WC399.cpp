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
#define pyes cout << "YES" << endl;
#define pno cout << "NO" << endl;
using namespace std;
ll mod = (ll)(1e9+7);
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

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
// YE DIL MAANGE MORE!!
int numberOfPairs1(vector<int>& v, vector<int>& t, int k) {
    for(auto &it:t){
        it *= k;
    }

    ll ans = 0;
    for(ll j = 0;j<t.size();++j){
        for(ll i = 0;i<v.size();++i){
            if(v[i]%v[j] == 0){++ans;}
        }
    }
    return ans;
}

string compressedString(string s) {
    string ans;
    ll n = s.size();
    for(ll i = 0;i<s.size();++i){
        ll cntr = 0;
        char ch = s[i];
        while(i<n and cntr<=9 and s[i] == ch){
            ++cntr;++i;
        }
        --i;
        ans += to_string(cntr);
        ans += ch;
    }
    return ans;     
}

long long numberOfPairs(vector<int>& dk, vector<int>& t, int k) {
    vector<ll> v;
    for(auto it:dk){
        if(it%k == 0){
            v.push_back(it/k);
        }
    }

    map<ll,ll> mp;
    for(ll i = 0;i<t.size();++i){
        mp[t[i]]++;
    }

    ll ans = 0;
    for(ll i = 0;i<v.size();++i){
        ll ele = v[i],sa = 0;
        for(ll j = 1;j*j<=ele;++j){
            if((ele%j) == 0){
                if(mp.find(j) != mp.end()){
                    sa += mp[j];
                }
            

                if ((j != ele/j) && (mp.find(ele/j) != mp.end())) {
                    sa += mp[ele/j];
                }
                
            }
        }
        ans += sa;
    }
    return ans;
}

struct Node {
    long long max_sum;
    long long max_with_last;
};

class SegmentTree {
private:
    vector<Node> tree;
    vector<int> arr;
    int n;

    Node combine(Node left, Node right) {
        Node res;
        res.max_sum = max(left.max_sum, right.max_sum);
        res.max_sum = max(res.max_sum, left.max_with_last + right.max_with_last);
        res.max_with_last = max(left.max_with_last, right.max_with_last);
        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node].max_sum = max(0, arr[start]);
            tree[node].max_with_last = max(0, arr[start]);
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            arr[start] = value;
            tree[node].max_sum = max(0, value);
            tree[node].max_with_last = max(0, value);
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, value);
            } else {
                update(2 * node + 1, mid + 1, end, idx, value);
            }
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return {0, 0};  // Neutral element for max
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node p1 = query(2 * node, start, mid, l, r);
        Node p2 = query(2 * node + 1, mid + 1, end, l, r);
        return combine(p1, p2);
    }

public:
    SegmentTree(const vector<int>& inputArr) {
        arr = inputArr;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }

    long long getMaxSum() {
        return tree[1].max_sum;
    }
};

int maximumSumSubsequence(vector<int>& a, vector<vector<int>>& query) {
    ll n = a.size(),q = query.size();

    SegmentTree segTree(a);
    ll ans = 0;
    for (int i = 0; i < q; ++i) {
        int pos = query[i][0], x = query[i][1];
        --pos; 
        segTree.update(pos, x);
        ans += segTree.getMaxSum();
        ans %= mod;
    }
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