#include <bits/stdc++.h>
using namespace std;
int c, m, v[1001], w[1001], dp[1001][1001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> c >> m;
    for(int i = 1, n, k; i <= c; i++)
    {
        cin >> n >> k; v[i] = n; w[i] = k;
    }
    for(int i = 0; i <= c; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(w[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(v[i] + dp[i-1][j-w[i]], dp[i-1][j]);
        }
    }
    cout << dp[c][m];
}