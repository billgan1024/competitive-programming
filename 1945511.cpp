#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, num[5001], wt[5001], val[5001], truck[5001][2]; ll ans = LLONG_MIN, dp[5001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> num[i] >> wt[i] >> val[i];
    for(int i = 1, c, f; i <= m; i++)
    {
        cin >> c >> f; if(truck[c][0] == 1) truck[c][1] = min(truck[c][1], f);
        else { truck[c][0] = 1; truck[c][1] = f; }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 5000; j >= wt[i]; j--)
        {
            for(int k = j-wt[i], cnt = 1; k >= 0; k -= wt[i], cnt++)
            {
                if(cnt > num[i]) break;
                dp[j] = max(dp[j], dp[k] + (ll)val[i]*cnt);
            }
        }
    }
    for(int i = 1; i <= 5000; i++)
    {
        if(truck[i][0] == 1) ans = max(ans, dp[i] - truck[i][1]);
    }
    cout << ans;
}