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

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> v,Node* ele){
        v.push_back(ele->data);
        if(ele->left){
            dfs(v,ele->left);
        }
        if(ele->right){
            dfs(v,ele->right);
        }
        if(!ele->left and !ele->right){
            ans.push_back(v);
        }
    }

    vector<vector<int>> Paths(Node* root) {
        // code here
        if(!root){return ans;}
        dfs({},root);
        return ans;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({0, 0, 0});
        moveTime[0][0] = 0;

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!minh.empty()) {
            auto current = minh.top();
            minh.pop();
            int currTime = current[0];
            int currRow = current[1];
            int currCol = current[2];
            if (currTime >= dp[currRow][currCol]) continue;
            if (currRow == n - 1 && currCol == m - 1) return currTime;
            dp[currRow][currCol] = currTime;

            for (auto& direction : directions) {
                int nextRow = currRow + direction[0];
                int nextCol = currCol + direction[1];
                if (nextRow >= 0 && nextRow < n &&
                    nextCol >= 0 && nextCol < m &&
                    dp[nextRow][nextCol] == INT_MAX) {
                    int nextTime = max(moveTime[nextRow][nextCol], currTime) + 1;
                    minh.push({nextTime, nextRow, nextCol});
                }
            }
        }
        return -1;
    }
};