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
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<ll, int> pii;
const int MV = 1e5+1;

struct node
{
    int v; ll d; int src;
};
struct cmp {
    bool operator()(node const& p1, node const& p2) {
        return p1.d > p2.d;
    }
};
int n, c, k, val[MV]; ll dis[MV]; vector<int> adj[2*MV-1];
priority_queue<node, vector<node>, cmp> q;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, c, k);
    for(int i = 1; i <= n; i++) sc(val[i]);
    for(int i = 1, cnt; i <= n; i++)
    {
        sc(cnt);
        for(int j = 0, x; j < cnt; j++)
        {
            sc(x); x += MV-1; adj[i].pb(x); adj[x].pb(i);
        }
    }
    fill(dis+1, dis+n+1, 1e18); dis[1] = 0; q.push({1, 0, -1});
    while(!q.empty())
    {
        node cur = q.top(); q.pop();
        if(cur.v >= MV)
        {
            //classroom node
            for(int nxt : adj[cur.v])
            {
                ll tmp = dis[cur.src] + abs(val[nxt]-val[cur.src]) + k;
                if(dis[nxt] > tmp)
                {
                    dis[nxt] = tmp; q.push({nxt, dis[nxt], -1});
                }
            }
        }
        else
        {
            //student node
            if(dis[cur.v] < cur.d) continue;
            for(int nxt : adj[cur.v]) q.push({nxt, cur.d, cur.v});
        }
    }
    for(int i = 1; i <= n; i++) pr(dis[i] == 1e18 ? -1 : dis[i], nl);
}