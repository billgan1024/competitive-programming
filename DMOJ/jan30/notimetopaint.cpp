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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int maxN = 1e5+2;

int n, q, cp[maxN][26], cs[maxN][26]; bool ap[maxN][26], as[maxN][26]; string s;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, q, s); s = '!' + s;
    //pre[i] = min # of moves to paint the prefix, suf[i] = same thing for suffixes
    //to calculate prefixes efficiently, find the min # of moves for any particular character
    //this can be done by tracking the number of times you find a group [l, r] which contains at least
    //one element = x and every element is >= x
    //with bool arrays tracking whether a previous group is active, you can determine the min # of moves
    //using any particular character for any prefix
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++) {
            if(ap[i-1][j]) {
                //active group
                bool b = s[i]-'A' >= j; cp[i][j] = cp[i-1][j]; ap[i][j] = b;
            }
            else {
                //listen for the arrival of a new group
                bool b = s[i]-'A' == j; cp[i][j] = cp[i-1][j] + b; ap[i][j] = b;
            }
        }
    }
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < 26; j++) {
            if(as[i+1][j]) {
                //active group
                bool b = s[i]-'A' >= j; cs[i][j] = cs[i+1][j]; as[i][j] = b;
            }
            else {
                //listen for the arrival of a new group
                bool b = s[i]-'A' == j; cs[i][j] = cs[i+1][j] + b; as[i][j] = b;
            }
        }
    }
    for(int i = 1, a, b; i <= q; i++) {
        sc(a, b); int ans = 0;
        for(int j = 0; j < 26; j++) ans += cp[a-1][j] + cs[b+1][j];
        pr(ans, nl);
    }
}