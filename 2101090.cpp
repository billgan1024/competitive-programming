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
const int N = 100;

int n, a[N], dp[N][N][2], ans;
int m(int i) { return (i+n)%n; }
int solve(int i) { return dp[m(i+1)][m(i-1)][1] + a[i] > 0; }
int main()
{
    //dp[l][r][k] resulting value of the score difference (ivana - p2) if
    //both players play optimally and each player can only take from the ends of the interval 
    //(deque guarantees that the moves are valid since the deque always surrounds the total interval where players picked numbers)
    //k = 0: ivana's turn, k = 1: p2's turn
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        scan(a[i]); a[i] = (a[i] % 2 == 1); dp[i][i][0] = a[i]; dp[i][i][1] = -a[i];
    }
    for(int len = 2; len <= n; len++)
    {
        for(int i = 0; i < n; i++)
        {
            int j = m(i+len-1);
            dp[i][j][0] = max(dp[m(i+1)][j][1] + a[i], dp[i][m(j-1)][1] + a[j]);
            dp[i][j][1] = min(dp[m(i+1)][j][0] - a[i], dp[i][m(j-1)][0] - a[j]);
        }
    }
    for(int i = 0; i < n; i++) ans += solve(i);
    print(ans);
}