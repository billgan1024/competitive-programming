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
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int n, m, a[22][22], lvl; bool vis[22][22]; vector<pii> path;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct block {
    int r, c, h;
    bool operator<(const block& y) const { return h > y.h; }
};
void dfs(int r, int c, int l) {
    if(a[r][c] > l) { lvl = min(lvl, a[r][c]); return; }
    if(vis[r][c]) return;
    vis[r][c] = true; path.pb({r, c});
    for(int i = 0; i < 4; i++) {
        int nr = r+dir[i][0], nc = c+dir[i][1];
        if(nr > 0 && nr <= n && nc > 0 && nc <= m) dfs(nr, nc, l);
        else lvl = -1e9;
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++) {
        sc(n, m); ms(a, 0); ms(vis, 0); int ans = 0; vector<block> v;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                sc(a[i][j]); v.pb({i, j, a[i][j]});
            }
        }
        sort(v.begin(), v.end());
        for(block b : v){
            int i = b.r, j = b.c;
            lvl = INT_MAX; path.clear(); dfs(i, j, a[i][j]);
            for(pii p : path) {
                if (lvl == -1e9) vis[p.first][p.second] = false;
                else ans += lvl - a[p.first][p.second];
            }
        }
        pr(ans, nl); flush;
    }
}