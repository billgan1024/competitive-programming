#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> edge;
int n, m, dis[5001], dis2[5001]; vector<edge> adj[5001];
priority_queue<edge, vector<edge>, greater<edge>> pq;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b, w; i < m; i++)
    {
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(w, b)); adj[b].push_back(make_pair(w, a));
    }
    fill(dis, dis+5001, INT_MAX); fill(dis2, dis2+5001, INT_MAX);
    dis[1] = 0; pq.push(make_pair(dis[1], 1));
    while(!pq.empty())
    {
        edge cur = pq.top(); pq.pop();
        if(dis2[cur.second] < cur.first) continue;
        for(edge neighbour : adj[cur.second])
        {
            if(cur.first + neighbour.first < dis[neighbour.second])
			{
				dis2[neighbour.second] = dis[neighbour.second];
				dis[neighbour.second] = cur.first + neighbour.first;
				pq.push(make_pair(dis[neighbour.second], neighbour.second));
			}
			else if(cur.first + neighbour.first < dis2[neighbour.second])
			{
				dis2[neighbour.second] = cur.first + neighbour.first;
				pq.push(make_pair(dis2[neighbour.second], neighbour.second));
			}
        }
    }
    cout << dis2[n] << "\n";
}