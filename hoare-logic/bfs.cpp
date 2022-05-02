#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// in c++, vector<ints> are their own types (i.e. c++'s custom implementation of the sequence object, which is probably 
// just a struct with a size, capacity, and pointer to an array on heap memory) with all the vector functions
// adj: array of vector<ints>

void bfs(vector<int> adj[], int dis[], int src, int n) {
    // 0 ≤ src < n
    fill(dis, dis+n, INT_MAX);
    queue<int> q;
    dis[src] = 0; q.push(src);

    // terminology: dis[v] = array value; δ(v) = length of shortest path from src to v (infty if none, such that 
    // we compare via extended real numbers)

    // the queue contains all vertices with min len(<src, v>) = 0, and all vertices with min len(<src, v>) ≤ 0
    // have dis[v] set to δ(v)

    // let P(k) = "the queue contains all vertices with δ(v) = k, and all vertices with min δ(v) ≤ k
    // have dis[v] set to δ(v); otherwise dis[v] = ∞"
    // assume that P(k) is true for some k ≥ 0.
    // claim: after we process these vertices with δ(v) = k, P(k+1) is true.
    // proof: any vertex with δ(v) = k+1 must satisfy "∃ w s.t. (w, v) in E ∧ δ(w) = k" (just expand the shortest path)  
    // we process all neighbours of {v : δ(v) = k} which is a superset of 
    // {v : δ(v) = k+1}; we can show that 
    // each nxt must have δ(nxt) ≤ k+1 since a shortest path from src to cur and then cur to nxt has length k+1
    // and we have δ(v) = k+1 ⇔ dis[v] = ∞ 
    // thus, checking to see if dis[nxt] > dis[cur] + 1 = k+1 will find all the new vertices.
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]) {
            if(dis[nxt] > dis[cur] + 1) {
                // cur discovers next (next is enqueued)
                // goal: dis[nxt] = min len(<src, nxt>)
                // proof: we proved that ∃ <src, nxt> s.t. dis[nxt] = len(<src, nxt>)
                dis[nxt] = dis[cur] + 1; q.push(nxt);
            }
        }
    }
}

void addEdge(vector<int> adj[], int u, int v) {
    // each vector object has its own methods which are probably called by going to a particular address when that function is called.
    adj[u].push_back(v); adj[v].push_back(u);
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // can initialize vectors with brace initialization, which places them in consecutive cells in memory and assigns 
    // the variable to point to that block in memory
    vector<int> adj[4]; int dis[4];
    addEdge(adj, 1, 3);
    bfs(adj, dis, 1, 4);
    printf("%d", 1);
}