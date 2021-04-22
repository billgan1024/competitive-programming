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

int w, h, n, dp[251][251], ans;
int sum(int r0, int c0, int h0, int w0)
{
    int ar = min(r0+h0-1, h), ac = min(c0+w0-1, w);
    return dp[ar][ac] - dp[ar][c0-1] - dp[r0-1][ac] + dp[r0-1][c0-1];
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(w, h, n);
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1, a; j <= w; j++)
        {
            scan(a); dp[i][j] = a + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    //if(h*w <= n) { print(dp[h][w]); return 0; }
    for(int r = 1; r <= sqrt(n); r++)
    {
        int c = n/r; //select the most amount of area possible for a given r
        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                //this accounts for rotations (improves runtime)
                ans = max(ans, sum(i, j, r, c));
                ans = max(ans, sum(i, j, c, r));
            }
        }
    }
    print(ans, nl);
}