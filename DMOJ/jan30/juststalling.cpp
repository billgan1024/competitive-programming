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

int n, a[20], b[20]; ll dp[1<<20];
ll f(int s) {
    if(dp[s] >= 0) return dp[s];
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        if(s & (1<<i) && a[i] <= b[popcnt(s)-1]) ret += f(s ^ (1<<i));
    }
    return dp[s] = ret;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 0; i < n; i++) sc(a[i]);
    for(int i = 0; i < n; i++) sc(b[i]);
    //dp[set] = # of ways to arrange a subset of these cows in the first (size) stalls
    //base case: dp[0] = 1 which was already set
    ms(dp, -INF); dp[0] = 1;
    pr(f((1<<n)-1), nl);
}