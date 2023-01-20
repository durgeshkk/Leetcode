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

set<vector<int>> ans;
void recur(ll i,vector<ll> &v,vector<ll> tmp,ll n,ll prev){
    if(i == n){
        ans.insert(tmp);
        return;
    }

    if(v[i] >= prev){
        // Pick 
        tmp.push_back(v[i]);
        recur(i+1,v,tmp,n,v[i]);
        tmp.pop_back();
    }

    // Not Pick
    recur(i+1,v,tmp,n,prev);
    return;
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    ans.clear();
    ll n = nums.size();
    vector<ll> tmp; 
    recur(0,nums,tmp,n,-101);
    vector<vector<int>> dk;
    for(auto it:ans){
        if(it.size() <= 1){continue;}
        dk.push_back(it);
    }
    return dk;
}
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    vector<vector<int>> dk = findSubsequences(v);

    for(ll i=0;i<dk.size();i++){
        show(dk[i]);
    }
    cout<<endl;
 
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