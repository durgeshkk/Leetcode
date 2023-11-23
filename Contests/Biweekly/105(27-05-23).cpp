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
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll sieve[1000005];
void createsieve(){
    ll ntlen = 1000000;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(ll i = 2;i*i<=ntlen;++i){
 
        // Set all multiples to 0
        if(sieve[i] == 1){
 
            for(ll j = i*i;j<=ntlen;j+=i){
                 sieve[j] = 0;
            }
        }
    }
}
 
 
vector<ll> adj[100004];
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
int buyChoco(vector<int>& v, int k) {
    sort(v.begin(),v.end());
    if(v[0]+v[1] <= k){
        return (k-(v[0]+v[1]));
    }else{
        return k;
    }
}

/*
string s;
ll n;
vector<string>v;
vector<ll> dp;
set<string> dk;

ll dfs(ll idx){
    if(idx == n){return 0;}
    // ll &a = dp[idx];
    // if(a != -1){return a;}
    ll a = n-idx+1;
    for(ll i = idx;i<n;++i){
        string tmp;
        for(ll j = idx;j<n;++j){
            tmp += s[j];
            if(dk.find(tmp) != dk.end()){
                ll sa = dfs(j+1)+(i-idx);
                a = min(a,sa);
            }
        }
    }
    return a;
}

int minExtraChar(string st, vector<string>& dictionary) {
    s = st;n = s.size();
    v.assign(dictionary.size(),"");
    v = dictionary;
    for(auto it:dictionary){dk.insert(it);}
    return dfs(0);

    // dp.assign(n+1,vector<ll>(n+1,0));
    // (all(dictionary));
    for(ll i = 0;i<n;++i){
        string tmp;
        for(ll j = i;j<n;++j){
            tmp += s[j];
            if(dk.find(tmp) != dk.end()){
                dp[i][j] = 1;
            }
        }
    }


}
*/

/*
vector<ll> v;
ll n,ans;

long long maxStrength(vector<int>& nums) {
    vector<ll> pos,neg;
    n = v.size();ans = 0;
    for(auto it:nums){
        if(it > 0){pos.push_back(it);}
        else if(it < 0){neg.push_back(it);}
    }

    sort(all(neg));
    if(!pos.size() and !neg.size()){return 0;}
    ll ans = 1;
    for(auto it:pos){ans *= it;}

    if(neg.size() & 1){
        for(ll i = 0;i<neg.size()-1;++i){
            ans *= neg[i];
        }
    }else{
        for(ll i = 0;i<neg.size();++i){
            ans *= neg[i];
        }
    }
    return ans;
}*/


ll maxi;
    vector<ll> smallest_pf; 
    vector<ll> adj[100014];
    
void sieve(){
    smallest_pf[1] = 1;
    for (ll i = 2; i < maxi; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        smallest_pf[i] = i;
 
    // separately marking smallest_pf for every even
    // number as 2
    for (ll i = 4; i < maxi; i += 2)
        smallest_pf[i] = 2;
 
    for (ll i = 3; i * i < maxi; i++) {
        // checking if i is prime
        if (smallest_pf[i] == i) {
            // marking smallest_pf for all numbers divisible by i
            for (ll j = i * i; j < maxi; j += i)
 
                // marking smallest_pf[j] if it is not
                // previously marked
                if (smallest_pf[j] == j)
                    smallest_pf[j] = i;
        }
    }
}
 
unordered_set<ll> dk; 
unordered_set<ll> factora(ll x)
{
    unordered_set<ll> ak;
    while (x > 1) {
        ak.insert(smallest_pf[x]);
        dk.insert(smallest_pf[x]);
        x = x / smallest_pf[x];
    }
    return ak;
}

vector<ll> vis;
ll bfs(ll i){
    vis[i] = 1;
    ll cntr = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            cntr += bfs(it);
        }
    }
    return (cntr+1);
}

bool canTraverseAllPairs(vector<ll>& nums) {
    maxi = (*max_element(all(nums))+10ll);
    vis.assign(maxi,0);
    smallest_pf.assign(maxi,0);
    sieve();
    
    map<pair<ll,ll>,ll> mp;
    for(auto it:nums){
        if(it == 1){return 0;}
        unordered_set<ll> x = factora(it);
        vector<ll> tmp(all(x));
        ll sz = x.size();
        for(ll i = 0;i<sz;++i){
            for(ll j = i+1;j<sz;++j){
                if(mp.find({tmp[i],tmp[j]}) == mp.end()){
                    adj[tmp[i]].push_back(tmp[j]);
                    adj[tmp[j]].push_back(tmp[i]);
                }
                mp[{tmp[i],tmp[j]}]++;
            }
        }
    }

    ll ans = 1;
    ll ele = *dk.begin(),sz = dk.size();
    ll ok = bfs(ele);
    if(ok != sz){
        return 0;
    }
    return 1;
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
 
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