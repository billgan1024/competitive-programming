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

int n, q, dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
string s; char g[25][25]; bool vis[25][25], ans = false;
bool in(int r, int c) { return 0 <= r && r < n && 0 <= c && c < n; }
//dfs returns true if you can find the word, (r, c) = current cell, idx = index of character to search for
void dfs(int r, int c, int idx)
{
    if(idx == sz(s)) { ans = true; return; }
    vis[r][c] = true;
    for(int i = 0; i < 8; i++)
    {
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if(in(nr, nc) && !vis[nr][nc] && g[nr][nc] == s[idx]) dfs(nr, nc, idx+1);
        if(ans) return;
    }
    vis[r][c] = false;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, q);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) sc(g[i][j]);
    }
    for(int t = 0; t < q; t++)
    {
        sc(s); ans = false;
        for(int i = 0; i < n; i++)
        {
            if(ans) break;
            for(int j = 0; j < n; j++)
            {
                if(ans) break;
                if(g[i][j] == s[0]) dfs(i, j, 1);
            }
        }
        pr(ans ? "good puzzle!" : "bad puzzle!", nl);
    }
}