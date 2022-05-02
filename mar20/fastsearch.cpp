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
const int maxN = 1<<20;

int N, Q, seg[2*maxN], targetNode, threshold; bool found = false;
void upd(int p, int v) {
    seg[p] = v;
    for(int i = p/2; i > 0; i /= 2) seg[i] = min(seg[2*i], seg[2*i+1]);
}
//modify this query to find the first node in the seg tree with min < k
//use the fact that dfsing on the left side before the right side will always yield the sequence
//of segments in the range from left to right, maintain a global search that processes each segment from left to right
//to determine the node to search further
void query(int l, int r, int a, int b, int p) {
    if(found) return;
    if(a >= l && b <= r) {
        if(seg[p] < threshold) { targetNode = p; found = true; return; }
    }
    else if(b < l || a > r) return;
    else {
        int mid = (a+b)/2;
        query(l, r, a, mid, 2*p);
        query(l, r, mid+1, b, 2*p+1);
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, Q); ms(seg, INF);
    //cout.setf(ios::unitbuf);
    //use binary search on a min segment tree to find the least index in [l, r] with a[i] < k
    //segment tree stores leaves in a 1-indexed way
    for(int i = 1, x; i <= N; i++) { sc(x); upd(i+maxN-1, x); }
    int lastAns = 0;
    while(Q--) {
        int c, p, x, l, r; sc(c);
        if(c == 1) {
            sc(p, x); p ^= lastAns; x ^= lastAns; upd(p+maxN-1, x);
        } else {
            sc(l, r, threshold); l ^= lastAns; r ^= lastAns; threshold ^= lastAns;
            found = false;

            //to find the first index in [l, r] with a[i] < k, it suffices to query the min seg tree for all of
            //the segments that make up the query range
            //then, because you are now dealing with an entire segment, you can use the trick in which you find
            //the first element < k in a range corresponding to exactly one segment in log(n) time
            query(l, r, 1, maxN, 1);
            //search from the targetNode segment until you find the leaf node which is the first index with a[i] < k
            //(edge case: targetNode is already a leaf node)
            //total complexity: 2 log(n) searches per query so O(nlogn)
            while(targetNode < maxN) {
                if(seg[targetNode*2] < threshold) targetNode *= 2;
                else if(seg[targetNode*2+1] < threshold) targetNode = targetNode*2+1;
            }
            pr(targetNode-maxN+1, nl); lastAns = targetNode-maxN+1;
        }
    }
}