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

int n, cnt, a[1001], dp[1001][1001][2];
int main()
{
    //dp[i][j][k] = biggest score diff (p1score - p2score)
    //if the board was a[i] to a[j] and it is player k's turn, assuming p1 plays optimally 
    //and p2 plays greedily (p1 is the only player to maximize the value of the score diff)
    //then the answer is dp[1][n][0] (0 = p1 goes first)
    cin.sync_with_stdio(0); cin.tie(0);
    while(true)
    {
        scan(n); if(n == 0) return 0; cnt++;
        for(int i = 1; i <= n; i++)
        {
            scan(a[i]); dp[i][i][0] = a[i]; dp[i][i][1] = -a[i];
        }
        for(int i = 1; i < n; i++)
        {
            dp[i][i+1][0] = max(a[i], a[i+1]) - min(a[i], a[i+1]);
            dp[i][i+1][1] = -dp[i][i+1][0];
        }
        for(int len = 3; len <= n; len++)
        {
            for(int i = 1; i+len-1 <= n; i++)
            {
                int j = i+len-1;
                dp[i][j][0] = max(a[j] + dp[i][j-1][1], a[i] + dp[i+1][j][1]);
                if(a[i] >= a[j]) dp[i][j][1] = dp[i+1][j][0] - a[i];
                else dp[i][j][1] = dp[i][j-1][0] - a[j];
            }
        }
        print("In game ", cnt, ", the greedy strategy might lose by as many as ", dp[1][n][0], " points.", nl);
    }
}