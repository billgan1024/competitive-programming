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
const int MV = 1e5+1, mod = 1e9+7;

int n, k, a[MV], s[101][MV], dp[101][MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k);
    for(int i = 1; i <= n; i++) scan(a[i]);
    for(int i = 0; i <= n; i++) { dp[i][0] = 1; s[i][0] = 1; }
    for(int i = 1; i <= k; i++) s[0][i] = s[0][i-1];

    //dp[i][j] = sum of dp[i-1][j-a[i]] to dp[i-1][j] (use psa to calculate sums quickly)
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(j > a[i]) dp[i][j] = s[i-1][j] - s[i-1][j-a[i]-1];
            else dp[i][j] = s[i-1][j];
            if(dp[i][j] < 0) dp[i][j] += mod;
            s[i][j] = (s[i][j-1] + dp[i][j]) % mod;
        }
    }
    print(dp[n][k]);
}