#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1;
int N, M;
set<int> g[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    //adj list storing (a, b) s.t. a < b in sorted order
    for (auto i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
    }

    ll ans = 0;
    for (auto i = 1; i <= N; i++) {
        ans += g[i].size();
        if ((int)g[i].size() > 1) { 
            int st = *g[i].begin();
            g[i].erase(g[i].begin());
            //swap the sets LOL (std::swap)
            //this function takes constant time (presumably since only the memory addresses were swapped
            //remember that referencing a variable x tells c++ to go to a particular memory address with the variable x
            //so swap() simply modifies memory addresses)
            //https://www.cplusplus.com/reference/set/set/swap-free/ 
            //(check complexity and iterator validity. iterators now point
            //to the other set because the memory address that they hold doesn't change.)
            if (g[i].size() > g[st].size()) swap(g[i], g[st]);
            for (auto x : g[i]) g[st].insert(x);
            g[i].clear();
        }
    }
    cout << ans << '\n';

    return 0;
}