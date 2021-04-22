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

int n, m, t, adj[301][301], dis[301][301]; priority_queue<pii, vector<pii>, greater<pii>> pq;
int main()
{
    //dis[i][j] = min attack power needed to go from i to j
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, t);
    for(int i = 1; i <= n; i++)
    {
        fill(adj[i]+1, adj[i]+n+1, INT_MAX); fill(dis[i]+1, dis[i]+n+1, INT_MAX);
    }
    for(int i = 0, s, e, h; i < m; i++)
    {
        scan(s, e, h); adj[s][e] = min(adj[s][e], h);
    }
    for(int i = 1; i <= n; i++)
    {
        dis[i][i] = 0; pq.push({dis[i][i], i});
        while(!pq.empty())
        {
            int atk = pq.top().first, cur = pq.top().second; pq.pop();
            if(dis[i][cur] < atk) continue;
            for(int j = 1; j <= n; j++)
            {
                if(adj[cur][j] != INT_MAX)
                {
                    if(max(atk, adj[cur][j]) < dis[i][j])
                    {
                        dis[i][j] = max(atk, adj[cur][j]);
                        pq.push({dis[i][j], j});
                    }
                }
            }
        }
    }
    for(int i = 0, a, b; i < t; i++)
    {
        scan(a, b);
        if(dis[a][b] == INT_MAX) print(-1, nl);
        else print(dis[a][b], nl);
    }
}