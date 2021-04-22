#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 100000;

struct edge
{
    int v, d;
};

vector<edge> adj[MM]; int endpoint, len, ans, cost[MM], previous[MM]; bool vis[MM]; vector<int> radii;

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

int travelTime(int N, int M, int L, int A[], int B[], int T[])
{
    //store forest in an adjacency list
    for(int i = 0; i < M; i++)
    {
        adj[A[i]].push_back({B[i], T[i]}); adj[B[i]].push_back({A[i], T[i]});
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
    return ans;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    return 0;
}