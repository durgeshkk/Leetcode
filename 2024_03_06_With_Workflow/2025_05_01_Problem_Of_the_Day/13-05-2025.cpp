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
    int lengthAfterTransformations(string s, int t) {
        int n=s.size();
        vector<int> freq(27,0);
        forj(n){
            freq[s[j]-'a']++;
        }

        while(t--){
            vector<int> currFreq(26,0);
            forj(26){
                if((j==25) and (freq[j]>0)){
                    currFreq[0] = mod_add(currFreq[0],freq[j]);
                    currFreq[1] = mod_add(currFreq[1],freq[j]);
                }else{
                    if(j<25){
                        currFreq[j+1] = mod_add(currFreq[j+1],freq[j]);
                    }
                }
            }
            forj(26){
                freq[j] = currFreq[j];
            }
        }

        ll ans = 0;
        forj(26){
            ans = mod_add(ans,freq[j]);
        }
        return ans;
    }
};