/*
Once in a LifeTime,
Will never let you Down!!
*/
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
// YE DIL MAANGE MORE!!

vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
    vector<string> ans;
    map<string,vector<string>> mp;
    for(auto it:a){
        mp[it[0]].push_back(it[1]);
    }

    for(auto it:mp){
        sort(all(it.second));
    }

    for(auto it:mp){
        vector<string> v= it.second;
        if(v.size() >= 3){
            ll l = 0,h = 2,f = 0;
            while(h<v.size()){
                string x,y;
                x += v[l][0];x += v[l][1];
                y += v[h][0];y += v[h][1];
                string x2,y2;
                x2 += v[l][2];x2 += v[l][3];
                y2 += v[h][2];y2 += v[h][3];

                ll hrx = stoll(x);ll mnx = stoll(x2);ll hry = stoll(y);ll mny = stoll(y2);
                if(hrx == 23){
                    mnx = 59;
                }else if(mnx){
                    mnx--;
                    hrx++;
                    if(hrx == 24){hrx = 23;mnx = 59;}
                }else{
                    mnx = 59;
                }

                if((hry <= hrx) and (mny <= mnx)){f = 1;}

                if(f){
                    ans.push_back(it.first);break;
                }
                ++h,++l;
            }
        }
    }
    return ans;
}

pair<ll,ll> solver(vector<int>& v, vector<int>& t){
    ll n = v.size(),f = 1,ans = 0;
    ll mx1 = v[n-1],mx2 = t[n-1];

    set<ll> idx;
    forj(n-1){
        if(v[j] > mx1){
            swap(v[j],t[j]);
            ++ans;
            idx.insert(j);
        }
    }

    forj(n-1){
        if(t[j] > mx2){
            if(idx.find(j) != idx.end()){f = 0;break;}
            swap(v[j],t[j]);
            ++ans;
            idx.insert(j);
        }

    }

    ll m1 = *max_element(all(v));
    ll m2 = *max_element(all(t));
    if((m1 > mx1) || (m2 > mx2)){f = 0;}
    return {f,ans};
}

int minOperations(vector<int>& nums1, vector<int>& nums2) {
    vector<int> x,y;
    for(auto it:nums1){x.push_back(it);}
    for(auto it:nums2){y.push_back(it);}

    auto p = solver(x,y);
    swap(x[x.size()-1],y[y.size()-1]);
    auto p2 = solver(x,y);

    ll n = x.size();
    ll ans = n+1;
    if(p.first){
        ans = min(ans,p.first);
    }
    if(p2.first){
        ans = min(ans,p2.first);
    }
    if(ans == n+1){ans = -1;}return ans;
}


class Trie{
    ll cntZero,cntOne;
    Trie* zeroPtr;
    Trie* onePtr;
public:
    Trie(){
        cntZero=cntOne=0;
        zeroPtr=onePtr=NULL;
    }

    void insert(Trie *root,ll ele){
        bitset<21> b(ele);
        for(ll i = 20;i>=0;--i){
            if(b[i]){
                if(!root->onePtr){
                    root->onePtr = new Trie();
                }
                root->cntOne++;
                root = root->onePtr;
            }else{
                if(!root->zeroPtr){
                    root->zeroPtr = new Trie();
                }
                root->cntZero++;
                root = root->zeroPtr;
            }
        }
    }

    void remove(Trie* root,ll ele){
        bitset<21> b(ele);
        for(ll i = 20;i>=0;--i){
            if(b[i]){
                root->cntOne--;
                root = root->onePtr;
            }else{
                root->cntZero--;
                root = root->zeroPtr;
            }
        }
    }

    ll getMx(Trie* root,ll ele){
        ll ans = 0;
        for(ll i=20;i>=0;--i){
            if((1<<i)&ele){
                // We have 1,
                // Call for 0 if present, since it will be max.
                if(root->cntZero){
                    root = root->zeroPtr;
                    ans += (1<<i);
                }else{
                    root = root->onePtr;
                }
            }else{
                // We have 0,
                // Call for 1 if present, since it will be max.
                if(root->cntOne){
                    root = root->onePtr;
                    ans += (1<<i);
                }else{
                    root = root->zeroPtr;
                }
            }
        }
        return ans;
    }
};

int maximumStrongPairXor(vector<int>& a) {
    ll n = a.size();
    sort(all(a));vector<ll> v(all(a));

    ll ans=  0,j = 0;
    Trie *root = new Trie();    
    for(ll i = 0;i<n;++i){
        while(j<n and (abs(v[j]-v[i]) <= v[i])){
            root->insert(root,v[i]);
            ++j;
        }
        ans = max(ans,root->getMx(root,v[i]));
        root->remove(root,v[i]);
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