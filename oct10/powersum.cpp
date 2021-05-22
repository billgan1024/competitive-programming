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
const int maxN = 3e5+1, mod = 998244353;

//sum[n][i] = 1^i + 2^i + ... + n^i (since a path sum can be determined by its depth, u can precompute path sums
//for all depths)
int n, q, up[maxN][19], d[maxN]; vector<int> adj[maxN]; ll sum[maxN][51];
void dfs(int cur, int pre, int dep) {
	//dfs fills the up array: up[i][j] = 2^jth ancestor of i as well as the depth of each node
	//node 0 is the 'undefined node' which is higher than every other node and up[0][k] = 0 for all k
	d[cur] = dep; up[cur][0] = pre;
	for(int i = 1; 1<<i < n; i++) up[cur][i] = up[up[cur][i-1]][i-1];
	for(int nxt : adj[cur]) {
		if(nxt != pre) dfs(nxt, cur, dep+1);
	}
}
int jump(int cur, int k) {
	while(k > 0) {
		int j = 31-clz(k); cur = up[cur][j]; k -= 1<<j;
	}
	return cur;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0); sc(n);
	for(int i = 1; i < n; i++) {
		ll cur = 1; //avoid overflow
		for(int j = 1; j <= 50; j++) {
			cur = (cur*i) % mod; sum[i][j] = (sum[i-1][j] + cur) % mod;
		}
	}
	for(int i = 1, a, b; i < n; i++) {
		sc(a, b); adj[a].pb(b); adj[b].pb(a);
	}
	dfs(1, 0, 0); sc(q);
	while(q--) {
		//a, b = normalized u, v (d[a] = d[b])
		int u, v, k; sc(u, v, k); int x = u, y = v; if(d[x] > d[y]) x = jump(x, d[x]-d[y]); else y = jump(y, d[y]-d[x]);
		//binary search for the min jump length we need to do in [0, n-1] such that u and v point to the same node
		//this less cancer implementation will calculate lca in log^2(n) time
		int lo = 0, hi = n-1, ans = 0;
		while(lo <= hi) {
			int mid = (lo+hi)/2, a = jump(x, mid), b = jump(y, mid);
			if(a == b) { ans = a; hi = mid-1; }
			else lo = mid+1;
		}
		//path sum = sum to u + sum to v - 2*sum to ans + d[ans]^k (actual value of node 'ans')
		//note the check to avoid undefined behaviour when ans = 1 (d[ans] = 0)
		int tmp1 = (sum[d[u]][k]-sum[max(d[ans]-1, 0)][k]+mod)%mod;
		int tmp2 = (sum[d[v]][k]-sum[d[ans]][k]+mod)%mod;
		pr((tmp1+tmp2)%mod, nl);
	}
}