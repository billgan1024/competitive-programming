#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int t, n, idx, a[501], ans[501]; bool dp[501][5001];
int main()
{
    //dp[i][j]: whether a subset of the first i musicians can be selected to sum up to j time
    //by getting the maximum possible sum less than t, it guarantees that the remainder is minimized
    //and thus a solution will always exist for the optimal configuration
    cin.sync_with_stdio(0); cin.tie(0); scan(t, n);
    for(int i = 1; i <= n; i++) scan(a[i]);
    for(int i = 0; i <= n; i++) dp[i][0] = true;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= t; j++)
        {
            dp[i][j] = dp[i-1][j] || (j >= a[i] && dp[i-1][j-a[i]]);
        }
    }
    int i = n, j = t; ms(ans, -INF);
    while(j > 0)
    {
        if(j >= a[i] && dp[i-1][j-a[i]]) { ans[i] = j-a[i]; j -= a[i]; i--; }
        else if(dp[i-1][j]) i--;
        else j--;
    }
    for(int i = 1; i <= n; i++)
    {
        if(ans[i] < 0) { print(idx, sp); idx += a[i]; }
        else print(ans[i], sp);
    }
}