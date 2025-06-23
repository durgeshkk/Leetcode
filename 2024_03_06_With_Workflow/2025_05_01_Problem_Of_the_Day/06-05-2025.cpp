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
    vector<int> buildArray(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n,0);
        forj(n){
            ans[j] = v[v[j]];
        }
        return ans;
    }

    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(!root){return ans;}
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size(),f = 0;
            while(sz--){
                Node* ele = q.front();
                q.pop();
                
                if(!f){ans.push_back(ele->data);f = 1;}

                if(ele->left){
                    q.push(ele->left);
                }
                if(ele->right){
                    q.push(ele->right);
                }
            }
        }
        return ans;
    }
};