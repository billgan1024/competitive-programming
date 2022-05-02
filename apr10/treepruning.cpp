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
const int maxN = 300;

int N, D, root, col[maxN], dp[maxN][2*maxN+1], d[maxN]; vector<int> adj[maxN]; 
// max val of dp[i] = N
// default value: -INF so that we know which dp states have been calculated
// invariant: f(cur, i) produces whether or not you can make a difference value of i
// in cur's subtree, where the answer to repeated calls is memoized by dp[cur][i+maxN]
// we could also use a dfs that returns nothing, if we maintain the invariant that dp[cur][i] is 
// a visited array and at the end of the dfs, dp[cur][i] is set. (it's the same dfs as the one used with the 
// function that returns something, and dfs(cur, i) is a command that sets the value of dp[cur][i] 
// by dfsing into the children)
int f(int cur, int i) {
    if(i == 0) return d[cur] == 0 ? 0 : 1;
    else if(sz(adj[cur]) == 0) return col[cur] == i ? 0 : 1e9;
    else if(dp[cur][i+maxN] >= 0) return dp[cur][i+maxN];
    // otherwise, we need to prune the subtrees (and only the subtrees)
    else if(sz(adj[cur]) == 1) return dp[cur][i+maxN] = f(adj[cur][0], i-col[cur]);
    else {
        dp[cur][i+maxN] = 1e9;
        for(int j = -maxN; j <= maxN; j++) {
            int k = i-j-col[cur]; 
            if(k >= -maxN && k <= maxN) {
                dp[cur][i+maxN] = min(dp[cur][i+maxN], f(adj[cur][0], j) + f(adj[cur][1], k));
            }
        }
        return dp[cur][i+maxN];
    }
}
void dfs(int cur) {
    d[cur] = col[cur];
    for(int nxt : adj[cur]) {
        dfs(nxt); d[cur] += d[nxt];
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, D);
    // observe that to prune the tree so that the difference value is D, you either prune the root (removing the entire tree)
    // or prune the subtrees.
    // define dp[i][j+maxN] to be the min # of prunes you need to perform on a subtree so that it has a difference value of j
    // then dp[i][j]'s default value is infinity
    // for i being a leaf node or when j == 0, we can easily determine the value of dp 
    // (if j == 0, then the answer is either 0 or 1. otherwise, for j not equal to zero and a leaf node, the only option
    // is to not prune it)
    // otherwise, for a non-leaf node + j not 0, the optimal pruning operations don't prune the root
    // so dp[i][j] = min(dp[child1][k] + dp[child2][j-k+1]) or min(dp[child1][k] + dp[child2][j-k-1]) depending on the difference

    // time complexity is O(N^3) since there are O(N) nodes, and each node has up to O(N^2) transitions if we consider a binary 
    // tree (then there are O(N^3) edges in the dfs)

    for(int i = 0, x, c; i < N; i++) {
        sc(x); sc(col[x], c); if(col[x] == 0) col[x]--; // 1 = white, -1 = black
        for(int j = 0, v; j < c; j++) {
            sc(v); adj[x].pb(v); 
        }
    }
    // dfs to get the difference value for each subtree initially
    dfs(0);
    ms(dp, -INF);
    int ans = f(0, D);
    pr(ans == 1e9 ? -1 : ans);
}