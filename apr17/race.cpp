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
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

// strategy: enumerate all paths of length len and find the one
// with the minimum number of edges

// centroid decomp: relies on the fact that an optimal path always either doesn't contain the root, 
// or does contain the root. then, using the standard iteration order for paths that go through the root, 
// observe that for any particular current node, you just need to find all nodes in previous subtrees 
// which are k-(current dis) away
// base case is when i is a child (think of any tree as a node with n>=0)
// in general, try to re-describe the algorithm as an algorithm which has a data structure optimization

// in general, path queries need to be optimized in interesting ways as we try to 
// compute min f(p) for p (path that goes through i). a path is just identified by 
// an (unordered) pair of nodes, and computing attributes of multiple paths needs to be optimized for most problems.
// remember that we can easily iterate through all nodes in a tree while threading the depth (unweighted distance)
// and weighted distance into the recursive calls, and easily compute the size of each subtree. watch out for dot-product type expressions,
// as if you can't brute force the dot product computation dp[i] = min sum of f(j)*c(j) or dp[i] = min sum of f(j)+c(j),
// we need to look for some other optimization (and in this case, try simulating the problem)

// recall that we proved that the centroid of a tree always existed due to the property of the centroid itself. 
// the algorithm for finding the centroid is bounded above by the time for a dfs (since we just visit nodes 
// on a particular path), and is thus O(V+E) where the graph may be a subgraph. 
// naming conventions: struct fields should be as verbose as possible, then variable names, such that 
// we can use generic variables for arrays
const int MN = 2e5, MM = 1e6;
vector<pii> adj[MN]; int s[MN], ans = 1e9, len; bool vis[MN]; 
//tldr: unordered_map sucks
hash_map<int, int> f; queue<pii> q;

// inline: turn a simple function into a macro (saves overhead of function calls)
inline int get(int i) {
    return f.find(i) == f.end() ? 1e9 : f[i];
}
// subtree search for the current node (updates ans accordingly)
void sub(int cur, int pre, int dis, int edges) {
    q.push({dis, edges});
    ans = min(ans, edges + get(len-dis));
    for(auto [nxt, w] : adj[cur]) {
        if(nxt != pre && !vis[nxt]) {
            sub(nxt, cur, dis+w, edges+1);
        }
    }
}
// computes the size values for this particular subtree 
// pre: cur = valid subtree
// post: s[cur] is set up correctly
void dfs(int cur, int pre) {
    s[cur] = 1;
    for(auto [nxt, w] : adj[cur]) {
        if(nxt != pre && !vis[nxt]) {
            dfs(nxt, cur); s[cur] += s[nxt];
        }
    }
}
int find_cent(int cur, int pre, int size) {
    for(auto [nxt, w]: adj[cur]) {
        if(nxt != pre && !vis[nxt] && s[nxt] > size/2) return find_cent(nxt, cur, size);
    }
    return cur;
}

// updates ans using cur, which is the centroid inside some subtree
// now f[i] = min # of edges for a path fragment of length i, where we only need to query 
// values in the range [1, k) (need a hashmap to only work with O(sz subtree) values)
// also we need to store a vector of new changes every time we run
// invariant: only interact with unvisited nodes such that we can effectively 
// dfs on child subtrees
void solve(int cur) {
    vis[cur] = true;
    // just ignore the path which just consists of the root node (since K > 0)
    f[0] = 0;
    //then update ans accordingly
    for(auto [nxt, w] : adj[cur]) {
        if(!vis[nxt]) {
            sub(nxt, -1, w, 1);
            // now release changes
            while(!q.empty()) {
                auto [dis, edges] = q.front(); 
                if(get(dis) > edges) f[dis] = edges;
                q.pop();
            }
        }
    }
    f.clear();
    // now we can block cur (which functions as the visited array, as we need to restrict dfses 
    // in the child subtrees)
    for(auto [nxt, w] : adj[cur]) {
        // basically we're doing dfs on the centroid tree, which is a tree of height O(logn)
        // and each call to solve(centroid) requires O(size of subtree) processing time, such that the main program 
        // requires a total of log(n) dfses, or O(nlogn) time.
        if(!vis[nxt]) {
            dfs(nxt, -1);
            solve(find_cent(nxt, -1, s[nxt]));
        }
    }
}
int best_path(int N, int K, int H[][2], int L[]) {
    len = K;
    for(int i = 0; i < N-1; i++) {
        int a = H[i][0], b = H[i][1], w = L[i];
        adj[a].pb({b, w}); adj[b].pb({a, w});
    }
    dfs(0, -1);
    solve(find_cent(0, -1, s[0]));

    //check how many times 
    return (ans == 1e9) ? -1 : ans;
}

// int main() {
//     cin.sync_with_stdio(0); cin.tie(0);
//     flush;
//     int N = 4, K = 3, H[][2] = {{0, 1}, {1, 2}, {1, 4}}, L[] = {1, 2, 3};
//     pr(best_path(N, K, H, L));
// }