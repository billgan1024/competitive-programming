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
const int maxN = 1.5e3;

// dp[i][j]: For i's subtree, max # of marked nodes where all marked nodes have depth >= j
// Transition: for 2j >= d <=> j >= ceil(d/2), dp[i][j] = sum of dp[k][j-1], since any two nodes at depth j (with respect to i).
// This requires O(E) processing time for each node, and the overall principle is that if you achieve O(E) computation
// for each node, your algorithm will run in O(N) time (equivalent to one dfs).
// otherwise, for j < ceil(d/2), only one marked node in i's subtree can have depth in the range [j, ceil(d/2)-1].
// thus, after the O(E) computation, find max(dp[v][m-1] + sum of dp[rest][d-m-1]) as m ranges over [j, ceil(d/2)-1] and 
// v ranges over all children

// recap: the complexity of a dp is equal to the complexity of one dfs on, which is ONLY equal to (# of states) * (# of transitions per state)
// if all states have a 'uniform' amount of transitions (see knapsack for an example)

// (E = # of edges coming out of a child node)
// right now, the running time for each state requires O(NE^2) since d = O(n) and for each child node, you're computing 
// O(EN) values. 

// the above complexity looks like O(n^5) but it's actually O(n^4) since for any fixed dimension, each vertex has O(NE^2) transitions,
// e_i = number of edges from node i projecting downward to its children
// the upper bound for # of edges for a fixed second dimension (the j in dp[i][j]) is e_1(Ne_1) + e_2(Ne_2)+... <= (e_1+...e_n)(N^2) = N^3

// (in general, sum of e_i = O(n) is a property found in most (if not all) graph theory problems)


// 1st optimization: for a particular child,
// we can speed up the computation of sum of dp[rest][d-m-1] by maintaining a psa of dp[children][m] where nodes 
// are mapped to indices such that the children of a node are all adjacent to each other (assuming that 
// there is a top-down or recursive order such that when we query the parent node, we already have 
// sum of dp[children][m] computed for each depth m).
// then, for every child node, you're computing O(N) values instead of O(EN) values
// edit: upon further analysis, you need to perform this dfs/bfs order mapping first, then 
// use 
// time complexity: O(n^3)

int N, D, dp[maxN][maxN], idx, s[maxN][maxN]; vector<int> adj[maxN];
// dfs:
// maintain the invariant that by the time dfs(cur) ends, all values of dp[c][m]
void dfs(int cur, int pre) {

}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, D);
    // nodes are from 0 to n-1
    for(int i = 1, x; i <= N-1; i++) {
        sc(x); adj[i].pb(x); adj[x].pb(i);
    }
}