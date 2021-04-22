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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int maxN = 1e6+1;

ll n, x; bool s[maxN];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); sc(n, x);
    if(x > (n-1)*(n-2)/2) { pr(-1); return 0; }
    ll rem = (n-1)*(n-2)/2 - x;
    //start with the configuration n, 1, 2, ..., n-1 which has (n-1)(n-2)/2 total volume,
    //then move some bars in {1, 2, ..., n-2} out to reduce the total volume (volume is always maximal)
    //s[i]: whether bar i was moved out of the main container of water
    //edge cases are accounted for since if n <= 2, x > 0 makes it impossible
    //make sure the second section is in decreasing order to avoid getting more water
    for(int i = n-2; i > 0; i--)
    {
        if(rem-i >= 0) { rem -= i; s[n-1-i] = true; }
        if(!rem) break;
    }
    pr(n, sp); for(int i = 1; i <= n-2; i++) { if(!s[i]) pr(i, sp); }
    pr(n-1, sp); for(int i = n-2; i > 0; i--) { if(s[i]) pr(i, sp); }
}