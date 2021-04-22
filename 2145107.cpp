#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, m, v[101], w[101], dp[55000];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 1; i <= n; i++) scan(v[i], w[i]);
    ms(dp, INF); dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = v[i]; j < 55000-1; j++) dp[j] = min(dp[j], w[i] + dp[j-v[i]]);
    }
    int ans = INT_MAX; for(int i = m; i < 55000-1; i++) ans = min(ans, dp[i]);
    print(ans);
}