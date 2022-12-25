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
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
 /*
// Q A: 
int closetTarget(vector<string>& words, string target, int si) {
    ll ans = LLONG_MAX,n = words.size();
    ll i = si;
    ll cnt = 0,f = 0;
    while(cnt <= n){
        if(words[i] == target){break;}
        i++;++cnt;
        f = 1;
        i = i%n;
    }

    if(cnt > n){
        ans = -1;return -1;
    }
    ans = min(ans,cnt);

    i = si;
    ll cnt = 0,f = 0;
    while(cnt <= n){
        if(words[i] == target){break;}
        i--;++cnt;
        f = 1;
        i = (n+i)%n;
    }
    ans = min(ans,cnt);
    return ans;
}

// Q B:
int takeCharacters(string s, int k) {
    ll n = s.size();
        
    map<char,ll>mp;
    mp['a'] = 0,mp['b'] = 0,mp['c'] = 0;
    for(ll i = 0;i<n;++i){
        mp[s[i]]++;
    }
    
    if(k == 0){return 0;}
    
    if(mp['a'] < k || mp['b'] < k || mp['c'] < k){
        return -1;
    }
    mp.clear();
    
    vector<vector<ll>> t(3, vector<ll>(n));
    ll c1 = 0;
    ll c2 = 0;
    ll c3 = 0;
    t[0][0] = n;
    t[1][0] = n;
    t[2][0] = n;
    for (ll j = n - 1; j >= 0; j--)
    {
        if (s[j] == 'a')
        {
            c1++;
            t[0][c1] = j;
        }
        else if (s[j] == 'b')
        {
            c2++;
            t[1][c2] = j;
        }
        else
        {
            c3++;
            t[2][c3] = j;
        }
    }

    if (min(c3, min(c1, c2)) < k)
    {
        // cout << -1 << endl;
        return -1;
    }

    ll ans = n;
    c1 = 0;
    c2 = 0;
    c3 = 0;
    for (ll i = 0; i < n; i++)
    {

        ll r = min(t[0][max(0ll, k - c1)], t[1][max(0ll, k - c2)]);
        r = min(r, t[2][max(0ll, k - c3)]);
        ans = min(ans, i + n - r);
        if (i == n)
        {
            continue;
        }
        if (s[i] == 'a')
        {
            c1++;
        }
        else if (s[i] == 'b')
        {
            c2++;
        }
        else
        {
            c3++;
        }
    }
    return ans;   
}
    
// Q C:
int maximumTastiness(vector<int>& v, int k) {
    sort(v.begin(),v.end());
    ll mx = *max_element(v.begin(),v.end());
    ll mn = *min_element(v.begin(),v.end());
    ll l = 0,r = (mx-mn),ans= 0,n = v.size();
    while(l <= r){
        ll mid = (l+r)/2;

        ll sm = 0,cnt = 0,prev = 0;

        for(ll i = 1;i<n;++i){
            sm = (v[i]-v[prev]);
            if(sm >= mid){
                ++cnt;sm = 0;
                prev = i;
            }
        }

        if((cnt+1) >= k){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }

    return ans;
}
*/

// Q D:
vector<ll> v;
map<pair<ll,ll>,ll> dp;
ll mod = (ll)(1e9+7);

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll recur(ll i,ll g1,ll n,ll &sm,ll k){
    if(i == n){
        
        if((sm-g1) >=k and g1>=k){
            return 1;
        }
        return 0;
    }

    if(dp.find({i,g1}) != dp.end()){
        return dp[{i,g1}];
    }

    // Adding to g1
    ll op1 = recur(i+1,g1+v[i],n,sm,k);

    // Adding to g2
    ll op2 = recur(i+1,g1,n,sm,k);
    ll op = mod_add(op1,op2,mod);
    return dp[{i,g1}] = (op);
}

// Trying to Optimize
/*
ll recur(ll i,ll n,ll &sm,ll k,vector<ll> flag){
    if(i == n){
        cout<<endl;
        show(flag);
        cout<<endl;
        ll g1 = 0;
        for(ll j = 0;j<n;++j){
            if(flag[j]){
                g1 += v[j];
            }
        }

        if((sm-g1) >=k and g1>=k){
            return 1;
        }
        return 0;
    }

    if(dp.find(i) != dp.end()){
        return dp[i];
    }

    // Adding to g1
    flag[i] = 1;
    ll op1 = recur(i+1,n,sm,k,flag);

    // Adding to g2
    flag[i] = 0;
    ll op2 = recur(i+1,n,sm,k,flag);

    ll op = mod_add(op1,op2,mod);
    return dp[i] = (op);
}
*/
int countPartitions(vector<int>& nums, int k) {
    ll n = nums.size();
    v.assign(n,0);
    ll sm = 0;
    for(ll i = 0;i<n;++i){
        v[i] = nums[i];
        sm += v[i];
    }
    // show(v);
    // cout<<sm<<endl;
    vector<ll> flag(n,0);
    ll ans = recur(0,0,n,sm,k);
    // ll ans = recur(0,n,sm,k,flag);
    return ans;
}

void solve()
{
 
    int k,n;cin>>n>>k;
    vector<int> v(n);enter(v);
    ll ans = countPartitions(v,k);
    cout<<ans<<endl;
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