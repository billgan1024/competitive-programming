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
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 202, maxX = 2.5e3+1;

// naive idea: read in the graph using the stack, and let dp[i][j] = max nutrients you can transport to the root
// with j boosters; note that n[parent] = min(n[child1], edge1) + min(n[child2], edge2) 
// this is too slow since you need to run O(X^2) computations for every state and there are O(NX) states

// new idea: treat edges like vertices and expand the graph into a graph with up to 201 nodes
// then do tree dp for every node (dp[i][j] = max nutrients you can transport to the root with the constraints)
// for a node that was previously an edge, dp[i][j] = max nutrients coming out of the 'root' of the tree 
// where this value for any configuration is min(nutrient of direct child, max nutrient value of edge)

string str; int node, n[maxN], edge[maxN], dp[maxN][maxX], X; vector<int> adj[maxN];

// dfs(cur, i) returns the max value you can obtain in the root node with i boosts (works for either original nodes or original edges)
// (note that it's always optimal to use all of your boosts i.e. dp[cur][j] is monotone)
// overlapping subproblems mean that the time complexity is the same as a dfs, and there are O(X) edges for O(NX) states
// if dp[cur][j] = 0 that means that the node is not visited, since the default value is always positive (= 1 or 2 depending on 
// the type of node of the root)
// max value of dp[i][j] = sum of nutrients + X
int f(int cur, int i) {
    if(sz(adj[cur]) == 0) return n[cur]+i;
    else if(dp[cur][i]) return dp[cur][i];
    else {
        if(sz(adj[cur]) == 1) {
            // //root is an edge, so simulate giving j boosts to the node below it
            // // last optimization: we can binary search for the optimal number of boosts to assign to the child
            // // since dp[nxt][j] is monotone but it's being restricted by (1+(i-j))^2
            int nxt = adj[cur][0];
            int lo = 0, hi = i, idx = 0;
            // optimal j is going to be: largest j in [0, i] such that dp[nxt][j] <= (1+i-j)^2, or that index + 1
            // if there's no such index i.e. you have no boosts, then the default is just 0 boosts to the child
            while(lo <= hi) {
                int mid = midpoint(lo, hi);
                if(f(nxt, mid) <= (1+i-mid)*(1+i-mid)) {
                    idx = mid; lo = mid+1; 
                } else hi = mid-1;
            }
            // then the value of that is going to be f(nxt, idx) or min(f(nxt, idx+1), (1+i-(idx+1))^2)
            // note: still need to take the min here, since you might not have found an index such that dp[nxt][j] <= (1+i-j)^2
            dp[cur][i] = min(f(nxt, idx), (1+i-idx)*(1+i-idx));
            if(idx < i) dp[cur][i] = max(dp[cur][i], min(f(nxt, idx+1), (1+i-(idx+1))*(1+i-(idx+1))));
            // for(int j = 0; j <= i; j++) {
            //     // assign j boosts to the edge
            //     dp[cur][i] = max(dp[cur][i], min(f(nxt, i-j), (1+j)*(1+j)));
            //     // pr(f(nxt, i-j), sp);
            // }
            // // pr(nl);
        } else {
            // the two child 'trees' (think of the original child subtrees + the edges)
            int nxt1 = adj[cur][0], nxt2 = adj[cur][1];
            for(int j = 0; j <= i; j++) {
                // assign j boosts to one group and i-j to the other
                dp[cur][i] = max(dp[cur][i], f(nxt1, j) + f(nxt2, i-j));
            }
        }
        return dp[cur][i];
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); scln(str); sc(X);
    // first read in the graph: the max # of nodes is 101 since you can prove that the # of total nodes for n leaf nodes 
    // is 2n-1
    // maintain a stack of previous nodes in the search to simulate dfs (recursion on string algorithsm is dumb)
    // this is a general idea when you're processing a recursive string
    stack<int> s;
    // invariant: each node is attached to a particular pair of parentheses; once it's over, the node has been processed.
    // entry function: attach the edge to the incoming child
    // relevant complexity: concatenating s += s' or a character is linear in the length of s'
    // stoi: linear in the number of characters
    // s[i] = 'c': constant (a string is just an array of characters)

    // proof of correctness: identify a tree by the root; then you are maintaining a stack of roots so that the next 
    // root can be attached to the previous one
    // then each expression (tl, tr) represents a node with tl, tr as the children,
    // and a value v represents a node with v as its value
    for(int i = 0; i < sz(str); i++) {
        switch(str[i]) {
            case '(':
                // expand this so that edges are also nodes
                // also only add one edge (from parent to child)
                node++; 
                if(!s.empty()) { 
                    edge[node] = true;
                    adj[s.top()].pb(node);
                    node++; adj[node-1].pb(node);
                }
                s.push(node);
            break;
            case ')': s.pop(); break;
            case ' ': break;
            default:
            // the next child node is a number, so immediately initialize the node and value
            string val = "";
            while(i < sz(str) && str[i] != ' ' && str[i] != '(' && str[i] != ')') {
                val += str[i]; i++;
            }
            node++; 
            if(!s.empty()) {
                edge[node] = true;
                adj[s.top()].pb(node); 
                node++; adj[node-1].pb(node); 
            }
            n[node] = stoi(val); i--;
            break;
        }
    }
    // for(int i = 1; i <= node; i++) {
    //     pr(i, ": ");
    //     for(int x : adj[i]) pr(x, sp);
    //     pr(nl);
    // }

    // for(int i = 1; i <= node; i++) pr(n[i], sp);
    pr(f(1, X));

}