#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#pragma gcc optimize("ofast")
#define inf 0x3f
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

void sc() {} template<class t, class...a> void sc(t &t, a &...a) { cin >> t, sc(a...); }
void pr() {} template<class t, class...a> void pr(t t, a...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename t, class cmp = less<t>> using ordered_set = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename t, typename x> using hash_map = gp_hash_table<t, x>;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
}