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
const int maxN = 4097;

int n, p, a[maxN], dp[2][maxN], prev[maxN];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    sc(n, p); for(int i = 1; i <= n; i++) sc(a[i]);
    //dp[i][j] = max subset sum from the elements 1...i which is congruent to j (mod p)
    //prev[i][j] =
    for(int i = 1; i < p; i++) dp[0][i] = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            dp[i%2][j] = max(dp[(i-1)%2][j], a[i] + dp[(i-1)%2][((j-a[i])%p+p)%p]);
        }
    }
    pr(dp[n%2][0], nl, 1, nl, 1);
}