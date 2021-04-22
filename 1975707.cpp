#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(a) sizeof(a)/sizeof(a[0])
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, dp[101][101], ans;
int main()
{
    //dp[i][j] = max sum that goes to the jth node in the ith row (default 0)
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1, a; j <= i; j++)
        {
            scan(a); dp[i][j] = a + max(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    for(int i : dp[n]) ans = max(ans, i);
    print(ans, nl);
}