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

int T, n, k, w, a[30001], s[30001], dp[501][30001];
int sum(int l, int r) { return s[r]-s[l-1]; }
int main()
{
    //dp[k][n]: answer if you only had k balls (always use all of them)
    //and can only knock over the first n pins
    cin.sync_with_stdio(0); cin.tie(0); scan(T);
    for(int t = 0; t < T; t++)
    {
        ms(dp, 0); scan(n, k, w);
        for(int i = 1; i <= n; i++) { scan(a[i]); s[i] = s[i-1] + a[i]; }
        for(int i = 1; i <= k; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i][j-1], sum(max(j-w+1, 1), j) + dp[i-1][max(j-w, 0)]);
            }
        }
        print(dp[k][n], nl);
    }
}