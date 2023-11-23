#include <bits/stdc++.h>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;

vector<ll> tree,tree2;
vector<ll> z,alpha;
void buildTree(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode) {
    // Base Case when start == end since we know the ans of that idx
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }

    ll mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void update(vector<ll> &Tree, ll idx, ll s,ll e, ll pos, ll X,ll f){
	if (s == e){
        if(f & 1){
        }else{
            z[idx] = 1-z[idx];
            Tree[idx] = 1-Tree[idx];
        }
	}else{
		ll m = (s + e) / 2;
		if (pos <= m) {
			update(Tree, 2 * idx, s, m, pos, X,f);
		}else {
			update(Tree, 2 * idx + 1, m + 1, e,
				pos, X,f);
		}
		Tree[idx] = Tree[2*idx] + Tree[2*idx+1];
	}
}

ll sum(vector<ll> &Tree, ll idx, ll s,ll e, ll ql, ll qr){
	if (ql == s && qr == e)
		return Tree[idx];

	if (ql > qr)
		return 0;

	ll m = (s + e) / 2;

	return sum(Tree, 2 * idx, s, m, ql, min(m, qr))+ sum(Tree, 2 * idx + 1, m + 1, e,max(ql, m + 1), qr);
}

ll getElement(vector<ll> &Tree, ll X, ll N){
    return sum(Tree, 1, 0, N - 1, 0, X);
}

void range_Update(vector<ll> &Tree, ll L,ll R, ll X, ll N,ll f){
	update(Tree, 1, 0, N - 1, L, 1,0);
	if (R + 1 < N){
		update(Tree, 1, 0, N - 1, R + 1, 0,1);
    }
}



void buildTree2(vector<ll> &arr,vector<ll> &tree, ll start, ll end, ll treeNode) {
    // Base Case when start == end since we know the ans of that idx
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }

    ll mid = (start+end)/2;
    buildTree2(arr,tree,start,mid,2*treeNode);
    buildTree2(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void update2(vector<ll> &Tree, ll idx, ll s,ll e, ll pos, ll X,ll f){
	if (s == e){
        if(f == 0){
            alpha[idx] += (X*z[idx]);
            Tree[idx] += (X*tree[idx+1]);
        }
	}else{
		ll m = (s + e) / 2;

		if (pos <= m) {
			update2(Tree, 2 * idx, s, m, pos, X,f);
		}else {
			update2(Tree, 2 * idx + 1, m + 1, e,
				pos, X,f);
		}

		Tree[idx] = (Tree[2 * idx] + Tree[2 * idx + 1]);
	}
}

ll sum2(vector<ll> &Tree, ll idx, ll s,ll e, ll ql, ll qr){
	if (ql == s && qr == e)
		return Tree[idx];

	if (ql > qr)
		return 0;

	ll m = (s + e) / 2;

	return sum2(Tree, 2 * idx, s, m, ql, min(m, qr))+ sum2(Tree, 2 * idx + 1, m + 1, e,max(ql, m + 1), qr);
}

ll getElement2(vector<ll> &Tree, ll X, ll N){
    return sum2(Tree, 1, 0, N - 1, 0, X);
}

void range_Update2(vector<ll> &Tree, ll L,ll R, ll X, ll N,ll f){
	update2(Tree, 1, 0, N - 1, L, 1,0);
	if (R + 1 < N)
		update2(Tree, 1, 0, N - 1, R + 1, 0,1);
}

vector<long long> handleQuery(vector<ll>& v1, vector<ll>& v2, vector<vector<ll>>& q) {
    tree.assign(4*v1.size()+4,0);
    tree2.assign(4*v2.size()+4,0);
    for(auto it:v1){
        z.push_back(it);
    }
    for(auto it:v2){
        alpha.push_back(it);
    }

    buildTree(v1,tree,0,v1.size()-1,1);
    buildTree2(v2,tree2,0,v2.size()-1,1);
    // show(tree);
    // show(tree2);cout<<endl;

    vector<long long> ans;
    for(ll i = 0;i<q.size();++i){
        vector<ll> x = q[i];
        show(x);
        if(x[0] == 1){
            range_Update(tree, x[1],x[2],0,v1.size(),0);
        }else if(x[0] == 2){
            range_Update2(tree2, 0,v2.size()-1,x[1],v2.size(),0);
        }else{
            long long sm = sum2(tree2,1,0,tree2.size()-1,0,v2.size()-1);
            ans.push_back(sm);
        }
        show(z);
        show(alpha);
        show(tree);
        show(tree2);
        cout<<endl;
    }
    return ans;
}  

void solve()
{
    ll n,q;cin>>n>>q;
    vector<ll> v(n);enter(v);
    vector<ll> d(n);enter(d);
    ll sz=q;
    vector<vector<ll>> query(sz,vector<ll>(3,0));
    for(ll i = 0;i<sz;++i){
        cin>>query[i][0]>>query[i][1]>>query[i][2];
    }

    vector<long long> ans = handleQuery(v,d,query);
    show(ans);
    return;
}
 
signed main()
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