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
typedef pair<int, int> pii;
template <typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 2e5;
vector<tuple<int, int, int, int>> event; int n; ll ans;
ordered_set<pii, null_type> pos, neg; hash_map<int, int> posID, negID;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 0, a, b, c, d; i < n; i++) {
        sc(a, b, c, d); event.pb({a, 1, b, d}); event.pb({c, -1, b, d});
    }
    sort(event.begin(), event.end());
    for(auto p : event) {
        int x, v, l, r; tie(x, v, l, r) = p;
        //note: deletions always come before insertions
        //query if you touch a new rectangle (# of left endpoints from [1, r] - # of right endpoints from [1, l-1])
        if(v == 1) {
            ans += pos.order_of_key({r-1, INT_MAX}) - neg.order_of_key({l, INT_MAX});
            pos.insert({l, ++posID[l]}); neg.insert({r, ++negID[r]});
        } else { pos.erase({l, posID[l]--}); neg.erase({r, negID[r]--}); }
    }
    pr(ans, nl);
}