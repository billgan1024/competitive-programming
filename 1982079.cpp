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

int n, a[1001], b[1001], dp[1001][1001]; string s, t;
int main()
{
    //dp[i][j] represents the max val for the first i chars in s and the first j chars in t (1-indexed)
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    scan(s); for(int i = 1; i <= n; i++) scan(a[i]);
    scan(t); for(int i = 1; i <= n; i++) scan(b[i]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if((s[i-1] == 'W' && t[j-1] == 'L' && a[i] > b[j])
                || (s[i-1] == 'L' && t[j-1] == 'W' && a[i] < b[j]))
            {
                dp[i][j] = max(dp[i][j], a[i] + b[j] + dp[i-1][j-1]);
            }
        }
    }
    print(dp[n][n], nl);
}