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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int maxN = 3e3+3;

int n, m, a[maxN], b[101], dp[maxN][2][103][103];
int f(int i, bool c, int l, int r) {
    if(dp[i][c][l][r]) return dp[i][c][l][r];
    int best = 0;
    //the max index = n+1
    //you always put pies to the left of the current index, in between pie i and i-1
    if(i <= n) {
        best = max(best, f(i+1, true, l, r));
        if(c) best = max(best, a[i] + f(i+1, false, l, r));
    }
    if(l <= r) {
        best = max(best, f(i, true, l+1, r));
        if(c) best = max(best, b[r] + f(i, false, l, r-1));
    }
    return dp[i][c][l][r] = best;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++) sc(a[i]);
    sc(m); for(int i = 1; i <= m; i++) sc(b[i]);
    sort(b+1, b+m+1);
    pr(f(1, true, 1, m), nl);
}