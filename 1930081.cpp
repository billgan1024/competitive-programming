#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> pts, cam; int n, m, sr, sc, dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char grid[100][100]; bool vis[100][100]; int dis[100][100]; queue<pii> q;
bool in(int r, int c) { return r >= 0 && r < n && c >= 0 && c <= m; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            grid[i][j] = s[j];
            switch(grid[i][j])
            {
                case 'S': sr = i; sc = j; break;
                case 'C': cam.push_back({i, j}); break;
                case '.': pts.push_back({i, j}); break;
            }
        }
    }
    for(pii c : cam)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 1; ; j++)
            {
                int nr = c.first + j*dir[i][0], nc = c.second + j*dir[i][1];
                if(!in(nr, nc) || grid[nr][nc] == 'W') break;
                if(grid[nr][nc] == '.' || grid[nr][nc] == 'S') grid[nr][nc] = 'C';
            }
        }
    }
    if(grid[sr][sc] != 'C') { vis[sr][sc] = true; q.push({sr, sc}); }
    while(!q.empty())
    {
        int cr = q.front().first, cc = q.front().second; q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nr = cr+dir[i][0], nc  = cc+dir[i][1];
			if(nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if(grid[nr][nc] == 'W' || grid[nr][nc] == 'C') continue;
				else if(grid[nr][nc] == '.')
				{
					if(vis[nr][nc]) continue;
					vis[nr][nc] = true; dis[nr][nc] = dis[cr][cc] + 1; q.push({nr, nc});
				}
				else
				{
					bool valid = true;
					while(true)
					{
						if(nr < 0 || nr >= n || nc < 0 || nc >= m) { valid = false; break; }
						if(vis[nr][nc] || grid[nr][nc] == 'C' || grid[nr][nc] == 'W') { valid = false; break; }
						if(grid[nr][nc] == '.') break; vis[nr][nc] = true;
						switch(grid[nr][nc])
						{
							case 'U': nr--; break;
							case 'D': nr++; break;
							case 'L': nc--; break;
							case 'R': nc++; break;
						}
					}
					if(valid) { vis[nr][nc] = true; dis[nr][nc] = dis[cr][cc] + 1; q.push({nr, nc}); }
				}
			}
        }
    }
    for(pii e : pts)
    {
        cout << (vis[e.first][e.second] ? dis[e.first][e.second] : -1) << "\n";
    }
}