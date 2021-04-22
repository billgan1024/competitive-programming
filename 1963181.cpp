#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, ans, t[2501], ut[2501]; vector<int> adj[2501];
void dfs(int cur, int prev)
{
    ut[cur] = t[cur];
    for(int next : adj[cur])
    {
        if(next == prev) continue;
        dfs(next, cur);
        ut[cur] += (12-ut[next])%12; ut[cur] %= 12;
    }
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) scan(t[i]);
    for(int i = 0, a, b; i < n-1; i++)
    {
        scan(a, b); adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        fill(ut+1, ut+n+1, 0);
        dfs(i, 0); if(ut[i] == 0 || ut[i] == 1) ans++;
    }
    print(ans, nl);
}