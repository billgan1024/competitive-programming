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
const int maxW = 2.5e5+1;

int N, W, dp[maxW], w[251], t[251], sum; double ans;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, W);
    //cout.setf(ios::unitbuf);
    //edit: my previous solution actually cheesed the problem lmao 
    //this is because it's not exactly true that for a given i, if the min weight < w, we should discard this possible value of t[i]
    //since there may be another configuration with the same sum of talent = i and yet the sum of the weights >= w AND
    //this ratio is the best.
    //another way is as follows: we know that the best possible ratio is 1000 and the worst possible ratio is 1.
    //out of all possible ratios, find the largest one <=> find the greatest possible x such that there exists a configuration 
    //with ratio >= x and sum of weights >= w
}