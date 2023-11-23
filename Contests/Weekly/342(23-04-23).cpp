#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

int findDelayedArrivalTime(int x, int y) {
    int ans = x;
    y %= 24;
    ans = (x+y)%24;
    return ans;
}

int sumOfMultiples(int n) {
    set<ll> s;
    for(ll i = 1;i<=n;++i){
        if(i%3 == 0){
            s.insert(i);
        }
        if(i%5 == 0){
            s.insert(i);
        }
        if(i%7 == 0){
            s.insert(i);
        }
    }
    ll ans = 0;
    for(auto it:s){
        ans += it;
    }
    return ans;
}

/*
vector<int> getSubarrayBeauty(vector<int>& v, int k, int x) {
    ordered_set os; 
    ll n = v.size();
    vector<ll> ans;
    for(ll i = 0;i<k;++i){
        os.insert(v[i]);
    }
    --x;
    ll ele = *(os.find_by_order(x));
    if(ele >= 0){
                ans.push_back(0);
            }else{
                ans.push_back(ele);
            }
    // ans.push_back(ele);

    ll l = 0,r = k;
    while(r < n){
        os.insert(v[r]);

        // Erase by order & find by order
        ll idx = os.order_of_key(v[l]);
        os.erase(os.find_by_order(idx));

        // Get the ans
        ll ele = *(os.find_by_order(x));
        if(ele >= 0){
                ans.push_back(0);
            }else{
                ans.push_back(ele);
            }
        // ans.push_back(ele);
        ++r,++l;
    }
    return ans;
}*/

int minOperations(vector<int>& v) {
    ll gcd = v[0],cntr = 0,n = v.size();
    for(auto it:v){
        gcd = __gcd(gcd,it);
        if(it == 1){
            ++cntr;
        }
    }

    if(cntr > 0){
        return n-cntr;
    }

    ll mn = 1e7;
    for (ll i = 0;i<n;++i) {
        ll gcd = v[i];
        for (ll j=i+1;j<n;++j) {
            gcd = __gcd(v[j], gcd); 
            if(gcd == 1) {
                mn = min(mn,j-i); 
                break;
            }
        }
    }
 
    if (mn != 1e7){
        ll ans = n+mn-1;
        return ans;
    }
    return -1;
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
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