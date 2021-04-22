#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan() {}template<class T, class...A> void scan(T& t, A&...a) { cin >> t, scan(a...); }
void print() {}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MV = 2e5 + 1;

struct edge
{
    int u, v, w;
};

bool cmp(edge x, edge y) { return x.w > y.w; }
int n, m, parent[MV], ans[MV], cnt = 1; vector<int> adj[MV]; vector<edge> edges; bool vis[MV];

int parent_find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = parent_find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y)
{
    parent[parent_find(x)] = parent_find(y);
}

bool connected(int x, int y) { return parent_find(x) == parent_find(y); }

void dfs(int cur, int pre, int val)
{
    ans[cur] = val; cnt++;
    for(int next : adj[cur])
    {
        if(next != pre) dfs(next, cur, val);
    }
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0, a, b, p; i < m; i++)
    {
        scan(a, b, p); edges.push_back({ a, b, p });
    }
    sort(edges.begin(), edges.end(), cmp); ans[1] = 0;
    for (edge e : edges)
    {
        bool u0 = connected(1, e.u), v0 = connected(1, e.v);
        if (!connected(e.u, e.v))
        {
            merge(e.u, e.v);
            if(connected(1, e.u) && !u0) { dfs(e.u, 0, e.w); }
            if(connected(1, e.v) && !v0) { dfs(e.v, 0, e.w); }
            adj[e.u].push_back(e.v); adj[e.v].push_back(e.u);
        }
        if(cnt == n) break;
    }
    for (int i = 1; i <= n; i++) print(ans[i], nl);
}