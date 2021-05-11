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
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 1.5e5+1;

int n, a[maxN], psa[maxN]; ll ans; ordered_set<pii, null_type> s; hash_map<int, int> id;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++) {
        sc(a[i]); if(a[i] == 2) a[i] = -1; psa[i] = psa[i-1] + a[i]; s.insert({psa[i], ++id[psa[i]]});
    }
    //count # of subarrays with positive sums by maintaining a list of active prefixes
    //then count the number of data points that remain when you advance a left pointer by 1,
    //removing the leftmost element from every prefix
    for(int i = 1; i <= n; i++) {
        //count how many remain after the update
        //simulates removing the value psa[i-1] from every active point in the pbds and checking how many are
        //sums are still positive
        ans += sz(s) - s.order_of_key({psa[i-1], INT_MAX});

        //remove the prefix with right endpoint at i
        s.erase({psa[i], id[psa[i]]--});
    }
    pr(ans, nl);
}