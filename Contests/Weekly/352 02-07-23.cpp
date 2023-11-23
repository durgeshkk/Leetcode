#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
 
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

int longestAlternatingSubarray(vector<int>& v, int x) {
    ll n = v.size(),ans = 0;     
    for(ll i = 0;i<n;++i)   {
        for(ll j = i;j<n;++j){
            // [i,j]
            if(v[i] & 1){continue;}
            ll f = 1;
            for(ll k = i;k<=j;++k){
                if(v[k] > x){f = 0;}
            }
            for(ll k = i;k<j;++k){
                ll x = v[k]%2;
                ll y = v[k+1]%2;
                if(x == y){f = 0;}
            }
            if(f){
                ans = max(ans,j-i+1);
            }
        }
    }
    return ans;
}

vector<vector<ll>> findPrimePairs(ll n) {
    createsieve();
    vector<vector<ll>> ans;
    for(ll i = 1;i<=(n/2);++i){
        ll rem = n-i;
        if(sieve[i] and sieve[rem]){
            ans.push_back({i,rem});
        }
    }
    return ans;
}

long long continuousSubarrays(vector<int>& v) {
    ll l = 0,r = 0,n = v.size(),ans = 0;
    multiset<ll> ms;
    while(r < n){
        ll mn = 0,mx=0;
        if(!ms.empty()){
            mn = *ms.begin(),mx = *ms.rbegin();
        }

        ll diff = abs(mx-mn);
        if(diff > 2){
            ans += (r-l);
            ms.erase(ms.find(v[l]));
            ++l;
        }else{
            ++r;
            if(r < n){
                ms.insert(v[r]);
            }
        }
    }
    ll ok = (r-l);
    ll sa = ok*(ok+1)/2;
    ans += sa;
    return ans;
}

int sumImbalanceNumbers(vector<int>& v) {
    ll n = v.size(),ans = 0;
    for(ll i = 0;i<n;++i){
        ordered_set os;
        ll prev = 0;
        for(ll j = i;j<n;++j){
            // Check if we can reduce prev or not
            os.insert(v[j]);

            ll idx = *os.order_of_key(v[j]);
            ll l = 0,r = 0;
            if(idx > 0){
                l = v[j]-(*os.find_by_order(idx-1));
            }
            if(idx+1 < os.size()){
                r = (*os.find_by_order(idx+1))-v[j];
            }
            if(l == 1 and r == 1){--prev;}
            if(l > 1 || r>1){++prev;}
        }
        ans += prev;
    }
    return ans;
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
   return 0;
}