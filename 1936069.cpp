#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, dis1[1001], dis2[1001]; vector<int> adj[1001]; queue<int> q;
void bfs1(int s)
{
    dis1[s] = 0; q.push(s);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int next : adj[cur])
        {
            if(dis1[next] == INT_MAX) { dis1[next] = dis1[cur] + 1; q.push(next); }
        }
    }
}
void bfs2(int s)
{
    dis2[s] = 0; q.push(s);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int next : adj[cur])
        {
            if(dis2[next] == INT_MAX) { dis2[next] = dis2[cur] + 1; q.push(next); }
        }
    }
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> m >> a >> b;
    fill(dis1, dis1+1001, INT_MAX); fill(dis2, dis2+1001, INT_MAX);
    for(int i = 0, v1, v2; i < m; i++)
    {
        cin >> v1 >> v2; adj[v1].push_back(v2); adj[v2].push_back(v1);
    }
    bfs1(1); bfs2(a); cout << (dis1[a] != INT_MAX && dis2[b] != INT_MAX ? dis1[a] + dis2[b] : -1);
}