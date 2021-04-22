#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int item, weight, wt[101], val[101]; ll dp[2][100001];
int main()
{
    //dp solution: time complexity item*weight, space complexity 1
    cin.sync_with_stdio(0); cin.tie(0); cin >> item >> weight;
    for(int i = 1, w, v; i <= item; i++)
    {
        cin >> w >> v; wt[i] = w; val[i] = v;
    }
    for(int i = 0; i <= item; i++)
    {
        for(int w = 0; w <= weight; w++)
        {
            //calculate max profit from the items (1, 2, ... i) and available weight w
            //instead of dp[i][w] use dp[i%2][w] since you only need the previous row in the dp table
            if(i == 0 || w == 0) dp[i%2][w] = 0;
            else if(wt[i] > w) dp[i%2][w] = dp[(i-1)%2][w];
            else dp[i%2][w] = max(val[i] + dp[(i-1)%2][w-wt[i]], dp[(i-1)%2][w]);
        }
    }
    cout << dp[item%2][weight];
}