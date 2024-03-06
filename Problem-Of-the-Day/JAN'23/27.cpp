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
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
multiset<string> ms;
bool recur_word(ll idx, string &s,string tmp){
    if(idx >= s.size()){
        // If tmp exists then return 1
        if((tmp.size() != s.size()) and (ms.find(tmp) != ms.end())){
            return 1;
        }
        return 0;
    }

    bool b = false,a = false,c = false;
    // If tmp exists then clear tmp & start new tmp
    a = recur_word(idx+1,s,tmp+s[idx]);

    if(ms.find(tmp) != ms.end()){
        // c = recur_word(idx+1,s,tmp+s[idx]);
        tmp.clear();tmp += s[idx];
        b = recur_word(idx+1,s,tmp);
    }

    return (a|b|c);
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& v) {
    // Recursion on v is waste as, we can pick some elements from v multiple times 
    // in any order!!
    vector<string> ans;
    for(ll i = 0;i<v.size();++i){
        ms.insert(v[i]);
    }

    for(ll i = 0;i<v.size();++i){
        string st = v[i];
        bool a = recur_word(0,st,"");
        if(a & 1){
            ans.push_back(st);
        }
    }
    return ans;
}

void solve()
{
 
    ll n;cin>>n;
    vector<string> v(n);
    enter(v);
 
    vector<string> ans = findAllConcatenatedWordsInADict(v);
    show(ans);
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
