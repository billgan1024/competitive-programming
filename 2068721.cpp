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

int n, dp[5000][2]; string s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, s);
    //dp[i][j] = answer for the interval starting at i with length j (j % 2)
    for(int i = 0; i < n-1; i++)
    {
        dp[i][1] = 0;
        dp[i][0] = s[i] != s[i+1];
    }
    for(int len = 3; len <= n; len++)
    {
        for(int i = 0; i+len <= n; i++)
        {
            int j = i+len-1;
            if(s[i] == s[j]) dp[i][len%2] = dp[i+1][(len-2)%2];
            else dp[i][len%2] = min(dp[i+1][(len-1)%2], dp[i][(len-1)%2]) + 1;
        }
    }
    print(dp[0][n%2], nl);
}