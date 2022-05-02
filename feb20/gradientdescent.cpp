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
    //if r/c is constant, this cost function is always concave up (unimodal) since as you sweep from left to right, the slope is equal to
    //# of points to the left - # of points to the right, which is always (non-strict) increasing.
    //thus, you can find a local minimum.
    //this minimum is also the position of all local minimums across all rows, so now you just find the optimal row so that
    //the horizontal minimum is the smallest. observe that as you move across each row, the function w.r.t. column number is just translated
    //according to how the vertical cost function changes, meaning that you can binary search to find the global minimum 
    //side note: all answer cells lie in the set of all r, c such that r and c are between the row and column medians.
    cin.sync_with_stdio(0); cin.tie(0); flush;
    sc(R, C, K);
    //binary search to find the first index i (1 <= i < c) s.t. f(r, i+1) - f(r, i) >= 0, then do the same thing vertically
    //however, this is too slow since the total number of queries is 2*(logR + logC)
    //you can simplify this by doing both binary searches at once i.e. find (i, j) which are the first indices (1 <= i < r, 1 <= j < c)
    //such that f(i+1, j)-f(i, j) >= 0 and f(i, j+1)-f(i, j) >= 0
    //use the two partial derivatives to do both binary searches in tandem 
    //we can do this since we know there is a particular row and column that creates an area where the horizontal cost function
    //these two regions create a bottom right rectangle where both the partial derivatives are nonnegative, and we're searching for the
    //intersection of the two lines
    //since the two binary searches are completely independent of each other (i.e. the current column being considered in the algorithm
    //ignores the current row, and vice versa), binary searching together works.
    //total number of operations is 3max(logR, logC)

    int rl = 1, rh = R-1, cl = 1, ch = C-1, ansr = R, ansc = C;
    while(rl <= rh || cl <= ch) {
        //compute the current row/col which is the middle of the endpoints, or if you have already found the optimal row/col, make it stay
        int rmid = rl <= rh ? (rl+rh)/2 : ansr, cmid = cl <= ch ? (cl+ch)/2 : ansc, a, b, c;

        pr("?", sp, rmid, sp, cmid, nl); sc(a); 
        //remember the edge case: if the current row/column is already the last row/column 
        //i.e. the ideal row/column is not in [1, R-1] or [1, C-1] (meaning it must be equal to R or C),
        //then you can't query the cell that's outside the grid.
        if(rmid+1 <= R) { pr("?", sp, rmid+1, sp, cmid, nl); sc(b); }
        if(cmid+1 <= C) { pr("?", sp, rmid, sp, cmid+1, nl); sc(c); }
        
        if(rl <= rh) {
            if(a <= b) { ansr = rmid; rh = rmid-1; }
            else rl = rmid+1;
        }
        if(cl <= ch) {
            if(a <= c) { ansc = cmid; ch = cmid-1; }
            else cl = cmid+1;
        }
    }
    //after you've found the best one, print it out
    int ans;
    pr("?", sp, ansr, sp, ansc, nl); sc(ans);
    pr("!", sp, ans, sp, nl);
}
