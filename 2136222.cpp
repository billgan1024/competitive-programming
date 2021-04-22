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
const int mod = 1e9+7, MV = 1e5+1;

int n, m, dp[MV], c[MV], in[MV], ans; vector<int> adj[MV];
int dfs(int cur)
{
    if(!sz(adj[cur])) { c[cur] = 1; return 0; }
    if(dp[cur] >= 0) return dp[cur];
    dp[cur] = 0;
    for(int i : adj[cur])
    {
        //mod rules mean that c[i] can be modded as well, call dfs the first time to update c[i]
        dp[cur] = (dp[cur] + (dfs(i) + c[i]) % mod) % mod; c[cur] = (c[cur] + c[i]) % mod;
    }
    return dp[cur];
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0, u, v; i < m; i++)
    {
        scan(u, v); adj[u].pb(v); in[v]++;
    }
    ms(dp, -INF);
    for(int i = 1; i <= n; i++)
    {
        if(!in[i]) ans = (ans + dfs(i)) % mod;
    }
    print(ans);
}