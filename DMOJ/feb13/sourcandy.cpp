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
typedef pair<char, int> pii;
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 1e5+1;

int n, a[maxN], b[maxN], c[maxN], d[maxN], idx[maxN], dp[maxN], best, ans, s[maxN+1];
int query(int x) {
    int ret = 0;
    for(int i = x; i > 0; i -= i&-i) ret += s[i];
    return ret;
}
void upd(int x, int v) {
    for(int i = x; i <= maxN; i += i&-i) s[i] += v;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++) { sc(a[i]); c[i] = a[i]; }
    for(int i = 1; i <= n; i++) sc(b[i]);
    sort(c+1, c+n+1);
    for(int i = 1; i <= n; i++) {
        //compress both arrays such that a and b are now permutations between 1 and n
        a[i] = lower_bound(c+1, c+n+1, a[i]) - c;
        b[i] = lower_bound(c+1, c+n+1, b[i]) - c;
    }
    //make b[i] equal to the permutation from 1 to n to convert a[i] accordingly
    //d[b[i]]: converted value of b[i]
    for(int i = 1; i <= n; i++) { d[b[i]] = i; b[i] = i; }
    for(int i = 1; i <= n; i++) {
        a[i] = d[a[i]];
        //idx[i] = index of the bar with value a[i]
        idx[a[i]] = i;
    }
    idx[0] = INT_MAX;
    //find the length of the longest subsequence of consecutive numbers
    //dp[i] = length of the longest subsequence of consecutive numbers ending at i
    for(int i = 1; i <= n; i++) {
        dp[i] = idx[i] > idx[i-1] ? dp[i-1]+1 : 1;
        if(ans < dp[i]) { ans = dp[i]; best = i; }
    }
    //the longest consecutive increasing subsequence in a is from best-dp[best]+1 to best
    pr(n-ans, nl);
    //move all elements which aren't part of this sequence to the beginning or end
    //calculate the new index of any particular bar with a bit for log(n) query and updates
    //shift bar idx to the beginning: add one to shift[1], ... shift[idx-1]
    //shift bar idx to the end: add one to shift[i+1], ... shift[n]
    for(int i = best-ans; i > 0; i--) {
        pr('F', sp, idx[i]+query(idx[i]), nl);
        upd(1, 1); upd(idx[i], -1);
    }
    for(int i = best+1; i <= n; i++) {
        pr('B', sp, idx[i]+query(idx[i]), nl);
        upd(idx[i]+1, -1); upd(n+1, 1);
    }
}