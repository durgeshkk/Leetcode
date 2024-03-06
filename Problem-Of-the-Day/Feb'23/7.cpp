#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

int totalFruit(vector<int>& v) {

    multiset<pair<ll,ll>> ms;
    ll old = 0,newda = 0,ans = 0;
    set<ll> s;
    map<ll,ll> mp;

    for(ll i = 0;i<v.size();++i){
        mp[v[i]] = i;

        newda = v[i];
        s.insert(v[i]);
        ms.insert({i,v[i]});

        if(s.size() == 3){
            ll remove;
            for(auto it:s){
                if(it == newda || it==old){
                }else{
                    remove = it;break;
                }
            }
            s.erase(s.find(remove));
            ll idx = mp[remove];
            // Remove all idx b4 remove

            while(!ms.empty()){
                auto p = *ms.begin();
                if(p.first <= idx){
                    ms.erase(ms.find(p));
                }else{
                    break;
                }
            }
        }
        
        ll sz = ms.size();
        ans = max(ans,sz);
        old = v[i];
    }
    return ans;
    /*
    map<ll,ll> mp;

    ll ans = 0,prev = 0,naya = 0,len = 0;
    for(ll i = 0;i<v.size();++i){
        mp[v[i]] = i;
        naya = v[i];

        if(mp.size() == 3){
            // Remove the front of queue from q and from mp;
            ll remove = 0;
            for(auto it:mp){
                if(it.first == prev || it.first == naya){}
                else{remove = it.first;}
            }
            ans = max(ans,i-mp[remove]);
            ans = max(ans,i-len-1);
            len = mp[remove];
            mp.erase(mp.find(remove));
        }
        prev = naya;
    }
    return ans;*/
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
    // show(v);
    ll ans = totalFruit(v);
    cout<<ans<<endl;
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}