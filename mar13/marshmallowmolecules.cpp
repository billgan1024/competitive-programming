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
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;

int N, M;  
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, M);
    for(int i = 0, a, b; i <= M; i++) {
        sc(a, b); 
    }
}
/* 
naive algorithm: follow the chain of required edges so that you only select the necessary ones by resolving inconsistencies
at node 1, then node 2, and so on (i.e. you add new edges so that there are no more inconsistencies a < b < c such that a = 1,
then move on to the next highest node). This takes O(n^3) time because EVERY node can have O(n) edges due to the propagation,
thus processing the set of neighbours for a particular node takes O(n^2) time.

apparently my original plan worked lmao (simply resolve inconsistencies at each node in increasing order so that
the cascading effect created by new required edges causing new required edges is completely resolved at each node)
then the directed adjancency list already represents the plan p[i] = { set of all vertices > i that need edges to go from i
to that vertex }, and you push more things in as required.

u only need to do one more thing which is use a set<int> so that at each stage of the algorithm, you only resolve inconsistencies
of the form "(1, y) is an edge, (1, x) is an edge, but (x, y) isn't an edge, where x is the next greater element to be in the 
list of edges to be constructed, so the cascading effect will eventually resolve itself."

Finally, there is only one more optimization, because this current implementation takes up to O(n^2logn) time, since
you're still building a graph with up to O(n^2) edges, meaning that EVERY node can potentially accumulate O(n) vertices
in the set. As one particular example, consider the case 

adj[1]: {1, 2, ..., n}
adj[2]: {}
...
adj[n]: {}

You literally insert all O(n) vertices into the next node's plan (set of edges to add starting from this node),
then the next, and so on, making you use up O(n^2logn) time and O(n^2) space. to fix this, 
remember the disjoint set merge-by-depth optimization, because this optimization is analagous to it.

In particular, you can simply merge smaller sets into larger sets and use swap(adj[x], adj[y]) to swap the contents of sets
in constant time using memory addresses
then, you're basically maintaining a single set which tracks the current set of nodes to use when constructing required edges
for a particular node
then, observe that the total number of inserts is bounded by O(# of edges) = linear, 
so the entire algorithm is now O(n + mlogn) (iterating through every node, + doing up to m inserts)
as a bonus, you only do m inserts, so now the memory complexity is also linear.

wrong idea below (gets too complicated for any particular algorithm/ds):

alternatively, you can consider dp[i] = min # of edges to connect the subgraph of vertices 1 to i in the original graph
with the restrictions. Then, dp[i+1] is simply dp[i] with new edges ending at i+1 and the inconsistensies formed (a<b<c) such 
that c = i+1. However, there will be 'cascading' behaviour when it comes to the construction of new required edges,
because constructing (x, i+1) implies the requirement of all (y, i+1) such that y is a neighbour of x (we can assume x < y
to avoid overcount). Thus, if you loop from left to right, you can see that you can easily propagate new requirements
by using an array p[x] = whether or not there is a requirement to construct an edge from x to i+1. However, no algorithm
that attempts to construct the target graph will work because it will eventually have O(n^2) edges, so try simplifying
by only tracking the number of nodes/edges attached to a particular node as opposed to nodes and edges themselves.

ok but that fails because now you have no data about the actual nodes you are tracking in array values so you can't take
the intersection of things so back to the directed (a<b) adjacency list
*/