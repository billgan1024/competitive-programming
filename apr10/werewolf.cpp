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
const ll MOD = 1e9+7;
const int MN = 201;

// the directed graph is actually just a collection of trees (can verify by analyzing the nodes in increasing order and 
// showing that the graph must be a collection of trees
// now we need a way to count # of valid configurations (n-sequences) that have exactly W werewolves
// but these can be generated by individual trees since they are independent. more generally, we
// need to compute ans[i][k] = # of valid configs for trees 1, ..., i with exactly k werewolves, for 
// 1 <= i <= # of rees and 
// we have ans[i][k] = sum of ans[i-1][c]f(i, k-c) where 0 <= c <= k and f(i, k) = # of valid configs for tree 
// i with exactly k werewolves
// total complexity so far: O(n^3)
// given that we only need to sum up ans[i-1][c]f(i, k-c) for c taking on O(size of tree i) values
// for each tree and k ranging from 0 to W
// now we need to find out how to compute f(i, k) for all trees i. 
// can try dp for this as well. 
// in general, when breaking up problems of the form 'find # of configurations such that 
// sum of f(i) = k', we can just use dp to isolate one variable from the rest, and take the dot product of 
// two vectors)
// let S be any valid configuration for current tree i with exactly k werewolves. if 
// the root node is a civilian, then we don't care about the root node edges, and we would have to 
// just use dp[child][k] := # of valid configs in child's subtree with exactly k werewolves, where 
// we must use an intermediate array to perform the isolation method on the current child subtree
// actually, you can just use dp[i] (the whole dp array for the current node)
// as an intermediate array (just use a swap array since you just need to operate on the accumulation of 
// the value "# of valid configs for the first j child subtrees such that # of werewolves = k" and the current subtree
// you just need O(n) space for each node for a total of O(n^2) space now
// otherwise, the root node is a werewolf, and then we can determine the statuses of all child nodes.
// thus, we also need the concept of dp[child][k][0/1] which represents the answer where the valid configurations 
// have the root node being a civilian or werewolf
// total time complexity has an upper bound of O(n^2) since flood fill dfs is O(n) (summing up the vertices
// and edges), but the time to process each edge is multiplied by O(n) cuz of the recurrence to calculate the 
// dp[i] array
// note that in general, dfs is O(V+E) in the flood fill sense, since every vertex is processed once and every 
// edge is processed twice.
struct edge {
    int v; char c;
};

int N, W, M; ll dp[2][MN][MN][2], ans[2][MN]; vector<edge> adj[MN]; bool vis[MN];
// post: dp[cur][k][0/1] := representing the array for # of configs in cur's subtree 
// where the root node is a civilian (0) or a werewolf (1), with exactly k werewolves (for all k) is correctly updated
// to compute dp[i], we just use the swp index (first one), then put the result in dp[0][i][k][0/1]
// in general, swp = how many child subtrees u are currently dealing with
void dfs(int cur) {
    vis[cur] = true; 
    // root node civilian (0): no restrictions on the root nodes of the child subtrees, such that # of configs 
    // for a particular child subtree with j werewolves is just equal to the sum of dp[?][child][j][0] + dp[?][child][j][1]
    // root node werewolf (1): must restrict each root of the child subtree to the status corresponding to the edge
    // such that dp tracks the # of valid configurations in the first ? child subtrees that have j werewolves
    // according to the required node status for the child nodes.

    dp[0][cur][0][0] = 1; 
    //for the root node being a werewolf, the base case without analyzing any subtree is that 
    //achieving one werewolf is the only option (since the root has to be a werewolf) 
    dp[0][cur][1][1] = 1;
    int swp = 0;
    for(auto [nxt, c] : adj[cur]) {
        // rely on directed graph
        dfs(nxt); 
        swp++;
        for(int j = 0; j <= W; j++) {
            // force out j werewolves in the first swp child subtrees
            dp[swp%2][cur][j][0] = dp[swp%2][cur][j][1] = 0;
            for(int k = 0; k <= j; k++) {
                dp[swp%2][cur][j][0] = (dp[swp%2][cur][j][0]+dp[(swp-1)%2][cur][j-k][0]*(dp[0][nxt][k][0] + dp[0][nxt][k][1])) % MOD;
                // werewolves only accuse other civilians, so we just take from the corresponding status 
                dp[swp%2][cur][j][1] = (dp[swp%2][cur][j][1]+dp[(swp-1)%2][cur][j-k][1]*dp[0][nxt][k][c == 'D']) % MOD;
            }
        }
    }
    //clone swp into 0
    for(int k = 0; k <= W; k++) {
        dp[0][cur][k][0] = dp[swp%2][cur][k][0];
        dp[0][cur][k][1] = dp[swp%2][cur][k][1];
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, W, M);
    for(int i = 0, a, b; i < M; i++) {
        char c;
        sc(c, a, b); adj[a].pb({b, c});
    }
    //then, sum up the results using ans
    //base case is ans[0][0] = 1 only (think about multiplicative identities, or the fact that 
    //the only configuration for 0 nodes is the empty string which has zero werewolves)
    ans[0][0] = 1;
    //we can search the current subtree and update answer at the same time, since by the time the 
    //search ends on the current subtree, dp[cur][0/1] is available to use
    int swp = 0;
    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            dfs(i);
            swp++; 
            // fill up ans[cnt%2][j] = # of valid configs for the first swp subtrees with j werewolves 
            for(int j = 0; j <= W; j++) {
                ans[swp%2][j] = 0;
                for(int k = 0; k <= j; k++) 
                    ans[swp%2][j] = (ans[swp%2][j] + ans[(swp-1)%2][j-k]*(dp[0][i][k][0] + dp[0][i][k][1])) % MOD;
            }
            //invariant: swp represents the most updated index (mod 2)
        }
    }
    // pr(dp[0][1][1][0], nl);
    pr(ans[swp%2][W], nl);
}