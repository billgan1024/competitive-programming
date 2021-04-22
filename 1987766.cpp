#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 1e6;

int m, n, grid[1001][1001]; bool vis[1001][1001]; vector<int> factors[MM+1]; queue<pii> q;
bool in(int r, int c) { return 1 <= r && r <= m && 1 <= c && c <= n; }
bool found(int r, int c) { return r == m && c == n; }
int main()
{
    for(int i = 1; i <= MM; i++)
    {
        for(int j = i; j <= MM; j += i) factors[j].push_back(i);
    }
    cin.sync_with_stdio(0); cin.tie(0); scan(m, n);
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1, a; j <= n; j++) { scan(a); grid[i][j] = a; }
    }
    vis[1][1] = true; q.push({1, 1});
    while(!q.empty())
    {
        int r = q.front().first, c = q.front().second, g = grid[r][c]; q.pop();
        for(int i : factors[g])
        {
            int nr = i, nc = g/i; if(found(nr, nc)) { print("yes"); return 0; }
            if(in(nr, nc) && !vis[nr][nc]) { vis[nr][nc] = true; q.push({nr, nc}); }

            if(found(nc, nr)) { print("yes"); return 0; }
            if(nr != nc && in(nc, nr) && !vis[nc][nr]) { vis[nc][nr] = true; q.push({nc, nr}); }
            if(nr >= nc) break;
        }
    }
    print("no");
}