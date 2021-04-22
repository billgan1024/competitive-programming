#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
struct edge
{
    int u, v, w;
};
bool cmp(edge x, edge y) { return x.w > y.w; }

int n, m, q, p[1001], s[1001]; edge edges[5001]; vector<edge> order; vector<pii> adj[1001];

int p_find(int n)
{
    if(p[n] != n) p[n] = p_find(p[n]);
	return p[n];
}
bool merge(int x, int y)
{
    int fx = p_find(x), fy = p_find(y);
    if(fx != fy) 
    {
        if(s[fx] < s[fy]) swap(fx, fy);
        s[fx] += s[fy];
        p[fy] = fx; return true;
    }
    return false;
}

void tree()
{
    order.clear(); for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 1; i <= m; i++) order.push_back(edges[i]);
    sort(order.begin(), order.end(), cmp);
    for(int i = 1; i <= n; i++) { p[i] = i; s[i] = 1; } int cnt = n;
    for(edge e : order)
    {
        if(merge(e.u, e.v))
        {
            cnt--; adj[e.u].push_back({e.v, e.w}); adj[e.v].push_back({e.u, e.w});
        }
        if(cnt == 1) break;
    }
}

bool dfs(int cur, int prev, int f, int l)
{
    if(cur == f) return true;
    for(pii p : adj[cur])
    {
        if(p.first != prev && p.second >= l && dfs(p.first, cur, f, l)) return true;
    }
    return false;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 1, u0, v0, z0; i <= m; i++)
    {
        scan(u0, v0, z0);
        edges[i] = {u0, v0, z0};
    }
    tree(); scan(q);
    for(int i = 0, c0, m0, x0, a0, b0, w0; i < q; i++)
    {
        scan(c0);
        if(c0 == 1)
        {
            scan(m0, x0); edges[m0].w = x0;
            tree();
        }
        else
        {
            scan(a0, b0, w0);
            if(dfs(a0, 0, b0, w0)) print(1, nl);
            else print(0, nl);
        }
    }
}