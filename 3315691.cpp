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
const int maxN = 5e5;

int n, a[maxN]; ll ans;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    sc(n); int l, r, best = INT_MIN;
    for(int i = 0; i < n; i++) {
        sc(a[i]); if(best < a[i]) { best = a[i]; l = i;}
    }
    for(int i = n-1; i >= 0; i--) {
        if(a[i] == best) { r = i; break; }
    }
    best = INT_MIN;
    for(int i = 0; i < r; i++)
    {
        best = max(best, a[i]); ans += best-a[i];
    }
    best = INT_MIN;
    for(int i = n-1; i > r; i--)
    {
        best = max(best, a[i]); ans += best-a[i];
    }
    pr(ans, nl);
}