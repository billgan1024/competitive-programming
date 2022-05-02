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
const int maxN = 2e5+1;

int n, d[maxN], a[maxN], bit[maxN]; ll ans; vector<int> deadlines[maxN]; set<int> s;
void upd(int idx, int val) {
	for (int i = idx; i <= n; i += i&-i) bit[i] += val;
}

int query(int idx) {
	int ret = 0;
	for(int i = idx; i > 0; i -= i&-i) ret += bit[i];
	return ret;
}
int main() {
	//since swapping two values of an array always decreases/increases the number of inversions by 1,
	//and inversions define an equivalence class relation across arrays, this means that making an array with x inversions will take at least x swaps (there is no way for u to make
	//this array with less than x swaps because if ur array has less inversions, it will definitely be different than the target array with more inversions
	//and also, an array with x inversions can always be made with x swaps from a sorted array
	// proof: from the array with x inversions,
	//u can always find a pair a[i] > a[i+1] to invert to reduce the number of inversions by 1 (PBC: if you can't find a pair while the array
	// has > 0 inversions, you would have a sorted array since a[1] < a[2] <...<a[n])
	// u can keep reducing the # of inversions to 0 <=> sorted array (then reverse the set of moves)
	//find a satisfactory array that has the least number of inversions by querying the maximum value of a set
	//(we have distinct values so it's fine)
	cin.sync_with_stdio(0); cin.tie(0); sc(n);
	for(int i = 1; i <= n; i++) { sc(d[i]); deadlines[d[i]].pb(i); }
	//insert the max value that can be inserted here
	for(int i = n; i > 0; i--) {
		for(int j : deadlines[i]) s.insert(j);
		if(s.empty()) { pr(-1); return 0; }
		a[i] = *s.rbegin(); ans += query(a[i]); upd(a[i], 1);
		s.erase(*s.rbegin());
	}
	pr(ans, nl);
}