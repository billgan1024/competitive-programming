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
const int maxN = 1e6+1;

int n, k, rem, days, a[maxN][20]; ll dp[maxN]; 
int query(int x, int y) {
    int j = log2(y-x+1);
    return max(a[x][j], a[y-(1<<j)+1][j]);
}
//f(day, # of breaks remaining)
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k); for(int i = 1; i <= n; i++) sc(a[i][0]);
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i+(1<<j)-1 <= n; i++) a[i][j] = max(a[i][j-1], a[i+(1<<(j-1))][j-1]);
    }
    rem = k-(n%k); days = ceil((double)n/k); if(rem == k) rem = 0;
    //pr(f(1, r));
    //find dp[i] = max sum if you just finished visiting a[1:i]
    for(int i = days; i >= 1; i--) {
        for(int j = rem; j >= 0; j--) {
            int idx = k*(i-1) - (rem-j); if(idx < 0) break;
            if(i == days) dp[idx] = query(idx+1, n);
            else {
                for(int used = 0; used <= j; used++) dp[idx] = max(dp[idx], query(idx+1, idx+k-used) + dp[idx+k-used]);
            }
        }
    }
    pr(dp[0]);
}