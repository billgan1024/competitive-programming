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

ll n, q, seg[2*maxN], s[2*maxN], pre[2*maxN], suf[2*maxN];
ll ans = LLONG_MIN, ansSuf = LLONG_MIN;
void upd(int idx, int val) {
    //adjust the index, then update all segment trees
    //note that u need to pick a segment so by default, all length-1 subarrays need to be chosen
    //if it's the only one in the interval
    int p = idx+maxN; seg[p] += val; s[p] += val; pre[p] += val; suf[p] += val;
    for(int i = p/2; i > 0; i /= 2) {
        seg[i] = max(max(seg[2*i], seg[2*i+1]), suf[2*i]+pre[2*i+1]);
        s[i] = s[2*i] + s[2*i+1];
        pre[i] = max(pre[2*i], s[2*i] + pre[2*i+1]);
        suf[i] = max(suf[2*i+1], s[2*i+1]+suf[2*i]);
    }
}
//segment tree dfs will always contruct the range from left to right, enabling you
//to easily merge the answer by tracking the current best sum as well as the best suffix sum
//(when merging, it's similar to how you would merge two segments normally)
void query(int l, int r, int a, int b, int p) {
    if(a >= l && b <= r) {
        if(ans == LLONG_MIN) {                
            //first segment 
            ans = seg[p]; ansSuf = suf[p];
        } else {
            ans = max(max(ans, seg[p]), ansSuf+pre[p]);
            ansSuf = max(suf[p], s[p] + ansSuf);
        }
    } 
    else if(b < l || a > r) return;
    else {
        int mid = (a+b)/2;
        query(l, r, a, mid, 2*p); query(l, r, mid+1, b, 2*p+1);
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, q); 
    //cout.setf(ios::unitbuf);
    //codeforces blog: use a segment tree for range queries & point updates
    //seg[i] = max subarray sum, pre[i] = max prefix sum, suf[i] = max suffix sum for a particular segment
    //seg[i] = max(seg[2*i], seg[2*i+1], suf[2*i]+pre[2*i+1])
    //pre[i] = max(pre[2*i], entire sum of segment 2*i + pre[2*i+1])
    //for simplicity, assume everything is 0-indexed 
    for(int i = 0, x; i < n; i++) {
        sc(x); upd(i, x);  
    }
    for(int i = 0; i < q; i++) {
        char cmd; int a, b; sc(cmd, a, b);
        if(cmd == 'S') {
            int dif = b-s[a+maxN-1]; upd(a-1, dif);
        } else {
            ans = LLONG_MIN; ansSuf = LLONG_MIN; 
            query(a-1, b-1, 0, maxN-1, 1);
            pr(ans, nl);
        }
    }
}