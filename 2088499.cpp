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

int n, dp[300][300]; string s;
int main()
{
    //dp[i][j] = min # of chars to make s[i...j] a balanced bracket sequence
    //note that unlike a palindrome, brackets on the outside do not optimally use each other
    //e.g. ()(), the outside brackets do not complete each other but rather they complete the ones
    //next to them. This means that you need to check all cases of your dp transition even if
    //you can remove the outer brackets for free.
    cin.sync_with_stdio(0); cin.tie(0); scan(s); n = sz(s);
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for(int len = 2; len <= n; len++)
    {
        for(int i = 0; i+len <= n; i++)
        {
            int j = i+len-1; dp[i][j] = INT_MAX;
            if((s[i] == '[' && s[j] == ']') || (s[i] == '(' && s[j] == ')')) dp[i][j] = dp[i+1][j-1];
            for(int k = i+1; k <= j; k++) dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j]);
        }
    }
    print(dp[0][n-1]);
}