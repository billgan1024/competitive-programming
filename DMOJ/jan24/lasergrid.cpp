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
const int maxN = 1e5;

int n, m, c, sx, sy, v[maxN], h[maxN];
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(sx, sy, n, m, c);
    for(int i = 0; i < n; i++) sc(v[i]);
    for(int i = 0; i < m; i++) sc(h[i]);
    sort(v, v+n); sort(h, h+m);
    for(int i = 0, x, y; i < c; i++) {
        sc(x, y);
        bool ix = (lower_bound(v, v+n, x)-v) != (lower_bound(v, v+n, sx)-v);
        bool iy = (lower_bound(h, h+m, y)-h) != (lower_bound(h, h+m, sy)-h);
        pr(ix || iy ? "N" : "Y", nl);
    }
}