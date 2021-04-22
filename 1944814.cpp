#include <bits/stdc++.h>
using namespace std;
int n, ans, dp[100001][3];
int main()
{
    //dp[i][j]: maximum happiness after i days and that end on action j (0 <= j <= 2) (dp[0][j] = 0)
    cin.sync_with_stdio(0); cin.tie(0); cin >> n;
    for(int i = 1, a, b, c; i <= n; i++)
    {
        cin >> a >> b >> c;
        dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);
    }
    for(int i : dp[n]) ans = max(ans, i); cout << ans;
}