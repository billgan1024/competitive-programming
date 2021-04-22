#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll a, dp[(int)1e6+2];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n;
    //dp[i] (2-indexed): max subset sum from the first i elements
    for(int i = 2; i <= n+1; i++)
    {
        cin >> a; dp[i] = max(dp[i-2] + a, dp[i-1]);
    }
    cout << dp[n+1];
}