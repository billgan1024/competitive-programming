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

int r, c, k, dp[26][26]; bool trap[26][26];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(r, c, k);
    for(int i = 0, r0, c0; i < k; i++) { scan(r0, c0); trap[r0][c0] = true; }
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(i == 1 && j == 1) dp[i][j] = 1;
            else if(!trap[i][j]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    print(dp[r][c]);
}