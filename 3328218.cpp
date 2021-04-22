#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("Ofast")
#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int maxN = 2e5+1;

int n, t, d1[maxN], d2[maxN], far, tot; vector<pii> adj[maxN];
priority_queue<pii, vector<pii>, greater<pii>> p;
void dijkstra(int src, int dis[])
{
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    dis[src] = 0; p.push({dis[src], src});
    while(!p.empty())
    {
        pii cur = p.top(); p.pop();
        if(cur.first > dis[cur.second]) continue;
        far = cur.second;
        for(pii nxt : adj[cur.second])
        {
            if(dis[nxt.second] > cur.first + nxt.first)
            {
                dis[nxt.second] = cur.first + nxt.first;
                p.push({dis[nxt.second], nxt.second});
            }
        }
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); sc(n, t);
    for(int i = 1, a, b, c; i < n; i++)
    {
        sc(a, b, c); adj[a].pb({c, b}); adj[b].pb({c, a}); tot += 2*c;
    }
    dijkstra(1, d1); int p1 = far;
    dijkstra(p1, d1); int p2 = far;
    dijkstra(p2, d2);
    for(int i = 1; i <= n; i++)
    {
        if(sz(adj[i]) == t) pr(i, sp, tot-max(d1[i], d2[i]), nl);
    }
}