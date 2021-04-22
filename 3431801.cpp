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
typedef pair<ll, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int maxN = 6e3;

int n, q, id[maxN], cnt, st[2*maxN-2][14][2]; ll d[maxN]; vector<pii> adj[maxN];
//sparse table tracks (depth, node) (node with min depth in the tree traversal array)
void dfs(int v, int pre, ll dis, int dep) {
    st[cnt][0][0] = dep; st[cnt][0][1] = v; d[v] = dis; id[v] = cnt++;
    for(pii nxt : adj[v]) {
        if(nxt.second != pre) {
            dfs(nxt.second, v, dis+nxt.first, dep+1);
            st[cnt][0][0] = dep; st[cnt++][0][1] = v;
        }
    }
}
int lca(int u, int v) {
    int a = id[u], b = id[v]; if(a > b) swap(a, b);
    int j = log2(b-a+1), nxt = b-(1<<j)+1;
    if(st[a][j][0] < st[nxt][j][0]) return st[a][j][1];
    else return st[nxt][j][1];
}
int main() {
    //euler tour
    //id[i]: index of node i in the tree traversal array
    //maintain a sparse table for depths
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 0, a, b, w; i < n-1; i++) {
        sc(a, b, w); adj[a].pb({w, b}); adj[b].pb({w, a});
    }
    dfs(0, -1, 0, 0);
    //st[i][j] = min(a[i], a[i+1], ... a[i+2^j-1])
    for(int j = 1; (1<<j) <= 2*(n-1); j++) {
        for(int i = 0; i+(1<<j)-1 < 2*(n-1); i++) {
            int nxt = i+(1<<(j-1));
            if(st[i][j-1][0] < st[nxt][j-1][0]) {
                st[i][j][0] = st[i][j-1][0]; st[i][j][1] = st[i][j-1][1];
            } else {
                st[i][j][0] = st[nxt][j-1][0]; st[i][j][1] = st[nxt][j-1][1];
            }
        }
    }
    sc(q);
    for(int i = 0, u, v; i < q; i++) {
        sc(u, v); pr(d[u] + d[v] - 2*d[lca(u, v)], nl);
    }
}