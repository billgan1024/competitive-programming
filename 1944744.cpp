#include <bits/stdc++.h>
using namespace std;
int n, w, sum, dp[2][245001], a[701];
int main()
{
    //knapsack but capacity is sum/2 (floored) and profit = weight
    cin.sync_with_stdio(0); cin.tie(0); cin >> n;
    for(int i = 1; i <= n; i++) { cin >> a[i]; sum += a[i]; } int w = sum/2;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(j < a[i]) dp[i%2][j] = dp[(i-1)%2][j];
            else dp[i%2][j] = max(dp[(i-1)%2][j], a[i] + dp[(i-1)%2][j-a[i]]);
        }
    }
    cout << sum-2*dp[n%2][w];
}