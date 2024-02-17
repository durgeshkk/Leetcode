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

class Solution {
public:
typedef pair<int,int> pii;
vector<vector<ll>> adj,dk;
map<ll,ll> mp;
#define V 26
const int modulo = 1924134973;
int getHashValue(string s) {
    long long sum = 0;
    for (auto character : s) {
        sum = (sum * 26 + character - 'a' + 1) % modulo;
    }
    return sum;
}

ll minDistance(ll dist[], bool sptSet[]){
    ll min = 1e10, min_index;
 
    for (ll v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

void dijkstra(ll src){
    ll dist[V]; 
    bool sptSet[V];
    for (ll i = 0; i < V; i++)
        dist[i] = 1e10, sptSet[i] = false;
 
    dist[src] = 0;
 
    for (ll count = 0; count < V - 1; count++) {
        ll u = minDistance(dist, sptSet);
        sptSet[u] = true;
 
        for (ll v = 0; v < V; v++)
            if (!sptSet[v] && adj[u][v] && dist[u] != 1e10 && ((dist[u] + adj[u][v]) < dist[v]))
                dist[v] = dist[u] + adj[u][v];
    }

    forj(V){
        dk[src][j] = dist[j];
    }
}

long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
    ll n = o.size();mp.clear();
    adj.assign(27,vector<ll> (27,1e10));dk.assign(27,vector<ll> (27,1e10));
    forj(n){
        adj[o[j]-'a'][c[j]-'a'] = min(adj[o[j]-'a'][c[j]-'a'],(ll)cost[j]);
    }

    forj(26){
        dijkstra(j);
    }

    ll ans = 0,f = 1;
    forj(s.size()){
        if(dk[s[j]-'a'][t[j]-'a'] == 1e10){f = 0;break;}
        ans += dk[s[j]-'a'][t[j]-'a'];
    }
    return ans;
}
};