#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 4e5+1;

int n, m, q; unordered_set<int> adj[MV]; bool s[MV];
void dfs(int v)
{
    for(int i : adj[v])
    {
        if(!s[i]) { s[i] = true; dfs(i); }
    }
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m, q); s[1] = true;
    for(int i = 0, a, b; i < m; i++)
    {
        sc(a, b);
        if(adj[a].find(b) == adj[a].end())
        {
            adj[a].insert(b);
            if(s[a] && !s[b]) { s[b] = true; dfs(b); }
        }
    }
    for(int i = 0, x, y; i < q; i++)
    {
        char cmd; sc(cmd);
        if(cmd == '+')
        {
            sc(x, y);
            if(adj[x].find(y) == adj[x].end())
            {
                adj[x].insert(y);
                if(s[x] && !s[y]) { s[y] = true; dfs(y); }
            }
        }
        else
        {
            sc(x); pr(s[x] ? "YES" : "NO", nl);
        }
    }
}