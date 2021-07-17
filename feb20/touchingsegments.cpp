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
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 1<<18;

//one-dimensional idea: use line sweep to mark out the important positions where the number of overlapping segments changes,
//then find the maximum element in that corresponding array
//2d approach: as one line sweeps past the grid, find the best position to place the second one (i.e. query the line sweep array
//again for the maximum # of overlapping segments)
//you can accomplish this in O(nlogn) time since as the line sweeps from left to right, touching/leaving a segment is equal to
//performing a range update (adjusting the number of overlapping segments by +- 1 for a particular range), then perform a range max query

struct event { int x, amnt, id, pos; } pts[maxN];
bool c(event a, event b) { return a.x < b.x; } 

int T, N, ans, s[2*maxN], d[2*maxN], cmp[maxN][2];
//d[i] = pending range increment on the children of node i (if i is already a leaf node, this has no effect)
void push(int p) {
    s[2*p] += d[p]; s[2*p+1] += d[p];
    d[2*p] += d[p];  d[2*p+1] += d[p];
    d[p] = 0;
}
void upd(int l, int r, int a, int b, int p, int v) {
    //enter recursion with the assumption that the node p is up-to-date
    //parent nodes: [1, maxN-1], leaf nodes: [maxN, 2*maxN-1]
    if(l <= a && b <= r) { s[p] += v; d[p] += v; } 
    else if(b < l || r < a) return; //in both cases, exit the node with an up-to-date status
    else {
        //make sure the children are up-to-date when searching into them
        if(d[p] != 0) push(p); int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p, v); upd(l, r, mid+1, b, 2*p+1, v);
        //at the end, automatically recalculate the new maximum to maintain up-to-dateness in the path from
        //this node to the root since those nodes will be outdated
        //the children nodes will be up-to-date so use the values.
        s[p] = max(s[2*p], s[2*p+1]);
    }
}

//maintain up-to-dateness in the current node 
//you're not changing the values of any particular node, so you're just propagating lazy updates downward when necessary
int query(int l, int r, int a, int b, int p) {
    if(l <= a && b <= r) return s[p];
    else if(b < l || r < a) return INT_MIN;
    else {
        if(d[p] != 0) push(p); int mid = (a+b)/2;
        return max(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1));
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(T);
    for(int t = 1; t <= T; t++) {
        sc(N); ms(s, 0); ms(d, 0); ms(pts, 0); ans = 0;
        //the easiest way to capture all important regions tracking # of overlapping segments (even at the edges)
        //is to pretend all points AND lines are array cells
        //then, you have an array of size 2N (segment tree of size 4N) to perform queries + updates on
        for(int i = 0, a, b; i < N; i++) {
            sc(a, b); 
            pts[2*i] = {2*a, 1, i, 0}; pts[2*i+1] = {2*b+1, -1, i, 0}; //1 = entering, -1 = exiting
        } 
        sort(pts, pts+2*N, c); int cnt = 0, pre = -1;
        
        //optimal way to compute store normalized position
        for(int i = 0; i < 2*N; i++) {
            pts[i].pos = pts[i].x == pre ? cnt : ++cnt;
            pre = pts[i].x;
            cmp[pts[i].id][pts[i].x % 2 == 1] = pts[i].pos;
        }
        
        //cmp[i][j] = actual normalized position
        //it is an integer between 1 and 2*N
        //we update on the half-open interval since the second normalized position represents the first interval where this segment disappeared 
        //in general, we're pretending that every normalized location is a region [a, b) that highlights a 
        //specific location where the # of overlapping rectangles is constant
        for(int i = 0; i < N; i++) upd(cmp[i][0], cmp[i][1]-1, 1, maxN, 1, 1);
        
        //as the first line sweeps across, maintain a counter of the number of segments touched by this line
        //note that we can afford to check all event (even if they repeat on the same normalized location) since
        //any event representing an incomplete transition (e.g. in the middle of taking all entering segments @ this position
        //or removing all exiting segments) would never be optimal
        //as a final observation, the optimal first line would always occur at a position in which new segments are entering.
        int touched = 0;
        for(int i = 0; i < 2*N; i++) {
            upd(cmp[pts[i].id][0], cmp[pts[i].id][1], 1, maxN, 1, -pts[i].amnt);
            touched += pts[i].amnt;
            ans = max(ans, touched + query(1, maxN, 1, maxN, 1));
        }
        pr("Case ", t, ": ", ans, nl);
    }
}