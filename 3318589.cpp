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
const int maxN = 2e4+1;

int n, s[maxN][2], dp[maxN][2];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    sc(n); for(int i = 1; i <= n; i++) { sc(s[i][0], s[i][1]); }
    //dp[i][j] = min length of the valid path that goes through the first i segments
    //and ends at the left or right endpoint of the ith segment
    dp[1][0] = s[1][1]-1 + s[1][1]-s[1][0]; dp[1][1] = s[1][1]-1;
    for(int i = 2; i <= n; i++)
    {
        int len = s[i][1]-s[i][0];
        int ac = dp[i-1][0] + abs(s[i][1]-s[i-1][0]) + len + 1;
        int ad = dp[i-1][0] + abs(s[i][0]-s[i-1][0]) + len + 1;
        int bc = dp[i-1][1] + abs(s[i][1]-s[i-1][1]) + len + 1;
        int bd = dp[i-1][1] + abs(s[i][0]-s[i-1][1]) + len + 1;
        dp[i][0] = min(ac, bc);
        dp[i][1] = min(ad, bd);
    }
    pr(min(dp[n][0] + n-s[n][0], dp[n][1] + n-s[n][1]));
}