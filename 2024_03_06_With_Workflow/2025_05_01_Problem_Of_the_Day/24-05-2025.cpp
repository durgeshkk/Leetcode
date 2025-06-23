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
    vector<int> findWordsContaining(vector<string>& s, char x) {
        vector<int> ans;
        for(int i = 0;i<s.size();i++){
            for(int j = 0;j<s[i].size();j++){
                if(s[i][j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }

    int sumSubstringsBruteForce(string &s) {
        int n=s.size();
        vector<string>sub;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                sub.push_back(s.substr(i,j-i+1));
            }
        }
        int sum=0;
        n=sub.size();
        for(int i=0;i<n;i++)
        {
            int num=stoi(sub[i]);
            sum+=num;
        }
        return sum;
    }

    int sumSubstrings(string &s) {
        int n = s.size();
        int sum = 1, pval = 1, ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            ans += ((i + 1) * ((s[i] - '0') * sum));
            pval *= 10;
            sum += pval;
        }
        return ans;      
    }
};