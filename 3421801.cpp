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
const int maxN = 2e5+1, mod = 1e9+7;

int n, id[maxN], s[maxN], v[maxN], ans[maxN], root, cnt; vector<int> adj[maxN];
void dfs(int cur) {
    id[cur] = ++cnt;
    for(int nxt : adj[cur]) {
        dfs(nxt); s[cur] += s[nxt] + 1;
    }
}
void upd(int idx, int val) {
    for(int i = idx; i <= n; i += i&-i) v[i] = (v[i]+val) % mod;
}
int sum(int idx) {
    int ret = 0;
    for(int i = idx; i > 0; i -= i&-i) ret = (ret+v[i]) % mod;
    return ret;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1, x; i <= n; i++) {
        sc(x); if(!x) root = i; else adj[x].pb(i);
    }
    //instead of updating node values on a path, we update the the "lazy" value of a node v[i] and
    //the query of the true value of a node is the sum of v[i] in its subtree (not including it) + 1 (initial value)
    //use a tree traversal array + bit to accomplish both tasks in logn time per node
    //id[i]: index of node i in the tree traversal array
    //s[i]: subtree size of node i, not including node i
    //v[i]: bit of the lazy value of the node with index i in the tree traversal array
    //update node x: upd(id[x], val)
    //query total lazy value to be added to the query value of node x: sum(id[x]+1, id[x]+s[x]) (inclusive)
    //store sums mod 1e9+7
    dfs(root);
    for(int i = 1, x; i <= n; i++) {
        sc(x);
        //query the value of node x
        int val = (sum(id[x]+s[x]) - sum(id[x]) + 1 + mod) % mod; ans[x] = val;
        //update lazy value of node x
        upd(id[x], val);
    }
    for(int i = 1; i <= n; i++) pr(ans[i], sp);
}