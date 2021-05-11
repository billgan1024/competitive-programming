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

int n, m, last; pbds s; unordered_map<int, int> id;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //pbds stores <element, id>
    //pii is compared lexicographically, with equality if both first and second are equal
    sc(n, m);
    for(int i = 0, v; i < n; i++)
    {
        sc(v); id[v]++; s.insert({v, id[v]});
    }
    for(int i = 0; i < m; i++)
    {
        char cmd; int x; sc(cmd, x); int v = x ^ last;
        if(cmd == 'I') {
            id[v]++; s.insert({v, id[v]});
        } else if(cmd == 'R') {
            s.erase({v, id[v]}); if(id[v] > 0) id[v]--;
        } else if(cmd == 'S') {
            last = s.find_by_order(v-1)->first;
            pr(last, nl);
        } else {
            last = id[v] ? s.order_of_key({v, 1})+1 : -1;
            pr(last, nl);
        }
    }
    for(pii p : s) pr(p.first, sp);
}