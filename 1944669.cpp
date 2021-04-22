#include <bits/stdc++.h>
using namespace std;
int n, x, y, z, dp[100001];
int main()
{
    //dp[i] = max number of friends that can receive a piece assuming that they can split a bar with
    //exactly i value (-infinity if they can't split a bar with i value)
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> x >> y >> z; fill(dp, dp+n+1, INT_MIN); dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i-x, cnt = 1; j >= 0; j -= x, cnt++)
        {
            dp[i] = max(dp[i], dp[j] + cnt);
        }
        for(int j = i-y, cnt = 1; j >= 0; j -= y, cnt++)
        {
            dp[i] = max(dp[i], dp[j] + cnt);
        }
        for(int j = i-z, cnt = 1; j >= 0; j -= z, cnt++)
        {
            dp[i] = max(dp[i], dp[j] + cnt);
        }
    }
    cout << dp[n];
}