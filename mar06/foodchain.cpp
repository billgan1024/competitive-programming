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
const int maxN = 5e4+1;

int N, K, ans, s[maxN], d[maxN], p[maxN], dis[maxN];
int root(int x) {
    return p[x] == x ? x : root(p[x]);
}
//calculates the cyclic shift of a node w.r.t. the root by maintaining the array dis[] which is the cyclic shift
//w.r.t. the node's parent
//|max cyclic shift value| = N so it won't overflow
int shift(int x) {
    return p[x] == x ? 0 : dis[x]+shift(p[x]);
} 
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, K); 
    for(int i = 1; i <= N; i++) { s[i] = 1; p[i] = i; }
    for(int i = 0, c, x, y; i < K; i++) {
        sc(c, x, y); c--; //0 if same species, 1 if not
        if(x > N || y > N) ans++;
        else {
            int fx = root(x), fy = root(y);
            if(fx == fy) {
                //if they are in the same component in the disjoint set, then check the cyclic shifts w.r.t. the parent
                //note that we always store cyclic shifts as any integer, so this check will make sure that we determine
                //whether a = b (mod 3) because both can be negative.
                if((shift(x) - shift(y) + c) % 3 != 0) ans++;
            } else {
                //merge two components together. normal direction: x eats y, and you're merging y's component with
                //x's component, so you're computing d(root(y), root(x))
                int dir = 1;
                if(s[fx] < s[fy]) { 
                    //merge component root(x) into root(y) and set the shift appropriately
                    p[fx] = fy; s[fy] += s[fx];
                    dis[fx] = shift(y)-shift(x)-c;
                } else {
                    //merge component root(y) into root(x)
                    p[fy] = fx; s[fx] += s[fy];
                    dis[fy] = shift(x)-shift(y)+c;
                }
            }
        }
    }
    pr(ans, nl);
}
/*you need to determine, for any pair of nodes, whether or not the current statement is true or not. observe that at any point, 
the graph of animals looks like a group of directed components showing x -> y if x eats y; in each directed component, animals are related to each other via
the relative species e.g. a node's species is always defined as the cyclic shift between it and another node. 
then observe that you can easily extend this to a disjoint set implementation because you can maintain p[i] (parent node of
every node i) and d[i] (this cyclic shift from this node's species to the parent node's species). just like a disjoint set,
you can find the parent by repeatedly finding the parent node until you get to the root, then sum up the distances to find the
cyclic shift with respect to the root. this will allow you to describe a whole directed component as simply nodes
with cyclic shifts relative to a root. Basically, if the root has species x, then any particular node in it has species
(x+dis) % 3. 

It is very important to visualize the graph of directed components AND the corresponding disjoint set graph,
which is a set of directed trees in which every node has a pointer to a parent node (i.e. the parent node has a one-sided
edge going to this node), and you interact with root nodes. Thus, you can use recursion to calculate the root of every
component with every node's relative cyclic shift with respect to the root, and you can visualize the disjoint set
as a forest of directed trees in which edges show the cyclic shift of nodes with respect to their parents. 

for two nodes in the same component, simply check whether or not they have the same cyclic shift from the root when there
is an assertion that x and y are the same species, or check whether the cyclic shifts differ by 1 in the case where x eats y.
these statements are 'redundant' in the fact that you can trim the edge (x eats y) in the original graph of directed components,
since the information can already be calculated.

otherwise, if x and y are in different directed components, you will always be able to merge them together because both components
don't have any relation to each other yet. In this case,
you merge the components by pointing the root node of the smaller component to the root node of the larger component; now you
need to find the cyclic shift between these two roots. llet d(x, y) = cyclic shift of x with respect to y.

you will see that at the point of contact where x eats y,
you can calculate the cyclic shift of root(x) with respect to root(y) to be d(y, root of y) - d(x, root of x) - 1,
or if you're merging the other way, the shift is d(x, root(x)) - d(y, root(y)) + 1 (observe that this cyclic shift of root(y)
w.r.t. root(x) is simply the previous value * -1). similar logic holds when x and y are the same species.

use merge by size to guarantee O(KlogN) time complexity 
*/