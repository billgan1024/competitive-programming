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
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, class cmp = less<T>> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

int v, t, r1, r2, w, var[26], term[26], dp[26][30][30]; vector<pii> adj[26]; vector<int> to[26]; string s;

int f(int i, int l, int r) {
    if(dp[i][l][r] >= 0) return dp[i][l][r];
    else if(l == r) return find(to[i].begin(), to[i].end(), s[l]-'a') != to[i].end(); 
    else {
        dp[i][l][r] = 0;
        for(pii p : adj[i]) {
            for(int j = l; j < r; j++) dp[i][l][r] |= f(p.first, l, j) & f(p.second, j+1, r);
        }
        return dp[i][l][r];
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(v, t);
    //cout.setf(ios::unitbuf);
    //observation: the optimal moveset always consists of applying v -> 2v some # of times until the sequence of variables turns into
    //one that can be converted into the terminal sequence, then using the v -> t on every variable in that sequence
    //this is because there is no benefit in applying the v -> t transformations first, since nothing can be done to a terminal
    //character after it has been created. (if there exists a solution where you create a terminal character while still using the 
    //v -> 2v operation after, you can always move that operation to the end)
    //then, realize that the whole process of forming the end sequence of variables is a binary tree where
    //each node, representing a variable, splits into two nodes (other variables) which needs to be a valid rule
    //use recursion to determine f(i, l, r) = whether or not variable i can transform into the terminal subarray [l, r]
    //f(i, l, r) is calculated as true if l == r and i can tranform directly into t[l], or check all v => 2v moves
    //and all divisions of that subarray, and tons of subproblems are re-used because the rule v -> v1v2 can be any characters
    //upper bound on operations: 26*30*30*30*30 per query
    //upper bound on memory: 26*30*30 integers
    for(int i = 0; i < v; i++) {
        char c; sc(c); var[i] = c-'A';
    }
    for(int i = 0; i < t; i++) {
        char c; sc(c); term[i] = c-'a';
    }
    //adj = stores v -> v1v2 data, to = which terminals this variable can transform to
    sc(r1); while(r1--) {
        char a, b; sc(a, b); to[a-'A'].pb(b-'a');
    }
    sc(r2); while(r2--) {
        char a, b, c; sc(a, b, c); adj[a-'A'].pb({b-'A', c-'A'});
    }
    //note: everything is 0-indexed
    sc(w); while(w--) {
        sc(s); ms(dp, -INF);
        pr(f(var[0], 0, sz(s)-1), nl);
    }
}