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
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int l, int r, string &s){
        if(l > r){return 0;}

        int &sa=dp[l][r];
        if(sa != -1){return sa;}
        sa = -1;
        if(s[l] == s[r]){
            sa = solve(l+1,r-1,s);
        }else{
            sa = min({1+solve(l+1,r,s),1+solve(l,r-1,s),2+solve(l+1,r-1,s)});
        }
        return sa;        
    }

    int minDeletions(string s) {
        // code here
        dp.assign(s.size()+1, vector<int> (s.size()+1,-1));
        return solve(0,s.size()-1,s);
    }

    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> available;
        priority_queue<int, vector<int>, greater<int>> assigned;
        int count = 0;

        for (int time = 0, k = 0; time < nums.size(); time++) {
            while (!assigned.empty() && assigned.top() < time)
                assigned.pop();
            while (k < queries.size() && queries[k][0] <= time) 
                available.push(queries[k++][1]);
            while (assigned.size() < nums[time] && !available.empty() && available.top() >= time) {
                assigned.push(available.top());
                available.pop();
                count++;
            }
            if (assigned.size() < nums[time])
                return -1;
        }
        return queries.size() - count;
    }
};