#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, w, ans, val[101], wt[101]; ll dp[2][(int)1e5+1];
int main()
{
    for(int i = 0; i < 2; i++)
    {
        fill(dp[i], dp[i]+(int)1e5+1, 1e12);
    }
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> w;
    for(int i = 1, w0, v0; i <= n; i++)
    {
        cin >> w0 >> v0; wt[i] = w0; val[i] = v0;
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= (int)1e5; j++)
        {
            if(j == 0) dp[i%2][j] = 0;
            else if(i == 0) continue;
            else
            {
                if(val[i] > j) dp[i%2][j] = dp[(i-1)%2][j];
                else dp[i%2][j] = min(dp[(i-1)%2][j], wt[i] + dp[(i-1)%2][j-val[i]]);
            }
        }
    }
    for(int i = (int)1e5; i >= 0; i--)
    {
        if(dp[n%2][i] <= w) { cout << i << "\n"; break; }
    }
    //time complexity: n*n*v, space complexity n*v
    //use dp[i][j] : min weight to get j profit from 1st i items (if you can't reach it, it is infinity)
    //now ur recurrence relation is as follows:
    //dp[i][j] = (if current item i not chosen: dp[i-1][j])
    //if currentitem i is chosen: w[i] + dp[i-1][j-val[i]]
    //pick smaller weight (to maximize value)
    //at the end, check the highest value that u can obtain with an aggregate weight no greater than w
    //that is ur max val
}