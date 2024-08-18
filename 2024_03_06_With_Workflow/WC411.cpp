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
int countKConstraintSubstrings(string s, int m) {
    int n = s.size(),ans = 0;
    for(int i = 0;i<n;++i){
        for(int j = i;j<n;++j){
            int z = 0,o = 0;
            for(int k = i;k<=j;++k){
                if(s[k] == '0'){++z;}
                else{++o;}
            }

            if(z <= m or o <= m){++ans;}
        }
    }
    return ans;
}

vector<vector<ll>> dp;
ll recur(vector<int> &v, vector<int> &t, ll idx,ll f){
    if(idx >= v.size()){return 0;}

    ll &sa = dp[idx][f];
    if(sa != -1){return sa;}
    sa = 0;
    if(!f){
        // Switch
        sa = max(sa,recur(v,t,idx+2,1)+v[idx]);
        // Continue
        sa = max(sa,recur(v,t,idx+1,0)+v[idx]);
    }else{
        // Switch
        sa = max(sa,recur(v,t,idx+2,0)+t[idx]);
        // Continue
        sa = max(sa,recur(v,t,idx+1,1)+t[idx]);
    }
    return sa;
}

long long maxEnergyBoost(vector<int>& v, vector<int>& t) {
    dp.assign(v.size()+5, vector<ll> (3,-1));
    ll a = recur(v,t,0,0);
    dp.clear();
    dp.assign(v.size()+5, vector<ll> (3,-1));
    ll b = recur(v,t,0,1);
    return max(a,b);
}

/*
1 -> All 9'ans
2 -> 8 (99..) 8
3 -> All 9'ans
4 -> All 8'ans
5 -> 5 (99..) 5
6 -> 
(size)%3 = 0 -> 88..
Even
(size)%6 = 2 -> 8(77)8 Mid 2 No. are 7
(size)%6 = 4 -> 8(66)8 Mid 2 No. are 6
Odd
5,11,17 -> 88(7)88
7,13,19 -> 88(6)88
-----
7 -> 
Odd Size remove from mid ele
Size%6 == 0 -> 9999..
2,4,14,16,26,28 -> 9(77)9
8,10,20,22 -> 9(44)9

8 -> 88..
9 -> 99..
*/

int check(string s){
    int n = s.length();
    int rem = 0;
    for (int i=0;i<n;i++){
        int val = rem*10 + (s[i]-'0');
        if (val>=7){
            rem = val%7;
        }
        else {
            if ((i+1)<n){
                val *= 10;
                val += (s[i+1]-'0');
                rem = val%7;
            }
        }
    }
    if (rem==0)return 1;
    else return 0;
}

string largestPalindrome(int n, int k){
    string ans = "";

    if (k == 1 or k == 3 or k == 9){
        while (n--){
            ans += "9";
        }
        return ans;
    }

    if (k == 2){
        if (n == 1)
            return "8";
        while (n > 2){
            ans += "9";
            n--;
        }
        return "8" + ans + "8";
    }
    if (k == 4){
        for (int i = 0; i < n; i++)
            ans += "8";
        
        for (int i = 2; i + 2 < n; i++)
            ans[i] = '9';

        return ans;
    }
    if (k == 8){
        for (int i = 0; i < n; i++)
            ans += "8";
        
        for (int i = 3; i + 3 < n; i++)
            ans[i] = '9';
            
        return ans;
    }
    if (k == 5){
        if (n == 1)
            return "5";
        while (n > 2){
            ans += "9";
            n--;
        }
        return "5" + ans + "5";
    }
    if (k == 6){
        if (n == 1)
            return "6";
        if (n == 2)
            return "66";
        
        int sum = 9 * (n - 2) + 16;

        for (int i = 0; i < n - 2; i++)
            ans += "9";

        ans = "8" + ans + "8";

        while (sum % 3){
            if (n % 2){
                int mid = n / 2;
                ans[mid] = (ans[mid] - '1') + '0';
                sum--;
            }
            else{
                int mid = n / 2;
                ans[mid - 1] = (ans[mid - 1] - '1') + '0';
                ans[mid] = (ans[mid] - '1') + '0';
                sum -= 2;
            }
        }
        return ans;
    }
    
    // The annoying k = 7 case
    if (k==7){
        if (n==1)return "7";
        if (n==2)return "77";
        if (n==3)return "959";
        if (n==4)return "9779";
        if (n==5)return "99799";
        if (n==6)return "999999";
        if (n%2==1){
            int len = n/2;
            string s1,s2;
            for (int i=0;i<len;i++){
                s1 += '9';
                s2 += '9';
            }
            for (int i=9;i>=0;i--){
                string s = s1;
                s += i + '0';
                s += s2;
                if (check(s))return s;
            }
        }
        else {
            int len = (n-1)/2;
            string s1,s2;
            for (int i=0;i<len;i++){
                s1 += '9';
                s2 += '9';
            }
            for (int i=9;i>=0;i--){
                string s = s1;
                s += i + '0';
                s += i + '0';
                s += s2;
                if (check(s))return s;
            }
        }
    }

    // App 2 for 7 :
    /*
    for (int i = 0; i < n; i++)
        ans += "9";
    
    int vals[] = {1, 3, 2, 6, 4, 5};
    int mod7 = (vals[n % 6] - 1 + 7) % 7;

    if (n % 2){
        int mid = n / 2;
        int sub = vals[(n / 2) % 6];

        while (mod7){
            ans[mid] = (ans[mid] - '1') + '0';
            mod7 = (mod7 - sub + 7) % 7;
        }
    }
    else{
        int duo[] = {4, 5, 1, 3, 2, 6};
        int mid = n / 2;
        int sub = duo[(n / 2 - 1) % 6];

        while (mod7){
            ans[mid - 1] = (ans[mid - 1] - '1') + '0';
            ans[mid] = (ans[mid] - '1') + '0';

            mod7 = (mod7 - sub + 7) % 7;
        }
    }*/
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