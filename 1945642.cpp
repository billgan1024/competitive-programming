#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, v, wt[2001], dp[10001], ans[100001]; vector<pii> query[2001];
int main()
{
    //complete knapsack problem, value of each coin represents the capacity as u are trying to
    //get exactly c value
    //dp[j] represents the minimum number of coins to use in the range 1...i to pay j value exactly
    //since it is a complete knapsack problem, fill array with infinity
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> v;
    for(int i = 1; i <= n; i++) cin >> wt[i];
    fill(dp+1, dp+10001, 1e5);
    for(int i = 1, c, l; i <= v; i++)
    {
        cin >> c >> l; query[l].push_back({c, i});
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = wt[i]; j <= 10000; j++)
        {
            dp[j] = min(dp[j], dp[j-wt[i]] + 1);
        }
        for(pii q : query[i])
        {
            ans[q.second] = dp[q.first] == 1e5 ? -1 : dp[q.first];
        }
    }
    for(int i = 1; i <= v; i++) cout << ans[i] << "\n";
}