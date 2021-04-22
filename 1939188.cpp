#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, x, q;
ll getDis(int x1, int y1, int x2, int y2)
{
    //dont use pow function
    return pow(x2-x1, 2) + pow(y2-y1, 2);
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n;
    pii pts[n+1]; bool vis[n+1]; ll dis[n+1]; fill(vis, vis+n+1, false); fill(dis, dis+n+1, 1e15);
    for(int i = 1; i <= n; i++)
    {
        cin >> pts[i].first >> pts[i].second;
    }
    cin >> x >> q; dis[x] = 0;
    for(int i = 1; i <= n; i++)
    {
        int cur = -1; ll d = 1e15;
        for(int j = 1; j <= n; j++)
        {
            if(dis[j] < d && !vis[j]) { d = dis[j]; cur = j; }
        }
        if(cur == -1) break;
        vis[cur] = true;
        for(int j = 1; j <= n; j++)
        {
            if(dis[cur] + getDis(pts[cur].first, pts[cur].second, pts[j].first, pts[j].second) < dis[j])
            {
                dis[j] = dis[cur] + getDis(pts[cur].first, pts[cur].second, pts[j].first, pts[j].second);
            }
        }
    }
    sort(dis, dis+n+1); ll h;
    for(int i = 0; i < q; i++)
    {
        cin >> h; cout << (upper_bound(dis, dis+n+1, h)-dis) << "\n";
    }
}