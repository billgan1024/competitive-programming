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
const int MV = 1e6+1;

int n; vector<int> adj[MV]; ll k, wt, w[MV]; bool vis[MV], found; vector<int> tree;
bool check(ll i) { return k <= i && i <= 2*k; }
void dfs(int cur)
{
    if(found || vis[cur]) return;
    vis[cur] = true; tree.pb(cur); wt += w[cur];
    if(check(wt))
    {
        print(sz(tree), nl);
        for(int i : tree) print(i, sp);
        found = true; return;
    }
    for(int nxt : adj[cur]) dfs(nxt);
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k);
    for(int i = 1; i <= n; i++)
    {
        scan(w[i]); if(w[i] > 2*k) vis[i] = true;
        if(check(w[i]))
        {
            print(1, nl, i); return 0;
        }
    }
    for(int i = 0, x, y; i < n-1; i++)
    {
        scan(x, y); adj[x].pb(y); adj[y].pb(x);
    }
    for(int i = 1; i <= n; i++)
    {
        wt = 0; tree.clear(); dfs(i);
        if(found) return 0;
    }
    print(-1);
}