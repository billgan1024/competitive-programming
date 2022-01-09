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

// use up-down tree dp to find the height+1 of the subtree when any node is the root
// naive: for each node, find furthest node (height of the tree)
// optimized way: root the tree arbitrarily. for each node, the answer is max(height of this subtree, max distance 
// to a node outside of this subtree) + 1
// we can find the size of each subtree in O(n) time. let the second value in the max() expression be g[x].
// it's equal to max(2+height of sibling nodes' subtrees, 1+g[parent])
// you can get all of these by tracking for each node, the first and second largest height with respect to each child subtree.
// (recall that height[x] = max(1+height[y]), and you're tracking the top two 1+height[y] (counting duplicates))

// generalizing, we can do up-down tree dp if each node's answer can be constructed using a computation on 
// certain values from a function that is determined either going down the tree (e.g. height[x] depends on height[children])
// or going up the tree (max distance to node outside the tree)
// 
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
}