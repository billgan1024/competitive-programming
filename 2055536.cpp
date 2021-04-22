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

int n, a[401]; ll s[401]; ll dp[401][401];
ll sum(int l, int r) { return s[r]-s[l-1]; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n); ms(dp, INF);
    for(int i = 1; i <= n; i++) { scan(a[i]); s[i] = s[i-1] + a[i]; dp[i][i] = 0; }
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i+len-1 <= n; i++)
        {
            int j = i+len-1;
            for(int k = i+1; k <= j; k++) dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j] + sum(i, j));
        }
    }
    print(dp[1][n]);
}