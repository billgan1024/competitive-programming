#include <bits/stdc++.h>
using namespace std;
int n, t, wt[2001][3], val[2001][3], dp[2][10001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> wt[i][0] >> val[i][0] >> wt[i][1] >> val[i][1] >> wt[i][2] >> val[i][2];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= t; j++)
        {
            int p0 = 0, p1 = 0, p2 = 0, p3 = dp[(i-1)%2][j];
            if(wt[i][0] <= j) p0 = val[i][0] + dp[(i-1)%2][j-wt[i][0]];
            if(wt[i][1] <= j) p1 = val[i][1] + dp[(i-1)%2][j-wt[i][1]];
            if(wt[i][2] <= j) p2 = val[i][2] + dp[(i-1)%2][j-wt[i][2]];
            dp[i%2][j] = max(max(max(p2, p3), p1), p0);
        }
    }
    cout << dp[n%2][t];
}