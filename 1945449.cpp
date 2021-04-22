#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, num[5001], wt[5001], val[5001], truck[5001][2], cnt[5001]; ll ans = LLONG_MIN, dp[5001];
int main()
{
    //standard limited knapsack (items have counts) will not work this time (time complexity is O(n^3))
    //we use O(n^2) time complexity by using a count array
    //this time, loop from left to right, using previous subproblems within the subproblem of this row
    //truck[c][0] represents whether a truck with capacity c exists
    //truck[c][1] represents max capacity of a truck with capacity c (if it exists)
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> num[i] >> wt[i] >> val[i];
    for(int i = 1, c, f; i <= m; i++)
    {
        cin >> c >> f; if(truck[c][0] == 1) truck[c][1] = min(truck[c][1], f);
        else { truck[c][0] = 1; truck[c][1] = f; }
    }
    for(int i = 1; i <= n; i++)
    {
        //count stores # of item i used in dp[i][j]: the maximum profit from items 1...i and j capacity
        //we can loop from left to right this time, meaning that we actually use subproblems from the same row
        //this speeds up the time needed to account for the count of each item (it would be much
        //slower to loop from right to left and account for the number of item i in a conventional way)
        //then we can build on previous subproblems
        fill(cnt, cnt+5001, 0);
        for(int j = wt[i]; j <= 5000; j++)
        {
            if(dp[j-wt[i]] + val[i] > dp[j] && cnt[j-wt[i]] + 1 <= num[i])
            {
                dp[j] = dp[j-wt[i]] + val[i]; cnt[j] = cnt[j-wt[i]] + 1;
            }
        }
        for(int i = 1; i <= 5000; i++) dp[i] = max(dp[i], dp[i-1]);
    }
    for(int i = 1; i <= 5000; i++)
    {
        if(truck[i][0] == 1) ans = max(ans, dp[i] - truck[i][1]);
    }
    cout << ans;
}