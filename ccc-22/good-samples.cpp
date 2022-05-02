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

const int maxN = 1e6+1;
ll N, M, K; vector<int> cycle;
int main() {
    // for any M, the max # of good samples you can construct is n + n-1 + ... + n-m+1, up to a maximum of n(n+1)/2
    // you must construct a minimum of N good samples
    cin.sync_with_stdio(0); cin.tie(0); sc(N, M, K);
    if(K > min(N*(N+1)/2, N*M - M*(M-1)/2) || K < N) { pr(-1, nl); return 0; }

    int distinct = 0; ll tot = 0, pre = 0;
    while(tot < K) {
        pre = tot;
        tot += N-distinct; distinct++; cycle.pb(distinct);
    }
    // # of subarrays of length (distinct) that we will allow to be good, when there is a change necessary (i.e. 
    // if we don't need to make a change to our cycle elements, then don't)
    ll bonus = K-pre;

    bool flag = tot > K;
    // offset it
    bonus += distinct-1;
    // otherwise, you can always construct an array with exactly k good subarrays using cycles by repeating a cycle 
    // of a particular length, then dropping one element in the cycle such that for all subarrays less than a particular length,
    // they are good, and for all subarrays with length k, only the first ? subarrays are good.
    // find the # of distinct elements you have to use, and the index for which you drop

    // construct a vector of elements for your cycle, and just drop one when it's time
    // then you need to go to the next element, such that 
    int cur = 0;
    for(int i = 0; i < N; i++) {
        if(bonus == 0 && flag) {
            // destroy the current element from the cycle and use the next element 
            cycle.erase(cycle.begin()+cur); 
            if(cur == sz(cycle)) cur = 0;
        }
        pr(cycle[cur], sp);
        cur = (cur+1)%sz(cycle);
        bonus--;
    }
}