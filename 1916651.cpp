#include <bits/stdc++.h>
using namespace std;
int n, m, parent[100001]; string s, ans; char c, type[100001];
int parent_find(int n)
{
    if(parent[n] != n) parent[n] = parent_find(parent[n]);
	return parent[n];
}
void merge(int x, int y)
{
    int fx = parent_find(x), fy = parent_find(y);
    if(fx != fy) parent[fx] = fy;
}
bool connected(int x, int y)
{
	return parent_find(x) == parent_find(y);
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; for(int i = 1; i <= n; i++) parent[i] = i;
    cin >> s; for(int i = 0; i < s.size(); i++) type[i+1] = s[i];
    for(int i = 0, a, b; i < n-1; i++)
    {
        cin >> a >> b;
        if(type[a] == type[b]) merge(a, b);
    }
    for(int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b >> c;
        if(type[a] == c || type[b] == c || !connected(a, b)) ans += "1";
        else ans += "0";
    }
    cout << ans;
}