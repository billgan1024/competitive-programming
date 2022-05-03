#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define enable_flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MN = 2e5+1;

// calculate, for each node, the number of length-k paths that go through it. we have almost solved 
// this problem with centroid decomposition, except we didn't calculate enough paths for each node.
// brute force: O(n^2) with a data structure: 1 + count all paths such that the left and right endpoints are 
// in different subtrees, or one is at the root
// now observe that you can speed this up by re-using the data, since
// for two adjacent nodes i and j, given a finished computation of ans[i] which is the root, 
// observe that ans[j] can be computed like ans[i], but split it into 
// paths that start and end in j's subtree, or paths that start and 
// more formally, the intersection of valid paths for i and j is given by the paths where 
// one node is in j's subtree, and the other node has to be in another subtree (or just node i)
// and then the complement of ans[j] w.r.t. ans[i] is given by restricting the problem to j's subtree.


int N, K;
char a[200];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> K;
    for(int k = 0; k < K; k++) {
        cin >> a;
        for(int i = 0; i < strlen(a); i++) pr(a[i], nl);
    }
}