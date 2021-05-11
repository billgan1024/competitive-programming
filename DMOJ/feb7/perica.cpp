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
const ll mod = 1e9+7, maxN = 1e5+1;

ll n, k, a[maxN], c[maxN][50], ans;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k); for(int i = 1; i <= n; i++) sc(a[i]);
    sort(a+1, a+n+1);
    for(int i = 0; i <= n; i++) c[i][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < k; j++) c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    }
    for(int i = k; i <= n; i++) {
        //a[i] is added i-1 choose k-1 times (use precomputed coefficients)
        ans = (ans + a[i] * c[i-1][k-1]) % mod;
    }
    pr(ans, nl);
}