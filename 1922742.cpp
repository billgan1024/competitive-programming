#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> m;
    vector<int> cur, adj[n+1];
    for(int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int x = 0; x < round(pow(2, n)); x++)
    {
        cur.clear(); bool valid = true;
        for (int i = n-1; i >= 0; i--) {
            int k = x >> i;
            if(k & 1) cur.push_back(n-i);
        }
        for(int i = 0; i < cur.size(); i++)
        {
            if(!valid) break;
            for(int j = 0; j < cur.size(); j++)
            {
                if(find(adj[cur[i]].begin(), adj[cur[i]].end(), cur[j]) != adj[cur[i]].end())
                {
                    valid = false; break;
                }
            }
        }
        if(valid) ans++;
    }
    cout << ans;
}