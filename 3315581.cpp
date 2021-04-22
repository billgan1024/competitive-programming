#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
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
const int maxN = 3e3;

int n, k, a[maxN][maxN]; ll ans; vector<int> sizes;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
	sc(n, k); sizes.pb(k);
	while(sizes.back() != 1)
	{
		sizes.pb(sizes.back() == 2 ? 1 : ceil((double)sizes.back()*2/3));
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++) sc(a[i][j]);
	}
	if(sz(sizes) >= 2) {
		for (int t = sz(sizes) - 1; t > 0; t--) {
			int cur = sizes[t], nxt = sizes[t - 1], d = nxt - cur;
			for (int i = 0; i + nxt - 1 < n; i++) {
				for (int j = 0; j <= i; j++) a[i][j] = max(a[i][j], max(a[i + d][j], a[i + d][j + d]));
			}
		}
	}
	for(int i = 0; i+k-1 < n; i++)
	{
		for(int j = 0; j <= i; j++) ans += a[i][j];
	}
	pr(ans, nl);
}