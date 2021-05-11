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
template<typename T, typename X, class cmp = less <T>> using ordered_set = tree <T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

//dp[n][t][f]: max value if you only consider the first n restaurants and have only t time and f capacity
//the closest 3 faces of the dp 'cube' are all zero
int m, u, r, dp[151][301][101], v[151], t[151], f[151];
int main() {
	cin.sync_with_stdio(0); cin.tie(0); sc(m, u, r);
	for(int i = 1; i <= r; i++) {
		sc(v[i], t[i], f[i]);
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= u; k++) {
				dp[i][j][k] = dp[i-1][j][k];
				if(j >= t[i] && k >= f[i] && v[i] + dp[i-1][j-t[i]][k-f[i]] > dp[i-1][j][k]) dp[i][j][k] = v[i] + dp[i-1][j-t[i]][k-f[i]];
			}
		}
	}
	pr(dp[r][m][u], nl);
}