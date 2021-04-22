#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, k, mod = 998244353, freq[1001]; ll dp[1001][1001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k);
    for(int i = 0, f; i < n; i++)
    {
        scan(f); freq[f]++;
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            if(j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j-1]*freq[i] + dp[i-1][j]) % mod;
        }
    }
    print(dp[n][k], nl);
}