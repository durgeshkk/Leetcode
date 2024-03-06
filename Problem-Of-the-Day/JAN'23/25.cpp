#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void dfs(int i, int dist, vector<int> &v, vector<int>& store) {
    while (i != -1 && store[i] == -1) {
        store[i] = dist++;
        i = v[i];
    }
    return;
}

int closestMeetingNode(vector<int>& v, int x, int y) {
    ll n = v.size();
    ll ans = -1, mn = INT_MAX;
    vector<ll> dist_a(n+1, -1), dist_b(n+1, -1);

    dfs(x,0,v,dist_a);
    dfs(y,0,v,dist_b);

    for (ll i = 0;i<n;++i){
        ll dist = min(dist_a[i], dist_b[i]);
        ll mx = max(dist_a[i],dist_b[i]);
        if((dist >= 0) && (mx < mn)){
            ans = i;
            mn = mx;
        }
    }
    return ans;
}

// TLE :
/*
int closestMeetingNode(vector<int>& v, int x, int y) {
    ll n = v.size();

    set<pair<ll,ll>> s,s2;
    s.insert({x,0});
    s2.insert({y,0});

    vector<ll> vis(n+1,0);

    ll cnt = 1,child = v[x];
    vis[x] = 1;
    while(child != -1 and (!vis[child])){
        vis[child] = 1;
        s.insert({child,cnt});
        child = v[child];
        ++cnt;
    }

    vis.assign(n+1,0);
    vis[y] = 1;
    cnt = 1,child = v[y];
    while(child != -1 and (!vis[child])){
        vis[child] = 1;
        s2.insert({child,cnt});
        child = v[child];
        ++cnt;
    }

    ll ans = INT_MAX,idx = INT_MAX;
    for(auto x:s){
        auto p = x;
        for(auto y:s2){
            if(p.first == y.first){
                if(ans == max(p.second,y.second)){
                    idx = min(idx,p.first);
                }
                else if(ans > max(p.second,y.second)){
                    ans = min(ans,max(p.second,y.second));
                    idx = p.first;
                }
            }
        }
    }

    if(ans == INT_MAX){idx = -1;}
    return idx;
}
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