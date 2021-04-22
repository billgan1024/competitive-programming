#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
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
const int maxN = 1e5+1;

int p[maxN], n;
int get(int a) { return p[a] = (p[a] == a ? a : get(p[a])); }
bool merge(int a, int b)
{
    int x = get(a), y = get(b);
    p[x] = y; return x != y;
}
int main() {
    for(int t = 0; t < 2; t++) {
        sc(n); for (int i = 1; i <= n; i++) p[i] = i;
        int ans = n;
        for (int i = 1, x; i <= n; i++) {
            sc(x);
            if (merge(x, i)) ans--;
        }
        pr(ans, sp);
    }
}