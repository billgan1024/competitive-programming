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
const int maxN = 2e5+1;

//centroid: node where all subtrees have <= n/2 nodes
int N, s[maxN]; vector<int> adj[maxN];
//invariant: when the dfs process terminates, s[cur] = size of subtree with cur as the root
void dfs(int cur, int pre) {
    s[cur] = 1;
    for(int nxt : adj[cur]) {
        if(nxt != pre) {
            dfs(nxt, cur); s[cur] += s[nxt]; 
        }
    }
}
//returns the centroid given the current root, where the invariant of the algorithm is that the subtree
//that starts with the root's parent already contains < n/2 nodes
//check if cur is the centroid; if it isn't, find the subtree (with one of the child nodes
//as the root, we aren't going back to the previous node) with sz > n/2
int centroid(int cur, int pre) {
    for(int nxt : adj[cur]) {
        if(nxt != pre && 2*s[nxt] > N) return centroid(nxt, cur);
    }
    return cur;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 0, a, b; i < N-1; i++) {
        sc(a, b); adj[a].pb(b); adj[b].pb(a);
    }
    //find size of each subtree when 1 is the root
    dfs(1, 0);
    //recursively traverse the tree to find the centroid
    pr(centroid(1, 0), nl);
}