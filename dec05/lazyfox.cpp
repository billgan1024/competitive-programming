#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("Ofast")
#define INF 0x3f
#define nl '\n'
#define pb push_back,.
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, class cmp = less<T>> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 2e3+1;

int n, ans, dp[maxN][maxN]; pii p[maxN], adj[maxN][maxN];
//original idea: dp[i][bound] = max number of points you can visit if you take a decreasing path and the first jump needs to have a distance < bound
//to save memory, note that only the actual node you're travelling to matters (not the distance exactly), thus we can save memory by only checking the index of the node

//dp[i][idx] = max number of points you can visit (including the current node) if
//you take a decreasing path and the first jump needs to have a distance <= adj[i][idx].first (time complexity is n^3)

//maintain an adjacency list of a sorted sequence of all of the nodes by distance (for every node)

//optimization:
//in visiting all nodes in the sorted list up to position idx, notice that 
//lots of work is reused; in particular, for any f(i, idx), the answer is the exact same as f(i, idx-1) if the optimal answer
//doesn't involve choosing the furthest available node.
//thus, f(i, idx) = max(f(i, idx-1), f(idx, nextIndex)+1) (choose furthest available node, or don't)
//base case is 1 if idx is 1.
int d(int i, int j) { 
    int dx = p[i].first-p[j].first, dy = p[i].second-p[j].second;
    return dx*dx+dy*dy;
}

int f(int cur, int idx) {
    if(dp[cur][idx]) return dp[cur][idx];
    else if(idx == 1) return 1;
    int nxt = adj[cur][idx].second, dis = adj[cur][idx].first;
    int nextIndex = lower_bound(adj[nxt]+1, adj[nxt]+n+1, make_pair(dis, 0))-adj[nxt]-1;
    return dp[cur][idx] = max(f(cur, idx-1), f(nxt, nextIndex)+1);
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    //cout.setf(ios::unitbuf);
    for(int i = 1; i <= n; i++) sc(p[i].first, p[i].second);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) adj[i][j] = {d(i, j), j};
        sort(adj[i]+1, adj[i]+n+1);
    }
    for(int i = 1; i <= n; i++) {
        int dis = d(0, i);
        //find the last index which is < distance from the origin
        int idx = lower_bound(adj[i]+1, adj[i]+n+1, make_pair(dis, 0))-adj[i]-1;
        ans = max(ans, f(i, idx));
    } 
    pr(ans);
}