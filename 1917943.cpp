#include <bits/stdc++.h>
using namespace std;
int n, h[100001], dp[100001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n;
    for(int i = 1, x; i <= n; i++) { cin >> x; h[i] = x; }
    dp[1] = 0; dp[2] = abs(h[2]-h[1]);
    for(int i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]));
    }
    cout << dp[n];
}