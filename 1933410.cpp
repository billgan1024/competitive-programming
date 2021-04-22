#include <bits/stdc++.h>
using namespace std;
int n, s, teacher[51][3], dp[51][1001], t[51][1001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n;
    //dp[i][j] = max value from the first i teachers (1 to i) and an overall time limit of j seconds
    //t[i][j] = minimum # of video seconds to use for the max value of dp[i][j]
    //note that if dp[i][j] (max profit) is 0, it follows that the min # of video seconds is 0 (no teachers are chosen)
    for(int i = 1; i <= n; i++)
    {
        //teacher[i][0] = initial value, teacher[i][1] = decay, teacher[i][2] = cost
        cin >> teacher[i][0] >> teacher[i][1] >> teacher[i][2];
    }
    cin >> s;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= s; j++)
        {
            dp[i][j] = dp[i-1][j]; t[i][j] = t[i-1][j];
            int k = j-teacher[i][2], cnt = 1, val = teacher[i][0];
            while(k >= 0)
            {
                if(dp[i][j] < val + dp[i-1][k]) { dp[i][j] = val + dp[i-1][k]; t[i][j] = t[i-1][k] + cnt; }
                else if(dp[i][j] == val + dp[i-1][k]) { t[i][j] = min(t[i][j], t[i-1][k] + cnt); }
                k -= teacher[i][2]; val += max(teacher[i][0] - teacher[i][1]*cnt, 0); cnt++;
            }
        }
    }
    cout << dp[n][s] << "\n" << t[n][s] << "\n";
}