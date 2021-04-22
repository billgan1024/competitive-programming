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
const int mod = 1e5;

ll n, dp[201][201]; string s;
int check(char c, char d)
{
    if(c == '?' && d == '?') return 3;
    if(c == '[' && d == ']') return 1;
    if(c == '(' && d == ')') return 1;
    if(c == '{' && d == '}') return 1;
    if(c == '?' && (d == ']' || d == ')' || d == '}')) return 1;
    if((c == '[' || c == '(' || c == '{') && d == '?') return 1;
    return 0;
}
int main()
{
    //dp[i][j] = answer for s[i...j] (0 if impossible to form a valid bracket sequence)
    //note that this prints leading zeroes if the answer is >= 10000, otherwise
    //it leaves the number mod 10000 as is (using simple mod rules)
    cin.sync_with_stdio(0); cin.tie(0); scan(n, s);
    for(int i = 1; i <= n; i++) dp[i][i-1] = 1;
    for(int len = 2; len <= n; len += 2)
    {
        for(int i = 0; i+len <= n; i++)
        {
            int j = i+len-1;
            for(int k = i+1; k <= j; k += 2)
            {
                dp[i][j] += check(s[i], s[k]) * dp[i+1][k-1] * dp[k+1][j];
            }
            if(dp[i][j] >= mod) dp[i][j] = mod + dp[i][j] % mod;
        }
    }
    if(dp[0][n-1] < mod) print(dp[0][n-1], nl);
    else print(setfill('0'), setw(5), dp[0][n-1] % mod, nl);
}