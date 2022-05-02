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
typedef pair<ll, int> pii;
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 1e6+2;

int n, p, bit[maxN]; ll a[maxN], ans, idx[maxN], cmp[maxN];
void upd(int idx, int val) {
	for (int i = idx; i < maxN; i += i&-i) bit[i] += val;
}
int query(int idx) {
	int ret = 0;
	for(int i = idx; i > 0; i -= i&-i) ret += bit[i];
	return ret;
}
int main() {
	//reduce the array by p so that we need to count the number of subarrays such that the sum is nonnegative
	//then construct a psa and then count the number of pairs (i, j) such that i < j, s[i] <= s[j]
	cin.sync_with_stdio(0); cin.tie(0); sc(n);
	for(int i = 1; i <= n; i++) sc(a[i]);
	sc(p);
	//for each sum, find the number of previous sums which are smaller than it
	//note: we use coordinate compression
	cmp[0] = 0;
	for(int i = 1; i <= n; i++) {
		a[i] -= p; a[i] += a[i-1]; cmp[i] = a[i];
	}
	sort(cmp, cmp+n+1);
	int cnt = 0; ll pre = LLONG_MAX;
	for(int i = 0; i <= n; i++) {
		if(cmp[i] != pre) {
			idx[cnt++] = cmp[i]; pre = cmp[i];
		}
	}
	//now for any sum a[i], u can find its converted value by binary searching for it in idx
	//map the elements 0, a[1], a[2], ..., a[n] to indices 1, 2, ... (we shift up the resulting position by 1)
	int res = lower_bound(idx, idx+cnt, 0)-idx+1; upd(res, 1);
	for(int i = 1; i <= n; i++) {
		int res = lower_bound(idx, idx+cnt, a[i])-idx+1; ans += query(res);
		upd(res, 1);
	}
	pr(ans, nl);
}