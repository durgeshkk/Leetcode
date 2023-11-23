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
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll snakesAndLadders(vector<vector<int>>& v) {
    ll cnt = 1;
    ll n = v.size();

    vector<pair<ll, ll>> vis(n*n+1);
    vector<ll> col(n);
    iota(col.begin(), col.end(), 0);
    for (ll r = n - 1; r >= 0;--r) {
        for (ll c : col) {
            vis[cnt++] = {r, c};
        }
        reverse(col.begin(), col.end());
    }

    vector<ll> tmp(n*n+1, -1);
    tmp[1] = 0;
    queue<ll> q;
    q.push(1);

    while (!q.empty()) {
        ll ak = q.front();
        q.pop();
        for (ll x = ak + 1; x <= min(ak+6, n*n); x++) {
            auto [r, c] = vis[x];
            ll dest = v[r][c] != -1 ? v[r][c] : x;
            if (tmp[dest] == -1) {
                tmp[dest] = tmp[ak] + 1;
                q.push(dest);
            }
        }
    }
    return tmp[n*n];        
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