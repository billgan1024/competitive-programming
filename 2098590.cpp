#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, a[3000]; ll dp[3000][3000][2];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    //dp[i][j][k] = resulting value of x-y if you only
    //consider the interval [i, j], k represents whose turn it is (0 = taro, 1 = jiro)
    for(int i = 0; i < n; i++)
    {
        scan(a[i]); dp[i][i][0] = a[i]; dp[i][i][1] = -a[i];
    }
    for(int len = 2; len <= n; len++)
    {
        for(int i = 0; i+len <= n; i++)
        {
            int j = i+len-1;
            dp[i][j][0] = max(dp[i+1][j][1] + a[i], dp[i][j-1][1] + a[j]);
            dp[i][j][1] = min(dp[i+1][j][0] - a[i], dp[i][j-1][0] - a[j]);
        }
    }
    print(dp[0][n-1][0], nl);
}