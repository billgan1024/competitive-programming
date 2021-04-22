#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 5e5+1;

struct node
{
    int v, d, b;
};

struct cmpd {
    bool operator()(node const& p1, node const& p2)
    {
        return p1.d > p2.d || (p1.d == p2.d && p1.b > p2.b);
    }
};

struct cmpl {
    bool operator()(node const& p1, node const& p2)
    {
        return p1.d > p2.d || (p1.d == p2.d && p1.b < p2.b);
    }
};

int n, m, q, dis[MV], d[MV], l[MV]; vector<pii> adj[MV]; priority_queue<node, vector<node>, cmpd> pd;
priority_queue<node, vector<node>, cmpl> pl;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0, x, y, z; i < m; i++)
    {
        scan(x, y, z); adj[x].pb({y, z}); adj[y].pb({x, z});
    }
    //d: minimize brightness
    //l: maximize brightness
    ms(dis, INF); ms(d, INF); dis[1] = 0; d[1] = 0; pd.push({1, 0, 0});
    while(!pd.empty())
    {
        node cur = pd.top(); pd.pop();
        if(dis[cur.v] < cur.d || (dis[cur.v] == cur.d && d[cur.v] < cur.b)) continue;
        for(pii next : adj[cur.v])
        {
            if(cur.d + 1 < dis[next.first] || (cur.d + 1 == dis[next.first] && cur.b + next.second < d[next.first]))
            {
                dis[next.first] = cur.d+1; d[next.first] = cur.b + next.second;
                pd.push({next.first, dis[next.first], d[next.first]});
            }
        }
    }
    ms(dis, INF); dis[1] = 0; l[1] = 0; pl.push({1, 0, 0});
    while(!pl.empty())
    {
        node cur = pl.top(); pl.pop();
        if(dis[cur.v] < cur.d || (dis[cur.v] == cur.d && l[cur.v] > cur.b)) continue;
        for(pii next : adj[cur.v])
        {
            if(cur.d + 1 < dis[next.first] || (cur.d + 1 == dis[next.first] && cur.b + next.second > l[next.first]))
            {
                dis[next.first] = cur.d+1; l[next.first] = cur.b + next.second;
                pl.push({next.first, dis[next.first], l[next.first]});
            }
        }
    }
    scan(q);
    for(int i = 0; i < q; i++)
    {
        int dest; string s; scan(dest, s);
        if(s == "Black") print(dis[dest], sp, d[dest], nl);
        else print(dis[dest], sp, l[dest], nl);
    }
}