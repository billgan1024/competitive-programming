#include <bits/stdc++.h>
using namespace std;
int dis, n;
int main()
{
    //dp[i]: min number of strokes to get here (max value if unreachable)
    //time complexity: roughly n^2, but upper bound is 5280
    cin.sync_with_stdio(0); cin.tie(0); cin >> dis >> n;
    int club[n], dp[dis+1]; fill(dp, dp+dis+1, INT_MAX); dp[0] = 0;
    for(int i = 0; i < n; i++) cin >> club[i];
    for(int i = 1; i <= dis; i++)
    {
        for(int c : club)
        {
            for(int k = i-c, cnt = 1; k >= 0; k -= c, cnt++)
            {
                if(dp[k] == INT_MAX) continue;
                else dp[i] = min(dp[i], dp[k] + cnt);
            }
        }
    }
    if(dp[dis] != INT_MAX) cout << "Roberta wins in " << dp[dis] << " strokes.";
    else cout << "Roberta acknowledges defeat.";
}