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
#define pyes cout << "YES" << endl;
#define pno cout << "NO" << endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
/*
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
ll power(ll best,ll n,ll mod){
    ll ans = 1;
    while( n!= 0){
        if(n%2){
            n-=1;
            ans = (ans*best)%mod;
        }
        else{
            n /= 2;
            best = (best*best)%mod;
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
string getEncryptedString(string s, int k) {
    string t = s;
    int n = s.size();
    for(int i=0;i<s.size();++i)        {
        t[i] = (s[(i+k)%n]);
    }
    return t;
}

vector<string> ans;
void recur(int n,string s){
    if(s.size() == n){
        ans.push_back(s);
    }

    if(s.back() == '0'){
        // s.push_back('1');
        recur(n,s+'1');
    }else{
        recur(n,s+'0');
        recur(n,s+'1');
    }
}

vector<string> validStrings(int n) {
    string s="";
    recur(n,s);
    return ans;
}

bool dfs(){
    
}

int numberOfSubmatrices(vector<vector<char>>& v) {
    ll n = v.size(),m = v[0].size();

    vector<vector<ll>> dpx(n,vector<ll> (m,0));
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            ll cnt = 0;
            if(i){
                cnt += dpx[i-1][j];
            }

            if(j){
                cnt += dpx[i][j-1];
            }

            if(i and j){
                cnt -= dpx[i-1][j-1];
            }

            if(v[i][j] == 'X'){cnt++;}
            dpx[i][j] = cnt;
        }
    }

    vector<vector<ll>> dpy(n,vector<ll> (m,0));
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            ll cnt = 0;
            if(i){
                cnt += dpy[i-1][j];
            }

            if(j){
                cnt += dpy[i][j-1];
            }

            if(i and j){
                cnt -= dpy[i-1][j-1];
            }

            if(v[i][j] == 'Y'){cnt++;}
            dpy[i][j] = cnt;
        }
    }

    ll ans = 0;
    for(ll i = 0;i<n;++i){
        for(ll j = 0;j<m;++j){
            if((dpx[i][j]) and (dpx[i][j] == dpy[i][j])){++ans;}
        }
    }
    return ans;
}

const ll mod = (ll)(1e9 + 7);
const int best = 31;

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

// TLE : 
/*
"jhealpdzquofpyekevtxwxstlmtqqcogjsuvfimyrnggvnjmbbmcamttbhgirehgcrxmqqpptzvonogkwcmgnzlieekoeihjfeowwwgrvpvtaxipofvrrmhgjgsorqqeererxsfzahfubwubtswmppkpacdqruocsnfcxxhjshcxmyxaohxirhdoemcaxnhshilfkcpaabivtltpmpvvvcetdkomudqmzcndgwckglpztdipgwtbasieytldrusolgmmvshmnytyxqgdfvqpjithzmuhdczkezamtfauvuawlxpsontapcsbniiymnbsqtuhjjzjqmxgqtplstbggzndvtytmugrtrkstuhqyyikxywcjrrhyvpuodizksjqouhrhtquvmhtyakqbjbwrmxoutocoykpinzvdkhbgovlzxsplkcjyeznnbuehcmskgonpsvzlbftikkqelffsqgadhuzaopyjwdnrjqhxqcmhwuwoftldequhcdjerpuysahdchvrfkmfehidptgtribkigmwnqotlrdlgjdexpkgyyliafcmanjlwhxyffaimgmogrdtexzqcdioqpohnircddffhxtuegwqutyiipyzeytheqvfapycfywvdmgswhohulqabkfctyclvsjvgkbkktmeiafbwlxlwmwgmrejjzjlkcsviuczhxqknjtvyhsyaefsynxxedlwvpcabfsvyfunhwqjljihheopcbgjnyqhtdhexeuyafbunqmaohxeyxlpnqrefzgysuepvxrutcrmjaoyuimftwxngfdnlawdilnbcpisipnyfimnealwnsknogcpqjrksgtexsavxsdovmlvmdsupxqpdceukiizwsuvtctuwkieulihjkatflyzkbqgocajohadmqpocxdalrutyysjezwjlbkzdiadktnaocctqzfjiomlkdpjyaubwgvwshhpanvslnygbyxqwkzfhlxqznlvprduymaliottdesigsiwmsnvuvnkzflazdxkjuuwasuvjcqoymmybblmcpgxiaqdhbjuienltdqbrepyvaqorlfkijhiiquwrtzymiymhrlzorfsenojpcspxnvptbygfmpadpwsopzzvojyoxeenvmtfptbyzjsxbvgjvrlgiccyaocsorgjmjyntxfqtyldevuszgabxztgpmtooebgnfvpzkfznailljlfslansocayeuorktliceleqmjzwzbjwmowmanlwxcwcmghgbquzqmncnjinnqnhfzqulhayvlbwmyxjvkuzqmvdtvtuqdnuqhesiyenzamzygbjcpfounbjzmdmmxkshnswslqwetrwpxzvipivxqbtpnpluopduimciqtbkaytdyvyrcfhwfaozeoniyhbfkfbsbgkmlebgnvvtyagdtoogooegekesvtyjpuyewlyxiedvpdbtxvdlwgsmk"
["yjpuyewlyxied","l","tyagdto","fvpzkfznailljlfslansocayeuorktliceleqmjzwzbjwmowmanlwxcwcmghgbquzqmncnjinnqnhfzqulhayvlbwmyxjvkuzqmvdtvtuqdnuqhesiyenzamzygbjcpfounbjzmdmmxkshnswslqwetrwpxzvipivxqbtpnpluop","qtyldevuszgabxztgpmtooebgnfvpzkfznailljlfslansocayeuorktliceleqmjzwzbjwmowmanlwxcwcmghgbquzqmncnjinnqnhfzqulhayvlbwmyxjvkuzqmvdtvtu","tyagdtoogooegekesv","x","b","nlwxcwcmghgbquzqmncnjinnqnhfzqulhayvlbwmyxjvkuzqmvdtvtuqdnuqhesiyenzamzygbjcpfounbjzmdmmxkshnswslqwetrwpxzvipivxqbtpnpluopduimciqtbkaytdyvyrcfhwfaozeoniyh","pdzquofpyekevtxwxstlmtqqcogjsuvfimyrnggvnjmbbmcamttbhgirehgcrxmqqpptzvonogkwcmgnzlieekoeihjfeowwwgrvpvtaxipofvrrmhgjgsorqqeererxsfzahfubwubtswmppkpacdqruocsnfcxxhjshcxmyxaohxirhdoemcaxnhshilfkcpaabivtltpmpvvvcetdkomudqmzcndgwckglpztdipgwtbasieytldrusolgmmvshmnytyxqgdfvqpjithzmuhdczkezamtfauvuawlxpsontapcsbniiymnbsqtuhjjzjqmxgqtplstbggzndvtytmugrtrkstuhqyyikxywcjrrhyvpuodizksjqouhrhtquvmhtyakqbjbwrmxoutocoykpinzvdkhbgovlzxsplkcjyeznnbuehcmskgonpsvzlbftikkqelffsqgadhuzaopyjwdnrjqhxqcmhwuwoftldequhcdjerpuysahdchvrfkmfehidptgtribkigmwnqotlrdlgjdexpkgyyliafcmanjlwhxyffaimgmogrdtexzqcdioqpohnircddffhxtuegwqutyiipyzeytheqvfapycfywvdmgswhohulqabkfctyclvsjvgkbkktmeiafbwlxlwmwgmrejjzjlkcsviuczhxqknjtvyhsyaefsynxxedlwvpcabfsvyfunhwqjljihheopcbgjnyqhtdhexeuyafbunqmaohxeyxlpnqrefzgysuepvxrutcrmjaoyuimftwxngfdnlawdilnbcpisipnyfimnealwnsknogcpqjrksgtexsavxsdovmlvmdsupxqpdceukiizwsuvtctuwkieulihjkatflyzkbqgocajohadmqpocxdalrutyysjezwjlbkzdiadktnaocctqzfjiomlkdpjyaubwgvwshhpanvslnygbyxqwkzfhlxqznlvprduymaliottdesigsiwmsnvuvnkzflazdxkjuuwasuvjcqoymmybblmcpgxiaqdhbjuienltdqbrepyvaqorlfkijhiiquwrtzymiymhrlzorfsenojpcspxnvptbygfmpadpwsopzzvojyoxeenvmtfptbyzjsxbvgjvrlgiccyaocsorgjmjyntxfqtyldevuszgabxztgpmtooebgnfvpzkfznailljlfslansocayeuorktliceleqmjzwzbjwmowmanlwxcwcmghgbquzqmncnjinnqnhfzqulhayvlbwmyxjvkuzqmvdtvtuqdnuqhesiyenzamzygbjcpfounbjzmdmmxkshnswslqwetrwpxzvipivxqbtpnpluopduimciqtbkaytdyvyrcfhwfaozeoniyhbfkfbsbgkmlebgnvvtyagdtoogooegekesvtyjpuyewlyxiedvp","l","d","t","k","a","w","d","g","dptgtribkigmwnqotlrdlgjdexpkgyyliafcmanjlwhxyffaimgmogrdtexzqcdioqpohnircddffhxtuegwqutyiipyzeytheqvfapycfywvdmgswhohulqabkfctyclvsjvgkbkktmeiafbwlxlwmwgmrejjzjlkcsviuczhxqknjtvyhsyaefsynxxedlwvpcabfsvyfunhwqjljihheopcbgjnyqhtdhexeuyafbunqmaohxeyxlpnqrefzgysuepvxrutcrmjaoyuimftwxngfdnlawdilnbcpisipnyfimnealwnsknogcpqjrksgtexsavxsdovmlvmdsupxqpdceukiizwsuvtctuwkieulihjkatflyzkbqgocajohadmqpocxdalrutyysjezwjlbkzdiadktnaocctqzfjiomlkdpjyaubwgvwshhpanvslnygbyxqwkzfhlxqznlvprduymaliottdesigsiwmsnvuvnkzflazdxkjuuwasuvj","tpnpluopduimciqtbkaytdyvyrcfhwfaozeoniyhbfkfbsbgkmlebgnvvtyagdtoogooegekesvtyjpuyewlyxiedvpdbtx","mttbhgirehgcrxmqqpptzvonogkwcmgnzlieekoeihjfeowwwgrvpvtaxipofvrrmhgjgsorqqeererxsfzahfubwubtswmppkpacdqruocsnfcxxhjshcxmyxaohxirhdoemcaxnhshilfkcpaabivtltpmpvvvcetdkomudqmzcndgwckglpztdipgwtbasieytldrusolgmmvshmnytyxqgdfvqpjithzmuhdczkezamtfauvuawlxpsontapcsbnii","h","mlebgnvvtyagdtoogooegekesvtyjpuyewlyxiedvpdbtxvdlwg","v","j","ofpyekevtxwxstlmtqqcogjsuvfimyrnggvnjmbbmcamttbhgirehgcrxmqqpptzvonogkwcmgnzlieekoeihjfeowwwgrvpvtaxipofvrrmhgjgsorqqeererxsfzahfubwubtswmppkpacdqruocsnfcxxhjshcxmyxaohxirhdoemcaxnhshilfkcpaabivtltpmpvvvcetdkomudqmzcndgwckglpztdipgwtbasieytldrusolgmmvshmnytyxqgdfvqpjithzmuhdczkezamtfauvuawlxpsontapcsbniiymnbsqtuhjjzjqmxgqtplstbggzndvtytmugrtrkstuhqyyikxywcjrrhyvpuodizksjqouhrhtquvmhtyakqbjbwrmxoutocoykpinzvdkhbgovlzxsplkcjyeznnbuehcmskgonpsvzlbftikkqelffsqgadhuzaopyjwdnrjqhxqcmhwuwoftldequhcdjerpuysahdchvrfkmfehidptgtribkigmwnqotlrdlgjdexpkgyyliafcmanjlwhxyffaimgmogrdtexzqcdioqpohnircddffhxtuegwqutyiipyzeytheqvfapycfywvdmgswhohulqabkfctyclvsjvgkbkktmeiafbwlxlwmwgmrejjzjlkcsviuczhxqknjtvyhsyaefsynxxedlwvpcabfsvyfunhwqjljihheopcbgjnyqhtdhexeuyafbunqmaohxeyxlpnqrefzgysuepvxrutcrmjaoyuimftwxngfdnlawdilnbcpisipnyfimnealwnsknogcpqjrksgtexsavxsdovmlvmdsupxqpdceukiizwsuvtctuwkieulihjkatflyzkbqgocajohadmqpocxdalrutyysjezwjlbkzdiadktnaocctqzfjiomlkdpjyaubwgvwshhpanvslnygbyxqwkzfhlxqznlvprduymaliottdesigsiwmsnvuvnkzflazdxkjuuwasuvjcqoymmybblmcpgxiaqdhbjuienltdqbrepyvaqorlfkijhiiquwrtzymiymhrlzorfsenojpcspxnvptbygfmpadpwsopzzvojyoxeenvmtfptbyzjsx","s","irehgcrxmqqpptzvonogkwcmgnzlieekoeihjfeowwwgrvpvtaxipofvrrmhgjgsorqqeererxsfzahfubwubtswmppkpacdqruocsnfcxxhjshcxmyxaohxirhdoemcaxnhshilfkcpaabivtltpmpvvvcetdkomudqmzcndgwckglpztdipgwtbasieytldrusolgmmvshmnytyxqgdfvqpjithzmuhdczkezamtfauvuawlxpsontapcsbniiymnbsqtuhjjzjqmxgqtplstbggzndvtytmugrtrkstuhqyyikxywcjrrhyvpuodizksjqouhrhtquvmhtyakqbjbwrmxoutocoykpinzvdkhbgovlzxsplkcjyeznnbuehcmskgonpsvzlbftikkqelffsqgadhuzaopyjwdnrjqhxqcmhwuwoftldequhcdjerpuysahdchvrfkmfehidptgtribkigmwnqotlrdlgjdexpkgyyliafcmanjlwhxyffaimgmogrdtexzqcdioqpohnircddffhxtuegwqutyiipyzeytheqvfapycfywvdmgswhohulqabkfctyclvsjvgkbkktmeiafbwlxlwmwgmrejjzjlkcsviuczhxqknjtvyhsyaefsynxxedlwvpcabfsvyfunhwqjljihheopcbgjnyqhtdhexeuyafbunqmaohxeyxlpnqrefzgysuepvxrutcrmjaoyuimftwxngfdnlawdilnbcpisipnyfimnealwnsknogcpqjrksgtexsavxsdovmlvmdsupxqpdceukiizwsuvtctuwkieulihjkatflyzk","e","ubwgvwshhpanvslnygbyxqwkzfhlxqznlvprduymaliottdesigsiwmsnvuvnkzflazdxkjuuwasuvjcqoymmybblmcpgxiaqdhbjuienltdqbrepyvaqorlfkijhiiquwrtzymiymhrlzorfsenojpcspxnvptbygfmpadpwsopzzvojyoxeenvmtfptbyzjsxbvgjvrlgiccyaocsorgjmjyntxfqtyldevuszgabxztgpmtooebgnfvpzkfznailljlfslansocayeuorktliceleqmjzwzbjwmowmanlwxcwcmghgbquzqmncnjinnqnhfzqulhayvlbwmyxjvkuzqmvdtvtuqdnuqhesiyenzamzygbjcpfounbjzmdmmxks","dceukiizwsuvtctuwkieulihjkatflyzkbqgocajohadmqpocxdalrutyysjezwjlbkzdiadktnaocctqzfjiomlkdpjyaubwgvwshhpanvslnygbyxqwkzfhlxqznlvprduymaliottdesigsiwmsnvuvnkzflazdxkjuuwasuvjcqoymmybblmcpgxiaqdhbjuienltdqbrepyvaqorlfkijhiiquwrtzymiymhrlzorfsenojpcspxnvptbygfmpadpwsopzzvojyoxeenvmtfptbyzjsxbvgjvrlgiccyaocsorgjmjyntxfqtyldevuszgabxztgpmtooebgnfvpzkfznailljlfslansocayeuorktliceleqmjzwzbjwmowmanlwxcwcmghgbquzqmncnjinnqnhfzqulhayvlbwmyxjvkuzqmvdtvtuqdnuqhesiyenzamzygbjcpfou","yysjezwjlbkzdiadktnaocctqzfjiomlkdpjyaubwgvwshhpanvslnygbyxqwkzfhlxqznlvprduymaliottdesigsiwmsnvuvnkzflazdxkjuuwasuvjcqoymmybblmcpgxiaqdhbjuienltdqbrepyvaqorlfkijhiiquwrtzymiymhrlzorfsenojpcspxnvptbygfmpadpwsopzzvojyoxeenvmtfptbyzjsxbvgjvrlgiccyaocsorgjmjyn","eiafbwlxlwmwgmrejjzjlkcsviuczhxqknjtvyhsyaefsynxxedlwvpcabfsvyfunhwqjljihheopcbgjnyqhtdhexeuyafbunqmaohxeyxlpnqrefzgysuepvxrutcrmjaoyuimftwxngfdnlaw","pzkfznailljlfslansocayeuorktliceleqmjzwzbjwmowmanlwxcwcmghgbquzqmncnjinnqnhfzqulhayvlbwmyxjvkuzqmvdtvtuqdnuqhesiyenzamzygbjcpfounbjzmdmmxkshnswslqwetrwpxzvipivxqbtpnpluopduimciqtbkaytdyvyrcfhwfaozeon","m","k","lawdilnbcpisipnyfimnealwnsknogcpqjrksgtexsavxsdovmlvmdsupxqpdceukiizwsuvtctuwkieulihjkatflyzkbqgocajohadmqpocxdalrutyysjezwjlbkzdiadktnaocctqzfjiomlkdpjyaubwgvwshhpanvslnygbyxqwkzfhlxqznlvprduymaliottdesigsiwmsnvuvnkzfla","qmzcndgwckglpztdipgwtbasieytldrusolgmmvsh"]
[8001,5984,8478,9173,1574,2667,4722,213,7500,486,5237,9773,8258,3153,1944,6549,1520,571,8748,8284,2625,3296,6136,6413,87,8720,5785,1338,1187,5808,4029,9279,8852,4558,5907,2386,8167,2452]
*/

// None of below solutions worked : Try for Trie!
/*
int minimumCost(string t, vector<string>& v, vector<int>& cst) {

    ll ans = 0,n = t.size(),m = v.size();
    vector<ll> dp(n+1,LLONG_MAX);

    map<string,ll> s;
    for(ll i =0;i<m;++i){
        if(s.find(v[i]) == s.end()){
            s[v[i]] = cst[i];
        }else{
            s[v[i]] = min(1ll*cst[i],s[v[i]]);
        }
    }

    for(ll i =0;i<n;++i){
        if(i and dp[i-1] == LLONG_MAX){
            continue;
        }
        string tmp;
        for(ll j = i;j<n;++j){
            tmp += t[j];
            if(s.find(tmp) != s.end()){
                if(i){
                    if(dp[i-1] != LLONG_MAX){
                        dp[j] = min(dp[j],dp[i-1]+s[tmp]);
                    }
                }else{
                    dp[j] = s[tmp];
                }
            }
        }
        // show(dp);
        // return 0;
    }
    if(dp[n-1] == LLONG_MAX){dp[n-1] = -1;}
    return dp[n-1];
}

int minimumCost(string t, vector<string>& v, vector<int>& cst) {
    int n = t.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    
    unordered_map<ll, vector<pair<ll, ll>>> strHa;
    ll m = v.size();
    for (ll i = 0;i<m;++i) {
        ll h = compute_hash(v[i]);
        strHa[h].emplace_back(v[i].size(),cst[i]);
    }

    vector<ll> prec(n,0);
    string tmp;
    for (ll j = 0; j < n; ++j) {
        tmp += t[j];
        ll hash = compute_hash(tmp);
        prec[j] = hash;
    }


    for (ll j = 0; j < n; ++j) {
        if (dp[j] == INT_MAX) continue; 

        for (ll length = 1; j + length <= n; ++length) {

            ll curr = prec[j+length-1];
            if(j){
                curr -= prec[j-1];
            }

            if (strHa.find(curr) != strHa.end()) {
                for (auto& [len, cost] : strHa[curr]) {
                    if ((len == length) && (dp[j+length]> (dp[j]+cost))) {
                        dp[j + length] = dp[j] + cost;
                    }
                }
            }
        }
    }

    if(dp[n] != INT_MAX){
        return dp[n];
    }
    return -1;
}*/

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