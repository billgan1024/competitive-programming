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
const int maxN = 1<<20;

int N, K, a[maxN][20], d[2*maxN]; deque<pii> c; ll s[2*maxN], dp[2*maxN]; 
void push(int p) {
    s[2*p] = dp[2*p] + d[p]; s[2*p+1] = dp[2*p+1] + d[p]; 
    d[2*p] = d[p]; d[2*p+1] = d[p]; 
    d[p] = 0;
}
void upd(int l, int r, int a, int b, int p, int v) {
    //update max seg tree of dp[]+c[] indicating that all segments in that range should have their values updated to 
    //max(dp[]) + v (simply use the corresponding nodes in the max dp segtree)
    if(l <= a && b <= r) { s[p] = dp[p] + v; d[p] = v; }
    else if(b < l || r < a) return;
    else {
        //note: because any particular range update to dp[]+c[] has a positive v, we don't do anything if the lazy value is 
        //not set to anything yet (== 0)
        if(d[p] != 0) push(p);
        int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p, v); upd(l, r, mid+1, b, 2*p+1, v); 
        s[p] = max(s[2*p], s[2*p+1]);
    }
}
ll query(int l, int r, int a, int b, int p) {
    if(l <= a && b <= r) return s[p];
    else if(b < l || r < a) return LLONG_MIN;
    else {
        if(d[p] != 0) push(p);
        int mid = (a+b)/2;
        return max(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1));
    }
} 
void dp_upd(int idx, ll v) {
    int p = idx+maxN; dp[p] += v; 
    for(int i = p/2; i > 0; i /= 2) dp[i] = max(dp[2*i], dp[2*i+1]);
}
int st_query(int x, int y) {
    int j = 31-clz(y-x+1);
    return max(a[x][j], a[y-(1<<j)+1][j]);
}
int main() {
    //dp[] = max seg tree for previous dp values (only supports range queries and point updates), 
    //s[] = max seg tree tracking dp[j]+c[j, i] that supports the range max update on c[j] 
    //d[i] = lazy update representing the intention to make the children of node i equal to max(dp[]) + d[i]
    //c = stack tracking <value, index>
    cin.sync_with_stdio(0); cin.tie(0); sc(N, K); 
    for(int i = 1; i <= N; i++) sc(a[i][0]);
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i+(1<<j)-1 <= N; i++) a[i][j] = max(a[i][j-1], a[i+(1<<(j-1))][j-1]);
    }
    for(int d = 1; d <= ceil((double)N/K); d++) {
        int l = (d-1)*K+1, r = d*K;
        //current stack tracks c[] from the previous range 
        for(int i = l; i <= r; i++) {
            //update the sliding window of the active range of c[] that you're considering
            //edit: it doesn't actually matter whether you keep this value in the stack since the queries for max(dp+c)
            //still lies in the valid range
            if(!c.empty() && c.front().second < max(i-K, 0)) c.pop_front();
            //find index for which the suffix is updated for c[] and perform a range update on dp+c
            //the stack basically tracks (element, index) meaning that the c[] array from [previous index+1, index] is filled with
            //this element
            while(!c.empty() && c.back().first <= a[i][0]) c.pop_back();
            //replace some suffix of the stack with a new element that basically says that from prev index+1 to the end, all of the c[]
            //are now equal to a[i][0]. (remember, c[] is the suffix max of the a[i] in the previous block)
            //edge case: clamp i-K to zero (when you're in the first block), and in this case, c[] simply tracks
            //max(a[1], ..., a[i])
            int pos = c.empty() ? max(i-K, 0) : c.back().second+1; c.pb({a[i][0], l-1});
            //update the segtree of dp+c in the previous block; note that dp[0] = 0 and in the edge case, you are making the range
            //[0, 0] = max(dp[0]) + max(a[1], ..., a[i])
            if(pos <= l-1) upd(pos, l-1, 0, maxN-1, 1, a[i][0]); 
            //calculate dp and update the seg tree of dp, exiting early once the desired answer is computed
            ll val = query(max(i-K, 0), l-1, 0, maxN-1, 1);
            dp_upd(i, val); if(i == N) { pr(dp[N+maxN]); return 0; }

            //update dp+c in the current block
            //always remember that the 'v' index represents an update to the c[] values only i.e. when you're updating
            //the dp+c seg tree, you're intending to make the range [i, i] have max(dp[]+c[]) = max(dp[]) + v
            //at the last index, the lazy value d[p] = 0 won't change anything so it's fine.
            //make sure in the last section, you don't perform a range max st_query outside of the array
            upd(i, i, 0, maxN-1, 1, i+1 > min(r, N) ? 0 : st_query(i+1, min(r, N)));
        }
        //clear the stack tracking ranges of c[] starting from the previous section, and fill it up with 
        //c[] starting from the current section
        //note that if you reach this area, then this current block is definitely not the last one.
        while(!c.empty()) c.pop_back();
        for(int i = l; i <= r; i++) c.pb({i+1 > r ? 0 : st_query(i+1, r), i});
    }
}
    /*let rem = k-(n%k), if rem == k then rem = 0. you're going to visit all the attractions in ceil(n/k) days,
    so you can start off by visiting k attractions and distributing rem breaks
    note that there is a bijection between a distribution of breaks into days, and a path visiting each block of k nodes once
    while the path forms a decreasing sequence in terms of location from the end of the block (the position that is a multiple of k)
    in general, let dp[i] = max sum if you visit attractions 1...i subject to the conditions
    thus, dp[i] = max(dp[j]+max(a[j+1], ..., a[i])) where j ranges from i-k to the end of i-k's block (the position that is a multiple of k)
    this simulates taking a certain suffix of the array for the last trip such that you are still able to visit all 
    attractions in ceil(n/k) days. base case: dp[0] = 0
    you can try maintaining a data structure that keeps track of dp[j]+max(c[j, i]) where c[j, i] = max(a[j+1], ..., a[i]) (the 
    'cost' or 'value' of going from j to i), but there is no single data structure that will allow you to update this easily
    optimization: observe that as i increases, the lowest j increases by one, and all of the max(range)s take in one extra element.
    our goal is to optimize the process of extending all the right endpoints of the set of c[j, i]s by one.

    Assume that we can probably still maintain a max seg tree of dp[j]+c[j, i] given that there may be certain optimizations we can 
    do to speed up the range update to the dp[]+c[]s of the active section.

    think about the array of c[i]s that can support this operation, and look at the individual elements. for every range update in which
    c[] = max(c[], v), you will update a certain suffix (namely, the suffix that has all elements <= v). this also means that
    you will update the suffix so that all the elements are the same, meaning that the resulting value of max(dp[]+c[]) in this
    range is actually just max(dp[])+v. thus, you need to precisely determine the first index i for which 
    c[i] <= v to perform a range update on the segtree AND set all c[i] after this index equal to v.
    observe that when you're performing this type of update, the new element makes a certain suffix obsolete in the fact that t
    they are simply replaced by the value of this new element, so you can use a stack to simulate the idea of 'lifting' the 
    end of the array to a common maximum. in the stack, remove elements from the end until you find one that has c[] > v,
    then you have found the desired range to update dp[]+c[]. then query the segtree for max(dp[]+c[]).
    finally, this easily extends to a sliding window if you use a deque. this is necessary because you drop off c[] 
    corresponding to the leftmost j from which you're considering dp[]+c[] because it will get too far away
    from i once i moves to the right) 
    amortized complexity for maintaining this stack is O(n) because in total, O(n) points are inserted into and removed 
    from the stack
    after this process is done, clear the stack and fill in c[] values in the current block into the stack and update the segment
    tree tracking dp[] and dp[]+c[].
    you can see that every index's element is added and removed twice so a total of O(n) points are still processed by the stack.
    make sure to consider the edge case when you're dealing with the first block
     */