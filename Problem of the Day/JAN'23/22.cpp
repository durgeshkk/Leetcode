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

bool isPalindrome(string s, int st, int e) {
    while (st <= e) {
        if (s[st++] != s[e--]){
            return false;
        }
    }
    return true;
}

void recur(int idx, string &s, vector<string> &tmp,vector<vector<string>> &ans) {
    if (idx == s.size()) {
        ans.push_back(tmp);
        return;
    }

    for (int i = idx; i<s.size(); ++i) {
        if (isPalindrome(s,idx,i)) {
            tmp.push_back(s.substr(idx,i-idx+1));
            recur(i + 1, s, tmp, ans);
            tmp.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string s) {
    vector<string> tmp;
    vector<vector<string>> ans;
    recur(0,s,tmp,ans);
    return ans;
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