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

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    bool isZeroArray(vector<int>& v, vector<vector<int>>& q) {
        int n=v.size();
        vector<int> pref(n+1,0);
        for(int i=0;i<q.size();++i){
            pref[q[i][0]] += 1;
            pref[q[i][1]+1] -= 1;
        }

        int sm=0;
        for(int i =0;i<n;++i){
            sm += pref[i];
            v[i] -= sm;
            if(v[i] > 0){return false;}
        }
        return true;
    }

    int dfs(Node* root,int key){
        if(root->data == key){
            return 0;
        }

        int sa = -1;
        if(root->left){
            sa = max(sa,dfs(root->left,key));
        }
        if(root->right){
            sa = max(sa,dfs(root->right,key));
        }

        if(sa == -1){
            return -1;
        }
        return (sa+1);
    }

    int minTime(Node* root, int target) {
        // code here
        int leftD = 0,rightD=0,extendHeight=0,leftH=0,rightH=0;
        queue<Node*> q;
        if(root->left){
            q.push(root->left);
            leftH=1;
        }
        while(!q.empty()){
            ll sz = q.size();
            while(sz--){
                Node* curr = q.front();q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ++leftH;
        }

        if(root->right){
            q.push(root->right);
            rightH=1;
        }
        while(!q.empty()){
            ll sz = q.size();
            while(sz--){
                Node* curr = q.front();q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ++rightH;
        }

        int ans=0;
        if(root->left){
            ans = dfs(root->left,target);
        }

        if(root->right){
            ans = dfs(root->left,target);
        }


    }
};