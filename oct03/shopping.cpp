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
const int maxN = 1<<18;

int n, q; ll st[maxN][18];
int log2(int x) {
	return 32 - __builtin_clz(x) - 1;
}
ll query(int a, int b) {
	int len = b-a+1, ord = log2(len);
	return min(st[a][ord], st[b-(1<<ord)+1][ord]);
}
//find the next index in [l, r] which is <= x, or returns r+1 if the range is invalid or all the elements are > x
int next(int l, int r, ll x) {
	int low = l, high = r, ans = r+1;
	while(low <= high) {
		int mid = (low+high)/2;
		if(query(l, mid) <= x) {
			ans = mid; high = mid-1;
		} else low = mid+1;
	}
	return ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0); sc(n, q);
	for(int i = 0; i < n; i++) sc(st[i][0]);
	for(int j = 1; j < 18; j++) {
		for(int i = 0; i+(1<<j)-1 < n; i++) st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	}
	//since x % m has an upper bound of n/2, the remaining money reduces extremely quickly in log(n) time assuming that x >= m (if x < m, then
	//queries can potentially take O(n) time)
	//thus, we need a data structure that allows us to query an array like this:
	//f(i, x) = first index j such that a[j] <= x, i < j <= r (basically find the first element in (i, r] <= x)
	//binary search using a sparse table since the prefix minimums are always decreasing so we can determine the first index
	//that has a prefix minimum <= x
	//total complexity: q*log^2(n) (each query consists of log(n) remainder calculations and for each one, you are binary searching for the next index)
	while(q--) {
		ll v; int l, r; sc(v, l, r); l--; r--;
		for(int i = l; i <= r; i = next(i+1, r, v)) v %= st[i][0];
		pr(v, nl);
	}
}