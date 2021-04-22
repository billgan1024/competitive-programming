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
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 262144;

int n, m, p[6] = {2, 3, 5, 7, 11, 13}, seg[6][2*maxN]; vector<pii> c[6][maxN+1];
tuple<int, int, int> intervals[maxN];
multiset<int> s;
//seg: [1, maxN-1], [maxN, 2*maxN-1]
void upd(int i, int val, int t) {
    int idx = i+maxN-1; seg[t][idx] = val;
    for(int j = idx/2; j != 0; j /= 2) seg[t][j] = min(seg[t][2*j], seg[t][2*j+1]);
}
int query(int l, int r, int a, int b, int idx, int t) {
    if(a > r || b < l) return INT_MAX;
    else if(a >= l && b <= r) return seg[t][idx];
    else {
        int mid = (a+b)/2;
        return min(query(l, r, a, mid, 2*idx, t), query(l, r, mid+1, b, 2*idx+1, t));
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    //for each condition, it's equivalent to saying that each cell in the range needs to have the
    //exponent >= k, for the primes 2, 3, 5, 7, 11, 13
    //you can efficiently find a solution if it exists by using a line sweep to assign an initial
    //exponent value to each cell which will always work if there's a solution
    //you assign each cell the max number in the active multiset (i.e. for all active ranges now
    //that say that this cell >= xi) set a[i] = max xi
    //throw it in a min seg tree and verify ranges
    //total complexity should be nlogn (note: max value of a number is limited by 2^4*3^2*5*7*11*13
    //since these operations set the exponent to the maximum of the exponents in the conditions
    sc(n, m);
    for(int i = 0, x, y, z; i < m; i++) {
        sc(x, y, z); intervals[i] = {x, y, z};
        //factorize the number and add the condition
        for (int j = 0; j < 6; j++) {
            for (int k = 4; k > 0; k--) {
                if (z % (int) pow(p[j], k) == 0) {
                    //k = exponent of p in the prime factorization of z
                    c[j][x].pb({k, 1}); c[j][y+1].pb({k, -1}); break;
                }
            }
        }
    }
    for(int i = 0; i < 6; i++) {
        //build the exponent array for this prime
        for(int j = 1; j <= n; j++) {
            for(pii t : c[i][j]) {
                if (t.second == 1) s.insert(t.first); else s.erase(s.find(t.first));
            }
            //update the current cell with the max exponent
            if(!s.empty()) upd(j, *s.rbegin(), i);
        }
        s.clear();
    }
    for(int i = 0; i < m; i++) {
        //check each gcd
        int prod = 1;
        for(int j = 0; j < 6; j++) {
            //find min exponent in the range (default 0)
            prod *= pow(p[j], query(get<0>(intervals[i])-1, get<1>(intervals[i])-1, 0, maxN-1, 1, j));
        }
        if(prod != get<2>(intervals[i])) { pr("Impossible"); return 0; }
    }
    for(int i = 1; i <= n; i++) {
        //get the actual value of this number via its prime factorization
        int prod = 1;
        for(int j = 0; j < 6; j++) prod *= pow(p[j], seg[j][i+maxN-1]);
        pr(prod, sp);
    }
}