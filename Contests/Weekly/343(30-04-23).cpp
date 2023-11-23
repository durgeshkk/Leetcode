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
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 

 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
int isWinner(vector<int>& v, vector<int>& t) {
    ll a  =0,b = 0;
    ll f = 0;
    for(ll i = 0;i<v.size();++i){
        if(i >= 2){
            if(v[i-2] == 10 || v[i-1] == 10){
                a += 2*v[i];
                continue;
            }
        }
        a += v[i];
    }

    f = 0;
    for(ll i = 0;i<v.size();++i){
        if(i >= 2){
            if(t[i-2] == 10 || t[i-1] == 10){
                b += 2*t[i];
                continue;
            }
        }
        b += t[i];
    }

    if(a > b){return 1;}
    else if(a==b){return 0;}
    else{return 2;}
} 

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& v) {
    ll n = v.size(),m = v[0].size();
    map<ll,ll> row,col;
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            row[v[i][j]] = i;
            col[v[i][j]] = j;
        }
    }

    ll cntr = 0;
    vector<ll> ak(n,0),dk(m,0);
    for(auto it:arr){
        ll r = row[it],c = col[it];
        ak[r]++,dk[c]++;
        ++cntr;
        if(ak[r] == n || dk[c] == m){
            return cntr;
        }
    }
    return cntr;
}


set<pair<ll,ll>> s;
vector<ll> vis,dist;
unordered_map<pair<ll,ll>,ll> vis;
void dijkstra(ll src){
    dist[src] = 0;
    s.insert({0,src});
    while(!s.empty()){
        auto p = *s.begin();s.erase(s.find(p));vis[p.second] = 1;
        for(auto it:adj[p.second]){
            if(!vis[it.first]){
                // new_dist = dist till par + dist from par to child
                ll new_dist = (p.first+it.second);
                if(new_dist < dist[it.first]){
                    s.erase(s.find({dist[it.first],it.first}));
                    s.insert({new_dist,it.first});
                    dist[it.first] = new_dist;
                }
            }
        }
    }
}


ll si,se;
vector<vector<ll>> v;
unordered_map<pair<ll,ll>,vector<ll>> adj;
unordered_map<vector<ll>,ll> tmp;

int minimumCost(vector<ll>& s, vector<ll>& arr, vector<vector<ll>>& t) {
    v.assign(t.size(),vector<ll> (t[0].size(),0));v = t;
    
    vector<pair<ll,ll>> z;
    z.push_back({s[0],s[1]});z.push_back({arr[0],arr[1]});
    for(auto it:t){z.push_back({it[0],it[1]});z.push_back({it[2],it[3]});}

    for(ll i = 0;i<z.size();++i){
        for(ll j = 0;j<z.size();++j){
            if(i == j){continue;}
            ll x1 = z[i].first,y1 = z[i].second;
            ll x2 = z[j].first,y2 = z[j].second;
            ll dist = abs(x2-x1)+abs(y2-y1);
            tmp[{x1,y1,x2,y2}] = dist;
            tmp[{x2,y2,x1,y1}] = dist;
        }
    }

    for(auto it:t){
        ll x1 = it[0],y1 = it[1];
        ll x2 = it[2],y2 = it[3];
        ll dist = abs(x2-x1)+abs(y2-y1);
        tmp[{x1,y1,x2,y2}] = min(dist,tmp[{x1,y1,x2,y2}]);
    }

    for(auto it:tmp){
        vector<ll> ok = {it.first[2],it.first[3],it.second};
        adj[{it.first[0],it.first[1]}] = (ok);
    }


}


int minimumCost2(vector<ll>& s, vector<ll>& arr, vector<vector<ll>>& t) {
    v.assign(t.size(),vector<ll> (t[0].size(),0));v = t;
    
    ll n = t.size(),m = t[0].size();
    adj[{s[0],s[1]}] = arr;

    for(ll i = 0;i<t.size();++i){
        ll dist = abs(t[i][3]-t[i][1])+abs(t[i][2]-t[i][0]);
        adj[{t[i][0],t[i][1]}] = {t[i][2],t[i][3],min(dist,t[i][4])};

        ll st = abs(t[i][3]-s[1])+abs(t[i][2]-s[0]);
        adj[{t[i][0],t[i][1]}] = {arr[0],arr[1],st};

        ll e = abs(t[i][3]-arr[1])+abs(t[i][2]-arr[0]);
        adj[{t[i][0],t[i][1]}] = {arr[0],arr[1],e};
        
        for(ll j = i+1;j<t[0].size();++j){

        }
    }
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