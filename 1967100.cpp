#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, k, dp[251][251], ans;
int main()
{
    //dp[i][j] represents the number of ways to split n pieces of pie to j people subject to the constraint
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(j == 1) dp[i][j] = 1;
            else if(i == 1) dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i-1][j-1]; if(i > j) { dp[i][j] += dp[i-j][j]; }
            }
        }
    }
    print(dp[n][k], nl);
}