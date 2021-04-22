#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define d first
#define v second
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 1e6;

int n, m, len = INT_MAX, dis1[701], dis2[701]; bool s[701]; vector<pii> adj[701];
ll ans, ways1[701], ways2[701];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra1(int start, int dis[], ll ways[])
{
    fill(dis, dis+n+1, INT_MAX); dis[start] = 0; pq.push({dis[start], start}); ways[start] = 1;
    while(!pq.empty())
    {
        pii cur = pq.top(); pq.pop(); if(cur.d > dis[cur.v] || s[cur.v]) continue;
        for(pii next : adj[cur.v])
        {
            if(cur.d + next.d < dis[next.v])
            {
                dis[next.v] = cur.d + next.d; pq.push({dis[next.v], next.v});
                ways[next.v] = ways[cur.v];
            }
            else if(cur.d + next.d == dis[next.v])
            {
                ways[next.v] = (ways[next.v] + ways[cur.v]) % mod;
            }
        }
    }
}

void dijkstra2(int start, int dis[], ll ways[])
{
    fill(dis, dis+n+1, INT_MAX); dis[start] = 0; pq.push({dis[start], start}); ways[start] = 1;
    while(!pq.empty())
    {
        pii cur = pq.top(); pq.pop(); if(cur.d > dis[cur.v]) continue;
        for(pii next : adj[cur.v])
        {
            if(cur.d + next.d < dis[next.v])
            {
                dis[next.v] = cur.d + next.d; pq.push({dis[next.v], next.v});
                ways[next.v] = ways[cur.v];
            }
            else if(cur.d + next.d == dis[next.v])
            {
                ways[next.v] = (ways[next.v] + ways[cur.v]) % mod;
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1, d; j <= n; j++)
        {
            scan(d); if(i != j) adj[i].push_back({d, j});
        }
    }
    scan(m); for(int i = 1, s0; i <= m; i++) { scan(s0); s[s0] = true; }
    dijkstra1(1, dis1, ways1); dijkstra2(n, dis2, ways2);
    for(int i = 1; i < n; i++)
    {
        if(s[i] && dis1[i] != INT_MAX)
        {
            if(len > dis1[i] + dis2[i])
            {
                len = dis1[i] + dis2[i]; ans = (ways1[i]*ways2[i]) % mod;
            }
            else if(len == dis1[i] + dis2[i]) ans = (ans + ways1[i]*ways2[i]) % mod;
        }
    }
    print(len, sp, ans);
}