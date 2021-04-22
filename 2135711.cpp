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
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, ans, a[1500][1500], dp[1500][1500], dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool in(int r, int c) { return r >= 0 && r < n && c >= 0 && c < n; }
int dfs(int r, int c)
{
    if(dp[r][c] >= 0) return dp[r][c];
    dp[r][c] = 0;
    for(int i = 0; i < 4; i++)
    {
        int nr = r+dir[i][0], nc = c+dir[i][1];
        if(in(nr, nc) && a[r][c] < a[nr][nc]) dp[r][c] = max(dp[r][c], 1 + dfs(nr, nc));
    }
    return dp[r][c];
}
int main()
{
    //dp also acts as a visited array lol (no cycles too so two state vis is not required)
    //each node is only updated once and called once in the loop so total time is O(N^2)
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) scan(a[i][j]);
    }
    ms(dp, -INF);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) ans = max(ans, dfs(i, j));
    }
    print(ans);
}