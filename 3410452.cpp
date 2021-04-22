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
const int maxN = 2e3+1;

struct mv {
    char c; int x;
};
int n; bool a[maxN][maxN], b[maxN]; vector<mv> ans;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++) { for(int j = 1; j <= n; j++) sc(a[i][j]); }

    bool solved = true;
    for(int i = 2; i <= n && solved; i++) {
        for(int j = 1; j <= n; j++) b[j] = a[i][j] ^ a[i-1][j];
        for(int j = 2; j <= n; j++) {
            if(b[j] != b[1]) { solved = false; break; }
        }
    }
    if(solved) {
        for(int i = 2; i <= n; i++) {
            if(a[i][1] != a[1][1]) ans.pb({'R', i});
        }
        for(int j = 1; j <= n; j++) {
            if(a[1][j]) ans.pb({'C', j});
        }
        pr(sz(ans), nl);
        for(mv m : ans) pr(m.c, sp, m.x, nl);
    } else pr(-1, nl);
}