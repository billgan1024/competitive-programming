#include <bits/stdc++.h>
using namespace std;
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef pair<int, int> pii; int n, m, startr, startc, ans = INT_MAX, dis[1000][1000];
bool vis[1000][1000]; string s; char grid[1000][1000]; queue<pii> q;
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool in(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m);
    for(int i = 0; i < n; i++)
    {
        sc(s); for(int j = 0; j < m; j++) {
            grid[i][j] = s[j];
            if(grid[i][j] == 's') { startr = i; startc = j; }
        }
    }
    vis[startr][startc] = true; q.push({startr, startc});
    while(!q.empty())
    {
        int cr = q.front().first, cc = q.front().second; q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nr = cr+d[i][0], nc = cc+d[i][1];
            if(in(nr, nc))
            {
                if(grid[nr][nc] == 'X' || vis[nr][nc]) continue;
                else if(grid[nr][nc] == 'e') { pr(dis[cr][cc]); return 0; }
                else
                {
                    vis[nr][nc] = true; dis[nr][nc] = dis[cr][cc] + 1; q.push({nr, nc});
                }
            }
        }
    }
    pr(-1);
}