/*
Once in a LifeTime,
Will never let you Down!!
*/
#include <bits/stdc++.h>
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
ll expo(ll a, ll b, ll mod) {ll ans = 1; while (b > 0) {if (b & 1)ans = (ans * a) % mod; a = (a * a) % mod; b = b >> 1;} return ans;}
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

ll expo(ll a, ll b, ll mod) {ll ans = 1; while (b > 0) {if (b & 1)ans = (ans * a) % mod; a = (a * a) % mod; b = b >> 1;} return ans;}

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

int maximumsizeSubstring(string s) {
    ll n = s.size(),ans = 0;
    for(ll i = 0;i<n;++i){
        map<ll,ll> mp;
        for(ll j = i;j<n;++j){
            mp[s[j]]++;
            if(mp[s[j]] > 2){
                ans = max(ans,j-i);
                break;
            }
        }
    }
    return ans;
}

int minOperations(int k) {
    int ans = 0;
    for(int i = 1;i<=k;++i){
        ans = min(ans,(int)(i-1+ceil(k/i)));
    }
    return ans;
}

vector<long long> mostFrequentIDs(vector<int>& v, vector<int>& freq) {
    vector<ll> ans;
    map<ll,ll> mp;
    multiset<ll> ms;
    for(ll i = 0;i<v.size();++i){
        if(freq[i] > 0){
            if(mp.find(v[i]) != mp.end()){
                ms.erase(ms.find(mp[v[i]]));
            }
            mp[v[i]] += freq[i];
            ms.insert(mp[v[i]]);
        }else{
            if(mp.find(v[i]) != mp.end()){
                ms.erase(ms.find(mp[v[i]]));
            }
            mp[v[i]] += freq[i];
            ms.insert(mp[v[i]]);
        }
        if(ms.empty()){
            ans.push_back(0);continue;
        }
        ans.push_back(*ms.rbegin());
    }
    return ans;
}

/*
// MLE : USE TRIE
vector<int> stringIndices(vector<string>& v, vector<string>& q) {
    vector<int> ans;
    map<string,vector<string>> mp;
    ll len = 1e5,idx = -1;

    for(ll i = 0;i<v.size();++i){
        string s = v[i];
        if(s.size() < len){
            idx = i;len = s.size();
        }

        string tmp,tmp2;
        for(ll j = s.size()-1;j>=0;--j){
            tmp2 += s[j];
            tmp2 += tmp;
            
            if(mp.find(tmp2) != mp.end()){
                vector<string> dk = mp[tmp2];
                int sz = (s.size());
                int sz1 = stoi(dk[1]);
                if(sz >= sz1){
                }else{
                    mp[tmp2] = {s,to_string(sz),to_string(i)};
                }
            }else{
                mp[tmp2] = {s,to_string(s.size()),to_string(i)};
            }
            tmp = tmp2;
            tmp2.clear();
        }
    }

    for(ll i = 0;i<q.size();++i){
        string s = q[i];
        string tmp,tmp2;
        ll f = -1;
        for(ll j = s.size()-1;j>=0;--j){
            tmp2 += s[j];
            tmp2 += tmp;
            
            if(mp.find(tmp2) != mp.end()){
                f = stoi(mp[tmp2][2]);
            }
            tmp = tmp2;
            tmp2.clear();
        }

        if(f == -1){
            ans.push_back(idx);
        }else{
            ans.push_back(f);
        }
    }

    // for(auto it:q){
    //     if(mp.find(it) != mp.end()){
    //         ans.push_back(stoi(mp[it][2]));
    //     }else{
    //         ans.push_back(-1);
    //     }
    // }

    return ans;
}
*/

struct Node {
    
	Node *links[26];
	bool flag = false;
    int index = -1;

	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}

	Node *get(char ch) {
		return links[ch - 'a'];
	}

	void setEnd() {
		flag = true;
	}

	bool isEnd() {
		return flag;
	}
};

class Trie {
private:
	Node* root;
public:
	Trie() {
		root = new Node();
	}

	void insert(string &s, int ind, vector<string>& wc) {
		Node *node = root;
		for (int i = s.size()-1; i>=0; --i){
			if (!node->containKey(s[i])){
				node->put(s[i], new Node());
			}

			node = node->get(s[i]);
            
            if(node->index != -1){   
                if(wc[node->index].size() > s.size())
                    node->index = ind; 
            }
            
            else
                node->index = ind;
		}
		node->setEnd();
	}
    

	int check(string &prefix){
        vector<int> temp;
		Node* node = root;
		for (int i = prefix.size()-1; i>=0;--i) {
			if (!node->containKey(prefix[i])) {
				return node->index;
			}
			node = node->get(prefix[i]);
		}
		return node->index;
	}
};

vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
    Trie* tr = new Trie();
    for(int i=0; i<wc.size(); ++i)
        tr->insert(wc[i], i, wc);
    
    vector<int> ans;
    int index;
    int mn = 1e5;
    for(int i=0; i<wc.size(); ++i){
        int len = wc[i].size();
        mn = min(mn, len);
    }

    int def;
    for(int i=0; i<wc.size(); ++i){
        if(wc[i].size() == mn){
            def = i;
            break;
        }
    }
    
    for(int i=0; i<wq.size(); ++i){   
        index = tr->check(wq[i]);
        if(index == -1){
            ans.push_back(def);
            continue;
        }
        ans.push_back(index);
    }
    return ans;
}


void solve(){
    ll n;cin>>n;
    vector<ll> v(n);enter(v);

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