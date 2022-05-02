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

// f(n) = number of trees with weight i = sum of f(floor(n/k)) for k = 2,..., n,
// since the weight of the child subtrees when there are k of them is floor(n/k)
// naive: upper bound complexity of O(nsqrt(n)) = O(n^{3/2})
// can optimize each function call to O(sqrt(n)) since you can observe that many computations are repeated
// given n, for k = floor(n/2)+1...n, floor(n/k) = 1.
// in general, the values of floor(n/i) range from 1 to k
// as i ranges from n to floor(n/(k+1))+1 (think of a point sliding to the left of the graph of n/x, when the point starts at (n, 1))
// and it turns out that this optimization will allow you to optimize since you can choose floor(sqrt(n)) to calculate 
// sum of f(n/i) as i ranges from floor(n/(sqrt(n)+1))+1 to n in O(sqrt(n)) time

// generalization: any function that has a curvature like this (skewed towards the origin) can be optimized like this
int N; unordered_map<int, ll> dp;

ll f(int n) {
    if(n == 1) return 1;
    else if(dp[n]) return dp[n];
    else {
        int cur, pre;
        for(int i = 1; i <= sqrt(n); i++) {
            // update cur
            cur = n/(i+1)+1; pre = n/i+1;
            dp[n] += (ll)(pre-cur)*f(i);
            // at the end of the loop, update (pre, cur) for the next iteration
            pre = cur; cur = n/(i+2)+1;
        }
        for(int i = 2; i < cur; i++) dp[n] += f(n/i);
        return dp[n];
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    pr(f(N));
}