#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("Ofast")
#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<ll, int> pii;
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 5e4+1;

int n, k, a[51][51], g[maxN]; ll dis[maxN]; priority_queue<pii, vector<pii>, greater<pii>> p;
set<int> b[51]; set<int, greater<int>> c[51];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //each node only has up to 50x2 outgoing edges since
    //we know that to go to another group, the optimal decision lies either in the closest cow to the left
    //or the right of the current cow
    //we can also move to the end if the cows are on the same group
    //total complexity: N + 100*NlogN (# of nodes + # of edges * complexity to access nodes from each edge)
    //use forward and reverse set to get next element strictly greater/smaller in any group
    sc(n, k); for(int i = 1; i <= n; i++) { sc(g[i]); b[g[i]].insert(i); c[g[i]].insert(i); }
    for(int i = 1; i <= k; i++) { string s; sc(s); for(int j = 1; j <= k; j++) a[i][j] = s[j-1] == '1'; }
    ms(dis, INF); dis[1] = 0; p.push({dis[1], 1});
    while(!p.empty()) {
        pii cur = p.top(); p.pop();
        if(dis[cur.second] < cur.first) continue;
        for(int i = 1; i <= k; i++) {
            if(!a[g[cur.second]][i]) continue;
            //find up to two nodes in the group which can be reached from this group
            auto it = b[i].upper_bound(cur.second);
            if(it != b[i].end()) {
                //explore right
                int nxt = *it;
                if(cur.first + abs(nxt-cur.second) < dis[nxt]) {
                    dis[nxt] = cur.first + abs(nxt-cur.second); p.push({dis[nxt], nxt});
                }
            }
            it = c[i].upper_bound(cur.second);
            if(it != c[i].end()) {
                //explore left
                int nxt = *it;
                if(cur.first + abs(nxt-cur.second) < dis[nxt]) {
                    dis[nxt] = cur.first + abs(nxt-cur.second); p.push({dis[nxt], nxt});
                }
            }
        }
    }
    pr(dis[n] > 1e18 ? -1 : dis[n], nl);
}