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
    string pushDominoes(string s) {
        int n = s.size();
        vector<int> left(n,0),right(n,0);
        int x = -1;
        for(int i = n-1;i>=0;--i){
            if(s[i] == 'L'){
                x = i;
            }else if(s[i] == 'R'){
                x = -1;
            }
            left[i] = x;
        }
        x = -1;
        for(int i = 0;i<n;++i){
            if(s[i] == 'R'){
                x = i;
            }else if(s[i] == 'L'){
                x = -1;
            }
            right[i] = x;
        }
        
        string ans;
        for(int i = 0;i<n;++i){
            if(left[i] == -1 and right[i] == -1){
                ans += '.';
            }else if(left[i] == -1){
                ans += 'R';
            }else if(right[i] == -1){
                ans += 'L';
            }else{
                if((left[i] - i) > (i - right[i])){
                    ans += 'R';
                }else if((left[i] - i) == (i - right[i])){
                    ans += '.';
                }else{
                    ans += 'L';
                }
            }
        }    
        return ans;
    }
};