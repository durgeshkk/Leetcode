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
 
/*
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
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
string digitSum(string s, int k) {
    ll sz = s.size();
    while(sz > k){
        string tmp;
        for(ll i = 0;i<sz;++i){
            ll cntr = 0;
            ll sm = 0;
            while(i<sz and cntr < k){
                sm += (s[i]-'0');
                ++cntr;++i;
            }
            --i;
            tmp += to_string(sm);
        }
        s = tmp;
        sz = s.size();
    }        
    return s;
}

int minimumRounds(vector<int>& v) {
    ll n = v.size();
    map<ll,ll> mp;
    for(ll i = 0;i<n;++i){
        mp[v[i]]++;
    }
    ll ans=  0;
    for(auto it:mp){
        if(it.second == 1){
            return -1;
        }else{
            ans += ceil(1.0*it.second/3);
        }
    }
    return ans;
}

/*
[[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],[40,9,1,10,6],[22,7,4,5,3]]
[[4,3,2],[7,6,1],[8,8,8]]
[[1,5,2,4,25]]
*/
// Same Approach a bit modified
/*
int maxTrailingZeros(vector<vector<int>>& v) {
    ll n = v.size(),m = v[0].size();
    vector<vector<ll>> td,dt,lr,rl; 
    td.assign(n,vector<ll> (m,0));dt.assign(n,vector<ll> (m,0));
    rl.assign(n,vector<ll> (m,0));lr.assign(n,vector<ll> (m,0));

    map<ll,ll> fve,two,ten;
    for(ll i = 0;i<n;++i){
        forj(m){
            ll ele = v[i][j],te = 0,fv = 0,t = 0;
            if(fve.find(ele) != fve.end()){continue;}

            while(ele > 0){
                ll f = 1;
                if(ele%10 == 0){
                    f = 0,++te;
                }else if(ele %5 == 0){
                    f = 0,++fv;
                }else if(ele %2 == 0){
                    f = 0,++t;
                }
                if(f){break;}
            }
            fve[ele] = fv;
            ten[ele] = te;
            two[ele] = t;
        }
    }

    for(ll i = 0;i<n;++i){
        ll cntr = 0,f = 0,t = 0;
        forj(m){
            cntr += ten[v[i][j]];
            t += two[v[i][j]];
            f += fve[v[i][j]];
            lr[i][j] = cntr+min(f,t);
        }
    }

    for(ll i = 0;i<n;++i){
        ll cntr = 0,f = 0,t = 0;
        for(ll j=m-1;j>=0;--j){
            cntr += ten[v[i][j]];
            t += two[v[i][j]];
            f += fve[v[i][j]];
            rl[i][j] = cntr+min(f,t);
        }
    }

    forj(m){
        ll cntr = 0,f = 0,t = 0;
        for(ll i = 0;i<n;++i){
            cntr += ten[v[i][j]];
            t += two[v[i][j]];
            f += fve[v[i][j]];
            td[i][j] = cntr+min(f,t);
        }
    }
    
    forj(m){
        ll cntr = 0,f = 0,t = 0;
        for(ll i = n-1;i>=0;--i){
            cntr += ten[v[i][j]];
            t += two[v[i][j]];
            f += fve[v[i][j]];
            dt[i][j] = cntr+min(f,t);
        }
    }

    for(ll i = 0;i<n;++i){
        forj(m){
            cout<<lr[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    
    for(ll i = 0;i<n;++i){
        forj(m){
            cout<<rl[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    for(ll i = 0;i<n;++i){
        forj(m){
            cout<<td[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    for(ll i = 0;i<n;++i){
        forj(m){
            cout<<dt[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;

    ll ans = 0;
    for(ll i = 0;i<n;++i){
        forj(m){
            ll t = 0,b = 0,l = 0,r = 0;
            if(i+1 < n){
                b = dt[i+1][j];
            }
            if(i-1 >= 0){
                t = td[i-1][j];
            }
            if(j+1 < m){
                r = rl[i][j+1];
            }
            if(j-1 >= 0){
                l = lr[i][j-1];
            }

            // pssbl ans = t+b,t+l,t+r,l+r,l+b,r+b
            ll sa = max({t+lr[i][j],l+td[i][j],t+dt[i][j],b+td[i][j],
                t+rl[i][j],r+td[i][j],l+rl[i][j],r+lr[i][j],l+dt[i][j],
                b+lr[i][j],r+dt[i][j],b+rl[i][j]});
            // ll sa = max({t+b,t+l,t+r,l+r,l+b,r+b});
            ans = max(ans,sa);
        }
    }
    return ans;
}*/

int maxTrailingZeros(vector<vector<int>>& grid) {
    ll n=grid.size(), m=grid[0].size();
    vector<vector<pair<ll,ll>>> v(n,vector<pair<ll,ll>>(m,{0,0})),lr,td,rl,dt;
    
    for(ll i=0;i<n;i++){
        forj(m){
            ll z=grid[i][j],c1=0,c2=0;
            while(z%2==0){
                z/=2;
                c1++;
            }
            while(z%5==0){
                z/=5;
                c2++;
            }
            v[i][j].first=c1;
            v[i][j].second=c2;
        }
    }

    lr=td=rl=dt=v;
    for(ll i=0;i<n;i++){
        for(ll j=1;j<m;j++){
            lr[i][j].first+=lr[i][j-1].first;
            lr[i][j].second+=lr[i][j-1].second;
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=m-2;j>=0;j--){
            rl[i][j].first+=rl[i][j+1].first;
            rl[i][j].second+=rl[i][j+1].second;
        }
    }

    forj(m){
        for(ll i=1;i<n;i++){
            td[i][j].first+=td[i-1][j].first;
            td[i][j].second+=td[i-1][j].second;
        }
    }

    forj(m){
        for(ll i=n-2;i>=0;i--){
            dt[i][j].first+=dt[i+1][j].first;
            dt[i][j].second+=dt[i+1][j].second;
        }
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        forj(m){
            ll c1,c2,c3,c4,x1,x2,x3,x4,a,b;
            a=v[i][j].first;
            b=v[i][j].second;       
            
            c1=lr[i][j].first;
            c2=rl[i][j].first;
            
            c3=td[i][j].first;
            c4=dt[i][j].first;
            
            x1=lr[i][j].second;
            x2=rl[i][j].second;
            
            x3=td[i][j].second;
            x4=dt[i][j].second;
            
            ans=max({ans,min(c3+c1-a,x3+x1-b),min(c3+c2-a,x3+x2-b),
            min(c4+c1-a,x4+x1-b),min(c4+c2-a,x4+x2-b)});
        }
    }
    return ans;
}

vector<ll> vis;
string s;
ll ans;
ll recur(ll i){
    vis[i] = 1;
    ll a = 0,b = 0,c = 0;
    for(auto it:adj[i]){
        if(!vis[it] and s[i] != s[it]){
            ll tmp = recur(it);
            if(tmp > a){
                b = a;
                a = tmp;
            }else{
                b = max(b,tmp);
            }
        }else if(!vis[it]){
            c = max(c,recur(it));
        }
    }
    ans = max({ans,a+b+1,c});
    return (a+1);
}

int longestPath(vector<int>& par, string st) {
    ll n = par.size();
    s = st;
    ans = 0;
    vis.assign(n+1,0);
    for(ll i = 1;i<n;++i){
        adj[i].push_back(par[i]);
        adj[par[i]].push_back(i);
    }

    // ll ans=  0;
    for(ll i = 0;i<n;++i){
        if(!vis[i]){
            ll sa = recur(i);
            // ans = max(ans,sa);
        }
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