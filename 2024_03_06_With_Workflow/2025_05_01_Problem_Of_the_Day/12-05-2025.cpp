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
    vector<int> findEvenNumbers(vector<int>& v) {
        vector<int> mp(10, 0);
        for (int i=0;i<v.size();++i){
            mp[v[i]]++;
        }

        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            if (!mp[i]) continue;
            mp[i]--;

            for (int j = 0; j <= 9; j++) {
                if (!mp[j]) continue;
                mp[j]--;
                for (int k = 0; k <= 8; k += 2) {
                    if (!mp[k]) continue;
                    ans.push_back(i*100 + j*10 + k);
                }
                mp[j]++;

            }
            mp[i]++;
        }
        return ans;
    }

    int mostBooked(int n, vector<vector<int>> &meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        
        vector <int> freq(n+1, 0);
        priority_queue <int, vector <int>, greater <int>> room;
        priority_queue <pair <int,int>, vector <pair <int,int>>, greater <pair <int,int>>> pq;
        
        for(int i = 0; i < n; i++) room.push(i);
        
        for(int i = 0; i < m; i++){
            int st = meetings[i][0];
            int end = meetings[i][1];
            int duration = end - st;
            
            while(!pq.empty() && st >= pq.top().first) {
                int y = pq.top().second;
                pq.pop();
                room.push(y);
            }
            
            if(room.empty()){
                int x = pq.top().first;
                int y = pq.top().second;
                pq.pop();
                
                pq.push(make_pair(x + duration, y));
                freq[y]++;
            }
            else{
                int book = room.top();
                room.pop();
                
                pq.push(make_pair(meetings[i][1], book));
                freq[book]++;
            }
        }
        
        int roomNum = 0;
        int mx = 0;
        for(int i = 0; i < n; i++){
            if(freq[i] > mx){
                mx = freq[i];
                roomNum = i;
            }
        }
        
        return roomNum;
    }
};