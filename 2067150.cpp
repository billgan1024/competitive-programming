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

int n, a[200], dp[200][201];
int main()
{
    //dp[i][j]: answer to interval [i, j] (0-indexed)
    //transition: the answer must have come via the last selection k, where k is strictly
    //between i and j
    //therefore to get the previous state, you have collected a score of dp[l][k] + dp[k][j]
    cin.sync_with_stdio(0); cin.tie(0);
    while(true)
    {
        scan(n); if(n == 0) return 0;
        for(int i = 0; i < n; i++) scan(a[i]);
        for(int i = 0; i < n; i++) { dp[i][i] = 0; dp[i][i+1] = 0; }
        for(int len = 3; len <= n; len++)
        {
            for(int i = 0; i+len <= n; i++)
            {
                int j = i+len-1; dp[i][j] = -1;
                for(int k = i+1; k < j; k++)
                    dp[i][j] = max(dp[i][j], a[i]+a[j]+a[k] + dp[i][k] + dp[k][j]);
            }
        }
        print(dp[0][n-1], nl);
    }
}