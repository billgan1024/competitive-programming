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
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, class cmp = less<T>> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 4e5+1;

// observation: connecting any two nodes gives u a tunnel of length d(a, b) + 1
// thus, find number of paths (which correspond to pairs of vertices, since there's exactly
// one path for any two pairs of vertices) with length = diameter
// find the centroid, then use divide and conquer: the number of diameters
// = number of diameters that go through the centroid + number of diameters that don't go through the 
// centroid. (the second sum is equal to the sum of the # of diameters 
// in a subtree, over all subtrees)
// think about this iteratively:
// each time, you are finding the centroids of the group of components
// and then calling dfs on these components which takes O(n) time.
// The centroids split 
// the tree into subtrees each with size <= (number of nodes in the component/2)
// thus, you only dfs on the original tree a total of O(logn) timwa

// to implement this process efficiently, we can simply call a modified dfs starting from 
// the centroid of the original tree. first, compute # of diameters psasing thru the current centroid,
// and then dfs into any one component and find # of diameters in that subtree and add it to the total.
// note: use a map so that resetting the map also takes O(sz component) time to ensure O(nlogn)  
// dfs computation time for each iteration. also make sure not to clear the size array, since that 
// takes more than O(sz component) time
int N, diam, far, len, s[maxN], b[maxN]; ll ans; vector<int> adj[maxN]; unordered_map<int, int> f;
void get_furthest(int cur, int pre, int d) {
    //invariant: when entering this node, d = distance from cur to source
    if(len < d) { far = cur; len = d; }
    for(int nxt : adj[cur]) {
        if(nxt != pre) get_furthest(nxt, cur, d+1);
    }
}

// the following algorithms work while the graph has a blocked array so that 
// we can effectively delete nodes in O(1) time. a blocked node will not allow any 
// search to pass through it

// the blocked array is necessary since we need to restrict the calculations to each subtree (finding centroid + solving 
// the problem for the subtree)

// store size of each node's subtree (s[i]), given an arbitrary root
// invariant: if a node was dfsed in the current call to get_size, then it will have the correct 
// size at the end of the function (no need to reset the portion of s corresponding to the subtree)
// simply call get_size(child, current centroid)
void get_size(int cur, int pre) {
    s[cur] = 1;
    for(int nxt : adj[cur]) {
        if(!b[nxt] && nxt != pre) {
            get_size(nxt, cur); s[cur] += s[nxt];
        }
    } 
}

// returns the centroid of a certain subtree (the blocked array will determine what subtree ur searching in)
// simply call centroid(child node, previous centroid, s[child node]) to only dfs in the current subtree
int centroid(int cur, int pre, int tot) {
    for(int nxt : adj[cur]) {
        if(!b[nxt] && nxt != pre && 2*s[nxt] > tot) return centroid(nxt, cur, tot);
    }
    return cur;
}

// dfs into this subtree to add the paths ending at each node in this subtree
// new: pass in the function as a parameter (the entry function for the depth first search) as a parameter
void dfs(int cur, int pre, int d, function<void(int)> func) {
    func(d);
    for(int nxt : adj[cur]) {
        if(!b[nxt] && nxt != pre) dfs(nxt, cur, d+1, func);
    }
}

// accumulates number of diameters in ans
// accepts a centroid to run in O(nlogn) time
void num_diam(int cent) {
    // first, compute the number of diameters that go through the centroid. 
    // this is equal to the number of pairs of nodes in different subtrees that satisfy 
    // d(a) + d(b) = diam
    // can accumulate all paths ending at a particular subtree by using a frequency map 
    // f[i] = tracking the number of nodes in 'previous' subtrees with distance i, for 0 <= i <= diam (f[0] = 1 always)
    // use f.clear() that runs in O(sz component time) so that the total complexity doesn't blow up to O(n^2logn) time
    // base case: one node will terminate the recursion 
    f.clear(); f[0] = 1;
    for(int nxt : adj[cent]) {
        if(!b[nxt]) {
            // get the number of paths that pass through the centroid and end at nodes in the current subtree using freq
            // and also update freq
            dfs(nxt, cent, 1, [](int d) -> void { ans += f[diam-d]; }); dfs(nxt, cent, 1, [](int d) -> void { f[d]++; });
        }
    }
    //then block the centroid and compute the number of diameters in each subtree
    b[cent] = true;
    for(int nxt : adj[cent]) {
        if(!b[nxt]) {
            get_size(nxt, 0);
            num_diam(centroid(nxt, 0, s[nxt]));
        }
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 0, u, v; i < N-1; i++) {
        sc(u, v); adj[u].pb(v); adj[v].pb(u);
    }
    //len = distance of furthest node
    get_furthest(1, 0, 0); int p1 = far;
    len = 0; get_furthest(p1, 0, 0); diam = len;
    get_size(1, 0);
    num_diam(centroid(1, 0, s[1]));
    pr(diam+1, sp, ans, nl);
}