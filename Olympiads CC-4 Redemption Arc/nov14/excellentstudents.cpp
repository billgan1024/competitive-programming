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
const int maxN = 5e5+1;

int n, ans, bit[maxN];
struct pt {
    int a, b, c;
} p[maxN];
bool cmp(pt x, pt y) { return x.a < y.a; }
void upd(int idx, int val) {
    for(int i = idx; i <= n; i += i&-i) bit[i] = min(bit[i], val);
}
int query(int idx) {
    int ret = INT_MAX;
    for(int i = idx; i > 0; i -= i&-i) ret = min(ret, bit[i]);
    return ret;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0); sc(n);
    //if you sort the player stats by first contest, the problem reduces to finding (for each player) whether there
	//exists a player that comes before them and has both coordinates closer to the "origin" (if we're thinking about
	//a 2d grid); assume every person's score is the 3D point (a, b, c)
	//thus, for every point, you can use a bit to query the minimum c-value for all points with lower a-value (since you're sweeping from left to right)
	//and b-value (since you're querying the prefix of the BIT from indices 1 to b); if this minimum value is < the current player's c-value, then this student isn't excellent
	//total time complexity: O(nlogn) with space complexity O(n)
	//we can use a min bit since we're only querying prefixes, and an individual array cell will always be updated to a SMALLER value (by default, assume all entries are infinity)
	ms(bit, INF);
	for(int i = 0; i < 3; i++) {
	    for(int j = 1, x; j <= n; j++) {
	        sc(x);
	        if(i == 0) p[x].a = j;
	        else if(i == 1) p[x].b = j;
	        else p[x].c = j;
	    }
	}
	sort(p+1, p+n+1, cmp);
	for(int i = 1; i <= n; i++) {
	    if(query(p[i].b) >= p[i].c) ans++;
	    upd(p[i].b, p[i].c);
	}
	pr(ans);
}