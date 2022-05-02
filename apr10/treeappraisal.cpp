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
const int maxN = 2e5+1;

int N, s[maxN]; bool b[maxN]; ll val[maxN], divi[2], vi[2], di[2], cnt[2], ans; vector<int> adj[maxN];
// naive O(n^2logn) method: precompute distance and sums of nodes along paths from an arbitrary root + use lca
// let f(i, j) = d(i, j)*v(i, j) where d is distance and v is the sum of values of nodes between i and j
// edit: dp doesn't work since you're not counting when two nodes are in different subtrees

// instead, focus on an arbitrary root, and consider all the paths that contain this node. this consists of all the pairs 
// of nodes in different child subtrees, or when one node is the actual root (and then you're free to pick any node)
// you can start a dfs into every subtree and maintain the sum of d_iv_i ranged over all paths 
// (d_i = length of any path, v_i = value of any path)
// from nodes in previous subtrees to the root node (+ the root node itself), but for each new node you discover, you need to 
// increase the sum by sum of (d_i+d)(v_i+v) = sum of d_iv_i + sum of vd_i + sum of dv_i + d*v*(# of previous paths), meaning that you actually need to track the sum of d_i
// and v_i (over all previous paths)

// then repeat the same process for each individual component, meaning that if you're dealing with the centroid, 
// the total number of operations is O(nlogn).
// make every relevant quantity ll to avoid overflow

// alternate approach (useful for paths): apply in-out dp (not recommended)

void dfs(int cur, int pre) {
    s[cur] = 1;
    for(int nxt : adj[cur]) {
        if(nxt != pre && !b[nxt]) {
            dfs(nxt, cur); s[cur] += s[nxt];
        }
    }
}

void dfs2(int cur, int pre, ll d, ll v, ll root) {
    // update ans based on previous paths (distance-value pairs) that can be extended to the current subtree
    // previous paths are calculated to extend to the root node, so make sure that the future paths you're
    // adding also extend to the root node
    ans += divi[0] + di[0]*v + d*vi[0] + d*v*cnt[0];
    divi[1] += d*(v+root); di[1] += d; vi[1] += v+root; cnt[1]++;
    for(int nxt : adj[cur]) {
        if(nxt != pre && !b[nxt]) dfs2(nxt, cur, d+1, v+val[nxt], root);
    }
}

// finds centroid of given component, given that the sizes are set up properly
// this strategy works since when travelling to a new node; you automatically rule out nodes outside of the new node's subtree 
// from being the centroid
// also works for single nodes, since they have no children
int centroid(int cur, int pre, int tot) {
    for(int nxt : adj[cur]) {
        if(nxt != pre && !b[nxt] && 2*s[nxt] > tot) return centroid(nxt, cur, tot);
    }
    return cur;
}

// using functional programming instead of imperative: given a configuration of the centroid with 
// cur denoting the current component, update the sum of all f(i, j) ranging over distinct paths (i.e. unordered 
// pairs of nodes) in cur's component
// the 'components' w.r.t. the centroid decomposition are entirely determined by the blocked array,
// so solve(1, 0) will return sum of f(i, j) in the entire graph
// invariant: at the beginning of this function, we're dealing with a component with at least cur being unblocked,
// and dfs will never process a blocked node (all dfs functions always process open nodes)
// and they will work for the base case (by default, ans is not updated when cur has no unblocked subtrees)
void solve(int cur) {
    // find centroid
    dfs(cur, 0);
    int cent = centroid(cur, 0, s[cur]);
    // compute all paths that go through centroid
    // maintain sum of all divi from previous paths that can be connected to nodes in the current subtree
    // cnt tracks number of previous paths
    // each one has an updater so that we can accumulate a change in the temp variable x[1] to
    // be able to update it at the end of each subtree call
    divi[0] = 0; di[0] = 0; vi[0] = val[cent]; cnt[0] = 1;
    for(int nxt : adj[cent]) {
        if(!b[nxt]) {
            dfs2(nxt, cent, 1, val[nxt], val[cent]); 
            divi[0] += divi[1]; di[0] += di[1]; vi[0] += vi[1]; cnt[0] += cnt[1];
            divi[1] = di[1] = vi[1] = cnt[1] = 0;
        }
    }
    // block centroid and recurse to individual subtrees
    b[cent] = true;

    for(int nxt : adj[cent]) {
        if(!b[nxt]) solve(nxt);
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 1; i <= N; i++) sc(val[i]);
    for(int i = 1, a, b; i < N; i++) {
        sc(a, b); adj[a].pb(b); adj[b].pb(a);
    }
    solve(1); pr(ans);
}