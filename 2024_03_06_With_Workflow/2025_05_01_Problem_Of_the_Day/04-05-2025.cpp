/*
Once in a LifeTime,
Will never let you Down!!
*/
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& v) {
        map<vector<int>,int> mp;
        for(auto it:v){
            mp[it]++;
        }

        int ans = 0;
        for(auto it:mp){
            ans += (it.second*(it.second-1))/2;
        }
        
        for(auto it:v){
            if(it[1] == it[0]){continue;}
            mp[it]--;
            vector<int> x;
            x.push_back(it[1]);
            x.push_back(it[0]);
            ans += mp[x];
        }

        return ans;
    }

    int findSubString(string& s) {
        set<int> st(all(s));
        int cnt = st.size(),ans = s.size()+1;
        map<char,int> mp;
        int l = 0,r = 0;
        while(r < s.size()){
            mp[s[r]]++;
            while(mp[s[l]] > 1){
                mp[s[l]]--;
                if(!mp[s[l]]){mp.erase(mp.find(s[l]));}
                ++l;
            }
            if(mp.size() == cnt){
                ans = min(ans,r-l+1);
            }
            ++r;
        }
        return ans;
    }
};