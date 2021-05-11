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
const int maxN = 1e5+1, maxM = 5e3+1;

struct block {
    int d[3], p, id;
} a[maxN]; int n, best; ll dp[maxN], bit[maxM][maxM], ans; vector<int> blocks;
bool cmp(block x, block y) {
    return x.d[2] < y.d[2] || (x.d[2] == y.d[2] && x.d[0] < y.d[0]) || (x.d[2] == y.d[2] && x.d[0] == y.d[0] && x.d[1] < y.d[1]);
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    sc(n);
    for(int i = 1; i <= n; i++) {
        sc(a[i].d[0], a[i].d[1], a[i].d[2], a[i].p);
        //since we can rotate pieces, sort the lengths because if two blocks can be stacked
        //without sorting, it implies that they can be stacked with sorting
        if(a[i].d[0] > a[i].d[1]) swap(a[i].d[0], a[i].d[1]); a[i].id = i;
    }
    //sort the array such that any valid sequence of blocks is a subsequence of the sorted array
    sort(a+1, a+n+1, cmp);
    //find the longest sequence s.t. d[0], d[1], and d[2] are increasing
    //after you sort by d[2], the list is now ordered and now you need to select an optimal sequence
    //such that d[0] and d[1] are increasing
    //dp[i] = highest value from a sequence ending at block i
    //dp[i] = max(dp[j]: 1 <= j < i and a[j].d[0] <= a[i].d[0], a[j].d[1] <= a[i].d[1], default = 0) + a[i].p
    //s[i][j] keeps previous values of dp by having s[d[0]][d[1]] set to previous dp values
    //use a bit to answer queries and updates in log^2(maxLength) time
    for(int i = 1; i <= n; i++)
    {
        //cur = prev idx in the highest valued sequence ending at block i
        ll cnt = 0;
        for(int j = a[i].d[0]; j > 0; j -= j&-j)
        {
            for(int k = a[i].d[1]; k > 0; k -= k&-k) cnt = max(cnt, bit[j][k]);
        }
        //update s[i][j], dp[i] to be cnt+p
        dp[i] = cnt+a[i].p;
        for(int j = a[i].d[0]; j < maxM; j += j&-j) {
            for (int k = a[i].d[1]; k < maxM; k += k&-k)
                bit[j][k] = max(bit[j][k], cnt+a[i].p);
        }
        if(ans < dp[i]) { ans = dp[i]; best = i; }
    }
    pr(ans, nl);
    //this method recalls the optimal sequence without an extra BIT's worth of memory
    ll nxt = dp[best];
    for(int i = best; i > 0; i--)
    {
        if(dp[i] == nxt) { blocks.pb(a[i].id); nxt -= a[i].p; }
    }
    pr(sz(blocks), nl);
    for(int i : blocks) pr(i, sp);
}