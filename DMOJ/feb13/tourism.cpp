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

int n, k, a[maxN]; ll dp[maxN][100];
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k); for(int i = 1; i <= n; i++) sc(a[i]);
    //total # of days: ceil(n/k)
    //recursive function: f(i, rem)
    //calculates answer for the first i attractions with 'rem' available breaks to distribute
    //our answer is dp[n][n%k] since there's n%k available breaks to distribute such that we get
    //the minimum # of trips
}