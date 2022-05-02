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
const int MN = 2e5+1;

int N; ll c[MN], dp[MN][3]; vector<int> adj[MN]; bool m[MN];
//dp[i][0/1]: min cost of a sequence that activates i's subtree where i is marked (1) or not marked (0)
//can prove this by induction on the depth of the node (starting from the bottom)
//we set infinity to be a large number to mean that we can't mark the entire subtree
//dp[i][2]: for the tree with i marked, min cost of a sequence that activates i's subtree and activates i
void dfs(int cur, int pre) {
    ll sn = 0, s1 = 0, min_c = 1e12;
    //dp[i][1] = min(sum of dp[child][1], sum of dp[child][m[child]])
    //dp[i][0] = min(sum of dp[child][m[child]] + min c[child], 
    //c[cur] + sum of dp[child][1] - dp[k][1] + dp[k][m[k]] + c[k]), and if m[k] == 1, then 
    // also check c[cur] + sum of dp[child][1] - dp[k][1] + dp[child][2]
    // a good way to think about dp[cur][0] is that either there exists an optimal sequence which doesn't
    // activate node i, in which case the first formula is intuitive. otherwise, if there exists an optimal 
    // sequence which does activate node i, we can rearrange the sequence of moves to obtain another 
    // sequence of the same optimal cost which consists of operating on all child subtrees with the child node 
    // already being set to 1, with the exception of one subtree
    // note that we only need accumulator variables, so we actually only need O(1) space to track
    // base case: dp[cur][1] = 0, dp[cur][0] = 1e12 (a really large number that won't overflow with addition)
    for(int nxt : adj[cur]) {
        if(nxt != pre) {
            dfs(nxt, cur);
            s1 += dp[nxt][1];
            sn += dp[nxt][m[nxt]];
        }
    }
    dp[cur][1] = min(c[cur] + s1, sn);
    // didn't activate node cur? then we have to find out the optimal sequence. 
    dp[cur][0] = 1e12;
    for(int nxt : adj[cur]) {
        if(nxt != pre) {
            dp[cur][0] = min(dp[cur][0], sn + c[nxt]);
            if(m[nxt]) dp[cur][0] = min(dp[cur][0], sn - dp[nxt][m[nxt]] + dp[nxt][2]);
        }
    }
    dp[cur][2] = c[cur] + s1;
    for(int nxt : adj[cur]) {
        if(nxt != pre) {
            // check if you can use subtree nxt to activate 
            dp[cur][0] = min(dp[cur][0], c[cur] + s1-dp[nxt][1] + dp[nxt][m[nxt]] + c[nxt]);
            if(m[nxt]) dp[cur][0] = min(dp[cur][0], c[cur] + s1-dp[nxt][1] + dp[nxt][2]);
        }
    }
    
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 0, a, b; i < N-1; i++) {
        sc(a, b); adj[a].pb(b); adj[b].pb(a);
    }
    string s; sc(s);
    for(int i = 0; i < N; i++) m[i+1] = s[i] == 'Y';
    for(int i = 1; i <= N; i++) sc(c[i]);
    dfs(1, -1);
    // for(int i = 1; i <= N; i++) pr(dp[i][0], sp, dp[i][1], nl);
    pr(dp[1][m[1]], nl);
}