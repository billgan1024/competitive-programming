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
const int maxN = 1e5+1;


int N, M; ll dp[maxN], out[maxN]; vector<ll> psa[maxN], suf[maxN]; vector<int> adj[maxN];
// invariant: at the end of the algorithm on the current node, dp[i] and the product arrays have been set
void dfs(int cur, int pre) { 
    dp[cur] = 1;
    // iterate through children in increasing order to calculate dp[i] and get prefix and suffix products of dp[child]+1
    // since the parent can be anywhere in the adjacency list, store it along with the children (it's a dummy node that doesn't affect 
    // computation since the implicit dp value is 1)
    for(int nxt : adj[cur]) {
        if(nxt != pre) {
            dfs(nxt, cur); 
            // update prefix
            dp[cur] = (dp[cur]*(dp[nxt]+1)) % M;
        }
        psa[cur].pb(dp[cur]);
    }
    ll s = 1;
    for(int i = sz(adj[cur])-1; i >= 0; i--) {
        int nxt = adj[cur][i];
        if(nxt != pre) s = (s*(dp[nxt]+1)) % M;
        suf[cur].pb(s);
    }
    reverse(suf[cur].begin(), suf[cur].end());
}

// note that we can't compute out without the parent product array being finished. 
// now dfs so that as soon as a node is discovered, its out[i] value is set correctly
// we choose to code the dfs enter function inside the discovering of a new node 
// since we can easily assign out[nxt] the value of dp[cur]/(dp[nxt]+1)
void dfs2(int cur, int pre) {
    for(int i = 0; i < sz(adj[cur]); i++) {
        int nxt = adj[cur][i];
        if(nxt != pre) {
            out[nxt] = 1;
            if(i > 0) out[nxt] = (out[nxt] * psa[cur][i-1]) % M;
            if(i < sz(suf[cur])-1) out[nxt] = (out[nxt] * suf[cur][i+1]) % M;
            out[nxt] = (out[nxt] * out[cur] + 1) % M;
            dfs2(nxt, cur);
        }
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // observation: for any given node, the number of ways to paint the graph (given that this node is black)
    // is equal to the number of subgraphs of black nodes that are trees, given that this node is in the subgraph
    // (a subgraph of black nodes is a subset of the original graph where all nodes are black and all edges are between black nodes)
    // because subgraphs can be uniquely identified by the subset of black nodes
    // for an arbitrary root: let dp[i] = number of valid subgraphs which are trees with respect to i's subtree (with respect to the root) 
    // that also contain i 
    // then dp[i] = sum over all products of subsets of dp[j], where j is a direct child of i because a subtree is 
    // composed of some collection of child subtrees
    // this is equal to product of dp[j]+1, so the O(n^2) solution is to rely on N depth-first searches to compute ans[i]
    // to optimize to a constant # of dfses, we can use in-out dp
    // ans[i] = dp[i]*(# of subtrees that contain i when we consider the nodes outside of i's subtree and i)
    // let out[i] represent the other product; then ans[i] = dp[i]*out[i]

    // analyzing the subtrees in the set of nodes i+tree\subtree(i) in the computation of out[i]:
    // case 1: the parent node's not marked i.e. you just have node i when ur considering the subtree 
    // that contains i in the set of nodes i + tree\subtree(i) (one configuration)
    // otherwise, there are (number of valid subtrees w.r.t. parent's subtree containing the parent but not considering 
    // the original subtree)*out[parent] subtrees.
    // the first product = dp[parent]/(dp[i]+1)

    // therefore out[i] = 1 + dp[parent]/(dp[i]+1) * out[parent]

    // then, you need to maintain a prefix and suffix product array for each node on their children
    // to easily calculate dp[parent]/(dp[i]+1) mod M(we can't calculate mod inverses for arbitrary M and dp[i]+1) 
    // simply use nxt -> (index of nxt in cur's adjacency list) as the map so that you can build an array of products

    // time complexity and memory complexity: O(n)

    sc(N, M);
    for(int i = 0, x, y; i < N-1; i++) {
        sc(x, y); adj[x].pb(y); adj[y].pb(x);
    }
    dfs(1, 0);
    out[1] = 1;
    dfs2(1, 0);
    for(int i = 1; i <= N; i++) pr((dp[i]*out[i]) % M, nl);
}