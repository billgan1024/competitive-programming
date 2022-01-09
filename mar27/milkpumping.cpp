#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
const int maxN = 1e3+1;

//finding the path with the max (min flow)/(sum of costs) is equivalent to finding the path with the min
//(sum of costs)/(min flow). Thus, if you can guarantee that the min flow is constant, then the problem reduces to dijkstra
//in which you're trying to find the least cost for a path from 1 to n
//to fix the min flow at i, 'remove' all edges with weight less than i and find min(ds[a] + df[b]) where a, b are connected
//by a pipe with flow = i. ds = min cost from node 1 to any other node; df = min cost from node n to any other node
//total time complexity: O(n^2logn) lol
//edges[i] = all edges with flow f
int N, M, ds[maxN], df[maxN]; vector<tuple<int, int, int>> adj[maxN]; vector<tuple<int, int, int>> edges[maxN]; double ans = DBL_MAX;
//priority queue allows u to retrieve the greatest element, meaning that when you're sorting elements in reverse order,
//pq.top() gives you the smallest element
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijk(int s, int d[], int f) {
    fill(d+1, d+N+1, 1e9); d[s] = 0; pq.push({d[s], s});
    while(!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        if(cur.first > d[cur.second]) continue;
        for(auto p : adj[cur.second]) {
            //only go on edges with flow >= f
            int cost, nxt, flow; tie(cost, nxt, flow) = p; 
            if(flow >= f && d[nxt] > d[cur.second] + cost) {
                d[nxt] = d[cur.second] + cost;
                pq.push({d[nxt], nxt});
            }
        }
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, M);
    for(int i = 0, a, b, c, f; i < M; i++) {
        sc(a, b, c, f); adj[a].pb({c, b, f}); adj[b].pb({c, a, f}); edges[f].pb({a, b, c});
    }
    for(int i = 1; i < maxN; i++) {
        //find min cost of a trip with min flow = i
        dijk(1, ds, i); dijk(N, df, i);
        //keep on finding the minimum (sum of costs)/(min flow)
        //max cost = 1e6
        //any value >= 1e9 effectively means the cost is infinite
        int cost = INT_MAX; 
        //find the least cost path that has flow exactly equal to i, or do nothing if there isn't one.
        for(auto p : edges[i]) {
            int a, b, c; tie(a, b, c) = p;
            cost = min(cost, c + min(ds[a] + df[b], ds[b] + df[a]));
        }
        if(cost < 1e9) ans = min(ans, (double)cost/i);
    }
    //print 1/ans * 1e6 which is going to be in the range [1, 1e9]
    pr((int)(1e6/ans), nl);
}