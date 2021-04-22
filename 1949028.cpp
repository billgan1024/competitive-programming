#include <bits/stdc++.h>
using namespace std;
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, t, a[16], dp[16][(int)1e6+1];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, t);
    for(int i = 1; i <= n; i++) scan(a[i]);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= t; j++)
        {
            if(j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i-1][j];
                if(j >= a[i]) dp[i][j] += dp[i-1][j-a[i]];
            }
        }
    }
    print(dp[n][t]);
}