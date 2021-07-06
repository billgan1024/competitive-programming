#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
const int maxN = 1e5+1;
//naive algorithm: sort all n*p + m*q edges and run kruskal's algorithm for a total time/mem complexity of O(n*m) since
//the total number of edges is >= n*m-1; in fact, we can prove that the beginning graph MUST be a list of N identical
//connected graphs (representing planets), which are themselves connected by bundles of M edges i.e. p >= m-1, q >= n-1
//no greedy algorithm works and no dp approach seems promising, so we can try to exploit the fact that this graph is special 
//in the fact that there are tons of identical node and edge structures.
//our goal is to improve the efficiency of the kruskal implementation
//observe that the p + q edges actually represent entire operations in which u either merge two cities across all n planets,
//or merge all cities between two planets. 
//after sorting these different types of edges, you can start inserting each 'bundle' of edges (either intraplanetary or interplanetary)
//in order of increasing weight.
//to efficiently calculate the connected components in order to not introduce cycles to the overall graph, observe that any
//p- or q-operation can be simplified via a diagram by simply merging nodes within a planet together, or merging entire planets together.
//thus, performing the city merge operation is basically merging two connected components together, for every large circle.
//performing the planet merge operation is basically merging two planets (which are guaranteed to have the same configuration of groups of cities) together.
//instead of circles representing individual nodes, you can thus have circles represent entire 'rectangular' ranges of nodes 
//(i.e. at any stage in this modified kruskal's, a 'blob' inside a particular circle represents 
//all cities (x, y) s.t. x ∈ {subset of 1...n}, y ∈ {subset of 1...m} where the x-subset is constant in this particular large circle.
//you're basically maintaining a disjoint set of size N except each circle represents a particular connected component of
//planets with its own disjoint set of size M, representing the configuration of current groups of cities

int N, M, P, Q, p[2][maxN], s[2][maxN]; ll cnt[2], ans, tot; vector<tuple<int, int, int, int>> edges; 
int parent(int i, int x) {
    if(p[i][x] == x) return x;
    else return p[i][x] = parent(i, p[i][x]);
} 
bool merge(int i, int a, int b) {
    int fa = parent(i, a), fb = parent(i, b);
    if(fa == fb) return false;
    if(s[i][fa] < s[i][fb]) swap(fa, fb);
    p[i][fb] = fa; s[i][fa] += s[i][fb];
    return true;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, M, P, Q); 
    for(int i = 1; i < maxN; i++) { p[0][i] = p[1][i] = i; s[0][i] = s[1][i] = 1; }
    for(int i = 0, a, b, c; i < P; i++) {
        sc(a, b, c); edges.pb({c, a, b, 0}); tot += (ll)c*N;
    }
    for(int i = 0, x, y, z; i < Q; i++) {
        sc(x, y, z); edges.pb({z, x, y, 1}); tot += (ll)z*M;
    }
    sort(edges.begin(), edges.end()); 
    //cout.setf(ios::unitbuf);
    //maintain 2 disjoint sets: one for the global configuration of cities and one for the global configuration of planets
    //2 places are connected if find_they are in the same large circle i.e. they must share the same parent in the city disjoint set
    //and they must share the same parent in the planet disjoint set. 
    //time complexity is O((p+q)alpha(n))
    //to compute the number of components merged + cost incurred for every p- or q-edge, 
    //track # of planet components (large circles) and # of connected city components
    //for every operation, check whether the corresponding cities or planets are already connected
    //an identifier of 0 represents connections between cities and an identifier of 1 represents connections between planets 
    //repeat until you only have one large circle and one large blob inside it representing all cities
    cnt[0] = M; cnt[1] = N;
    for(auto op : edges) {
        if(cnt[0] == 1 && cnt[1] == 1) break;
        int c, a, b, i; tie(c, a, b, i) = op;
        if(merge(i, a, b)) {
            ans += cnt[!i]*c; cnt[i]--;
        }
    }

    pr(tot-ans);
}