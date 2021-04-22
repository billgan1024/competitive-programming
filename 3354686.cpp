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

string a, b; int c[26], ans;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(a, b);
    for(int i = 0; i < sz(a); i++) c[a[i]-'a'] = i;
    int idx = INT_MAX;
    for(char x : b) {
        //find the char idx in a and check if a new melody was hummed
        if(idx >= c[x-'a']) ans++;
        idx = c[x-'a'];
    }
    pr(ans, nl);
}