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
struct item {
    int a, b;
    bool operator<(const item& y) const
    {
        return a < y.a;
    }
};
bool cmp(item x, item y) { return x.a < y.a; }
template <typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename X> using hash_map = gp_hash_table<T, X>;

ordered_set<pii, null_type> p; item h[3];
int main() {
    //custom pbds demo:
    //since pii compares lexicographically, and equality is when both variables are equal,
    //you can define a pbds like so
    cin.sync_with_stdio(0);
    cin.tie(0);
    p.insert({1, 1}); p.insert({1, 2});
    //p.erase({1, 3948934});
    pr(sz(p), nl);
    pr(*p.lower_bound({1, 2}), nl);
    h[0] = {3, 1}; h[1] = {2, 3}; h[2] = {2, 5};
    //sort(h, h+3);


    //pbds will print elements in "increasing" order (in this case, only 'a' is sorted)
    //for(item x : p) pr(x.a, sp, x.b, nl);
}