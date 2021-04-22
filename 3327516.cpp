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
const int maxN = 1e5+1, maxM = 1e6+1;

int n, bit[maxM], dp[maxN], ans, best; pii s[maxN]; stack<pii> seq;
bool cmp(pii x, pii y) { return x.second > y.second || (x.second == y.second && x.first < y.first); }
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    sc(n); for(int i = 1; i <= n; i++) sc(s[i].first, s[i].second);
    //sort the array such that any valid sequence of intervals is a subsequence of this array
    //since any valid sequence of intervals is a subsequence of this array,
    //a valid sequence is one which has the right and left intervals closing in on each other
    //the right intervals close in on each other as you progress down the list of intervals,
    //so the longest valid sequence is the one which has the left intervals close in on each other
    //i.e. the lis of this array
    sort(s+1, s+n+1, cmp);
    //lis with bit: dp[i] = lis ending at interval i
    //dp[i] = max(dp[j]+1) where 1 <= j < i, a[j] <= a[i] or 1 if no such j exists
    //thus, when u loop from left to right, update an array x[] such that
    //x[l] = dp[j] (l is the left endpoint)
    //then you can use the max bit to do
    //x[l] = max(x[1], ..., x[l])+1 (we always update a bit to make the current element greater)
    //also get the previous interval in the lis ending at interval i
    //for the current interval with left endpoint l
    //we don't even need the x array
    //time complexity: NlogL where L is the max BIT size (in this case, the left one can go up to 1e6)
    //pre[i] = index of previous interval in the lis ending at interval i (0 if none)
    //idx[i] = index of the interval which contributes to the value of the segment in bit[i] (0 if none)
    for(int i = 1; i <= n; i++)
    {
        //cur = current index responsible for the value of max(x[1], ..., x[l]) (default 0)
        //cnt = max(x[1], ..., x[l]) (default 0)
        int cur = 0, cnt = 0;
        //query bit
        for(int j = s[i].first; j > 0; j -= j&-j) cnt = max(cnt, bit[j]);
        //update: s[l] = cnt+1 = dp[i]
        dp[i] = cnt+1;
        for(int j = s[i].first; j < maxM; j += j&-j) bit[j] = max(bit[j], cnt+1);
        if(ans < dp[i]) { ans = dp[i]; best = i; }
    }
    pr(ans, nl);
    int nxt = dp[best];
    for(int i = best; i > 0; i--)
    {
        if(dp[i] == nxt) { seq.push({s[i].first, s[i].second}); nxt--; }
    }
    while(!seq.empty()) {
        pii p = seq.top(); seq.pop();
        pr(p.first, sp, p.second, nl);
    }
}