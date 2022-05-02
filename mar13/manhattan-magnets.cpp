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
const int maxN = 1<<15; 

struct event {
    int row, l, r, v; 
};
vector<event> events[2];
bool cmp(event x, event y) { return x.row < y.row; }
//pro tip: make 'more important' features of the array come first in the dimension declaration
int M, N, ans, maxDis = 4e3-1, s[2*maxN], d[2*maxN]; pii b[10];

void push(int p) {
    s[2*p] += d[p]; s[2*p+1] += d[p];
    d[2*p] += d[p]; d[2*p+1] += d[p];
    d[p] = 0;
}
void upd(int l, int r, int a, int b, int p, int v) {
    if(l <= a && b <= r) { s[p] += v; d[p] += v; }
    else if(b < l || r < a) return;
    else {
        push(p);
        int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p, v); upd(l, r, mid+1, b, 2*p+1, v);
        s[p] = max(s[2*p], s[2*p+1]); 
    }
}
void solve(int x) {
    //find the maximum of the diagonal (either odd or even according to x) whenever it changes
    int preRow = INT_MIN;
    for(event e : events[x]) {
        if(preRow != e.row) ans = max(ans, s[1]); 
        upd(e.l, e.r, 0, maxN-1, 1, e.v);
        preRow = e.row;
    }
    //note: you don't need to have a dummy value at the end since you already know that the last active rectangle was cleared
}
int main() {
    //for this problem you can determine, for each existing metal piece, the minimum distance to another existing magnet to determine
    //the area in which you can place the special magnet to pick up this piece
    //then simply find the max # of areas that overlap, which corresponds to the max number in a grid if every existing metal piece
    //contributed a diamond-shaped update (an increment of 1) to the grid. in effect, g[i][j] represents # of overlapping ranges = 
    //# of pieces you can pick up if you placed the special magnet at (i, j).
    //upper bound on operations is about 8000*n which is too slow. (remember that there is an infinite grid, and the max radius
    //for an update is 2*maxDis-1 when the piece is at the opposite corner of the existing magnet)
    //you can use segment tree with line sweep to find the maximum of the current diagonal whenever things change
    //total time complexity is O(nlogn)
    //grid length (the span of the actual diagonal column indices) is about 4000*6 so make the seg tree small (# leaf nodes = 32768)
    sc(M); for(int i = 0; i < M; i++) sc(b[i].first, b[i].second); 
    //pretend that (x, y) = (r, c) (the grid extends downwards and to the right)
    sc(N);

    //min row and col (min col is used for the offset because diagonal column indices are used for the segument tree and therefore
    //must be nonnegative
    int cmin = -3*maxDis;
    for(int i = 0, r, c; i < N; i++) {
        sc(r, c); int d = INT_MAX;
        for(int j = 0; j < M; j++) d = min(d, abs(b[j].first-r) + abs(b[j].second-c));
        d--;
        //do a +1 update at the diamond centered at (r, c) with radius d
        //index diagonals by their position in the southeast direction 
        //then index them by their position in the northeast direction
        //then the two grids contain the cells which have r+c = even/odd because mapping (r, c) to (r+c, c-r) will require two grids
        //remember that l <= r

        if(d >= 0) {
            //diagonal coords are either all odd or all even
            int dl = c-d-r-cmin, dr = c+d-r-cmin, dt = r+c-d, db = r+c+d;
            events[(dt%2+2)%2].pb({dt, dl, dr, 1}); events[(db+2)%2].pb({db+2, dl, dr, -1});
            if(d > 0) { events[((dt+1)%2+2)%2].pb({dt+1, dl+1, dr-1, 1}); events[(db+1)%2].pb({db+1, dl+1, dr-1, -1}); }
        }
    }
    sort(events[0].begin(), events[0].end(), cmp); sort(events[1].begin(), events[1].end(), cmp);
    solve(0); ms(s, 0); ms(d, 0); solve(1);
    pr(ans);
}
//calculating the boundaries when converting original (r, c) to diagonal coords (r+c, c-r): (without the shift):
//the boundaries are (0, -2*maxDis+1) => (-2*maxDis+1, -2*maxDis+1) => min row 
//(maxDis, -2*maxDis+1) => (-maxDis+1, -3*maxDis+1) -> min col 
//(3*maxDis-1, maxDis) => (4*maxDis-1, -2*maxDis-1) -> max row
//(0, 3*maxDis-1) => (3*maxDis-1, 3*maxDis-1) -> max col 
//however, those coordinates don't match up so simply adjust them