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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int maxN = 2e5;

int n, m, ans; map<int, map<int, int>> ds; gp_hash_table<int, int> posID, negID;
pii b[maxN]; pbds pos, neg;
int main() {
    //keep an implicit 2d difference array with ds (the original array represents the total area of boxlings on
    //a particular square)
    //use 2 pbds (multiset enabled) to calculate the actual array value quickly and to determine whether
    //it's positive or zero
    //remember: maps only generate key-value pairs if the cell is updated so it saves time and memory
    //sort by increasing y, then increasing x (up and to the right)
    //note that we update the bounds by one since boxlings can rest on the edges
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m);
    for(int i = 0, x1, y1, x2, y2; i < n; i++) {
        sc(x1, y1, x2, y2); ds[y1][x1]++; ds[y1][x2+1]--; ds[y2+1][x1]--; ds[y2+1][x2+1]++;
    }
    for(int i = 0; i < m; i++) sc(b[i].second, b[i].first);
    sort(b, b+m); int cur = 0;
    for(auto p : ds) {
        //update answer based on the boxlings that were passed
        while(cur < m && b[cur].first < p.first) {
            if(pos.order_of_key({b[cur].second, INT_MAX}) - neg.order_of_key({b[cur].second, INT_MAX})) ans++;
            cur++;
        }
        //update line sweeps
        for(pii q : p.second) {
            //update pbds with (x-coord, +-val)
            for(int i = 0; i < abs(q.second); i++) {
                if(q.second > 0) pos.insert({q.first, ++posID[q.first]});
                else neg.insert({q.first, ++negID[q.first]});
            }
        }
    }
    pr(ans, nl);
}