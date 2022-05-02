#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <format>

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
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
// templates for order statistic trees using the total order less<T>
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

int N = 1000, M = 1000;
ordered_set<int> s;
int main() {
    // freopen("bruhtest.txt", "w", stdout);
    cin.sync_with_stdio(0); cin.tie(0);
    // pr(__cplusplus);
    s.insert(6);
    cout << format("{}", 3);
}