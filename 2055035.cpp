#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int dp[51][27]; string s, t = "abcdefghijklmnopqrstuvwxyz";
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(s);
    for(int i = 1; i <= sz(s); i++)
    {
        for(int j = 1; j <= sz(t); j++)
        {
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    print(26-dp[sz(s)][sz(t)], nl);
}