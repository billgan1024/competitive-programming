#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    //unlimited knapsack problem
    //test all possible multiples of item i that you can take in and take the max values
    cin.sync_with_stdio(0); cin.tie(0); cin >> n;
    int val[n+1], dp[n+1]; fill(dp, dp+n+1, 0);
    for(int i = 1, v; i <= n; i++)
    {
        cin >> v; val[i] = v;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = n; j >= i; j--)
        {
            for(int k = j-i, cnt = 1; k >= 0; k -= i, cnt++)
            {
                dp[j] = max(dp[j], cnt*val[i] + dp[k]);
            }
        }
    }
    cout << dp[n];
}