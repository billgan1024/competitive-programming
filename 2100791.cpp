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

int n, a[3000]; ll dp[3000][3000];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    //dp[i][j] = resulting value of x-y if you only
    //consider the interval [i, j] (the current player is already decided by the length 
    //of the board since taro always goes first)
    for(int i = 0; i < n; i++)
    {
        scan(a[i]);
        if(n % 2 == 1) dp[i][i] = a[i];
        else dp[i][i] = -a[i];
    }
    for(int len = 2; len <= n; len++)
    {
        for(int i = 0; i+len <= n; i++)
        {
            int j = i+len-1;
            if(n % 2 == 1)
            {
                if(len % 2 == 1)
                {
                    dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
                }
                else dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j]);
            }
            else
            {
                if(len % 2 == 0)
                {
                    dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
                }
                else
                {
                    dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j]);
                }
            }
        }
    }
    print(dp[0][n-1], nl);
}