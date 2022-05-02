#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;

const int MN = 1e6;

int N, C; ll p[MN], s[MN];
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, C);
    for(int i = 0, x; i < N; i++) {
        sc(x); p[x]++;
    }
    s[0] = p[0];
    for(int i = 1; i < C; i++) s[i] = s[i-1] + p[i];

    int half = ceil((double)C/2)-1;
    // x goes from 0 to the halfway point, not including the point
    // beginning product is the one with 0 as the anchor
    // half is always the largest integer < C/2, so we can use that in many areas to to compute the correct range sums in the general case
    // similarly, we need to use C/2 since it is the largest integer <= C/2 as the left endpoint of the sum, to guarantee 
    // that we sum over valid p[y]

    // brute force: for every 0 <= x <= half, for every x < y <= x+half, sum up p[x]*p[y]*(s[min(C-1, y+half]-s[x+C/2])
    // all indices are guaranteed to be in range (even when x = half, it still works due to our use of the prefix sum array)
    // or in general, the inequality min(C-1, y+half) >= x+C/2 holds
    // remember N >= 3 so half >= 1

    ll ans = 0; 
    ll prod = 0;
    for(int x = 0; x <= half; x++) {
        if(x == 0) {
            //first do the standard summing pattern
            for(int y = x+1; y <= x+half; y++) {
                prod += p[y]*(s[min(C-1, y+half)]-s[x+C/2]);
            }
            ans += p[x]*prod;
        }
        else {
            // remember that half >= 1 (if that helps)
            // we want to obtain the current term 
            // sum of p[x]*p[y]*(s[min(C-1, y+half]-s[x+C/2]) where x+1 <= y <= x+half

            // now look at the previous sum. w.r.t. the previous x, the fragment of products of p[y](sum of p[z]) we are interested in is
            // (p[x+1]*(s[min(C-1, x+1+half)]-s[x+C/2]) + p[x+2]*(s[min(C-1, x+2+half)]-s[x+C/2]) + ... + p[x+half]*(s[min(C-1, x+half+half)]-s[x+C/2])
            // (which would have been multiplied by p[x])
            // now, we want to obtain the fragment
            // (p[x+2]*(s[min(C-1, x+2+half)]-s[x+1+C/2]) + p[x+3]*(s[min(C-1, x+3+half)]-s[x+1+C/2]) + ... + p[x+1+half]*(s[min(C-1, x+1+half+half)]-s[x+1+C/2])
            // we know this fragment is well defined with respect to the previous x.
            // how do we update it in O(1) time, while being accurate? we don't want to oversubtract when there is nothing to subtract.
            x--;
            // subtract the first term
            prod -= p[x+1]*(s[min(C-1, x+1+half)]-s[x+C/2]);

            // then observe that we just subtract off a prefix sum times a constant (which is again well-defined)
            // we got the intuition by writing out the terms in a sample case
            prod -= (s[x+half]-s[x+1])*p[x+1+C/2];
            // add a new term
            prod += p[x+1+half]*(s[min(C-1, x+1+half+half)]-s[x+1+C/2]);
            // then we multiply it by p[x+1] (current x now)
            ans += p[x+1]*prod;
            x++;
        }
    }
    pr(ans, nl);

    // a triplet of points (in the range [0, C)) that is sorted is good 
    // if and only if p2-p1, p3-p2, (p1-p3+C) < C/2 (as a decimal value)

    // note that the original answer is equal to the number of unordered triplets of points from the multiset of locations of points
    // if we re-number the points using a permutation of 1,..., n such that x <= y => P_x <= P_y
    // then you can speed up this process by summing up products of frequencies.

    // let p[i] be the # of points at location i (for 0 <= i < c)
    // basically, we need to compute the sum of p[x]*p[y]*p[z] where 0 <= x < y < z < n, y-x, z-y, x-z+C < C/2 (as a decimal value)
    // by combinatorics rules (no need to compute the product for when x, y, z aren't distinct, cuz those won't correspond to 
    // valid triangles)
    // this is O(n^2), but upon expanding this expression and seeing how it changes, 
    //  we can just precompute sums, and then accumulate the answer using values from the prefix sum array in O(1) time per update 
    // for a total complexity of linear time

}