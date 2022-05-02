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
const int maxN = 1e5;

int M, N, s[1<<17]ans; pii a[maxN], b[10];
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
ll query(int l, int r, int a, int b, int p) {
    if(l <= a && b <= r) return s[p]; 
    else if(b < l || r < a) return LLONG_MIN;
    else {
        push(p);
        int mid = (a+b)/2;
        return max(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1));
    }
}
int main() {
    //for this problem you can determine, for each existing metal piece, the minimum distance to another existing magnet to determine
    //the area in which you can place the special magnet to pick up this piece
    //then simply find the max # of areas that overlap, which corresponds to the max number in a grid if every existing metal piece
    //contributed a diamond-shaped update (an increment of 1) to the grid. in effect, g[i][j] represents # of overlapping ranges = 
    //# of pieces you can pick up if you placed the special magnet at (i, j).
    //because of the constraints, you can simply perform <= 4000 range updates for every magnet and win (total # of operations is about 4000n)
    //use a psa since all updates are static
    //the grid is shifted to be in the range [1, 4000]
    //update: you need a complexity <= 4000*n, so think about how you can perform updates in <= 4000 operations per magnet
    sc(M); for(int i = 0; i < M; i++) {
        sc(b[i].first, b[i].second); b[i].first++; b[i].second++;
    }
    //pretend that (x, y) = (r, c)
    sc(N);
    for(int i = 0; i < N; i++) {
        sc(a[i].first, a[i].second); a[i].first++; a[i].second++; int d = INT_MAX;
        for(int j = 0; j < M; j++) d = min(d, abs(b[j].first-a[i].first) + abs(b[j].second-a[i].second));
        d--;
        for(int j = max(a[i].first-d, 1); j <= min(a[i].first+d, 4000); j++) {
            //at row j, you need to perform the range increment at columns [c-(d-row distance to the row), c+(d-row distance to the row)]
            int k = abs(j-a[i].first);
            s[j][max(a[i].second-(d-k), 1)]++; s[j][min(a[i].second+(d-k), 4000)+1]--;
        }
    }
    for(int i = 1; i <= 4000; i++) {
        for(int j = 1; j <= 4000; j++) {
            s[i][j] += s[i][j-1]; ans = max(ans, s[i][j]);
        }
    }
    pr(ans);
}