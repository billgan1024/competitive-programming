#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned int ui;
const int MV = 1e5+1;

int n, f[32], dp[MV], ans; vector<int> adj[MV];
void dfs(int cur)
{
    dp[cur] = 1;
    for(int i : adj[cur])
    {
        if(dp[i] == 0) dfs(i);
        dp[cur] = max(dp[cur], 1 + dp[i]);
    }
}
int main()
{
    //build a directed graph, if i and j are connected that means that there exists
    //a sequence starting from a[i] and ending at a[j] which is valid
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1, x; i <= n; i++)
    {
        scan(x);
        for(int j = 0; j < 32; j++)
        {
            if(x & (1 << j)) { adj[f[j]].pb(i); f[j] = i; }
        }
    }
    //dp[i]: max length path starting from a[i] to some node (counting nodes so min length is 1)
    //note that in this graph, if a < b and a and b are connected, then dp[a] > dp[b]
    //since a has a path that is at least dis(a, b) + dp[b]
    //thus we only need to update ans once we find an unvisited node since
    //the dfs will automatically update its branch
    //total time complexity: O(nlogn) (constructing the graph takes nlogn,
    //dfs takes n+m with n vertices, m <= nlogn)
    for(int i = 1; i <= n; i++)
    {
        if(dp[i] > 0) continue;
        dfs(i); ans = max(ans, dp[i]);
    }
    print(ans, nl);
}