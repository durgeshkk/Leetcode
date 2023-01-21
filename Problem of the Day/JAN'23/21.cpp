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
 
ll num = 0; 
vector<string> ans;
void recur(string tmp,string &s,ll i,ll n,ll cnt,string st){

    if(i >= n){
        if(tmp.empty()){
            ll val = count(st.begin(),st.end(),'.');
            if(val != 3){return;}
            ++num;
            ans.push_back(st);
        }
        return;
    }

    if(!tmp.empty()){
        ll val = (stoll(tmp));
        if(val == 0){return;}
    }


    tmp += s[i];
    ll val = (stoll(tmp));
    if(val < 0 || val > 255){return;}

    recur(tmp,s,i+1,n,cnt,st);

    if(!st.empty()){
        st += '.';
        st += tmp;
        tmp.clear();
        recur(tmp,s,i+1,n,1+cnt,st);
    }else{
        st = tmp;
        tmp.clear();
        recur(tmp,s,i+1,n,1+cnt,st);
    }
    return;
}

// vector<string> restoreIpAddresses(string s) {
vector<string> restoreIpAddresses(string s) {
    string st,tmp;
    recur(tmp,s,0,s.size(),0,st);
    return ans;
}
 
void solve()
{
    num = 0;
    ans.clear();
    string s;cin>>s;
    vector<string> dk = restoreIpAddresses(s);
    for(auto it:dk){
        cout<<it<<endl;
    }
    cout<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with num now
   // use setprecision before num
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