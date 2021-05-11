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
const int maxN = 2e5+1;

int n, k, idx[maxN]; set<pii> ans;
int main() {
    //for every character:
    //find the leftmost index which is greater than the rightmost index in the current subsequence
    //or, if no such index exists, repeat for second last index
    //if there's no more indices, find the leftmost index
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k);
    for(int i = 1, x; i <= n; i++) {
        sc(x);
        if(idx[x] != 0) {
            auto it = ans.upper_bound({idx[x], x});
            if(it == ans.end() || it->second < x) {
                //update the pointer
                ans.erase({idx[x], x}); idx[x] = i; ans.insert({idx[x], x});
            }
        } else {
            idx[x] = i;
            ans.insert({idx[x], x});
        }
    }
    for(pii p : ans) pr(p.second, nl);
}