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
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n = t.size();
        map<int,int> mp;
        int ans = n+1;
        for(int j=1;j<=6;++j){
            int swaps = 0;
            // top formation
            for(int i = 0;i<n;++i){
                if(t[i] != j){
                    if(b[i] == j){swaps++;}
                    else{swaps = n+1;}
                }
            }

            ans = min(ans,swaps);
            
            // bottom formation
            swaps = 0;
            for(int i = 0;i<n;++i){
                if(b[i] != j){
                    if(t[i] == j){swaps++;}
                    else{swaps = n+1;}
                }
            }
            ans = min(ans,swaps);
        }

        if(ans == n+1){ans = -1;}
        return ans;
    }
};