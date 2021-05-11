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
const int maxN = 1e3+1;

int n, a[maxN][maxN], g[maxN][maxN], ans;
void dfs(int r, int c, int sum, int s) {
    //final state: (r, c) = (n, 1) since (r, c) is the top right corner of the 2x2 square focus
    //size: the length of one side of the l-shaped figure in this run
    if(r == n && c == 1) { ans = max(ans, sum); return; }
    //g[][] stores the current state (we construct all possible final grids with dfs)
    int nr = 0, nc = 0, ns = 0;
    if(r == 1) { nr = s+1; nc = 1; ns = s+1; }
    else if(c == s) { nr = r-1; nc = c; ns = s; }
    else { nr = r; nc = c+1; ns = s; }
    //check how many cells are filled, if it's too much, this path is invalid
    int cnt = g[r][c] + g[r+1][c] + g[r][c+1] + g[r+1][c+1]; if(cnt > 2) return;
    //check where to fill the cells
    if(r == c) {
        //corner, check side
        if(cnt == 0) {
            g[r][c+1] = g[r+1][c+1] = true; dfs(nr, nc, sum + a[r][c+1] + a[r+1][c+1], ns);
            g[r][c+1] = g[r+1][c+1] = false;
        } else if(cnt == 1) {
            g[r][c+1] = true; dfs(nr, nc, sum + a[r][c+1], ns); g[r][c+1] = false;
            g[r+1][c+1] = true; dfs(nr, nc, sum + a[r+1][c+1], ns); g[r+1][c+1] = false;
        } else dfs(nr, nc, sum, ns);
    } else if(c == 1) {
        //new row, check bottom
        if(cnt == 0) {
            g[r+1][c] = g[r+1][c+1] = true; dfs(nr, nc, sum + a[r+1][c] + a[r+1][c+1], ns);
            g[r+1][c] = g[r+1][c+1] = false;
        } else if(cnt == 1) {
            g[r+1][c] = true; dfs(nr, nc, sum + a[r+1][c], ns); g[r+1][c] = false;
            g[r+1][c+1] = true; dfs(nr, nc, sum + a[r+1][c+1], ns); g[r+1][c+1] = false;
        } else dfs(nr, nc, sum, ns);
    } else {
        //there's only one available spot
        if(cnt == 0) return;
        else if(cnt == 1) {
            if(r == s) {
                //bottom, sliding right
                g[r+1][c+1] = true; dfs(nr, nc, sum + a[r+1][c+1], ns); g[r+1][c+1] = false;
            } else if(c == s) {
                //side, sliding up
                g[r][c+1] = true; dfs(nr, nc, sum + a[r][c+1], ns); g[r][c+1] = false;
            }
        }
        else dfs(nr, nc, sum, ns);
    }
}
void test(int p, int q, int r, int s) {
    g[p][q] = g[r][s] = true; dfs(2, 1, a[p][q] + a[r][s], 2); g[p][q] = g[r][s] = false;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++) { for(int j = 1; j <= n; j++) sc(a[i][j]); }
    if(n == 2) {
        vector<int> v; v.pb(a[1][1]); v.pb(a[1][2]); v.pb(a[2][1]); v.pb(a[2][2]);
        sort(v.begin(), v.end()); pr(v[3]+v[2], nl); return 0;
    }
    //test all 6 starting configurations
    test(1, 1, 1, 2);
    test(1, 1, 2, 1);
    test(1, 1, 2, 2);
    test(1, 2, 2, 1);
    test(1, 2, 2, 2);
    test(2, 1, 2, 2);
    pr(ans, nl);
}