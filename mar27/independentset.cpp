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
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
const int maxN = 1e5+1;
const ll mod = 1e9+7;

//root the tree arbitrarily (at node 1), then calculate dp[i][j]: # of ways to correctly paint the subtree with root i
//when node i is colour j (0 = black, 1 = white)
//if node i is black, then all the children nodes of i need to be white
//otherwise, there are no restrictions
//total complexity: 1 dfs, so O(v+e) (simply do dfs to guarantee the correct order in traversing the tree because
//you need to know who the parent node is)
int N; vector<int> adj[maxN]; ll dp[maxN][2];
void dfs(int cur, int prev) {
    //calculate the value for dp[cur][j]
    //dp[cur][0] = product of all dp[nxt][1]
    //dp[cur][1] = product of all dp[nxt][0] + dp[nxt][1]
    dp[cur][0] = dp[cur][1] = 1;
    //explore the children nodes, should they exist
    for(int nxt : adj[cur]) {
        if(nxt != prev) {
            dfs(nxt, cur);
            //after dfs(nxt, cur) terminates, dp[nxt][0] and dp[nxt][1] have been calculated
            dp[cur][0] = (dp[cur][0]*dp[nxt][1]) % mod;
            dp[cur][1] = (dp[cur][1]*(dp[nxt][0] + dp[nxt][1])) % mod;
        }
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 0, x, y; i < N-1; i++) {
        sc(x, y); adj[x].pb(y); adj[y].pb(x);
    }
    dfs(1, 0);
    pr((dp[1][0] + dp[1][1]) % mod, nl);
}