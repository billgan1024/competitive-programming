#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("Ofast")
#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

//observation: since we're cloning stacks and appending new elements every time, we know that the delete/query operation always
//creates a clone of an existing stack
//track the distinct stacks by the top element which will be the number of the node representing that stack (use a tree)
//insert operation: append a new leaf node to the node which represented the original stack (the one which u cloned)
//we know that any existing stack can be made from the empty stack by adding numbers in increasing order (in fact, we can follow a path
//from the root to a node, adding the node numbers to construct that stack since at each step, we are adding the new top element)
//this means that the depth of lca(a, b) is equal to the size of the intersection since given the two paths that create stacks a & b,
//they start to diverge and since all node numbers (top elements) are unique, the sets of nodes
//described by the paths of stack a & b after the lca will be disjoint
//since the stacks are always created in order from 1 to n (and never deleted), we can process queries offline so that we can use the
//nlogn euler tour + segment tree preprocessing trick to calculate lca in O(logn) time (use segment tree to avoid mle)
//for lca, we can use the node numbers as ids to find the smallest node since for any a which is an ancestor of b, a < b since leaf node numbers
//are added in increasing order

//p[i]: parent of node i (node 0 represents the empty stack), d[i] = depth of node i
//segment tree: [1, 2*seg-1] = tree nodes, [2*seg, 4*seg-1] = leaf nodes
//euler tour array is 0-indexed
const int maxN = 3e5+1, seg = 1<<20;
int n, idx[maxN], p[maxN], d[maxN], euler[maxN], ans[maxN], s[2*seg], cnt; vector<int> adj[maxN]; vector<tuple<int, int, int>> q;
void upd(int i, int v) {
	int idx = i+seg; s[idx] = v;
	for(int p = idx/2; p > 0; p /= 2) s[p] = min(s[2*p], s[2*p+1]);
}
int query(int l, int r, int a, int b, int p) {
	int mid = (a+b)/2;
	if(a >= l && b <= r) return s[p];
	else if(a > r || b < l) return INT_MAX;
	else return min(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1));
}
void dfs(int cur) {
	//fill up the segment tree with
	euler[cur] = cnt; upd(cnt++, cur);
	for(int nxt : adj[cur]) { dfs(nxt); upd(cnt++, cur); }
}
int lca(int l, int r) {
	l = euler[l]; r = euler[r]; if(l > r) swap(l, r);
	return query(l, r, 0, seg-1, 1);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0); sc(n); ms(idx, -INF); ms(ans, -INF);
	for(int i = 1; i <= n; i++) {
		//idx[i]: original id of stack i if it was cloned from a previous stack (so we don't add nodes with duplicate numbers to the array)
		char cmd; int v, w; sc(cmd);
		if(cmd == 'a') {
			//convert stack index of parent -> node number
			//node number of stack i = i if we're adding
			sc(v); v = idx[v] >= 0 ? idx[v] : v;
			p[i] = v; d[i] = d[v]+1; adj[v].pb(i);
		} else if(cmd == 'b') {
			//set the node number of stack i to be the parent of the node you're cloning (we don't need to update the depth/parent array)
			//thus, print out the node number of the original stack
			sc(v); v = idx[v] >= 0 ? idx[v] : v;
			idx[i] = p[v]; ans[i] = v;
		} else {
			//set the node number of stack i to be the node you're cloning (we don't need to update the depth/parent array)
			sc(v, w); v = idx[v] >= 0 ? idx[v] : v; w = idx[w] >= 0 ? idx[w] : w;
			idx[i] = v; q.pb({v, w, i});
		}
	}
	dfs(0);
	for(auto p : q) {
		//note: according to c++ scopes, p exists as the tuple here, not the global array
		ans[get<2>(p)] = d[lca(get<0>(p), get<1>(p))];
	}
	for(int i = 1; i <= n; i++) {
		if(ans[i] >= 0) pr(ans[i], nl);
	}
}