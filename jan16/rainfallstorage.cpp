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

int n, h[501]; bool dp[25001];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //cout.setf(ios::unitbuf);
    //we cannot brute force all permutations since the time complexity for that is O(n!*n),
    //so we can determine how to find the possible volume by seeing how a particular configuration traps water 
    //notice that any configuration is made up of a series of wells (segments [l, r] in which the pillar + water height = 
    //min(a[l], a[r]) and a[l] != a[r]). define a 'pole' as a pillar which is an endpoint of a well.
    //notice that only wells trap water, and for any particular configuration, the poles (which describe the well locations)
    //form a strictly increasing sequence, then all of the max height bars are at the middle (the middle well is the only one
    //with a[l] = a[r], when a[l] = max height), then a strictly decreasing sequence
    //notice that WLOG, the poles form a strictly increasing sequence (since we can always merge wells on the right of the same height if they exist)
    //we can thus generate all possible configurations of wells by brute forcing all poles + all pillars inside of the wells
    //another way is to construct each configuration: given the array of pillars in reverse order, you can either insert the 
    //current pillar into a well, or select it for a new well if it hasn't been selected yet.
    //the goal is to find an array dp[i] = whether volume i can be collected
    //given all possible volumes achievable by the top i pillars, it seems like we need to keep track of the available wells
    //so that we can have dp[i+difference] = dp[i from previous row] to add the current pillar to a previous well
    //this problem can be simplied because of an observation: at any stage with some pillars being poles and some being contained,
    //it doesn't matter whether any particular pillar is a pole. this is because if a particular well doesn't exist, that pillar 
    //must lie inside another well. in this case, the operation +(difference in heights) can be simulated by simply replacing that pillar
    //with the current pillar. 
    //of course, you can still create a new well, in which case dp[i] = dp[i from prev row]
    //total time complexity in its current state is O(n^2*maxVol) if we compute all possible differences in each iteration using the set of used pillars
    //however, since there's only a total of 50 possible differences, we can simplify this to O(n*h*maxVol)
    sc(n); for(int i = 1; i <= n; i++) sc(h[i]);
    sort(h+1, h+n+1); unordered_set<int> used;
    //used = all the heights of previous pillars
    //upper bound on max volume is about 50*n
    dp[0] = true;
    //start on the 2nd highest pillar since that's the first index where you could actually create a well (2nd highest with 1st highest)
    //the third highest pillar can go in between, or be used for a new well
    for(int i = n-1; i > 0; i--) {
        //current pillar height is h[i], by default, dp[i] = dp[i from prev row] since you could always 
        //create a new well (if it doesn't exist yet) or insert it at the well with height h[i] (same height = no water)
        for(int j = 50*n; j >= 0; j--) {
            for(int k : used) {
                int pre = j-(k-h[i]);
                if(pre >= 0) dp[j] |= dp[pre];
            }
        }
        //add h[i] to the set of previous pillars
        used.insert(h[i]);
    }
    for(int i = 0; i <= 50*n; i++) {
        if(dp[i]) pr(i, sp);
    }
}
