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
const int maxN = 1e3+2;

int n, a[maxN], b[maxN], d[maxN], sign[maxN], ans;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    //cout.setf(ios::unitbuf);
    for(int i = 1; i <= n; i++) sc(a[i]);
    for(int i = 1; i <= n; i++) { sc(b[i]); d[i] = b[i]-a[i]; }
    while(true) {
        //loop from left to right, collecting a list of indices to be updated 
        //reduce all positive and negative regions until the entire difference array is zero
        for(int i = 1; i <= n; i++) sign[i] = d[i] == 0 ? 0 : d[i]/abs(d[i]);
        int activeIndex = -1, activeSign = 0, mn = INT_MAX, mx = INT_MIN;
        for(int i = 1; i <= n; i++) {
            if(activeSign == 0) {
                if(sign[i] != 0) {
                    mn = INT_MAX; mx = INT_MIN; 
                    activeIndex = i; activeSign = sign[i]; 
                }
            } else {
                if(sign[i] != activeSign) {
                    if(activeSign == 1) {
                        for(int j = activeIndex; j < i; j++) d[j] -= mn;
                        ans += mn;
                    } else {
                        for(int j = activeIndex; j < i; j++) d[j] -= mx;
                        ans -= mx;
                    }
                    mn = INT_MAX; mx = INT_MIN;
                    if(sign[i] != 0) {
                        activeIndex = i; activeSign = sign[i];
                    }
                } 
            }
            mn = min(mn, d[i]); mx = max(mx, d[i]);
        }
        if(activeSign == 1) {
            for(int j = activeIndex; j <= n; j++) d[j] -= mn;
            ans += mn;
        } else {
            for(int j = activeIndex; j <= n; j++) d[j] -= mx;
            ans -= mx;
        }
        bool flag = true;
        for(int i = 1; i <= n; i++) if(d[i] != 0) { flag = false; break; }
        if(flag) { pr(ans, nl); return 0; }
    }
}