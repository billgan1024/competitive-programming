#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, m, dp[1001][1001]; string a, b;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, a, b);
    for(int i = 1; i <= n; i++) dp[i][0] = ceil((double)i/3);
    for(int i = 1; i <= m; i++) dp[0][i] = ceil((double)i/3);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                for(int k = 1; k <= 3; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[max(i-k, 0)][j]);
                    dp[i][j] = min(dp[i][j], 1 + dp[i][max(j-k, 0)]);
                }
            }
        }
    }
    print(dp[n][m]);
}