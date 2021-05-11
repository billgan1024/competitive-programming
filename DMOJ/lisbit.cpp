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
const int maxN = 1e6+1;

int n, a[maxN], b[maxN], bit[maxN], ans;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++) { sc(a[i]); b[i] = a[i]; }
    sort(b+1, b+n+1);
    //each a[i] is assigned an identifier for coordinate compression
    //dp[i] = lis of the first i numbers ending at position i
    //c[i] = index of a[i] in b
    //dp[i] = max(dp[j], j < i && c[j] < c[i]) + 1
    for(int i = 1; i <= n; i++) {
        int res = 0, c = lower_bound(b+1, b+n+1, a[i]) - b;
        for(int j = c-1; j > 0; j -= j&-j) res = max(res, bit[j]);
        ans = max(ans, res+1);
        for(int j = c; j < maxN; j += j&-j) bit[j] = max(bit[j], res+1);
    }
    pr(ans, nl);
}