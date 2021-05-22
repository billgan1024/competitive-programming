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
const int maxN = 1e5+1;

//each point = (position, id, left?)
//minVal[i] = min value of any node on the root path to i, minNode[i] = deepest node with that min value
//depth[i] = distance from root for lca calculations
int n, q, up[maxN][18], v[maxN], minVal[maxN], minNode[maxN], dep[maxN]; vector<tuple<int, int, bool>> p;
int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	//first one: loop from a number i such that 2^(i+1)-1 >= n-1 (max jump length)
	for(int i = 16; i >= 0; i--) {
		if(dep[u]-dep[v] >= 1<<i) u = up[u][i];
	}
	if(u == v) return u;
	for(int i = 17; i >= 0; i--) {
		if(up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	}
	//u = last node such that up[u][0] = lca(u, v)
	//if lca(u, v) = 0 or the root node it means that they are in completely different trees/the root node is the lca
	return up[u][0];
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0); sc(n);
	//find the lca of the two segments (these segments form a collection of trees with the node number = segment id)
	//from the lca, we need to find the deepest (furthest from root) node which has the minimum val
	//thus, we can calculate that value for every node in their tree using a dfs
	//when ur using a dfs, the pair (min val, node) of the child is changed when the val of the child node is <= the current min val of the
	//parent node
	for(int i = 1, l, r; i <= n; i++) {
		sc(l, r, v[i]); p.pb({l, i, true}); p.pb({r, i, false});
	}
	sort(p.begin(), p.end());
	//construct the tree using a line sweep algorithm (if an interval is open and you encounter another interval's left boundary, it
	//means that the first segment is the direct parent of the second segment
	//use a smart way to determine minVal, minNode, up, and depth without ever performing dfs
	//all elements have an 'ultimate root' which is node 0 (it is infinitely high such that up[0][i] = 0)
	stack<int> s;
	for(auto t : p) {
		int pos, cur; bool left; tie(pos, cur, left) = t;
		if(left) {
			if(!s.empty()) {
				dep[cur] = dep[s.top()]+1; up[cur][0] = s.top();
				for(int i = 1; i <= 16; i++) up[cur][i] = up[up[cur][i-1]][i-1];
				minVal[cur] = min(v[cur], minVal[s.top()]);
				minNode[cur] = v[cur] <= minVal[s.top()] ? cur : minNode[s.top()];
			} else {
				minVal[cur] = v[cur]; minNode[cur] = cur;
			}
			s.push(cur);
		} else s.pop();
	}
	sc(q);
	for(int i = 1, a, b; i <= q; i++) {
		//find the lca of a and b, then go up by one
		sc(a, b); int ans = lca(a, b);
		if(ans == a || ans == b) ans = up[ans][0];
		pr(ans == 0 ? -1 : minNode[ans], nl);
	}
}