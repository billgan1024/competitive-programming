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

string s, t, ans; int dp[3001][3001];
int main()
{
    //dp[i][j] represents the lcs of the first i characters of s and the first j characters of t (1-indexed)
    cin.sync_with_stdio(0); cin.tie(0); scan(s, t);
    for(int i = 0; i <= sz(s); i++)
    {
        for(int j = 0; j <= sz(t); j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int r = sz(s), c = sz(t);
    while(r > 0 && c > 0)
    {
        if(s[r-1] == t[c-1]) { ans = s[r-1] + ans; r--; c--; }
        else
        {
            if(dp[r-1][c] > dp[r][c-1]) r--;
            else c--;
        }
    }
    print(ans, nl);
}