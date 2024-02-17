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
    int maxSelectedElements(vector<int>& v) {
        map<ll,ll> mp;
    for(auto it:v){mp[it]++;}
        
    
    vector<ll> tmp;
    for(auto it:mp){
        tmp.push_back(it.first);
    }

    vector<vector<ll>> grps;
    vector<ll> dk;dk.push_back(tmp[0]);
    for(ll j = 1;j<tmp.size();++j){
        if(tmp[j] == 1+tmp[j-1]){
            dk.push_back(tmp[j]);
        }else{
            grps.push_back(dk);
            dk.clear();dk.push_back(tmp[j]);
        }
    }

    if(!dk.empty()){
        grps.push_back(dk);
    }

    ll ans = 0;
    vector<pair<ll,ll>> mv,ak;
    for(auto it:grps){
        vector<ll> dk = it;
        ll freq = 0,sa = dk.size();
        for(auto x:dk){
            freq += min(2ll,mp[x]);
        }
        if(freq > dk.size()){
            mv.push_back({dk[0],1+dk[dk.size()-1]});
            ans = max(ans,sa+1);
        }else{
            mv.push_back({dk[0],dk[dk.size()-1]});
            ans = max(ans,sa);
        }
    }

        for(auto it:mv){
            cout<<it.first<<" "<<it.second<<endl;
        }
        
        ak.push_back(mv[0]);
     for(ll j = 1;j<mv.size();++j)   {
         auto p = ak[ak.size()-1];
         if(p.second+1==mv[j].first){
             ak.pop_back();
             ak.push_back({p.first,mv[j].second});
         }else{
             ak.push_back(mv[j]);
         }
     }
         mv.clear();
        for(auto it:ak){
            mv.push_back(it);
        }
        for(auto it:mv){
            cout<<it.first<<" "<<it.second<<endl;
        }
        
        
        vector<ll> till;
    till.push_back(mv[0].second-mv[0].first+1);
    for(ll i = 1;i<mv.size();++i){
        ll sa = 0;
        auto p = mv[i-1],p1 = mv[i];
        if(p1.first == p.second+2){
            till.push_back(mv[i].second-mv[i].first+2+mv[i-1].second-mv[i-1].first);
        }else if(p1.first == p.second+1){
            till.push_back(mv[i].second-mv[i].first+1+till[till.size()-1]);
        }else{
            till.push_back(mv[i].second-mv[i].first+1);
        }
    }
        show(till);
    for(auto it:till){
        ans = max(ans,it);
    }
        
    return ans;
    }
};