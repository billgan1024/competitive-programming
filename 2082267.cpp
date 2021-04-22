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

int n, l, a[2001], dp[2001][2001][2];
int d(int l, int r) { return a[r]-a[l]; }
int main()
{
    //dp[i][j][k] = min total cost if you visit cheeses i to j exclusively
    //k = 0: end position is at i, k = 1: end position is at j
    //if invalid, it is -INF
    cin.sync_with_stdio(0); cin.tie(0); scan(n, l);
    for(int i = 0; i < n; i++) scan(a[i]); a[n] = l; n++;
    sort(a, a+n); int st = lower_bound(a, a+n, l) - a;

    ms(dp, -INF);
    //pretend that there are n+1 cheeses, and that you start by eating the start cheese
    dp[st][st][0] = dp[st][st][1] = 0;
    for(int len = 2; len <= n; len++)
    {
        for(int i = 0; i+len <= n; i++)
        {
            int j = i+len-1; dp[i][j][0] = dp[i][j][1] = INT_MAX;

            //check if previous dp cells are valid (nonnegative) before comparing
            if(dp[i+1][j][1] >= 0) dp[i][j][0] = min(dp[i][j][0], dp[i+1][j][1] + d(i, j)*(n-(j-i)));
            if(dp[i+1][j][0] >= 0) dp[i][j][0] = min(dp[i][j][0], dp[i+1][j][0] + d(i, i+1)*(n-(j-i)));
            if(dp[i][j-1][1] >= 0) dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + d(j-1, j)*(n-(j-i)));
            if(dp[i][j-1][0] >= 0) dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + d(i, j)*(n-(j-i)));

            if(dp[i][j][0] == INT_MAX) dp[i][j][0] = -1;
            if(dp[i][j][1] == INT_MAX) dp[i][j][1] = -1;
        }
    }
    //check if some end bounds are invalid 
    //(i.e. start cheese is at the edge so it is impossible to end somewhere)
    if(dp[0][n-1][0] < 0) dp[0][n-1][0] = INT_MAX;
    if(dp[0][n-1][1] < 0) dp[0][n-1][1] = INT_MAX;
    print(min(dp[0][n-1][0], dp[0][n-1][1]), nl);
}