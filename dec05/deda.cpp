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
const int maxN = 1<<18;

int n, q, seg[2*maxN];

void upd(int p, int val) {
    seg[p] = val;
    for(int i = p/2; i > 0; i /= 2) seg[i] = min(seg[2*i], seg[2*i+1]);
}

int query(int l, int r, int a, int b, int p) {
    if(a >= l && b <= r) return seg[p];
    else if(b < l || a > r) return INT_MAX;
    int mid = (a+b)/2;
    return min(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1)); 
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, q); ms(seg, INF);
    //cout.setf(ios::unitbuf);
    //use binary search on a min segment tree to find the least index >= b with a[i] <= y
    //do this by binary searching for the last index such that the prefix min > y
    while(q--) {
        char cmd; int a, b, x, y; sc(cmd);
        if(cmd == 'M') {
            sc(x, a); upd(a+maxN-1, x);
        } else {
            sc(y, b);
            if(seg[b+maxN-1] <= y) pr(b, nl);
            else {
                int lo = b, hi = n, ans = 0; 
                while(lo <= hi) {
                    int mid = (lo+hi)/2;
                    if(query(b-1, mid-1, 0, maxN-1, 1) > y) { ans = mid; lo = mid+1; }
                    else hi = mid-1; 
                }
                pr(ans == n ? -1 : ans+1, nl);
            }
        }
    }
}