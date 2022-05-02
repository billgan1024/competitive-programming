#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
const int MN = 1e6;

// path questions: for an arbitrary root, either there exists a path with minimal cost that doesn't touch 
// the root node, or a path with minimal cost that does touch the root.
// then, we can show that this path is just equal to some path from a node in a subtree to the root combined with 
// a path from a node in a strictly different subtree (where we make an edge case for the case where 
// we only take the root node). 
// how do we check all paths containing the root in O(V) time? even if we could fix the length to find 
// the minimum product of previous nodes,
// we use the centroid which will result in O(nlogn) steps in total by this recursive decomposition.
int N, s[MN], m[MN]; vector<int> adj[MN];
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 0, a, b; i < N; i++) {
        sc(a, b); adj[a].pb(b); adj[b].pb(a);
    }
    for(int i = 0; i < N; i++) sc(m[i]);
}