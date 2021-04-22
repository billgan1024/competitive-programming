#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define d first
#define v second
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9+7;

struct edge
{
    int wt, to, id;
};

//the dijkstra-induced DAG has this very important property: all paths between two nodes that are
//connected in the DAG are absolute shortest paths in the original graph. (see doc for explanation)
//this means that to calculate the # of shortest paths that are forced through a particular edge,
//loop through all nodes. For each Dijkstra-induced DAG starting from a particular node:
//first check if the edge is in the DAG. If it isn't, continue because using this edge does not
//create any shortest paths from source to any node.
//otherwise, add this number to the shortest path total for this edge id in ans[i] for each DAG built:
//(# of shortest paths from source to e.u) * (# of shortest paths from e.v to any other node + 1)
//after doing dijkstra and accumulating the count for all edges, you have the answer for each edge
//time complexity: V dijkstras, V dfs, and V loops through E edges
//total: V(ElogV + E)
int n, m, ans[5001], dis[1501], ways[1501], from[1501], edges[5001][3]; vector<edge> adj[1501];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int dfs(int c)
{
    //base: the pre-calculated from[c] value
    if(from[c] != 0) return from[c];
    for(edge e : adj[c])
    {
        //traverse the Dijkstra-induced DAG of shortest paths and determine from[c] for this node
        //in essence, check if this edge lies on the DAG and use it only if it is on the DAG
        //the shortest paths from this node = shortest paths from its DAG neighbours + # of edges to DAG neighbours
        if(dis[c] + e.wt == dis[e.to]) from[c] = (from[c] + dfs(e.to) + 1) % mod;
    }
    return from[c];
}

void dijkstra(int st)
{
    //ways[i]: # of shortest paths from st -> i
    //from[i]: # of shortest paths from i to ANY NODE in the DAG reachable from i (use DFS dp)
    //(this is not all of the shortest paths from i)
    fill(dis, dis+n+1, INT_MAX); ms(ways); ms(from); dis[st] = 0; ways[st] = 1; pq.push({0, st});
    while(!pq.empty())
    {
        pii cur = pq.top(); pq.pop(); if(cur.d > dis[cur.v]) continue;
        for(edge e : adj[cur.v])
        {
            if(cur.d + e.wt < dis[e.to])
            {
                dis[e.to] = cur.d + e.wt; ways[e.to] = ways[cur.v]; pq.push({dis[e.to], e.to});
            }
            else if(cur.d + e.wt == dis[e.to]) ways[e.to] = (ways[e.to] + ways[cur.v]) % mod;
        }
    }

    //to calculate from[i], it is equal to # of edges starting from node i + sum of all dp[neighbour]
    dfs(st);
    for(int i = 1; i <= m; i++)
    {
        //all of these paths start from the source node to a particular node in the DAG,
        //and they are all shortest paths
        //thus we won't overcount because each iteration will have a different starting node
        //check if this edge is part of this DAG and if so, add # of paths that go through this edge
        int ui = edges[i][0], vi = edges[i][1], wi = edges[i][2];
        if(dis[ui] + wi == dis[vi])
        {
            //add one to from cuz we can stop at vi as well
            ans[i] = (ans[i] + (ll)ways[ui] * (from[vi]+1)) % mod;
        }
    }
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 1, ui, vi, wi; i <= m; i++)
    {
        scan(ui, vi, wi); adj[ui].pb({wi, vi, i});
        edges[i][0] = ui; edges[i][1] = vi; edges[i][2] = wi;
    }
    for(int i = 1; i <= n; i++) dijkstra(i);
    for(int i = 1; i <= m; i++) print(ans[i], nl);
}