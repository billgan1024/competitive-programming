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
const int mod = 1e9+7;

ll n, c[352][352], dp[352][352], tot = 1;
ll f(int i, int rem) {
    //dp[i][rem] = # of ways we can give rem tasks to person i, ..., n such that none of them are satisfied (mod 1e9+7)
    //base case: there's no more people (either there's 1 valid way if the remainder is 0, or none if there's still some tasks)
    if(i == n+1) return rem == 0 ? 1 : 0;
    if(dp[i][rem] >= 0) return dp[i][rem];
    dp[i][rem] = 0;
    for(int j = 0; j <= rem; j++) {
        //assign j tasks to person i while not giving exactly i tasks
        if(j != i) dp[i][rem] = (dp[i][rem] + f(i+1, rem-j)*c[rem][j]) % mod;
    }
    return dp[i][rem];
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    ms(dp, -INF);
    for(int i = 0; i <= n; i++) c[i][0] = 1;
    for(int i = 1; i <= n; i++) {
        tot = (tot*n) % mod; for(int j = 1; j <= i; j++) c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    }
    pr((tot-f(1, n)+mod) % mod, nl);
}