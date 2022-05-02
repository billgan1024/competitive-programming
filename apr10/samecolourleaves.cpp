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
const int mod = 1e9+7, maxN = 3e5+1;

int N; ll ans[maxN], dp[maxN][2]; int col[maxN]; string str; vector<int> adj[maxN];
// edited for clarification b/w subtree and subgraph tree
// definition of a leaf: node w/ only one edge 
// observation: given an arbitrary root, ans[i] (representing # of subgraph trees with same coloured leaves 
// in i's subtree) can be broken down into 
// sum of ans[child] (if i is not in the subtree)
// + (# of subgraph trees (all leaf nodes are the same colour, including the root if the root only has one children) containing node i)

// we need to define a more robust dp state: let dp[i][0/1] represent the number of subgraph trees containing i such that 
// all leaf nodes (define by the ends of the tree when i is the root) are colour 0/1; we are temporarily assuming 
// that the root node is never a leaf node

// this definition ensures that the transition is correct, and the base case is when you're dealing with a leaf
// node of the original tree, in which case the answer is 1 if the colour matches.

// then dp[i][c] = sum over all products of subsets of dp[child][c], subtracting 1 if col[i] != c (if the subgraph tree only consists
// of a single node, it is considered a leaf)

// then observe that the # of subgraph trees containing i is  
// dp[i][0] + dp[i][1] - number of invalid subtrees (where the subgraph trees has leaves which are a different colour 
// than the root node, and the root node only used one child subgraph tree, making the root node have the wrong colour)
// for the colour (c) of node i, dp[i][c] is completely accurate 
// otherwise, for dp[i][!c], all leaf nodes are the other colour, and the only invalid trees here are when node i 
// extends into only one subtree with leaves of the different colour, so you need to subtract sum of dp[child][!c]

// therefore, it suffices to perform three dfses; one to calculate dp[i][0/1] and another to calculate ans[i].
// the transition for each state takes O(e) (e = # of edges coming out of the node), so the time complexity is O(N)

// side note: lambdas are basically functions defined at the top of the program; u can pass parameters 
// by reference so that they will automatically update variables (even works with local variables inside dfs)

void dfs(int cur, int pre, int c) {
    // if cur has no children, then dp[cur][c] = 0 or 1 depending on whether col[cur] = c
    dp[cur][c] = 1; 
    for(int nxt : adj[cur]) {
        if(nxt != pre) {
            dfs(nxt, cur, c);
            dp[cur][c] = (dp[cur][c] * (dp[nxt][c]+1)) % mod;
        }
    }
    if(col[cur] != c) dp[cur][c] = (dp[cur][c]-1+mod)%mod;
}
// invariant: when dfs2(cur) ends, ans[cur] shows the correct answer
// this algorithm works for the base case (when cur has no children, since the for loop won't run)
void dfs2(int cur, int pre) {
    ans[cur] = (dp[cur][0] + dp[cur][1]) % mod;
    for(int nxt : adj[cur]) {
        if(nxt != pre) {
            dfs2(nxt, cur); 
            ans[cur] = (ans[cur] + ans[nxt]) % mod;
            ans[cur] = (ans[cur] - dp[nxt][!col[cur]] + mod) % mod;
        }
    } 
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, str); 
    for(int i = 1; i <= N; i++) col[i] = str[i-1] == 'R';
    for(int i = 0, u, v; i < N-1; i++) {
        sc(u, v); adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1, 0, 0); dfs(1, 0, 1);
    dfs2(1, 0);
    pr(ans[1]);
}