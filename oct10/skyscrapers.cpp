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
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 1e5+1;

int m, n, a, b, r[maxN], c[maxN]; ll rsum[maxN], csum[maxN], ans, ans2;
int main() {
	cin.sync_with_stdio(0); cin.tie(0); sc(n, m, a, b);
	//sort the rows/columns because for any solution without the sorted rows, we can always swap rows/columns of buildings so that
	//the rows/columns are sorted while retaining this minimum/maximum value
	for(int i = 1; i <= n; i++) sc(r[i]);
	for(int i = 1; i <= m; i++) sc(c[i]);
	sort(r+1, r+n+1); sort(c+1, c+m+1); if(r[n] != c[m]) { pr("Impossible", nl); return 0; }
	for(int i = 1; i <= n; i++) rsum[i] = rsum[i-1] + r[i];
	for(int i = 1; i <= m; i++) csum[i] = csum[i-1] + c[i];
	ans = rsum[n] + csum[m];
	int i = n, j = m;
	while(i > 0 && j > 0) {
		if(r[i] == c[j]) { ans -= r[i]; i--; j--; }
		else if(r[i] < c[j]) j--;
		else i--;
	}
	for(int i = 0; i < min(n, m); i++) {
		//note: only binary search on the desired section of the array to make sure that the out of bounds position when an element
		//is greater than the whole row/column is always one position outside of the array.
		int ridx = lower_bound(r+1, r+n-i+1, c[m-i])-r, cidx = lower_bound(c+1, c+m-i+1, r[n-i])-c;
		ans2 += rsum[ridx-1] + (n-i-ridx+1)*c[m-i];
		ans2 += csum[cidx-1] + (m-i-cidx+1)*r[n-i];
		ans2 -= min(r[n-i], c[m-i]);
	}
	pr("Minimum: ", ans*a, ", Maximum: ", ans2*b, nl);
}