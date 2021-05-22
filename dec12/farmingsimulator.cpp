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
const int maxN = 3e3+1;

int n, h, st[maxN][12]; pii p[maxN]; ll dp[maxN];

int query(int a, int b) {
    int j = log2(b-a+1);
    return max(st[a][j], st[b-(1<<j)+1][j]);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, h);
    //cout.setf(ios::unitbuf);
    //define the activation time as the time when u plant the seed + w[i]
    //intuition: we can't solve this with a greedy algorithm since there are two modes of planting the trees which may or
    //may not be better than each other: wait for each seed to activate and then water it, or go to each point first, then
    //return to the beginning to wait for all the seeds to activate and then go towards the finish again to plant all the trees

    //the optimal way consists of continually selecting a block of points to completely finish
    //there are thus 2^n such configurations and the best one lies within one of them.
    //for every block, you go to the end to plant all the seeds, then go back, then return to the end. this means that for every
    //point in this block, the min time between seeding and finishing is 2*distance(start, end)
    //the total time to completely finish this block (starting from the leftmost point in the block
    //is 3*distance(start, end) + max 'delay' you will encounter in trying to finish planting a tree at a particular point 
    //so query range min i.e. the delay will be max w[i] - 2*distance(start, end) if that's nonnegative.
    for(int i = 1; i <= n; i++) sc(p[i].first, p[i].second);
    sort(p+1, p+n+1); for(int i = 1; i <= n; i++) st[i][0] = p[i].second;
    for(int j = 1; 1<<j <= n; j++) {
        for(int i = 1; i+(1<<j)-1 <= n; i++) st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
    }
    for(int i = 1; i <= n; i++) {
        //we can thus establish dp[i] = min time to completely finish planting trees at the first i points
        //by brute forcing all possible blocks from the end at point i.
        dp[i] = INT_MAX;
        for(int j = 1; j <= i; j++) {
            //use dp[j-1], then traverse points [j, i] in the aforementioned fashion
            int dis = p[i].first-p[j].first;
            dp[i] = min(dp[i], dp[j-1] + p[j].first-p[j-1].first + 3*dis + max(query(j, i)-2*dis, 0));
        }
    }
    pr(dp[n] + h-p[n].first, nl);
}