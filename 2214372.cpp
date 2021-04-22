#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e5+1;

int n, m, k, adj[26][26], dis[26][26], dp[MV], c[MV][26], best[MV][26]; string s;
int main()
{
    //if dp and best are invalid the value is INF
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m, k, s); ms(dis, INF); ms(dp, INF);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++) { sc(adj[i][j]); dis[i][j] = adj[i][j]; }
    }
    for(int k = 0; k < m; k++)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    //build prefix sum array
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++) c[i][j] = c[i-1][j] + dis[s[i-1]-'a'][j];
    }

    //dp[i] = min of all best[i-k][p] + c[i][p], where p is any character
    //best[i][p] = min of all dp[j][p] - c[j][p], j is from [1, i]
    for(int i = k; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            dp[i] = min(dp[i], best[i-k][j] + c[i][j]);
        }
        for(int j = 0; j < m; j++) best[i][j] = min(best[i-1][j], dp[i] - c[i][j]);
    }
    pr(dp[n], nl);
}