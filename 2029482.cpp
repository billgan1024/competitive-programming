#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define w first
#define v second
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, t, dp[101][101]; vector<pii> skills[101];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, t);
    for(int i = 1, l; i <= n; i++)
    {
        scan(l);
        for(int j = 0, ti, xi; j < l; j++)
        {
            scan(ti, xi); skills[i].pb({ti, xi});
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= t; j++)
        {
            int st = 0, sx = 0; dp[i][j] = dp[i-1][j];
            for(pii p : skills[i])
            {
                st += p.w; sx += p.v; if(st > j) break;
                dp[i][j] = max(dp[i][j], sx + dp[i-1][j-st]);
            }
        }
    }
    print(dp[n][t]);
}