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
void upd(int l, int r, int a, int b, int p) {
    //key idea about range updates: repeated range updates to an entire segment should stack
    //and updates to partial segments need to push the current lazy update to the children
    //before executing
    //lazy[i] represents the value u need to xor the current segment by (0 = do nothing, 1 = xor the segment by 1)
    if(a >= l && r <= b) {
        if(a == b) seg[p] ^= 1;
        else  
    } 
    else if(b < l || a > r) return;
    else {
        //for partial overlap, push the lazy update to the children before doing stuff
        lazy[2*p] ^= lazy[p]; lazy[2*p+1] ^= lazy[p]; lazy[p] = 0;
        int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p); upd(l, r, mid+1, b, 2*p+1);
    } 
}

int query(int l, int r, int a, int b, int p) {
     
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m, l);
    //cout.setf(ios::unitbuf);
    //maintain a segment tree tracking the number of 1s in each segment as well as range xor 1 updates
    while(m--) {
        int a, b; sc(a, b);
        upd(a-1, b-1, 0, maxN-1, 1);
        //binary search for the smallest index in [0, n) that has the prefix sum
        //equal to L, or return n if no such index is found
        int lo = 0, hi = n-1, ans = n;
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(query(0, mid, 0, maxN-1, 1) <= l) { ans = mid; lo = mid+1; }
            else hi = mid-1;
        }
        if(ans == n) pr("AC?", nl); else pr(ans-1, nl);
    } 
}