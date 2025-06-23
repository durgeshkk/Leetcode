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
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(),m = workers.size(),ans = 0;
        int l = 0,r = n;
        sort(all(tasks));
        sort(all(workers));
        while(l <= r){
            int mid = (l+r)/2,sa = 0,i = mid-1,j=m-1,p = pills;
            multiset<int> ms(all(workers));

            while(i>=0){
                if(ms.empty()){break;}
                int ele = *ms.rbegin();
                if(tasks[i] <= ele){
                    ms.erase(ms.find(ele));
                    ++sa,--i;
                }else if(tasks[i] <= (ele+strength)){
                    if(p){
                        int x = tasks[i]-strength;
                        if(x > ele){break;}
                        int ub = *ms.lower_bound(x);
                        if(ub > *ms.rbegin()){break;}
                        // show(ms);
                        // cout<<i<<" "<<l<<" "<<r<<" "<<x<<" "<<ub<<endl;
                        ms.erase(ms.find(ub));
                        ++sa,--i,--p;
                    }else{
                        break;
                    }
                }else{break;}
            }
            if(sa >= mid){
                ans = max(ans,sa);
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
};