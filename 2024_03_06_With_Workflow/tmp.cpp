class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        vector<vector<int>>intervals;
        map<pair<int,int>,long long int>mp;

        for(int i=0;i<coins.size();i++){
            intervals.push_back({coins[i][0],coins[i][1]});
            mp[{coins[i][0],coins[i][1]}]=coins[i][2];    
        }

        sort(intervals.begin(),intervals.end());

        int i=0;
        queue<int>q;    
        long long int totbags=0;
        long long int totcoins=0;
        int lastidx=0;
        long long int ans=0;

        while(i<intervals.size()){
            if(i-1>=0){
                totbags+=intervals[i][1]-intervals[i-1][1];
            }
            else{
                totbags=intervals[i][1]-intervals[i][0]+1;    
            }

            long long int range=intervals[i][1]-intervals[i][0]+1; 

            if(totbags<=k){
                totcoins+=mp[{intervals[i][0],intervals[i][1]}]*range;
                ans=max(ans,totcoins);
            }
            else{
                if(i-1>=0){
                    totbags-=intervals[i][1]-intervals[i-1][1];
                }
                else{
                    totbags-=intervals[i][1]-intervals[i][0]+1;   
                }

                long long int rem=k-totbags;

                long long int coinstobetaken=rem*mp[{intervals[i][0],intervals[i][1]}];

                totcoins+=coinstobetaken;
                ans=max(ans,totcoins);    
                totcoins-=coinstobetaken;

                while(lastidx<intervals.size()&&(intervals[i][1]-intervals[lastidx][0]+1)>k){
                    long long int range=intervals[lastidx][1]-intervals[lastidx][0]+1;
                    totcoins-=range*mp[{intervals[lastidx][0],intervals[lastidx][1]}];
                    lastidx++;
                }

                totcoins+=(intervals[i][1]-intervals[i][0]+1)*(mp[{intervals[i][0],intervals[i][1]}]);
                ans=max(ans,totcoins);
            }
            i++;
        }    
        // cout<<ans<<endl;



        totbags=0;
        totcoins=0;
        lastidx=intervals.size()-1;
        i=lastidx;

        while(i>=0){
            if(i+1<intervals.size()){
                totbags+=intervals[i+1][0]-intervals[i][0];
            }
            else{
                totbags=intervals[i][1]-intervals[i][0]+1;    
            }
            long long int range=intervals[i][1]-intervals[i][0]+1; 

            if(totbags<=k){
                totcoins+=mp[{intervals[i][0],intervals[i][1]}]*range;
                ans=max(ans,totcoins);
            }
            else{
                if(i+1<intervals.size()){
                    totbags-=intervals[i+1][0]-intervals[i][0];
                }
                else{
                    totbags-=intervals[i][1]-intervals[i][0]+1;
                }

                long long int rem=k-totbags;
                long long int coinstobetaken=rem*mp[{intervals[i][0],intervals[i][1]}];
                totcoins+=coinstobetaken;
                ans=max(ans,totcoins);    
                totcoins-=coinstobetaken;
                while(lastidx>=0&&(intervals[lastidx][1]-intervals[i][0]+1)>k){
                    long long int range=intervals[lastidx][1]-intervals[lastidx][0]+1;
                    totcoins-=range*mp[{intervals[lastidx][0],intervals[lastidx][1]}];
                    lastidx--;
                }
                totcoins+=(intervals[i][1]-intervals[i][0]+1)*(mp[{intervals[i][0],intervals[i][1]}]);
                // ans=max(ans,totcoins);
            }
            cout<<i<<" "<<totcoins<<endl;
            i--;
        }    
        
        return ans;
    }
};