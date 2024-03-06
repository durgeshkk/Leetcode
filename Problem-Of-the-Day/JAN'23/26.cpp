#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll ans = LLONG_MAX; 
vector<ll> vis;
map<pair<ll,ll>,ll> mp;
vector<ll> adj[105];

// Will deduce in error
void dfs(ll i,ll dest,ll cnt,ll k,ll price){
    vis[i] = 1;
    if(i == dest){
        if(cnt+1 <= k){
            ans = min(ans,price);
        }
        return;
    }

    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it,dest,cnt+1,k,price+mp[{it,i}]);
        }
    }
    return;
}

/*
0 -> 4 
1 -> 5 0 7 2 9 
2 -> 5 
3 -> 4 
4 -> 7 0 1 
5 -> 9 2 
6 -> 2 8 5 
7 -> 4 9 0 8 2 
8 -> 7 
9 -> 6 7 
10 -> 
*/

// Use BFS :
ll bfs(ll src,ll dest,ll k,ll n){
    vector<ll> p(n+1,LLONG_MAX);
    ll cnt = 0,price = 0;

    queue<pair<ll, ll>> q;
    q.push({src,0});
    p[src] = 0;

    while(!q.empty()){
        ll sz = q.size();
        for(ll j = 0;j<sz;++j){
            auto pt = q.front();
            q.pop();
            
            ll ele = pt.first,cst = pt.second;
            for(auto it:adj[ele]){
                ll price = mp[{it,ele}];
                if (price + cst < p[it]){
                    p[it] = price + cst;
                    q.push({it, p[it]});
                }
            }

            // ll ele = q.front();q.pop();
            // for(auto it:adj[ele]){
            //     q.push(it);
            //     p[it] = min(p[it],p[ele]+mp[{ele,it}]);
            // }
        }
        ++cnt;
        if(cnt == k+1){break;}
    }
    return p[dest];
}

// Correct Sol :
/*
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight : flights){
            // flight[0] represent node i, flight[1] represent neighbor node of node i, flight[2] represent cost between node i to neighbor node
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        //it will store [node, cost]
        queue<pair<int, int>> q;
        q.push({src, 0});
        //it will store minimum cost to reach each node
        vector<int> minCost(n, INT_MAX);
        int stops = 0;
        while(!q.empty() && stops <= k){
            int size = q.size();
            while (size--) {
                auto [currNode, cost] = q.front();
                q.pop();
                for (auto& [neighbour, price] : adj[currNode]) {
                    if (price + cost < minCost[neighbour]){
                        minCost[neighbour] = price + cost;
                        q.push({neighbour, minCost[neighbour]});
                    }
                }
            }
            stops++;
        }
        if(minCost[dst] == INT_MAX)
            return -1;
        return minCost[dst];
    }
};
*/

int findCheapestPrice(int n, vector<vector<int>>& v, int src, int dst, int k) {
    for(ll i = 1;i<=n;++i){adj[i].clear();}
    vis.assign(n+1,0);mp.clear();

    for(auto x:v){
        ll f = x[0],s = x[1],wt = x[2];
        adj[f].push_back(s);
        mp[{f,s}] = wt;mp[{s,f}] = wt;
    }


    for(ll i = 1;i<=n;++i){
        cout<<i<<" -> ";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }cout<<endl;
    }

    ans = bfs(src,dst,k,n);

    if(ans == LLONG_MAX){ans = -1;}
    return ans;
}

void solve()
{
 
    ll n;cin>>n;
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