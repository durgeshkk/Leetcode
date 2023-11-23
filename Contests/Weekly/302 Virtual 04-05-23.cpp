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
vector<int> numberOfPairs(vector<int>& nums) {
    map<int,int> mp;
    for(auto it:nums){
        mp[it]++;
    }
    int p = 0,r = 0;
    for(auto it:mp){
        if(it.second & 1){++r;}
        p += (it.second/2);
    }
    return {p,r};
} 

int maximumSum(vector<int>& v) {
    ll n = v.size();
    map<ll,multiset<ll>> mp;
    for(ll i = 0;i<n;++i){
        string s = to_string(v[i]);
        ll sod = 0;
        for(ll j = 0;j<s.size();++j){
            sod += (s[j]-'0');
        }
        mp[sod].insert(v[i]);
    }

    ll ans =0;
    for(auto it:mp){
        multiset<ll> ms = it.second;
        if(ms.size() >= 2){
            ll a = *ms.rbegin();ms.erase(ms.find(a));
            ll b = *ms.rbegin();ms.erase(ms.find(a));
            ll sa = (a+b);
            ans = max(ans,sa);
        }
    }
    if(ans == 0){ans = -1;}
    return ans;
}

bool comp(pair<string,ll> a,pair<string,ll> b){
    return a.first.size()<b.first.size();
}


static bool comp2(string a,string b){
    if(a.size() == b.size()){
        return a < b;
    }
    return a.size()<b.size();
}

/*
["7062852270146477248296527","8433780701670054260678760","8699421879227760163019849",
"7708276868930722275669591","5074829025635016047494703","5896327888048068611168261",
"7260190089159791786288449","5781138574494763732963172","3205437840168891808107684",
"5391561242659929681878939","9291899334089749518212291","8708326599236172552237668",
"3618812336262173046978703","4807369922822632937475631","0316892108136392839378991",
"8367705082821693868985331","2107315678805939657548178","9907244113601275760502412",
"4677127508895251971677534","1439698519575527518052264","2511775183710951968637133",
"6664307020593448841804234","3713561166640567497350787","9222117189171058392839857",
"9814178925901695758525967","1730249210741355068666166","4032999420142272853817457"]
[[5,21],[23,7],[6,2],[27,8],[14,21],[25,21],[26,23],[12,19],[7,8],[25,9],[11,8],[17,17],[21,8],[1,18],[16,18],[13,1],[27,7],[11,1],[4,7],[24,14],[9,1],[14,25],[2,13],[7,21],[15,1],[9,6],[7,2],[23,20],[15,20],[21,1]]

[6,24,15,22,2,14,5,16,14,13,0,3,15,21,18,8,14,12,18,10,17,7,22,25,19,22,20,6,0,24]
[6,24,15,22,2,14,5,16,14,13,0,3,15,21,18,8,14,12,18,10,17,7,22,25,19,22,20,6,0,24]
*/

vector<ll> smallestTrimmedNumbers(vector<string>& v, vector<vector<ll>>& queries) {
    ll q = queries.size();
    vector<ll> ans;
    for(ll i = 0;i<q;++i){
        vector<pair<string,ll>> dk;
        for(ll j = 0;j<v.size();++j){
            string st = v[j];
            st.substr(v[0].size()-queries[i][1]);
            dk.push_back({st,i});
        }
        sort(all(dk));
        ans.push_back(dk[queries[i][0]-1].second);
    }
    return ans;

    for(ll i = 0;i<q;++i){
        ll k = queries[i][0],trim = queries[i][1];
        vector<pair<string,ll>> dk;
        vector<string> ak;
        vector<string> tmp = v;

        map<string,set<ll>> mp;

        ll sz = tmp[0].size()-trim; 
        for(ll j = 0;j<tmp.size();++j){
            string st;
            for(ll k = sz;k<tmp[j].size();++k){
                if(tmp[j][k] == '0' and st.size() == 0){continue;}
                st += tmp[j][k];
            }
            // mp[st].insert(j);
            // ak.push_back(st);
            dk.push_back({st,j});
        }

        sort(dk.begin(),dk.end(),comp);
        ans.push_back(dk[k-1].second);
        /*
        sort(ak.begin(),ak.end(),comp2);
        vector<ll> chottu;
        for(ll l = 0;l<ak.size();++l){
            ll idx = *mp[ak[l]].begin();
            mp[ak[l]].erase(mp[ak[l]].find(idx));
            chottu.push_back(idx);
        }
        ans.push_back(chottu[k-1]);
        */
    }
    return ans;
}

int minOperations(vector<int>& v, vector<int>& t) {
    int gcd = t[0];
    for(auto it:t){gcd = __gcd(gcd,it);}
    if(gcd == 1){return -1;}
    sort(v.begin(),v.end());

    for(ll i = 0;i<v.size();++i){
        if(gcd%v[i] == 0){
            return i;
        }
    }
    ll sz = v.size();
    return sz;
}

void solve()
{
 
    ll n;cin>>n;
    vector<string> v(n);enter(v);
    sort(all(v),comp2);
    show(v);
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

/*
["102","473","251","814"]
[[1,1],[2,3],[4,2],[1,2]]
["24","37","96","04"]
[[2,1],[2,2]]
["22815075558233825216608524106002125300576861178458010421612236904685926248375591146033203976","61732138178847180187552069274184781994003873626671186056131716903309918915377365386468368030","25549136765041017868248457975727261624864420907057584822880261673997132255940156345586392047","89164788973105653633315894344488856115146333425940341666474496829079680365832544521847222650","39775902014408339306700530996939133218558542663364881974599886120721285306740806664452271847","14276621631862702805522979985094115117207514954414631659818245111678083697461858550211615154","86867312158256649714598382376438932980533522647169490102951124550014666834789063415459920678","26825449638093095990053739363503895328001281316303819226747568616072836987797112242873397477","79863835179814879454854136917255913272185922676374735462359354893555518781132500671806818293","63880568232044987139891045451765666199977206481568251471290646468110373161088286544673651583","48396637243951669974381576631017884632234930649783984442748812975705275071297484305526752934","72606535648524089333263974598932893684703515566674295966981800300798863712934059162606947805","35537875558412879196304408703015196491898140532414106870028632388415717714495857651708422538","50357139125819126519479958561733181693234190375355400067582619856049823328503452552192095074","89784648309002476276365102591713512586245461106448020125793564492925353244580760441669481024","15620970371091556906130382696521552883166322410537298715041913840396911549210647922357134755","37353175697888272519605498106741887627559961970100938600433338934658608026478792760133747245","45188782903244541385404622461055132795904749844632193904321005150703754781220014506129699568","88700838906117159154291016383983419956818300379088102917545182441648459575420176083025300710","61948982377131271728773710013671801530078981001236373620393996191813553786990421210919804384","30839657457731313959539089690769584528295414134355497085650019500832502040474840818625656551","62081579871199699117058751620565866785062870377790863701733813670395504497411729688113870400","35830821938055517343603502449146479706368433996661739827212549267443728334162401502324760975","79717775256385689412520175892974878921814677854956960798749151982341381246138368153535455413","50077333381169479760403131780615079166125285790781956193894844613294550689508513756560858751","87897557440585611915808222966512697525362947281855257136792001871731025399825096985104828127","24372159262677867913107031719227448519832064985954764614538451748968164874293292217887114443","73839880448275442681138541765862399166660045009936512170026247433373064542861297523002485862","54054173580447155342886183914418257483300321488636231919513004033761990223320556783712321229","82012486724645725881168302228058481167024302925003750445573977252464412776693922296479229344","02652193433198630883237108263628260486319639044661354497746895664654262986996933673360465770","44142244487068498478117208104497689434390161436798212643131698836874696310153707030778983984","41895770647732760333909370574640643679793684436531044070884745281056989741221872919255150447","82436895682307187383364907401496067517558875334471185770857777644079247156474083678343913033","23634986418153047376649160496259035961674986045248490776548059783920902594814556473424203750","49211676609700662432411038975518294778284824660324681311133466723292497184734226038976644216","32507474931054909901038241282608875804542811230923769750198553591396898488418496370495984761","41183125871121142924181763397438252967196450405851645116665727824955925601929896160702379009","26871119081751624806007634973406705101446191155947305269241123446920242929192263831776163450","33966048813080498553711950081252273688351796058635485399509248363459297404042049215549121306","63076389228944234784656039246643901537529250815435209586124239324466565108652037234530969804","18475377550782048206831787076012143418725684943776939173152201570845257395498675848837920928","79753602037056963327606095942239078878919948978713966338648868690658760837487711893529925869","09040808243104172414639934321021364990243543344808198365802278238261673150325378847960974714","56343792236293261078907222005633519616324740130811579212327850423543243346007570029703242518","43066971718467631670962599339266926718368204385995752821869780939357023577146203387876020183","51204893436207672681335771719181166001295048082878933292954352941872898290866495693489707335","42647974664693642061188207810278247439984996596760138231553039142791948454363046079788345386","65092270253815021675670946205934393885384855342423966574857396751313706731972716727655488022","62117346944216828593874454456359919816974021165437568375532979916655974428250759462489189576","05500919354455954538017317622402220448745284313797464808391794798788359045147240258234495449","52032980785306010605711180235996690000391687678257412731941701361488713540651311488051801738","53415693550662583263749197491221035338693329766855705072459072499264727980878678939557194920","64418150699170522326365564361620660865121847013184484283801496968680612943661170974035329083","25275693344894668271925664519141880949259332420321723316838907345312566011954893507774449318","39072346376281124765625966521722347656845888204249937604457039236855414936358028477666326275","78748439961827075733784692487780677699863883984270552170983290829541562395074129975364089950","98995760628273338339843877254680114235006707877785927519476686637022715373175285653114635339","60965235310537564557807445437687929483634364104338547943389841186740092960252979845235937290","69268788154763120471716562954405157871691219660976477599532775582215617864277844381548516002","14729144961066027868757290472387164730792280399803147407413337219824697662636388029209713393","00617242381688844169257757919953766566072733706334116263787727165007614288991561326889933043","62432087327093264832263863041051043942587575552624832605128770199035064516428435246033578281","81053510518176728772101345557967677721412164612164824561775445264263598856945350824554059509","32457726606133838507049913922964002535957445423746933704714847390352275986649689764468709624","41495678543734025830648893938388745545900402939288602194712190799376484002357415661061849889","18912888459862922682639258478684510219617196528310020710853306760185477927269620685704668724","98386662295897760214908703181208097595790782054131289609098306652653080197859437400562250982","09167354679387085134031032798341895300930010713356749969922340737308729293812744502777248102","64760924711828295737772438510893017923289568754431330025514731027388235838153716890997940897","69799983537120954403296192923285130302557440831414040523520617867279129842798943324781778056","82927191488204421769211537514842877200316548784451840677274362243832623125213790024223754176","42144734625639762499704405235442070383672553812108882205621515664699751348929617837658430427","24894945649390598514290314814989421057346656643540899939968778000582947733433422944292808090","43647268505804284932408459174327229614758178322402156697959672150567019641622773538375464868","01848966783908314850868305885302958101282500725460363170057598224235978427507771223932460128","65683665835399637993726174219249643305039317609351136641632322796591438830267411426272048465","23193405171778072662688467144672603981900956032482990295853112842609074984434331087121671213","41358439701389544051579913925212222431835343807673392360266689454273339125836185407380792537","48757172710220147749276831259138754672432049614687200352982705058013378992486149746103842169","11262324530313640840870878564773972976040541847769367433039057791135921360780212676462166925","90692501636072021138097343463558950928975213163283491218129737938891581373162548369596396577","60972790620514098864108800279599314434922635649028916783737930473380823000233721061210357695","50821978768845818296059456186479301208014161401984426443735887438086165319832132034497014371","36385261402336825609189865950181086064518828592926225455464949176778381513304604065672510442","38610755537029970806981055653056128548247816536881688251419024465673268213530004138084591007","70893746894917766479278431080983961636607515061951027815430130993394000399211908136927696082","17327917145504006168488268750666017929162403494100874641287053430111441323077816138997527527","14629733761652544824263490786082071363127350571388594877383705277617634474420073651744599917","90852196019177673814434471641695380846257345415617480404071386414600232970223889333500188598","36445310626055857752318685550554156100630292838327224186476918454258174037081151153849101033","41646018845017456018478305511313849985865865768070167173663992918420506630909597810916415837","79065254665628014435884548000666215722775025803826605738846591010418204202643913307116107823"]
[[91,33],[5,82],[39,11],[12,36],[1,74],[6,88],[11,48],[63,7],[15,54],[25,55],[20,38],[12,2],[56,24],[60,68],[8,57],[40,29],[27,28],[22,13],[7,91],[46,25],[38,10],[42,62],[1,81],[66,29],[17,67],[56,21],[25,86],[15,46],[18,79],[83,79],[43,56],[83,60],[10,69],[66,78],[57,22],[57,66],[13,90],[84,5],[57,59],[33,64],[84,63],[31,55],[32,20],[91,51],[56,84],[93,44],[49,45],[22,67],[59,9],[87,11],[93,33],[70,90],[42,29],[90,62],[79,45],[30,12],[92,55],[79,41],[75,84],[58,83],[15,24],[73,70],[51,18],[28,71],[42,83],[90,44],[33,73],[12,91],[56,68],[57,30],[63,87],[54,29],[77,44],[18,64],[48,35],[20,19],[64,24],[75,63],[14,55],[6,33],[10,86],[78,57],[32,1],[54,66],[84,5],[64,20],[19,16],[67,15],[71,40],[79,39],[7,57],[22,66],[3,85],[46,36],[28,29]]
["32724775965059031331106105482758082022961516659496377977643441492687639997488495348335148695","96779635467217236343928908630848074272863098238876679010331631360746289689108301017106929962","46514887471190051902454367096826698489160350556269087809469161229940031623896182400198524851","53754008318049786187858094601568449600977670423693047204600090511476510212011009867774115856","48651243110976642815929320780294611050898889207540241224194216116452662327234588556517846206","24401575353222280503484274027281353058955571604337296251816948739193056676909448507276025532","23302124946629328795825046296282855751177915588527806244247760940711972279944737927288232670","81390926743525849755964803498883143396452635960962927160234888566601938200558407165951245893","65838296961274519117450154308617119691813960532104444579689427831991665109093590639911141345","87628022311050308718565283246455463243570530952592951162139634463208649967071909971288523139","20263843285311135254157043149099818363829855475484239978192368639070667298581859717183732920","33636443874912241223889302519471975164808280537622524473326558666041065601687002234529955042","90923704376323473708326234399044061563242471195603022209170820618353979766319976536155924065","62990551239124527584314193075863060866224577023211165756353842007342478729968977723785492992","86529556949810181528790113518464796483186823171073823882427390722656434811632430138787956690","31577832312644331940937956607411641534285516024883559582766379597938765515200102622441484677","27370317503232908579754168758320732998937027744474727784202197635547572547118657250017850688","94545316813005108768615433046463231309347105573632816640457237042656546487250869405641900588","01186874950731722376822616488258849857466728074041728871972857956583473603803545171147083339","16126393311712878096994586381674771082022107077932386140229262367716875058086776464911039346","52231291014962191026273534052021022957004386509816857369658566021766561116308402050026236242","05932414651594611023370636844294832422697876706530176876624899330800511267914818545649677916","50305867015040801700655849596942055856696439683489168259359508335369563750691845878231605355","21602708908918778112249128866560091012096452964198039303783170175573273195458291279165043693","30407687392796798133599685666290466516506344417377437061309981573855388684292375497166396979","25119580669707286970481258212496818075218852647287811068332219590906304677466968380167716379","48998175645388186786806450347842756910853251956063056131197677152729971636654878584194943249","52615871153534914895319563230411446626392602298327977455226459278240205933469043080705824573","42418069299605458558168617768851650818889721752889774615026462039627154240375077063494772037","34145388274170571248491264920112568509582687996869599248065934362971309984466327825182915713","46456231237799576866023396543646691252391016100125305837364685401853974578655301625930920390","15019778462359462862571339482012011119201348699592233071016273929825981017122088977624167706","48190811173113289980879489760091864735518283119485687771058259308160890513312317436524051137","06002227795875105304374550130239732322753482894054159809372383307474775487472730409510681092","43725853518468571436596093204535374985671362498539611381665528872071059382836951765016261710","04298657957961974011340349774923173490751761333915740406964964173285721746479149156409361938","84119724415561267047234681855733295481010220449876015967601168545598562796940709104275784026","80277524711768775543401206453472375143726096393032079971653093845756957545312014512456129188","69453300853176969164763361315856838249229709946090671074749417909707288078139590986194062291","42076253039639206780671709451100329296054189999613091114247765984379692139622960632233852438","94716537605285699693389552902839156191217283906913512005989365475776689104293607088379718804","18545906769395661990060992917049839341512600813495139865035535999432400003008584817704146769","75493513226353999412835346498121785302770133246510496259056080624153825369785007339466865291","99390393072595360802425971418469724148691503838055400334301792024447494997295407756167632413","18475925919088479600901094425910158573134648741351030111022553301713912649357516451995938341","12094819121909941849696194108925236335812132314164409579038539204660044715933299219817742365","76899823926296446428555397458415901610447822731789866710691406261249136755864113272186667894","95321660719383154318832828996026851365385092530455978838630391833525558994483185453537481114","81639491325649753273837371650162806188869949790451421738649646013747311530809765975602071340","26607934346977985397497221197188255772997952177936745712282073872765174889171427799155489418","74077571768097210973656834997747302135634355778874725760172132724701532835429665088865109808","79669134481655971001906860829329383634109532773187623539744160413344385012386671399028619445","14094902896341875359710931560670043031417408192736296063519803715702798185841361246221142024","65296288557543061148036716670448937907893838126897578274817589300235892531965739931540252287","45667588484405560083052580316324929934158370951355315973015146231577029021793167027281400130","99104538878029797918575039513668364844460684992499709929022703283863176992343629131642239348","16860016312241119383211482398282171004413679815455620117154261310419632844374858021454626723","25316759196889504750819150907247830305862316479006537636808355057008505741944732759633939640","81509487339230956942054068623806930206702045367822748357394331030090297220693998494152515740","78781445034307078071510621285790212977967432472276992692119580785370221266642404582349854059","69457577267777978529409505697318427592921278302526176671837482161562312157993539585343869319","77774740069172898459309539489104762698195801610618752812862447991028152681599894290979630162","98958088483063503223122692210027005651577364465669667792067840969811103041408696091748283484","46063526305427466885908732609928788126652355853971696182184714892568360403289612203238991284","02220208350386163551595924376400045259513758206312276563955568110770271483864439857036165745","67967583609777691881844079820613347992781880569221474847407340979421592262074219848289820262","73241768297473476779555649782556286456006482676104557705376905561100249265541951697460144460","84990010028822691232232706649684788374411151757592341372675918032506880122725885067215468238","44954397646070932263334429427295886611551022103616014425550874041697311957426014171502390052","24865400630256927381201390275314630665906610463714370242010640827330285832423847603186752740","35524731857358774639108552961750197209995239505680428365751061081524778745927085142983769790","99653861809465533648301653929249575291054419074888552885931365369667140815027856822822273247","47887165559525602974657877407767768320780601409769632446394356686741217838858613417767266825","34383520342220544224570226414480984467674638702453854348411018280918644087271799128129236617","39720864116443321864308257703440916537439802970586606138363341218041727973865565456264239417","10512960680997202232883674867004955254236035311989748843582693810765306272309174820426159019","85122221396190077462184113549504655762473745850132930588366180933700214239114262233981018413","59559946303915209867907594603384758871863293462599908037702251307296813730644225272881932984","95964846209309606280743598964702336018469270583354232474878182345397636871101953135262217619","04798035363014466282647793269872373513482103973519090598728632905765837714523046567796310981","61389044994926321365687954439272186537407382269520251838210073350401773919793887031348766655","73001897616824501554808300966175837880681815823556938520254429501702153397667190626319461614","20490360961804888722886029035463716691005072500998431905675986975049351260076459901818845674","39020252567615568036996601649084771639154513664621010026062562536431719000399645225264819265","78061785940317583782253955388236640859297161222804611526438496937114236388696188505681105658","16545114992135089612350262685292160250389734339912789002882091194855365031789663025083001130","67964376447819665881945149060984190427366096928380057734800871519901500955108173356217217382","80011068900010906668230918808228424314880859837252723038116473247358602620058476249758251471","20497237723367026776973903624428771797996477199727070500515440261351767259072335037737842937","92640135807504260867980359007185561289894017175521341026086005680976502925703260761148686803","64821131183052404271951930270652207370445506631483324241998861662933632429618416092336540865"]
[[31,33],[86,38],[67,29],[88,71],[70,27],[81,83],[28,8],[31,14],[12,2],[48,56],[88,9],[38,79],[26,5],[58,64],[42,16],[18,88],[43,14],[21,3],[39,41],[84,51],[82,26],[66,20],[4,71],[69,75],[58,69],[66,81],[73,46],[44,75],[66,16],[28,40],[28,82],[43,4],[64,18],[36,4],[80,77],[28,19],[36,21],[50,57],[33,82],[31,22],[34,89],[64,43],[49,82],[78,31],[81,70],[37,68],[17,41],[40,44],[11,23],[34,23],[31,25],[86,53],[36,68],[67,32],[31,88],[6,45],[82,41],[87,66],[15,69],[3,15],[7,45],[16,17],[66,8],[33,51],[51,23],[25,55],[83,71],[18,20],[77,71],[76,7],[74,37],[50,4],[43,77],[28,22],[86,42],[68,55],[58,70],[68,50],[83,87],[10,33],[19,38],[87,34],[1,30],[26,51],[58,91],[7,39],[72,57],[40,48],[53,4],[88,16],[85,82],[7,11]]
*/