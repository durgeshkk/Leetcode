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

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    int colorTheGrid(int m, int n) {
        
    }

    vector<int> findSpiral(Node* root) {
        // code here
        int f = 0;
        vector<int> ans;
        stack<int> s;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                Node* ele = q.front();q.pop(); 
                if(ele->left){
                    q.push(ele->left);
                }
                if(ele->right){
                    q.push(ele->right);
                }

                if(!f){
                    s.push(ele->data);
                }else{
                    ans.push_back(ele->data);
                }
            }
            while(!s.empty()){
                int ele=s.top();s.pop();ans.push_back(ele);
            }
            f^=1;
        }
        return ans;
    }
};