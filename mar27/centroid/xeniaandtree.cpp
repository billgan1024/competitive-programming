#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 1e5+1;
//sparse table of 2E edges for euler tour (sparse table tracking (depth, node) + time that each node appeared in the array)
pii st[18][2*maxN]; int t[maxN], N, M, idx, p[maxN], s[maxN], b[maxN], c[maxN], dis[maxN]; vector<int> adj[maxN];

// naive solution: dfs each time to find closest red node
// observation: given an arbitrary root and a query node, if the closest red node is not in the corresponding subtree 
// (with respect to the root), then the path to the closest red node 
// ends with a path from the root to the closest red node.
// you can precompute the shortest distance to a red node for the centroid
// and use it in the calculation for the query node
// otherwise, solve the same problem for the query node's subtree (with respect to the root)
// thus, u can think of a separate tree of these special roots that have c[i] representing the 
// min distance to a red node, when u only consider the nodes in the subtree defined by these special roots
// (with respect to this special graph)
// then u can find the centroid tree so that you only need to update and query O(logn) c[i] values (using precomputed
// distance in O(1) time with lca), querying the min d(v, centroid) + c[centroid]
// since the centroid tree has height O(logn) (as a proof of this, 
// u can show that for the centroid tree, the total number of nodes in each node's centroid component is 
// <= n/2^{depth}, by definition of a centroid

// (can prove the splitting of the desired path algorithm is correct 
// by descending argument that this works, and the size of the centroid component will decrease until it's just a singleton 
// containing the query node)

//centroid tree is just a parent array p[i] so that you can easily update c[i] values in log(n) time

void dfs(int cur, int pre, int d, auto f, auto g) {
    f(cur, d); // entry(cur, depth)
    for(int nxt : adj[cur]) {
        if(nxt != pre) {
            if(!b[nxt] && nxt != pre) {
                dfs(nxt, cur, d+1, f, g); g(nxt, cur, d); //entry(nxt node, cur node, depth of current node)
            }
        }
    }
}

// gets the centroid with respect to the local subtree in O(sz subtree) time
int centroid(int cur, int pre, int tot) {
    for(int nxt : adj[cur]) {
        if(!b[nxt] && nxt != pre && 2*s[nxt] > tot) return centroid(nxt, cur, tot);
    }
    return cur;
}

// construct the centroid tree using the recursive call to this function
// the current call to cent_tree assumes that we're in a specific component controlled by the blocked array
// will terminate once u reach components with one node (which is the centroid itself)
void cent_tree(int cent) {
    b[cent] = true;
    for(int nxt : adj[cent]) {
        if(!b[nxt]) {
            // find the centroid of this subtree
            // lambda functions have higher scope, so cur, nxt are local variables within the lambdas
            dfs(nxt, 0, 0, [](int cur, int d) { s[cur] = 1; }, [](int nxt, int cur, int d) { s[cur] += s[nxt]; });
            int nxt_cent = centroid(nxt, 0, s[nxt]);
            p[nxt_cent] = cent;
            cent_tree(nxt_cent);
        }
    }
}
int argmin(pii x, pii y) {
    if(x.first < y.first) return x.second; else return y.second;
}
int lca(int u, int v) {
    int a = t[u], b = t[v]; if(a > b) swap(a, b); 
    int flog2 = 31 - clz(b-a+1);
    return argmin(st[flog2][a], st[flog2][b-(1<<flog2)+1]);
}
int d(int u, int v) { return dis[u] + dis[v] - 2*dis[lca(u, v)]; }
// updates a centroid tree in v's components all the way up to the original centroid
void upd(int v) {
    // end of centroid tree is when j == 0
    for(int j = v; j != 0; j = p[j]) {
        c[j] = min(c[j], dis[v]+dis[j]-2*dis[lca(v, j)]);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, M);
    for(int i = 0, a, b; i < N-1; i++) {
        sc(a, b); adj[a].pb(b); adj[b].pb(a);
    }
    // use lca to calculate distance between any two nodes (out of n^2 nodes) in O(1) time using the euler tour
    // use lambdas again to re-use dfs code (we update the dis[] array and euler tour sparse table, as well 
    // as calculate the size of each subtree when 1 is the root)

    dfs(1, 0, 0, [](int cur, int d) { s[cur] = 1; st[0][++idx] = {d, cur}; t[cur] = idx; dis[cur] = d; }, 
        [](int nxt, int cur, int d) { s[cur] += s[nxt]; st[0][++idx] = {d, cur}; });
    
    //find centroid tree
    cent_tree(centroid(1, 0, s[1]));

    //sparse table processing
    for(int j = 1; (1<<j) <= idx; j++) {
        for(int i = 1; i+(1<<j)-1 <= idx; i++) {
            st[j][i] = {min(st[j-1][i].first, st[j-1][i+(1<<(j-1))].first), argmin(st[j-1][i], st[j-1][i+(1<<(j-1))])};
        }
    }

    //now c[i] = min distance to a red node with respect to the centroid component
    ms(c, INF); 

    upd(1);
    for(int i = 0, t, v; i < M; i++) {
        sc(t, v);
        if(t == 1) upd(v);
        else {
            // solve using the above idea but simply do an upward traversal of the centroid tree
            int ans = INT_MAX;
            for(int j = v; j != 0; j = p[j]) ans = min(ans, d(v, j)+c[j]);
            pr(ans, nl);
        }
    }
}