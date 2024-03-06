#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

int maxSubarraySumCircular(vector<int>& nums) {
    vector<int> v(nums);

    // Modified Kadane's Algo
    ll ans = INT_MIN;
    ll sm = 0,n = v.size();
    ll currsm1 = 0,currsm2 = 0;
    ll mxsm = INT_MIN,mnsm = INT_MAX;

    for(ll i = 0;i<n;++i){
        sm += v[i];
        currsm1 += v[i];
        currsm2 += v[i];

        // Get max. sm subarray
        mxsm = max(mxsm,currsm1);
        if(currsm1 < 0){currsm1 = 0;}

        // Get min. sm subarray
        mnsm = min(mnsm,currsm2);
        if(currsm2 > 0){currsm2 = 0;}
    }

    if(sm == mnsm){
        // return max element, if all ele r neg
        ans = mxsm;
    }else{
        ans = max(mxsm,sm-mnsm);
    }
    return ans;
} 

void solve()
{
 
    int n;
    cin>>n;
    vector<int> v(n);
    enter(v);
    ll ans = maxSubarraySumCircular(v);
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
