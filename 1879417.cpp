#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> edge;
priority_queue<edge, vector<edge>, greater<edge>> pq;
int s, n, e, ans = INT_MAX, dis[1600][3601]; vector<edge> adj[1600];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s >> n >> e;
    for(int i = 0, u, v, w, g; i < e; i++)
    {
        cin >> u >> v >> w >> g;
        adj[u].push_back(make_pair(w, make_pair(v, g))); adj[v].push_back(make_pair(w, make_pair(u, g)));
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            dis[i][j] = INT_MAX;
        }
    }
    dis[0][0] = 0; pq.push(make_pair(dis[0][0], make_pair(0, 0)));
    while(!pq.empty())
    {
        edge cur = pq.top(); pq.pop(); int w = cur.first, v = cur.second.first, g = cur.second.second;
        if(dis[v][g] < w) continue;
        for(edge neighbour : adj[v])
        {
            int nw = neighbour.first, nv = neighbour.second.first, ng = neighbour.second.second;
            if(g + nw*ng > s) continue;
            if(w + nw < dis[nv][g + nw*ng])
            {
                dis[nv][g + nw*ng] = w + nw;
                pq.push(make_pair(dis[nv][g + nw*ng], make_pair(nv, g + nw*ng)));
            }
        }
    }
    for(int i = 0; i <= s; i++) ans = min(ans, dis[n-1][i]);
    cout << (ans == INT_MAX ? -1 : ans);
}