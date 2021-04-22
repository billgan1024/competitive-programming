#include <bits/stdc++.h>

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

typedef unsigned long long ll;
typedef pair<int, int> pii;
const int maxN = 2e4 + 1;

int n, t, s[101], u[101], dp[maxN], dp2[maxN], ans = INT_MAX;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, t);
    for(int i = 1; i <= n; i++) sc(s[i]);
    for (int i = 1; i <= n; i++) sc(u[i]);
    fill(dp + 1, dp + maxN, 1e9); fill(dp2 + 1, dp2 + maxN, 1e9); 
    for (int i = 1; i <= n; i++)
    {
        int tot = u[i]; 
        for (int cnt = 1; cnt <= tot; cnt *= 2)
        {
            int val = cnt * s[i];
            for (int j = maxN - 1; j >= val; j--) dp[j] = min(dp[j], cnt + dp[j - val]);
            tot -= cnt;
        }
        if (tot != 0)
        {
            int val = tot * s[i];
            for (int j = maxN - 1; j >= val; j--) dp[j] = min(dp[j], tot + dp[j - val]);
        }
    }
    //do unlimited on the other one
    for (int i = 1; i <= n; i++)
    {
        for (int j = s[i]; j < maxN; j++) dp2[j] = min(dp2[j], 1 + dp[j - s[i]]);
    }
    for (int i = t; i < maxN; i++)
    {
        ans = min(ans, dp[i] + dp2[i - t]);
    }
    pr(ans >= 1e9 ? -1 : ans, nl);
}