#include <bits/stdc++.h>
using namespace std;
struct edge {
    int v, d, x;
    bool operator<(const edge& e) const
    {
        return d > e.d;
    }
};
int n, m, val[101], dis[101], pickup[101], ans = INT_MAX, most = 0;
vector<edge> adj[101]; priority_queue<edge> pq;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n; fill(dis, dis+n+1, INT_MAX);
    for(int i = 1; i <= n; i++) cin >> val[i]; cin >> m;
    for(int i = 0, a, b, d; i < m; i++)
    {
        cin >> a >> b >> d; adj[a].push_back({b, d, val[b]}); adj[b].push_back({a, d, val[a]});
    }
    dis[1] = 0; pickup[1] = val[1]; pq.push({1, dis[1], pickup[1]});
    while(!pq.empty())
    {
        edge cur = pq.top(); pq.pop();
        if(dis[cur.v] < cur.d || (dis[cur.v] == cur.d && pickup[cur.v] > cur.x)) continue;
        for(edge next : adj[cur.v])
        {
            if(cur.d + next.d < dis[next.v] || (cur.d + next.d == dis[next.v] && cur.x + next.x > pickup[next.v]))
            {
                dis[next.v] = cur.d + next.d; pickup[next.v] = cur.x + next.x;
                pq.push({next.v, dis[next.v], pickup[next.v]});
            }
        }
    }
    if(dis[n] == INT_MAX) cout << "impossible";
    else cout << dis[n] << " " << pickup[n];
}