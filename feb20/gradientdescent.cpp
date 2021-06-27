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

int R, C, K, p, q;
int main() {
    //if r is constant, this cost function is always concave up since as you sweep from left to right, the slope is equal to
    //# of points to the left - # of points to the right, which is always (non-strict) increasing.
    //thus, you can find a local minimum.
    //this minimum is also the position of all local minimums across all rows, so now you just find the optimal row so that
    //the horizontal minimum is the smallest. observe that as you move across each row, the function is just translated
    //according to how the vertical cost function changes, meaning that you can binary search to find the global minimum 
    cin.sync_with_stdio(0); cin.tie(0); flush;
    sc(R, C, K);
    //binary search to find the first index i (1 <= i < c) s.t. f(r, i+1) - f(r, i) >= 0. this means that column i is a
    //column with local minimum. (note that there may not always be an index i that exists, in which case, you select index c)
    //edit: this is too slow because the cost for this bsearch is 2log2(n) which requires too many guesses
    int lo = 1, hi = C-1, ans = C;
    while(lo <= hi) {
        int mid = (lo+hi)/2, a, b;
        pr("?", sp, 1, sp, mid, nl); sc(a);
           
    }
}
