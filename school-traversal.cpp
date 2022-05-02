#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
// LG just has to be (max k such that 2^k <= N-1)+1 = min k such that 2^k >= N; even if N was lower than the max value, 
// our program would still work
const int MN = 6e3+1, LG = 13;

int N, Q, dep[MN], anc[LG][MN]; ll dis[MN]; vector<pii> adj[MN];
// dfs function: can initialize ancestor array, depth array, and distance array all at once
// anc[k][i] = 2^kth ancestor of i, or 0 if we are already above the root of the tree
// note that depth is unweighted while distance is weighted
void dfs(int cur, int pre, ll di, int dp) {
    // update the array first, then go (necessary for standard initialization of 1; actually we don't need to set stuff)
    dis[cur] = di; dep[cur] = dp;
    for(auto [w, nxt] : adj[cur]) {
        if(nxt != pre) {
            //invariant: when dfs on a new node is called, all of its ancestors already have anc[i][v] already set, so we can use 
            //them to update anc[i][nxt]
            anc[0][nxt] = cur;
            for(int i = 1; i < LG; i++) anc[i][nxt] = anc[i-1][anc[i-1][nxt]];
            dfs(nxt, cur, di+w, dp+1);
        }
    }
}
int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    // move u up to v using the strategy.

    // then, we employ a binary search algorithm simply by moving up the nodes using powers of two until we can't anymore.
    // this is an iterative version of binary search, as we're finding the minimum index such that u and v are distinct 
    // given the ability to jump by powers of two, where we can verify that the binary search condition (an array of 
    // true, ..., false) is met. this strategy shows that the algorithm uses the binary representation of the index 
    // can be exploited when we have a data structure that allows us to advance the current index by a power of two,
    // and we can move to any number in the range [0, 2^LG-1] which is >= N-1 (which is the max length we need to traverse)
    // node 0 must have -1 depth, as node 1 would be at depth 0
    for(int i = LG-1; i >= 0; i--) {
        if(dep[anc[i][u]] >= dep[v]) u = anc[i][u];
    }
    // edge case: u was already equal to v
    if(u == v) return u;
    // otherwise, move u and v upward until they are at the maximum index such that u != v
    for(int i = LG-1; i >= 0; i--) {
        if(anc[i][u] != anc[i][v]) u = anc[i][u], v = anc[i][v];
    }
    return anc[0][u];
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 0, a, b, w; i < N-1; i++) {
        sc(a, b, w); a++; b++; adj[a].pb({w, b}); adj[b].pb({w, a});
    }
    // start: node 1 (and 0) already have the anc array set up correctly, meaning that 
    dfs(1, 0, 0, 0);
    sc(Q);
    while(Q--) {
        int u, v; sc(u, v); u++; v++;
        pr(dis[u] + dis[v] - 2*dis[lca(u, v)], nl);
    }
}