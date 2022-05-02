#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
const int maxN = 1<<17;

//observation: to determine whether a valid x exists, it suffices to determine whether you can assign the right half bins
//in INCREASING order to the left half bins in increasing order (i.e. you match relative order when assigning bins)
//define this to be a 'good' assignment of bins (as opposed to a regular assignment of bins)
//proof: let A = there exists a good assignment, and B = there exists an assignment.
//then we have A => B and !A => !B 
//proof for the second assertion: since !A, then when you're assigning the bins starting from the greatest bin in the right half to the
//greatest bin in the left half, there must exist an bin in the smaller bins (right prefix) which is greater than the corresponding bin in the 
//greater bins. However, no other assignment works since you need to somehow assign the top k smaller bins to the 
//top k-1 greater bins, which is impossible.
//you can determine whether a good assignment exists by sorting both halves and checking whether an invalid index exists by looping through
//brute force: O(n^2) 
//to speed this up, you can think of each configuration as a number line with two groups of points: one in the first half,
//and one in the second half
//you can maintain a 'frequency array' which tracks # of points in the first group in a suffix range
//minus # of points in the second group in a suffix range
//as long as this array is completely nonnegative, this represents a valid configuration.
//start from x = n/2 and work your way downwards by deleting the last two elements from the second group, then transferring the last element
//into the first group
//these correspond to prefix range updates, and each time, you need to check whether the array is completely nonnegative.
//thus, you can use a minimum segment tree (querying the top node) w/ lazy propagation for a total time complexity of O(nlogn)

int N, a[maxN], s[2*maxN], d[maxN]; //s[i] = segment tree, d[i] = delayed operation to be performed on the children of this node
//tree nodes = [1, maxN-1], leaf nodes = [maxN, 2*maxN-1]

//seg tree always maintains up-to-date values at the root downwards, and it always tracks the min value
void upd(int l, int r, int a, int b, int p, int v) {
    //at the beginning of the recursive call, the current node is up-to-date
    if(l <= a && b <= r) {
        //gradually apply the update to the corresponding segments. d[i] represents that the children nodes of s[i] should all be incremented by that much
        //since you're performing a range increment on this segment by d[i].
        s[p] += v; if(p < maxN) d[p] += v; 
    } else if(b < l || r < a) return; 
    else {
        //push lazy update to make the children nodes up-to-date, maintaining the up-to-date layer starting from the root  
        //makes the recalculation (upward pushing) process correct 
        if(d[p] != 0) {
            s[2*p] += d[p]; s[2*p+1] += d[p]; 
            if(2*p < maxN) { d[2*p] += d[p]; d[2*p+1] += d[p]; }
            d[p] = 0;
        }
        //partial intersection
        int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p, v); upd(l, r, mid+1, b, 2*p+1, v);
        //after recurring, recalculate the minimum to push the new changes 'upwards' to maintain the up-to-date layer
        //u need to do this because when querying, you never recur further down the tree when a segment lies completely in range. the assumption
        //is that when you're searching into a node, it is up-to-date initially.
        //this is why the beginning node needs to be up-to-date, so that the recalculation process now updates the path to the root correctly.
        s[p] = min(s[2*p], s[2*p+1]);
    }
}

//recursion: what is the minimum of the suffix sum array from l to r?
int query(int l, int r, int a, int b, int p) {
    //similar to the update function, always maintain an up-to-date layer from the root
    if(l <= a && b <= r) return s[p];
    else if(b < l || r < a) return INT_MAX;
    else {
        if(d[p] != 0) {
            s[2*p] += d[p]; s[2*p+1] += d[p]; 
            if(2*p < maxN) { d[2*p] += d[p]; d[2*p+1] += d[p]; }
            d[p] = 0;
        }
        int mid = (a+b)/2;
        return min(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1));
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 1; i <= N; i++) {
        //construct initial array by performing range updates  
        sc(a[i]); upd(1, a[i], 1, maxN, 1, i <= N/2 ? 1 : -1); 
    }

    for(int x = N/2, l = N/2, r = N; x > 0; x--) {
        //verify, then update the pointers
        //note: it doesn't matter whether you pretend like the indices (l, r, a, b) represent an array which is 0- or 1- indexed
        if(query(1, N, 1, maxN, 1) >= 0) { pr(x); return 0; }
        //delete the last two numbers in the second subarray, then transfer the last number in the first subarray to the second subarray
        upd(1, a[r], 1, maxN, 1, 1);
        upd(1, a[r-1], 1, maxN, 1, 1);
        upd(1, a[l], 1, maxN, 1, -2);
        l--; r -= 2;
    }
    pr(0);
}