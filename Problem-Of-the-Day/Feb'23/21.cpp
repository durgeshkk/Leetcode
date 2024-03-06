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
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
 
int singleNonDuplicate(vector<int>& v) {
    ll l = 0,r = v.size()-1;
    while(l <= r){
        ll mid = (l+r)/2;
        // Check on left
        if(mid != 0 and v[mid] == v[mid-1] ){
            // Now check index of mid, if odd then ele exists on right else on left
            if(mid & 1){
                l = mid+1;
            }else{
                r = mid-2;
            }
        }else if(mid+1 != v.size() and v[mid] == v[mid+1]){
            // Check on right
            if(mid & 1){
                r = mid-1;
            }else{
                l = mid+2;
            }
        }else{
            return v[mid];
        }
    }
    return v[l];
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
    ll ans = singleNonDuplicate(v);
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