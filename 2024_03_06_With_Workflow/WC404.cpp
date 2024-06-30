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


int maxHeightOfTriangle(int r, int b) {
    ll cntr = 1,heigh = 1,ans = 0,red = r,blue = b;
    while(1){
        if(cntr){
            // Consider red
            if(red-heigh >= 0){
                red -= heigh;
                ans = heigh;
            }else{
                break;
            }
        }else{
            if(blue-heigh >= 0){
                blue -= heigh;
                ans = heigh;
            }else{
                break;
            }
        }
        ++heigh;
        cntr ^= 1;
    }

    cntr = 0,heigh = 1,red = r,blue = b;ll ans1 = 0;
    while(1){
        if(cntr){
            // Consider red
            if(red-heigh >= 0){
                red -= heigh;
                ans1 = heigh;
            }else{
                break;
            }
        }else{
            if(blue-heigh >= 0){
                blue -= heigh;
                ans1 = heigh;
            }else{
                break;
            }
        }
        ++heigh;
        cntr ^= 1;
    }

    return max(ans,ans1);
}

int maximumLength(vector<int>& v) {
    ll o = 0,e = 0,dk  = 0,f = 0,cntr = 0;
    for(auto &it:v){
        it %= 2;
        if(it & 1){
            ++o;
            if(!f){
                f = 1;
                cntr = 0;
                ++dk;
            }else{
                if(cntr){
                    cntr = 0;
                    ++dk;
                }
            }
        }else{
            ++e;
            if(!f){
                f = 1;
                cntr = 1;
                ++dk;
            }else{
                if(!cntr){
                    cntr = 1;
                    ++dk;
                }
            }
        }
    }
    return max({dk,o,e});
}

int maximumLength(vector<int>& v, int k) {
    for(ll i =0;i<v.size();++i){
        v[i] %= k;
    }

    ll ans = 0,n = v.size();
    for(ll sm = 0;sm <= 2*k;++sm){

        vector<ll> dp(k+5,0);
        ll sa = 0;
        for(ll i = 0;i<n;++i){
            if((sm-v[i]) < k and ((sm-v[i]) >= 0)){
                dp[v[i]] = max(dp[v[i]],dp[(sm-v[i])]+1);
                sa = max(sa,dp[v[i]]);
            }
        }   
        ans = max(ans,sa);
    }
    return ans;
}

// Longest distance from 0 wala banda hamesha Diameter mein involved honga!
// Now again run the same algo to find the node at the farthest diastance from this Node.
vector<vector<ll>> adj;
pair<ll,ll> maxDia;
void dfs(ll i,ll par= -1, ll d = 0){
    maxDia = max(maxDia,{d,i});
    for(auto it:adj[i]){
        if(it != par){
            dfs(it,i,d+1);
        }
    }
}

int diameter(vector<vector<int>> edge) {
    adj.clear();
    ll n = edge.size()+5;
    adj.resize(n);
    for(auto it:edge){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    maxDia = {-1,-1};
    dfs(0);
    ll x = maxDia.second;
    maxDia = {-1,-1};
    dfs(x);
    return maxDia.first;
}

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int dia = diameter(edges1);
    int dia2 = diameter(edges2);
    return max({dia+1,dia2+1,(dia+1)/2+(dia2+1)/2+1});
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