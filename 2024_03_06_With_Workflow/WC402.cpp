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
long long countCompleteDayPairs(vector<int>& hours) {
    ll ans = 0;
    map<ll,ll> mp;
    for(auto &it:hours){
        it %= 24;
        mp[it]++;
    }

    for(auto it:hours){
        if((!it) and (it != 12)){
            ll ele = 24-it;
            ll freq = mp[ele];
            ans += freq;
        }
    }

    ans /= 2;

    ll a = mp[12],b = mp[0];
    ans += a*(a-1)/2;
    ans += b*(b-1)/2;
    return ans;
}

long long maximumTotalDamage(vector<int>& v) {
    sort(all(v));

    vector<ll> dp,dk,freq;
    map<ll,ll> mp,indices;

    for(auto it:v){
        if(dk.empty()){
            dk.push_back(it);
            freq.push_back(1);
            continue;
        }

        if(dk.back() == it){
            ll ele = freq.back();
            freq.pop_back();
            freq.push_back(ele+1);
        }else{
            dk.push_back(it);
            freq.push_back(1);
        }
    }

    ll ptr = 0;
    multiset<ll> ms;

    forj(dk.size()){
        if(!j){
            dp.push_back(freq[j]*dk[j]);
        }else{
            ll idx = lower_bound(all(dk),dk[j]-2)-dk.begin();
            --idx;
            if(idx >= 0 and ((dk[j]-2)>dk[idx])){
                while(ptr <= idx){
                    ms.insert(dp[ptr]);
                    ++ptr;
                }
                ll mxi = *ms.rbegin();
                dp.push_back(freq[j]*dk[j]+mxi);
            }else{
                dp.push_back(freq[j]*dk[j]);
            }
        }
    }

    ll ans = 0;
    for(auto it:dp){
        ans = max(ans,it);
    }
    return ans;
}

int getSum(int BITree[], int index)
{
    int sum = 0; // Initialize result
 
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse ancestors of BITree[index]
    while (index > 0) {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BITree) at given
// index in BITree.  The given value 'val' is added to
// BITree[i] and all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse all ancestors and add 'val'
    while (index <= n) {
        // Add 'val' to current node of BI Tree
        BITree[index] += val;
 
        // Update index to that of parent in update View
        index += index & (-index);
    }
}
 
// Returns the sum of array from [0, x]
int sum(int x, int BITTree1[], int BITTree2[])
{
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}
 
void updateRange(int BITTree1[], int BITTree2[], int n,
                 int val, int l, int r)
{
    // Update Both the Binary Index Trees
    // As discussed in the article
 
    // Update BIT1
    updateBIT(BITTree1, n, l, val);
    updateBIT(BITTree1, n, r + 1, -val);
 
    // Update BIT2
    updateBIT(BITTree2, n, l, val * (l - 1));
    updateBIT(BITTree2, n, r + 1, -val * r);
}
 
int rangeSum(int l, int r, int BITTree1[], int BITTree2[])
{
    // Find sum from [0,r] then subtract sum
    // from [0,l-1] in order to find sum from
    // [l,r]
    return sum(r, BITTree1, BITTree2)
           - sum(l - 1, BITTree1, BITTree2);
}
 
int* constructBITree(int n)
{
    // Create and initialize BITree[] as 0
    int* BITree = new int[n + 1];
    for (int i = 1; i <= n; i++)
        BITree[i] = 0;
 
    return BITree;
}


class SegmentTree {
private:
    struct Node {
        int peaksCount;
        int leftPeak;  // 1 if it is a peak, 0 otherwise
        int rightPeak; // 1 if it is a peak, 0 otherwise
    };

    vector<Node> tree;
    vector<int> nums;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node].peaksCount = 0;
            tree[node].leftPeak = (start > 0 && start < n - 1 && nums[start] > nums[start - 1] && nums[start] > nums[start + 1]) ? 1 : 0;
            tree[node].rightPeak = (start > 0 && start < n - 1 && nums[start] > nums[start - 1] && nums[start] > nums[start + 1]) ? 1 : 0;
            if (tree[node].leftPeak && tree[node].rightPeak) {
                tree[node].peaksCount = 1;
            }
            return;
        }

        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);

        tree[node].peaksCount = tree[2 * node + 1].peaksCount + tree[2 * node + 2].peaksCount;

        tree[node].leftPeak = tree[2 * node + 1].leftPeak;
        if (tree[2 * node + 1].leftPeak && tree[2 * node + 2].leftPeak) {
            tree[node].leftPeak++;
        }

        tree[node].rightPeak = tree[2 * node + 2].rightPeak;
        if (tree[2 * node + 1].rightPeak && tree[2 * node + 2].rightPeak) {
            tree[node].rightPeak++;
        }

        if (nums[mid] > nums[mid + 1]) {
            tree[node].rightPeak++;
        }
        if (nums[mid] > nums[mid - 1]) {
            tree[node].leftPeak++;
        }

        if (tree[node].leftPeak && tree[node].rightPeak) {
            tree[node].peaksCount++;
        }
    }

    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            nums[idx] = val;
            tree[node].leftPeak = (start > 0 && start < n - 1 && nums[start] > nums[start - 1] && nums[start] > nums[start + 1]) ? 1 : 0;
            tree[node].rightPeak = (start > 0 && start < n - 1 && nums[start] > nums[start - 1] && nums[start] > nums[start + 1]) ? 1 : 0;
            if (tree[node].leftPeak && tree[node].rightPeak) {
                tree[node].peaksCount = 1;
            } else {
                tree[node].peaksCount = 0;
            }
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(idx, val, 2 * node + 1, start, mid);
        } else {
            update(idx, val, 2 * node + 2, mid + 1, end);
        }

        tree[node].peaksCount = tree[2 * node + 1].peaksCount + tree[2 * node + 2].peaksCount;

        tree[node].leftPeak = tree[2 * node + 1].leftPeak;
        if (tree[2 * node + 1].leftPeak && tree[2 * node + 2].leftPeak) {
            tree[node].leftPeak++;
        }

        tree[node].rightPeak = tree[2 * node + 2].rightPeak;
        if (tree[2 * node + 1].rightPeak && tree[2 * node + 2].rightPeak) {
            tree[node].rightPeak++;
        }

        if (nums[mid] > nums[mid + 1]) {
            tree[node].rightPeak++;
        }
        if (nums[mid] > nums[mid - 1]) {
            tree[node].leftPeak++;
        }

        if (tree[node].leftPeak && tree[node].rightPeak) {
            tree[node].peaksCount++;
        }
    }

    int query(int l, int r, int node, int start, int end) {
        if (r < start || l > end) return 0;
        if (l <= start && r >= end) return tree[node].peaksCount;

        int mid = (start + end) / 2;
        int left_query = query(l, r, 2 * node + 1, start, mid);
        int right_query = query(l, r, 2 * node + 2, mid + 1, end);

        return left_query + right_query;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        if (n == 0) return;

        nums = arr;
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void update(int idx, int val) {
        if (n == 0) return;
        update(idx, val, 0, 0, n - 1);
    }

    int countPeaksInRange(int l, int r) {
        if (n == 0 || l >= r || l < 1 || r > n - 2) return 0;
        return query(l, r, 0, 0, n - 1);
    }
};

vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    SegmentTree segTree(nums);
    vector<int> results;

    for (auto& query : queries) {
        int type = query[0];
        if (type == 1) {
            int l = query[1], r = query[2];
            int countPeaks = segTree.countPeaksInRange(l, r);
            results.push_back(countPeaks);
        } else if (type == 2) {
            int index = query[1], val = query[2];
            segTree.update(index, val);
        }
    }

    return results;
}

vector<int> countOfPeaks2(vector<int>& v, vector<vector<int>>& queries) {
    int *BITTree1, *BITTree2;
    ll n = v.size();
    // BIT1 to get element at any index
    // in the array
    BITTree1 = constructBITree(n);
 
    // BIT 2 maintains the extra term
    // which needs to be subtracted
    BITTree2 = constructBITree(n);
    vector<ll> pref(n);
    for(ll i = 0;i<n;++i){
        if(i == 0){
            pref[i] = 0;
        }else if(i==(n-1)){
            pref[i] = pref[i-1];
        }else{
            pref[i] += pref[i-1];
            if(v[i] > v[i-1] and v[i] > v[i+1]){++pref[i];}
        }
    }

    for(auto it:queries){
        ll l = it[1],r = it[2];
        if(it[0] == 1){
            // Update Neighbours
            // Left
            if(((l>=1) and (l<n-1)) and v[l-1] > v[l-2] and v[l-1]>v[l]){
                updateRange(BITTree1,BITTree2,n,-1,l-1,n-1);
            }
            if(((l>=1) and (l<n-1)) and v[l-1] > v[l-2] and v[l-1]>r){
                updateRange(BITTree1,BITTree2,n,1,l-1,n-1);
            }

            // Right
            if(((l) and ((l)<n-2)) and v[l+1] > v[l] and v[l+1]>v[l+2]){
                updateRange(BITTree1,BITTree2,n,-1,l+1,n-1);
            }
            if(((l) and ((l)<n-2)) and v[l+1] > r and v[l+1]>v[l+2]){
                updateRange(BITTree1,BITTree2,n,1,l+1,n-1);
            }

            if(((l) and (l<n-1)) and v[l] > v[l-1] and v[l]>v[l+1]){
                updateRange(BITTree1,BITTree2,n,-1,l,n-1);
            }
            v[l] = r;
            if(((l) and (l<n-1)) and v[l] > v[l-1] and v[l]>v[l+1]){
                updateRange(BITTree1,BITTree2,n,1,l,n-1);
            }
        }else{

        }
    }


    // Add 5 to all the elements from [0,4]
    int l = 0, r = 4, val = 5;
    updateRange(BITTree1, BITTree2, n, val, l, r);
    vector<int> ans;

    for (const auto& query : queries) {
        if (query[0] == 1) {
            int l = query[1];
            int r = query[2];
            ans.push_back(st.query(l, r));
        } else if (query[0] == 2) {
            int idx = query[1];
            int val = query[2];
            st.update(idx, val);
        }
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