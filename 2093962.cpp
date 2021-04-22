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

struct node
{
    int mr, mc, er, ec;
};

int n, rs, cs, re, ce, sr, sc, sr2, sc2, dis[16][16][16][16], ans = INT_MAX; bool vis[16][16][16][16];
queue<node> q; pii dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool in(int r, int c) { return r > 0 && r <= n && c > 0 && c <= n; }
bool adj(int r1, int c1, int r2, int c2)
{
    return (r1 == r2 && abs(c1-c2) == 1) || (c1 == c2 && abs(r1-r2) == 1);
}
int main()
{
    //bfs on a grid, there are n^2 "nodes" and n^2 edges since each node has around O(1) edges
    //this is because from a state, you can only swap the empty spot with a magnet in 4 directions
    //or swap the empty spot and the marble spot
    cin.sync_with_stdio(0); cin.tie(0);
    scan(n, rs, cs, re, ce, sr, sc, sr2, sc2);
    if(sr == rs && sc == cs) { swap(sr, sr2); swap(sc, sc2); }
    vis[rs][cs][sr][sc] = true; q.push({rs, cs, sr, sc});
    while(!q.empty())
    {
        node cur = q.front(); q.pop();
        int d = dis[cur.mr][cur.mc][cur.er][cur.ec];
        if(cur.mr == re && cur.mc == ce) ans = min(ans, d);
        for(pii p : dir)
        {
            int nr = cur.er+p.first, nc = cur.ec+p.second;
            if(in(nr, nc) && (nr != cur.mr || nc != cur.mc) && !vis[cur.mr][cur.mc][nr][nc])
            {
                vis[cur.mr][cur.mc][nr][nc] = true;
                dis[cur.mr][cur.mc][nr][nc] = d+1;
                q.push({cur.mr, cur.mc, nr, nc});
            }
        }
        if(adj(cur.mr, cur.mc, cur.er, cur.ec))
        {
            if(!vis[cur.er][cur.ec][cur.mr][cur.mc])
            {
                vis[cur.er][cur.ec][cur.mr][cur.mc] = true;
                dis[cur.er][cur.ec][cur.mr][cur.mc] = d+1;
                q.push({cur.er, cur.ec, cur.mr, cur.mc});
            }
        }
    }
    print(ans);
}