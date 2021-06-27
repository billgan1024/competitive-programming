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

int n, m, l, seg[2*maxN], lazy[2*maxN];
void updLazy(int p, int len) {
    if(lazy[p] != 0) {
        seg[p] = len-seg[p];
        if(len > 1) { lazy[2*p] ^= 1; lazy[2*p+1] ^= 1; }
        lazy[p] = 0;
    }
}
void upd(int l, int r, int a, int b, int p) {
    //build a segment tree that handles range xor updates and range sum queries 
    //seg[i] = range sum of the corresponding segment, lazy[i] = 1 if you need to xor all elements in that segment 

    //see computer contest notes for the intuition of maintaining a segment tree with lazy updates
    updLazy(p, b-a+1);
    if(a >= l && b <= r) { 
        seg[p] = b-a+1-seg[p]; 
        if(a != b) { lazy[2*p] ^= 1; lazy[2*p+1] ^= 1; }
    }
    else if(b < l || a > r) return;
    else {
        //for partial overlap, push the lazy update to the children before doing stuff
        int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p); upd(l, r, mid+1, b, 2*p+1);
        //make sure that all of the top-level up to date nodes are correct in the return step of the recursion
        seg[p] = seg[2*p]+seg[2*p+1];
    } 
}

int query(int l, int r, int a, int b, int p) {
    //for every node visited (regardless if you would recur into the node's children), make sure it's up to date
    //for processing lazy updates, it suffices to set seg[i] = len-seg[i] (simulate flipping all bits)
    updLazy(p, b-a+1); 
    //this node is now up to date
    if(a >= l && b <= r) return seg[p];
    else if(b < l || a > r) return 0;
    else {
        int mid = (a+b)/2;
        return query(l, r, a, mid, 2*p) + query(l, r, mid+1, b, 2*p+1);
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m, l);
    cout.setf(ios::unitbuf);
    for(int i = 0; i < n; i++) upd(i, i, 0, maxN-1, 1);
    while(m--) {
        int a, b; sc(a, b);
        upd(a-1, b-1, 0, maxN-1, 1);
        //binary search for the smallest index in [0, n) that has the prefix sum
        //equal to L, or return n if no such index is found
        int lo = 0, hi = n-1, ans = n;
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(query(0, mid, 0, maxN-1, 1) >= l) { ans = mid; hi = mid-1; }
            else lo = mid+1;
        }
        if(ans == n) pr("AC?", nl); else pr(ans+1, nl);
    } 
}