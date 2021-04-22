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

int n, dp[2][5000], cur = 1, pre = 0; string s;
int main()
{
    //loop from bottom to top, so i goes from n-1 to zero while j goes from i+1 to n-1
    //the only time this can access an undefined location is when two chars are the same
    //in which case the undefined location will store a min cost of 0
    //otherwise this works because the dp cell only relies on the left and bottom cell
    cin.sync_with_stdio(0); cin.tie(0); scan(n, s);
    for(int i = n-1; i >= 0; i--)
    {
        swap(cur, pre);
        for(int j = i+1; j < n; j++)
        {
            if(s[i] == s[j]) dp[cur][j] = dp[pre][j-1];
            else dp[cur][j] = 1 + min(dp[pre][j], dp[cur][j-1]);
        }
    }
    print(dp[cur][n-1], nl);
}