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
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, class cmp = less<T>> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

string a, b;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	//cout.setf(ios::unitbuf);
	sc(a, b);
	if(sz(a) == sz(b)) { pr(a == b ? "Yes" : "No"); return 0; }
	else if(sz(a) != sz(b) + 1) { pr("No"); return 0; }
	int cur = 0;

	for(int i = 1; i <= sz(b); i++) {
		if(a[i-1] != b[i-1]) {
			cur = i; break;	
		}
	}
	if(cur != 0) {
		for(int i = cur; i <= sz(b); i++) {
			if(a[i] != b[i-1]) { pr("No"); return 0; }
		}
	}
	pr("Yes");
}