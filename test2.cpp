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

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int a[5] = {1, 2, 3, 4, 5};
    //if there is no section of the array that has the index with a[i] >= v, then return the right endpoint, which is outside 
    //of the half-open interval [l, r)
    pr(lower_bound(a+1, a+1, 2)-a);
}