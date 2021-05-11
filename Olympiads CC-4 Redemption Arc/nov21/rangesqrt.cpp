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

void sc()
{}
template <class T, class... A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {}
template <class T, class... A>
void pr(T t, A... a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template <typename T, class cmp = less<T>>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename X>
using hash_map = gp_hash_table<T, X>;
const int maxN = 1e5 + 1;

int n, m;
ll a[maxN], bit[maxN];
set<int> s;
void upd(int idx, ll val) {
    for (int i = idx; i <= n; i += i & -i)
        bit[i] += val;
}

ll query(int idx) {
    ll ret = 0;
    for (int i = idx; i > 0; i -= i & -i)
        ret += bit[i];
    return ret;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.setf(ios::unitbuf);
    sc(n);
    for (int i = 1; i <= n; i++) {
        sc(a[i]);
        upd(i, a[i]);
    }
    //this problem is basically range update + range sum but for the range update,
    //we can brute force it using point updates since the total number of point updates
    //will not exceed nlogn (we can also use a bit now since no actual range updates occur)
    //thus, to iterate efficiently, maintain a set to track the next index that needs to be updated
    //whenever u encounter a range update

    //set tracks active nodes (nodes that will still change after a range update is applied)
    for (int i = 1; i <= n; i++) {
        //only let this node be updated if it isn't 1 or 0
        if (a[i] >= 2) s.insert(i);
    }
    sc(m);
    for (int i = 0, x, l, r; i < m; i++)
    {
        sc(x, l, r);
        if (x == 1) {
            pr(query(r) - query(l - 1), nl);
        }
        else {
            auto it = s.lower_bound(l);
            while(it != s.end() && *it <= r) {
                int i = *it; ll newVal = sqrt(a[i]); upd(i, newVal - a[i]);
                a[i] = newVal;
                if (a[i] == 1) s.erase(it);
                it = s.lower_bound(i+1);
            }
        }
    }
}