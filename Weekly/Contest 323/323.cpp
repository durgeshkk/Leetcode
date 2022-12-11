#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

// Q1 : 
/*
    int deleteGreatestValue(vector<vector<int>>& grid) {
        ll n = grid.size(),m = grid[0].size();
        for(ll i = 0;i<n;++i){
            sort(grid[i].begin(),grid[i].end());
        }

        ll ans = 0;
        for(ll j = m-1;j>=0;--j){
            ll mx = 0;
            for(ll i = 0;i<n;++i){
                mx = max(grid[i][j],(int)mx);
            }
            ans += mx;
        }
        return ans;
    }
*/

// Q2 :
/*
int longestSquareStreak(vector<int> &v) {

    map<ll,ll> mp;
    set<ll> s;
    vector<ll> tmp;
    for(ll i = 0;i<v.size();++i){
        if(s.find(v[i]) == s.end()){
            s.insert(v[i]);
            tmp.push_back(v[i]);
        }
    }

    ll n = tmp.size();
    sort(tmp.begin(),tmp.end());
    for(ll i = 0;i<tmp.size();++i){
        mp[tmp[i]] = i;
    }

    vector<ll> vis(n,0);
    ll ans= 0;
    for(ll i = 0;i<n;++i){
        if(!vis[i]){
            vis[i] = 1;
            ll sq = tmp[i]*tmp[i],len = 1;
            while(s.find(sq) != s.end()){
                ll idx = mp[sq];
                vis[idx] = 1;
                sq *= sq;
                ++len;
            }
            ans = max(ans,len);
        }
    }
    if(ans <= 1){
        ans = -1;
    }
    return ans;
}*/

// Q3 :
/*
class Allocator {
public:
    vector<ll> v;
    ll rem;
    Allocator(int n) {
        v.assign(n,0);
        rem = n;
    }
    
    int allocate(int size, int mID) {
        if(rem < size ){return -1;}

        ll cnt = 0,start = -1,end = -1;
        for(ll i = 0;i<v.size();++i){
            if(v[i]){
                cnt = 0;
            }else{
                ++cnt;
            }

            if(cnt >= size){
                end = i;
                start = i-cnt+1;
                break;
            }
        }

        if(start == -1){
            return -1;
        }else{
            for(ll i = start;i<=end;++i){
                v[i] = mID;
            }
            return start;
        }
    }
    
    int free(int mID) {
        ll f = 0;
        for(ll i = 0;i<v.size();++i){
            if(v[i] == mID){
                ++f;v[i] = 0;++rem;
            }
        }
        return f;
    }
};
*/

// Q3 
// Extra Tamm Jhammm
/*
class Allocator {
public:
    map<ll,set<pair<ll,ll>>> mp;
    multiset<ll> s;//free size
    map<ll,set<pair<ll,ll>>> mid;
    ll *obj;
    
    multiset<pair<ll,ll>> fr;//free size

    Allocator(int n) {
        obj = new ll[n];
        s.insert(n);
        mp[n].insert({0,n-1});
        fr.insert({0,n-1});
    }
    
    int allocate(int sz, int mID) {
        ll z = 0,flag = 1;
        for(auto it:s){
            if(sz <= it){z = it;flag = 0;break;}
        }

        if(flag & 1){return -1;}

        s.erase(s.find(z));
        auto p = *mp[z].begin();
        mp[z].erase(mp[z].find(p));
        fr.erase(fr.find(p));

        ll start = p.first;
        ll end = (p.first+sz-1);

        mid[mID].insert({start,end}); 

        if(end == p.second){
            // Size == z do nthng
        }else{
            // Size != z ,insert size in s as well as in mp[s] {start,end_idx}
            ll val = p.second-p.first+1-sz;
            // s.insert(p.second-p.first+1-sz);
            fr.insert({end+1,p.second});
            // mp[val].insert({end+1,p.second});

            if(mID == 1 and sz == 1){
                cout<<"----\n";
                for(auto it:fr){
                    cout<<it.first<<" "<<it.second<<endl;
                }
                cout<<"----\n";
            }

            vector<pair<ll,ll>> v(fr.begin(),fr.end());
            fr.clear();

            for(auto it:fr){
                ll si = it.second-it.first+1;
                if(mp[si].find(it) == mp[si].end()){

                }else{
                    mp[si].erase(mp[si].find(it));
                    s.erase(s.find(si));
                }
            }

            ll l = v[0].first,r = v[0].second;
            for(ll i = 1;i<v.size();++i){
                if(v[i].first == (r+1)){
                    r = v[i].second;
                }else{
                    fr.insert({l,r});
                    l = v[i].first,r = v[i].second;
                }
            }
            fr.insert({l,r});

            for(auto it:fr){
                ll si = it.second-it.first+1;
                mp[si].insert(it);
                s.insert(si);
            }
        }

        if(mID == 1 and sz == 1){
            for(auto it:fr){
                cout<<it.first<<" "<<it.second<<endl;
            }
            
            for(auto it:s){
                cout<<it<<" ";
            }cout<<endl;

        }
        return start;
    }
    
    int free(int mID) {
        ll ans = 0;
        if(mid.find(mID) == mid.end()){
            return 0;
        }else{
            for(auto it:mid[mID]){
                ans += (it.second-it.first+1);
                // Insert the space to free memory
                // s.insert(it.second-it.first+1);//inserting size
                fr.insert(it);
                // mp[it.second-it.first+1].insert({it.first,it.second});
            }

            vector<pair<ll,ll>> v(fr.begin(),fr.end());
            fr.clear();

            for(auto it:fr){
                ll si = it.second-it.first+1;
                if(mp[si].find(it) == mp[si].end()){

                }else{
                    mp[si].erase(mp[si].find(it));
                    s.erase(s.find(si));
                }
            }

            ll l = v[0].first,r = v[0].second;
            for(ll i = 1;i<v.size();++i){
                if(v[i].first == (r+1)){
                    r = v[i].second;
                }else{
                    fr.insert({l,r});
                    l = v[i].first,r = v[i].second;
                }
            }
            fr.insert({l,r});

            for(auto it:fr){
                ll si = it.second-it.first+1;
                mp[si].insert(it);
                s.insert(si);
            }
            mid.erase(mid.find(mID));
        }
        return ans;
    }
};*/

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

ll n,m;
bool check(ll i,ll j){
    if(i >= n || j >= m || i<0 || j<0 ){return false;}
    return true;
}

ll ans = 0;
void recur(ll i,ll j,ll allowed,vector<vector<ll>> &v,vector<vector<ll>> &vis){

    if(!check(i,j)){return;}
    if(vis[i][j]){return;}

    vis[i][j] = 1;

    if(v[i][j] < allowed){
        // cout<<i<<" "<<j<<endl;
        ++ans;
    }else{
        return;
    }

    recur(i+1,j,allowed,v,vis);
    recur(i-1,j,allowed,v,vis);
    recur(i,j+1,allowed,v,vis);
    recur(i,j-1,allowed,v,vis);
    return;
}

void solve(){
    cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll> (m));
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            cin>>v[i][j];
        }
    }
    
    // for(ll i = 0;i<n;++i){
    //     for(ll j = 0;j<m;++j){
    //         cout<<v[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;

    ll q;cin>>q;
    vector<ll> query;
    while(q--){
        ll a;cin>>a;
        query.push_back(a);
    }

    for(ll i = 0;i<query.size();++i){
        vector<vector<ll>> vis(n,vector<ll> (m,0));
        ans = 0;
        recur(0,0,query[i],v,vis);
        // for(ll i = 0;i<n;++i){
        //     for(ll j = 0;j<m;++j){
        //         if(!vis[i][j]){
        //         }
        //     }
        // }
        cout<<ans<<endl;
    }
    return;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
    
    solve();
    return 0;
}
