#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define sz(x) (int)x.size()
#define INF 0x3f
void sc() {}
template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {}
template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 2e5+1;

int n, w, d, p[maxN], dis[maxN]; queue<int> q; vector<int> adj[maxN];
ordered_set<pii, null_type> ds; map<int, int> id;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, w, d);
    //reverse the edges s.t. u find the shortest reverse path from the end to every other node
    for(int i = 0, a, b; i < w; i++) {
        sc(a, b); adj[b].pb(a);
    }
    ms(dis, INF);
    for(int i = 1; i <= n; i++) sc(p[i]);
    dis[n] = 0; q.push(n);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]) {
            if(dis[nxt] > dis[cur]+1) {
                dis[nxt] = dis[cur]+1; q.push(nxt);
            }
        }
    }
    //you only need to use the train once at the beginning, then leave since if you need to wait for the train
    //to come to a particular node, it's no better than just taking the train to that node
    //thus, use a pbds to find the min of (0+dis[1], 1+dis[a], 2+dis[b]+...) where
    //1, a, b, c, ... = route of the bus (allow duplicates in the set
    for(int i = 1; i <= n; i++) {
        int dist = i-1+dis[p[i]]; ds.insert({dist, ++id[dist]});
    }
    for(int i = 1, x, y; i <= d; i++) {
        sc(x, y); int dx = x-1+dis[p[x]], dy = y-1+dis[p[y]], nx = y-1+dis[p[x]], ny = x-1+dis[p[y]];
        ds.erase({dx, id[dx]--}); ds.erase({dy, id[dy]--});
        ds.insert({nx, ++id[nx]}); ds.insert({ny, ++id[ny]});
        pr(ds.begin()->first, nl);
        swap(p[x], p[y]);
    }
}