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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int maxN = 1e6+1;

int n, rating[maxN], cnt; pbds p;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    sc(n);
    for(int t = 1; t <= n; t++)
    {
        char cmd; int x, r, k; sc(cmd);
        if(cmd == 'N') {
            sc(x, r); rating[x] = r; p.insert({r, x}); cnt++;
        }
        else if(cmd == 'M') {
            sc(x, r); p.erase({rating[x], x});
            rating[x] = r; p.insert({r, x});
        }
        else {
            sc(k); pr(p.find_by_order(cnt-k)->second, nl);
        }
    }
}