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

int n, i, j, k, cnt[4]; double dp[301][301][301];
tuple<int, int, int> idx(int c0, int c1, int c2)
{
    return {c0, c0+c1, c0+c1+c2};
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, x; i < n; i++) { scan(x); cnt[x]++; }
    for(int c3 = 0; c3 <= n; c3++)
    {
        for(int c2 = 0; c2 <= n-c3; c2++)
        {
            for(int c1 = 0; c1 <= n-c3-c2; c1++)
            {
                int c0 = n-c3-c2-c1; tie(i, j, k) = idx(c0, c1, c2);
                if(c1 == 0 && c2 == 0 && c3 == 0) dp[i][j][k] = 0;
                else if(c1 == 0 && c2 == 1 && c3 == 0) dp[i][j][k] = 2*n;
                else if(c1 == 0 && c2 == 0 && c3 == 1) dp[i][j][k] = 3*n;
                else if(c1 > 0 && c2 == 0 && c3 == 0) dp[i][j][k] = dp[i+1][j][k] + (double)n/c1;
                else if(c1 >= 0 && c2 > 0 && c3 == 0)
                {
                    dp[i][j][k] = 1;
                    if(c1 > 0) dp[i][j][k] += ((double)c1/n)*dp[i+1][j][k];
                    if(c2 > 0) dp[i][j][k] += ((double)c2/n)*dp[i][j+1][k];
                    dp[i][j][k] /= 1.0 - (double)c0/n;
                }
                else if(c1 >= 0 && c2 >= 0 && c3 > 0)
                {
                    dp[i][j][k] = 1;
                    if(c1 > 0) dp[i][j][k] += ((double)c1/n)*dp[i+1][j][k];
                    if(c2 > 0) dp[i][j][k] += ((double)c2/n)*dp[i][j+1][k];
                    if(c3 > 0) dp[i][j][k] += ((double)c3/n)*dp[i][j][k+1];
                    dp[i][j][k] /= 1.0 - (double)c0/n;
                }
            }
        }
    }
    tie(i, j, k) = idx(0, cnt[1], cnt[2]); print(fixed, setprecision(9), dp[i][j][k]);
}