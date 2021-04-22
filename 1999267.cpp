#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(a) sizeof(a)/sizeof(a[0])
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, m, k, ans, dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; bool grid[101][101]; bool vis[101][101]; queue<pii> q;
bool in(int r, int c) { return r > 0 && r <= n && c > 0 && c <= m; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, k);
    for(int i = 0, r, c; i < k; i++)
    {
        scan(r, c); grid[r][c] = true;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(vis[i][j] || !grid[i][j]) continue;
            vis[i][j] = true; q.push({i, j}); int cnt = 0;
            while(!q.empty())
            {
                int r = q.front().first, c = q.front().second; q.pop(); cnt++;
                for(int i = 0; i < 4; i++)
                {
                    int nr = r + dir[i][0], nc = c + dir[i][1];
                    if(in(nr, nc))
                    {
                        if(vis[nr][nc] || !grid[nr][nc]) continue;
                        vis[nr][nc] = true; q.push({nr, nc});
                    }
                }
            }
            ans = max(ans, cnt);
        }
    }
    print(ans);
}