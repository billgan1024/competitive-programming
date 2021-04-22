#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, m, k, a, b, d1[100001], d2[100001], ans = INT_MAX;; vector<int> adj[100001], stores;
bool vis[100001]; queue<int> q;
void bfs(int st, int dis[])
{
    ms(vis); q.push(st);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int next : adj[cur])
        {
            if(!vis[next]) { vis[next] = true; dis[next] = dis[cur] + 1; q.push(next); }
        }
    }
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, k, a, b);
    for(int i = 0, s; i < k; i++) { scan(s); stores.pb(s); }
    for(int i = 0, u, v; i < m; i++) { scan(u, v); adj[u].pb(v); adj[v].pb(u); }
    bfs(a, d1); bfs(b, d2);
    for(int s : stores) ans = min(ans, d1[s] + d2[s]);
    print(ans);
}