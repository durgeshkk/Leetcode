#include<bits/stdc++.h>
#define ll int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;

// Q 1: 
int alternateDigitSum(int n) {
    string s;
    s = to_string(n);
    int ans = 0;
    for(ll i = 0;i<s.size();++i){
        if(i & 1){
            // Take neg
            ans -= (s[i]-'0');
        }else{
            ans += (s[i]-'0');
        }
    }
    return ans;
}

// Q 2:
vector<vector<int>> sortTheStudents(vector<vector<int>>& v, int k) {
    ll n = v.size();
    ll m = v[0].size();
    vector<vector<int>> ans(n,vector<ll> (m,0));
    multiset<pair<int,int>> ms;
    for(ll i = 0;i<n;++i){
        ms.insert({v[i][k],i});
    }

    ll sz = 0;
    while(!ms.empty()){
        auto p = *ms.rbegin();
        ms.erase(ms.find(p));
        ll i = p.second;

        for(ll j = 0;j<m;++j){
            ans[sz][j] = v[i][j];
        }
        ++sz;
    }

    return ans;
}

// Q 3:
bool makeStringsEqual(string s, string t) {
    // To get '1' I need min. 1 '1'
    // To get '0' I need min. 2 '1'
    
    // So first make all 1's
    // Now target must need min. '1' as s will anyway leave 1 '1'
    
    if(s == t){return true;}
    else if(s.size() != t.size()){return false;}

    // Now t must have atleast 1 '1' and also s
    bool so = false;
    bool to = false;
    for(ll i = 0;i<s.size();++i){
        if(s[i] == '1'){so = true;}
        if(t[i] == '1'){to = true;}
    }

    return (so and to);
}

ll mn = LLONG_MAX;
vector<vector<ll>> dp;
void recur(ll idx,ll n,ll prev,ll cst,vector<ll> &v,ll k){
    if(idx == n){
        
        mn = min(cst,mn);
        return;
    }

    // Partition
    recur(idx+1,n,idx,cst+k+dp[prev][idx-1],v,k);

    // Not - Partition
    recur(idx+1,n,prev,cst,v,k);
    return;
}

ll minCost(vector<ll>& v, ll k) {
    ll n = v.size();

    dp.assign(n,vector<ll> (n,0));
    for(ll i = 0;i<n;++i){
        map<ll,ll> mp;
        ll ele = 0,cnt = 0;
        for(ll j = i+1;j<n;++j){
            if(mp.find(v[j]) == mp.end()){
            }else{
                ll z = mp[v[j]];
                if(z == 1){ele += 2;}
                else{++ele;}
            }
            dp[i][j] = ele;
            mp[v[j]]++;
        }
    }


    for(ll i = 0;i<n;++i){
        for(ll j = i+1;j<n;++j){
        }
    }

    /*
    ll l = k,r = (k*n),ans = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(mid)){
            l = mid+1;
        }else{
            ans = mid;
            r = mid-1;
        }
    }
    */
    return mn;
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