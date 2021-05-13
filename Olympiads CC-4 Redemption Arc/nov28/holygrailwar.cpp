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
const int maxN = 1<<17;
ll n, seg[2*maxN], s[2*maxN], pre[2*maxN], suf[2*maxN];
void upd(int idx, int val) {
    //adjust the index, then update all segment trees
    int p = idx+maxN; seg[p] += val; s[p] += val; pre[p] += val; suf[p] += val;
    for(int i = p/2; i > 0; i /= 2) {
        seg[i] = max(max(seg[2*i], seg[2*i+1]), suf[2*i]+pre[2*i+1]);
        s[i] = s[2*i] + s[2*i+1];
        pre[i] = max(pre[2*i], s[2*i] + pre[2*i+1]);
        suf[i] = max(suf[2*i+1], s[2*i+1]+suf[2*i]);
    }
}
ll query(int l, int r, int a, int b, int p) {
    //you can query the best subarray in any range by merging nodes
    if(a >= l && b <= r) return seg[p];
    else if(b < l || a > r) return LLONG_MIN;
    else {
        int mid = (a+b)/2, ql = query(l, r, a, mid, 2*p), qr = query(l, r, mid+1, b, 2*p+1);
        //merge these two ranges to ultimately find the max sum subarray in the original range
        //by merging the values of ranges that fall inside the range
        return max(max(ql, qr), ()+()
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n); 
    //cout.setf(ios::unitbuf);
    //codeforces blog: use a segment tree for range queries & point updates
    //seg[i] = max subarray sum, pre[i] = max prefix sum, suf[i] = max suffix sum for a particular segment
    //seg[i] = max(seg[2*i], seg[2*i+1], suf[2*i]+pre[2*i+1])
    //pre[i] = max(pre[2*i], entire sum of segment 2*i + pre[2*i+1])
    //for simplicity, assume everything is 0-indexed 
    for(int i = 0, x; i <= n; i++) {
        sc(x); upd(i, x);  
    }
}