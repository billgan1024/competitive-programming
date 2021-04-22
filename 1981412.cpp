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

int n0, m0, n[1001], m[1001], dp[1001][1001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n0, m0);
    for(int i = 1; i <= n0; i++) scan(n[i]);
    for(int i = 1; i <= m0; i++) scan(m[i]);
    for(int i = 1; i <= n0; i++)
    {
        for(int j = 1; j <= m0; j++)
        {
            if(n[i] == m[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    print(dp[n0][m0], nl);
}