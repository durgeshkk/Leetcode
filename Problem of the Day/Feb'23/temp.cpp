class Solution {
public:
    vector<ll> shortestAlternatingPaths(ll n, vector<vector<ll>>& r, vector<vector<ll>>& b) {
        
        //create adjacency list
        vector<vector<ll>> adj_b(n);
        vector<vector<ll>> adj_r(n);
        
        for(ll i=0;i<n;i++){
            adj_r[r[i][0]].push_back(r[i][1]);
        }
        
        for(ll i=0;i<n;i++)
        {
            adj_b[b[i][0]].push_back(b[i][1]);
        }
        
        queue<pair<ll,ll>> q;
        
        vector<pair<ll,ll>> ans(n,{INT_MAX,INT_MAX});
        ans[0]={0,0};
        q.push({0,-1});
        q.push({0,1});

        ll curr=0;
        while(!q.empty())
        {
            ll sz=q.size();
            //for every node in q check if a shorter dist exists with alternative manner

            while(sz--)            
            {
                auto [node,edge]=q.front();
                q.pop();
                
                if(edge==1)
                {
                    for(auto x:adj_r[node]){
                        if(ans[x].second > curr+1){
                            q.push({x,-1});
                            ans[x].second=curr+1;
                        }
                    }
                }
                else{
                    for(auto x:adj_b[node])
                    {
                        if(ans[x].first > curr+1)
                        {
                            q.push({x,1});
                            ans[x].first=curr+1;
                        }
                    }
                }
            }
            curr++;
        }
        
        vector<ll> z(n);
        
        for(ll i=0;i<n;i++)
        {
            ll mn = min(ans[i].first,ans[i].second);
            z[i]=(mn==INT_MAX) ? -1 : mn;
        }
        return z;
        
    }
};