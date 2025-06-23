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
    int findMissing(vector<int> &v) {
        // code here
        int n = v.size(),ans = 0;
        map<int,int> mp;
        for(int i=1;i<n;++i){
            ll diff = v[i]-v[i-1];
            mp[diff]++;
        }
        
        if(mp.size() == 1){return v[n-1]+v[1]-v[0];}
        ll actualDiff = -1,doubleDiff=-1;
        for(auto it:mp){
            if(it.second == 1){doubleDiff=it.first;}
            else{actualDiff=it.first;}
        }

        for(int i=1;i<n;++i){
            ll diff = v[i]-v[i-1];
            if(diff == doubleDiff){
                return v[i-1]+actualDiff;
            }
        }
        
        return ans;
    }

    int minTimeToReach(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));

        using State = tuple<int, int, int>;
        using PQNode = pair<int, State>;
        priority_queue<PQNode, vector<PQNode>, greater<>> pq;

        dp[0][0][0] = 0;
        pq.push({0, {0, 0, 0}});

        vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};

        // while (!pq.empty()) {
        //     // PQNode tym; vector<PQNode> state;
        //     auto [tym, state] = pq.top(); pq.pop();
        //     auto [x, y, parity] = state;

        //     if (dp[x][y][parity] < tym) continue;

        //     for (auto [dx, dy] : dir) {
        //         int nx = x + dx, ny = y + dy;
        //         if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

        //         int wait_time = max(tym, v[nx][ny]);
        //         int next_parity = 1 - parity;
        //         int next_time = wait_time + 1 + parity;

        //         if (nx == n - 1 && ny == m - 1)
        //             return next_time;

        //         if (dp[nx][ny][next_parity] <= next_time) continue;

        //         dp[nx][ny][next_parity] = next_time;
        //         pq.push({next_time, {nx, ny, next_parity}});
        //     }
        // }

        return -1;
    }
};