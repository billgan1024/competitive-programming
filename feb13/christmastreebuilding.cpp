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
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
const int maxN = 1e5+1;
//since you can pick the root of the tree, this problem basically asks u to find the tree with maximum diameter or minimum radius
//which is a superset of the input graph (that is a forest), since for every tree, the diameter is the
//longest path (i.e. largest possible height) and the radius is the smallest possible height (and u find the optimal tree)
//observe that the end graph is actually just a tree of the subtrees, meaning that any longest path should be on a graph
//which simply connects all of the subtrees in a line (because the longest path will only be able to traverse the 'bridge' edges once)
//from there, connect all graphs via the diameter since the longest path is simply the sum of individual paths in each subtree, so maximize individually

//minimum radius: merge all graphs together as to maintain the minimum possile radius of the combined graph every time 
//it can be shown that you just take the maximum radius, then check if there are >= 2 trees with that radius. if so, add one to the min radius of the entire connected tree

int N, M, Q, far, cnt; ll ans, dis[maxN], len; vector<pii> adj[maxN]; vector<pair<ll, ll>> dat; bool vis[maxN], vis2[maxN];
//dfs and keep track of the node with the maximum distance
void dfs(int cur, ll d) {
    if(vis[cur]) return;
    vis[cur] = true; if(len < d) { far = cur; len = d; }
    for(pii nxt : adj[cur]) dfs(nxt.first, d+nxt.second);
}
void dfs2(int cur, ll d) {
    if(vis2[cur]) return;
    //dfs enter function
    vis2[cur] = true; dis[cur] = d;
    if(len < d) { far = cur; len = d; }
    for(pii nxt : adj[cur]) dfs2(nxt.first, d+nxt.second);
    //dfs return function
}
void solve(int cur) {
    //computes the radius and diameter for node i's connected component (we can do dfs to determine distances since it's a tree)
    len = LLONG_MIN;
    dfs(cur, 0); int p1 = far; len = LLONG_MIN;
    //note: we need 2 vis arrays because we're doing dfs on the same connected component twice
    dfs2(p1, 0); int p2 = far; ll diameter = len, dr1 = diameter, dr2 = 0, radius = LLONG_MAX;
    //we can use this trick to recall the actual shortest path to a node in O(v+e) time
    //(side note: the last iteration (when i == p1) is ignored since it is just equal to when i == p2)
    int i = p2;
    while(i != p1) {
        radius = min(radius, max(dr1, dr2));
        //transition to the next one
        for(pii nxt : adj[i]) {
            if(dis[nxt.first] == dis[i]-nxt.second) { i = nxt.first; dr1 -= nxt.second; dr2 += nxt.second; break; }
        }
    }
    dat.pb({diameter, radius == LLONG_MAX ? 0 : radius});
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, M, Q);
    for(int i = 0, u, v, l; i < M; i++) {
        sc(u, v, l); adj[u].pb({v, l}); adj[v].pb({u, l});
    }
    //for each component, compute the radius and diameter (data stores {diameter, radius})
    for(int i = 1; i <= N; i++) {
        if(!vis[i]) solve(i);
    }
    if(Q == 1) {
        for(auto p : dat) ans += p.first;
        pr(ans+sz(dat)-1);
    } else {
        ans = LLONG_MIN; 
        for(auto p : dat) {
            if(ans < p.second) { ans = p.second; cnt = 1; }
            else if(ans == p.second) cnt++;
        }
        pr(ans+(cnt > 2 ? 1 : 0));
    }
}