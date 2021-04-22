#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, k, notes[201], cnt[201], dp[201][20001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) scan(notes[i]); for(int i = 1; i <= n; i++) scan(cnt[i]); scan(k);
    for(int i = 0; i <= n; i++) fill(dp[i], dp[i]+20001, INT_MAX);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            if(j == 0) dp[i][j] = 0;
            else
            {
                if(i > 0) dp[i][j] = dp[i-1][j];
                for(int k = j-notes[i], n = 1; k >= 0; k -= notes[i], n++)
                {
                    if(n > cnt[i]) break;
                    if(dp[i-1][k] != INT_MAX) dp[i][j] = min(dp[i][j], n + dp[i-1][k]);
                }
            }
        }
    }
    print(dp[n][k]);
}