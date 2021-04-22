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
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<char, int> pii;
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

int n1, n2, T; string s, t; pii a[52];
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n1, n2, s, t, T);
    int c = 0;
    for(int i = sz(s)-1; i >= 0; i--) a[c++] = {s[i], 1};
    for(int i = 0; i < sz(t); i++) a[c++] = {t[i], -1};
    for(int t0 = 0; t0 < T; t0++) {
        bool canSwap = a[0].second == 1;
        for(int i = 1; i < n1+n2; i++) {
            if(a[i].second == 1) canSwap = true;
            else if(canSwap && a[i].second == -1 && a[i-1].second == 1) {
                canSwap = false;
                pii tmp = a[i]; a[i] = a[i-1]; a[i-1] = tmp;
            }
        }
    }
    for(int i = 0; i < n1+n2; i++) pr(a[i].first);
}