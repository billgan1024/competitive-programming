#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int MM = 100000;

struct edge
{
    int v, d;
};

vector<edge> adj[MM]; int endpoint, len, ans, cost[MM], previous[MM]; bool vis[MM]; vector<int> radii;
int N, M, L;
void dfs(int cur, int p, int dis)
{
    if(dis > len) { len = dis; endpoint = cur; } vis[cur] = true;
    for(edge e : adj[cur])
    {
        int next = e.v, weight = e.d;
        if(next != p)
        {
            cost[next] = weight; previous[next] = cur; dfs(next, cur, dis+weight);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    sc(N, M, L);
    for(int i = 0, a, b, t; i < M; i++)
    {
        sc(a, b, t);
        adj[a].pb({b, t}); adj[b].pb({a, t});
    }

    //get radius of all connected components (minimum maximum depth when the centre is the root)
    for(int i = 0; i < N; i++)
    {
        if(!vis[i])
        {
            len = -1; dfs(i, -1, 0); int p1 = endpoint;
            len = -1; dfs(p1, -1, 0); int p2 = endpoint, diameter = len, radius = len; ans = max(ans, diameter);
            int right = 0;
            for(int i = p2; i != p1; i = previous[i])
            {
                int left = diameter-right;
                radius = min(radius, max(left, right));
                right += cost[i];
            }
            radii.push_back(radius);
        }
    }
    sort(radii.begin(), radii.end()); int k = sz(radii);
    if(k >= 2) ans = max(ans, radii[k-1] + radii[k-2] + L);
    if(k >= 3) ans = max(ans, radii[k-2] + radii[k-3] + 2*L);
    pr(ans, nl);
}