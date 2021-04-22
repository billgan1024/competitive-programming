#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001]; int n, m, c, h, ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> m;
    for(int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        bool carbon = false;
        if(adj[i].size() == 1) h++;
        else if(adj[i].size() == 4) { c++; carbon = true; }
        else { cout << "Impossible"; return 0; } vector<int> adjacent;
        for(int neighbour : adj[i])
        {
            if(adj[neighbour].size() == 1)
            {
                if(count(adjacent.begin(), adjacent.end(), neighbour) == 0) {
                     adjacent.push_back(neighbour);
                     if(carbon) ans += 413; 
                     else { cout << "Impossible"; return 0; }
                }
                else { cout << "Impossible"; return 0; }
            }
            else if(adj[neighbour].size() == 4)
            {
                if(count(adjacent.begin(), adjacent.end(), neighbour) == 0) {
                     adjacent.push_back(neighbour);
                     if(carbon) ans += 346;
                     else ans += 413;
                }
                else if(count(adjacent.begin(), adjacent.end(), neighbour) == 1)
                {
                    adjacent.push_back(neighbour);
                    if(carbon) ans += 269;
                    else { cout << "Impossible"; return 0; }
                }
            }
            else { cout << "Impossible"; return 0; }
        }
    }
    cout << ans/2 << "\n";
    cout << "C" << (c > 1 ? to_string(c) : "") << "H" << (h > 1 ? to_string(h) : "");
}