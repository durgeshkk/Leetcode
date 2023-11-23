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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
/*
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
*/
 
// Fxn call(for ((b/a)%mod)) :
// ll c = (b*power(a,mod-2(prime num in power of a),mod))%mod;
// Also for formula like nCr..
ll power(ll base,ll n,ll mod){
   ll ans = 1;
   while( n!= 0){
      if(n%2){
          n-=1;
          ans = (ans*base)%mod;
      }
      else{
          n /= 2;
          base = (base*base)%mod;
      }
   }
   return ans;
}
 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
 
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
int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int ans=  0;
    for(auto it:hours)        {
        if(it >= target){++ans;}
    }
    return ans;
}

int countCompleteSubarrays(vector<int>& v) {
    set<ll> s(all(v));
    ll sz = s.size(),n = v.size(),ans = 0;

    for(ll i = 0;i<n;++i){
        set<ll> st;
        for(ll j = i;j<n;++j){
            st.insert(v[j]);
            if(st.size() == sz){++ans;}
        }
    }
    return ans;
}

string fxn(string &a,string &b,string &c){
    string ans;
    ans += a;
    ll f = 0;
    for(ll i = 0;i<ans.size();++i){
        if(ans[i] == b[0]){
            ll j = 0,k = i;
            while(k<ans.size() and j<b.size() and  ans[k] == b[j]){
                ++k,++j;
            }
            if(j == b.size()){f = 1;break;}
            if(k==ans.size()){
                while(j<b.size()){
                    ans += b[j];++j;
                }
                f = 1;break;
            }
        }
    }
    if(!f){ans += b;}

    f = 0;
    for(ll i = 0;i<ans.size();++i){
        if(ans[i] == c[0]){
            ll j = 0,k = i;
            while(k<ans.size() and j<c.size() and  ans[k] == c[j]){
                ++k,++j;
            }
            if(j == c.size()){f = 1;break;}
            if(k==ans.size()){
                while(j<c.size()){
                    ans += c[j];++j;
                }
                f = 1;break;
            }
        }
    }
    if(!f){ans += c;}
    return ans;
}

string minimumString(string a, string b, string c) {
    string ans;
    multiset<string> ms;

    // abc
    ms.insert(fxn(a,b,c));
    ms.insert(fxn(a,c,b));
    ms.insert(fxn(b,a,c));
    ms.insert(fxn(b,c,a));
    ms.insert(fxn(c,a,b));
    ms.insert(fxn(c,b,a));
    ll len = a.size()+b.size()+c.size();
    for(auto it:ms){
        len = min(len,1ll*it.size());
    }
    multiset<string> ok;
    for(auto it:ms){
        if(it.size() == len){
            ok.insert(it);
        }
    }
    ans = *ok.begin();
    return ans;
}

string l,r;
ll recur(ll idx,string &s,ll num){
    if(idx == r.size()){
        if(s>=l and s<=r){return 1;}
        return 0;
    }

    ll a =  0,b = 0;
    if(num > 0){
        ll ele = num-1;
        char ch = (ele+'0');
        s+=ch;
        a = recur(idx+1,s,ele);
        s.pop_back();
    }
    
    if(s>=l and s<=r){a++;a%=mod;}

    if(num < 9){
        ll ele = num+1;
        char ch = (ele+'0');
        s+=ch;
        b = recur(idx+1,s,ele);
        s.pop_back();
    }

    ll sa = mod_add(a,b,mod);
    return sa;
}

vector<ll> s,h;
ll n;
ll dfs(ll idx,bool li,bool hi,ll prev){
    if(idx == n){return 0;}

    ll a = 0,b = 0;
    if(!li and !hi){
        // Both not set
        if(prev+1 <= 9){
            if(prev+1<h[idx] and prev+1>s[idx]){
                a = dfs(idx+1,0,0,prev+1);
            }else if(prev+1<s[idx] || prev+1>h[idx]){
            }else{
                if((prev+1 == s[idx]) and (prev+1<h[idx])){
                    a = dfs(idx+1,li,1,prev+1);
                }else if((prev+1 > s[idx]) and (prev+1 == h[idx])){
                    a = dfs(idx+1,1,hi,prev+1);
                }else if((prev+1 == s[idx]) and (prev+1 == h[idx])){
                    a = dfs(idx+1,li,hi,prev+1);
                }
            }
        }

        if(prev-1 >= 0){
            if(prev-1<h[idx] and prev-1>s[idx]){
                b = dfs(idx+1,0,0,prev-1);
            }else if(prev-1<s[idx] || prev-1>h[idx]){
            }else{
                if((prev-1 == s[idx]) and (prev-1<h[idx])){
                    b = dfs(idx+1,li,1,prev-1);
                }else if((prev-1 > s[idx]) and (prev-1 == h[idx])){
                    b = dfs(idx+1,1,hi,prev-1);
                }else if((prev-1 == s[idx]) and (prev-1 == h[idx])){
                    b = dfs(idx+1,li,hi,prev-1);
                }
            }
        }
    }else if(li and !hi){
        // li is done hi is still pending
        if(prev+1 <= 9){
            if(prev+1 < h[idx]){
                a = dfs(idx+1,li,1,prev+1);
            }else if(prev+1 == h[idx]){
                a = dfs(idx+1,li,hi,prev+1);
            }
        }

        if(prev-1 >= 0){
            if(prev-1 < h[idx]){
                b = dfs(idx+1,li,1,prev-1);
            }else if(prev-1 == h[idx]){
                b = dfs(idx+1,li,hi,prev-1);
            }
        }
    }else if(!li and hi){
        // li is pending hi is done
        if(prev+1 <= 9){
            if(prev+1 > s[idx]){
                a = dfs(idx+1,1,hi,prev+1);
            }else if(prev+1 == s[idx]){
                a = dfs(idx+1,0,hi,prev+1);
            }
        }

        if(prev-1 >= 0){
            if(prev-1 > s[idx]){
                b = dfs(idx+1,1,hi,prev-1);
            }else if(prev-1 == s[idx]){
                b = dfs(idx+1,0,hi,prev-1);
            }
        }
    }else{
        // Both done
        if(prev > 0){
            a = dfs(idx+1,li,hi,prev-1);
        }
        if(prev < 9){
            b = dfs(idx+1,li,hi,prev+1);
        }
    }

    ll sa = mod_add(a,b,mod);
    return sa;
}

int countSteppingNumbers(string low, string high) {
    // l = low,r = high;
    s.assign(high.size()+1,0);
    h.assign(high.size()+1,0);

    for(ll i = high.size()-1;i>=0;--i){
        h[i] = (high[i]-'0');
    }

    ll j = high.size()-1;
    for(ll i = low.size()-1;i>=0;--i,--j){
        s[j] = (low[i]-'0');
    }

    ll ans=  0;
    for(ll i = s[0];i<=h[0];++i){
        ll li = 0;
        if(i == s[0]){li = 1;}
        ll hi = 0;
        if(i == h[0]){hi = 1;}
        ll sa = dfs(1,li,hi,i);
        ans = mod_add(ans,sa,mod);
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