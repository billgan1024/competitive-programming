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
#define popcnt __builtin_popcount
#define fl() cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int maxN = 2e5+1;

int n, h[maxN], a[maxN]; ll bit[maxN], ans;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //max bit queries:
    //max(a[1...r])
    //update: a[i] = v where v >= a[i]
    sc(n); for(int i = 1; i <= n; i++) sc(h[i]);
    for(int i = 1; i <= n; i++) sc(a[i]);
    for(int i = 1; i <= n; i++)
    {
        ll cnt = 0;
        for(int j = h[i]; j > 0; j -= j&-j) cnt = max(cnt, bit[j]);
        ans = max(ans, cnt+a[i]);
        for(int j = h[i]; j < maxN; j += j&-j) bit[j] = max(bit[j], cnt+a[i]);
    }
    pr(ans, nl);
}