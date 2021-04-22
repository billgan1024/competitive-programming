#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, ans, dp[2002][2002]; char grid[2002][2002];
int main()
{
    //dp[r][c] represents the total # of troyangles which are rooted at (r, c)
    //we take the minimum of the three spaces under dp[r][c] because we need all three rows to contain a certain number of troyangles rooted at each space
    //thus the # of troyangles rooted at a particular cell is the minimum # of troyangles rooted at its child cells
    cin.sync_with_stdio(0); cin.tie(0); scan(n); string s;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) scan(grid[i][j]);
    }
    for(int i = n; i > 0; i--)
    {
        for(int j = 1; j <= n; j++)
        {
            if(grid[i][j] == '#')
            {
                dp[i][j] = 1 + min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]));
                //finally, total up the troyangles rooted at any cell with a '#'
                ans += dp[i][j];
            }
        }
    }
    print(ans, nl);
}