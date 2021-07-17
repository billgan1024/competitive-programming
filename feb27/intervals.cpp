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
const int maxN = 1<<18;

int N, M; ll s[2*maxN], d[2*maxN]; vector<pii> a[maxN];
//d[i] = pending range increment on the children of node i (if i is already a leaf node, this has no effect)
void push(int p) {
    s[2*p] += d[p]; s[2*p+1] += d[p];
    d[2*p] += d[p];  d[2*p+1] += d[p];
    d[p] = 0;
}
void upd(int l, int r, int a, int b, int p, ll v) {
    //parent nodes: [1, maxN-1], leaf nodes: [maxN, 2*maxN-1]
    if(l <= a && b <= r) { s[p] += v; d[p] += v; } 
    else if(b < l || r < a) return; 
    else {
        if(d[p] != 0) push(p); int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p, v); upd(l, r, mid+1, b, 2*p+1, v);
        s[p] = max(s[2*p], s[2*p+1]);
    }
}

ll query(int l, int r, int a, int b, int p) {
    if(l <= a && b <= r) return s[p];
    else if(b < l || r < a) return INT_MIN;
    else {
        if(d[p] != 0) push(p); int mid = (a+b)/2;
        return max(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1));
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, M);
    for(int i = 0, l, r, v; i < M; i++) {   
        sc(l, r, v); a[r].pb({l, v});
    }
    //actual dp' array indices represented by the seg tree are from 0 to N
    //dp'[i][0] = 0 at all times because that's when the entire string is 0
    for(int i = 1; i <= N; i++) {
        //query, then update all elements dp'[i][j] => dp'[i+1][j]
        ll mx = query(0, i-1, 0, maxN-1, 1); upd(i, i, 0, maxN-1, 1, mx);
        for(pii p : a[i]) upd(p.first, i, 0, maxN-1, 1, p.second);
    }
    //make the seg tree 0-indexed
    pr(query(0, N, 0, maxN-1, 1), nl);
}

/* hint: use the general DP with ds optimization for determining an optimal subset with certain constraints 
(use the LIS problem as a classic example)
basically, you use a type of divide and conquer to isolate individual ending positions which are definitely selected, then 
determine a recurrence based on that to construct an optimal sequence/subset overall, for EVERY possible ending position
in particular, look at all possible endings of the optimal subset (of 1s). it's better to think of this as a sequence.
this is equal to max(0, max(dp[i])) where dp[i] = max value of a subset with the LAST 1-bit at position i.
then dp[i] is equal to sum of overlapping intervals at i + max(0, max(dp[j] + sum of intervals at i but not at j)) where 1 <= j < i
we count all the available intervals exactly once in this recursion for every i, meaning all the intervals are accounted for in the dp.
proof: all the new intervals to consider are only the ones @ position i, since i contains the next 1-bit.
if those intervals don't touch j, then they are not used yet since there's no 0 bits in between j and i. otherwise, they are already 
used by the 1-bit @ j.
remember that this dp works because we now know of two positions in the string that are definitely 1: i and j, and 
they will eventually build out the optimal sequence (just like longest increasing subsequence)
we can do this in O(n^2) time using two line sweeps for i and j, keeping track of the sum of the active intervals @ i that don't touch j*/
/*
if you look at this, the expression for dp[i] is very complicated. it involves max(dp[j] + c[j]) where c[j] is almost an arbitrary value, preventing
the use of a max-BIT on the dp values. it's clear we can't optimize this function by simply computing it faster with a ds. so
we think about how to simplify this expression to make it easier to evalute.
find another dp transition state which can be optimized with a ds by expanding the dimensions of the dp state, then optimizing it again.
observe that dp[i] = sum of all intervals overlapping at i, then delete all intervals that touch @ i (since u just used them)
then, find max dp'[i][j] (0<=j<i), where dp'[i][j] is the max value u can achieve with a string
with the last 1-bit at j while not considering any interval that touches i.
you can thus calculate dp'[i][i] for any i since that is equal to max dp'[i][j] using a max seg tree.
Then, you can turn any row of dp'[i][j] into dp'[i+1][j] by performing a range update on that interval once you cross the right 
//endpoint. this is because for every j inside that interval, 
we know the last 1-bit is there, so the dp value
needs to get updated with the value of the interval as soon as the next row (i+1, the right line) doesn't intersect it anymore
finally, compress every row and throw the array into a max seg tree
*/