#include <bits/stdc++.h>
using namespace std;
int n, k, h[100001], dp[100001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> k;
    for(int i = 1, l; i <= n; i++) { cin >> l; h[i] = l; }
    fill(dp, dp+n+1, INT_MAX); dp[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        for(int j = max(i-k, 1); j < i; j++)
        {
            int c = dp[j] + abs(h[i]-h[j]);
            dp[i] = min(dp[i], c);
        }
    }
    cout << dp[n];
}