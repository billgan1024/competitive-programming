#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int MV = 1e3+1;

int n, t, h[MV], v[MV], dp[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, t);
    for(int i = 1; i <= n; i++) sc(v[i], h[i]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = t; j >= h[i]; j--) dp[j] = max(dp[j], v[i] + dp[j-h[i]]);
    }
    pr(dp[t], nl);
}