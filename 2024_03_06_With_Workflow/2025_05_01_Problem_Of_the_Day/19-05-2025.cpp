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
    
    Node* pre=NULL;
    Node* succ=NULL;
    int ele1=INT_MIN;
    int ele2=INT_MAX;
    void pred(Node*root,int key){
        if(root==NULL)
        return;
        if(root->data<key){
            if(ele1<root->data){
                ele1=root->data;
                pre=root;
            }
            pred(root->right,key);
        }
        else
        pred(root->left,key);
    }
    void success(Node* root,int key){
        if(root==NULL)
        return;
        if(root->data>key){
            if(ele2>root->data){
                ele2=root->data;
                succ=root;
            }
            success(root->left,key);
        }
        else
        success(root->right,key);
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        pred(root,key);  
        success(root,key);  
        return {pre,succ};
    }
    
};