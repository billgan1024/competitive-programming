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
const int mod = 1e9+7;

int T, c[3001][3001]; ll p[42], rem[501][501], q[3001], exps[42][2], inv = 5e8+4;
int main() {
    //solve this problem 2 times: once with t, r, c <= 500 and another one with t <= 10, r <= 1e9, c <= 3000
    cin.sync_with_stdio(0); cin.tie(0); sc(T);
    p[0] = 2; for(int i = 1; i < 42; i++) p[i] = (p[i-1]*p[i-1]) % mod;
    q[0] = 1; for(int i = 1; i < 3001; i++) q[i] = (2*q[i-1]) % mod;
    for(int i = 0; i <= 3000; i++) c[i][0] = 1;
    for(int i = 1; i <= 3000; i++) {
        for(int j = 1; j <= 3000; j++) c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    }
    for(int i = 0; i <= 500; i++) {
        for(int j = 0; j <= 500; j++) {
            rem[i][j] = 1; ll x = i*j;
            for(int k = 0; k < 42; k++) {
                if(x & (1LL << k)) rem[i][j] = (rem[i][j] * p[k]) % mod;
            }
        }
    }
    //total number of matrices: 2^(r*c) which is calculated in log(r*c) time by precomputing 2^(2^k)
    for(int t0 = 0; t0 < T; t0++) {
        ll R, C; sc(R, C); ll sub = 0;
        if(T <= 500 && R <= 500 && C <= 500) {
            for(ll i = 1; i <= R+C; i++) {
                //use pie: # of binary matrices = 2^(r*c) - (# of matrices where at least one row/column is all zeroes)
                //because all row/col zero conditions are dependent (they aren't mutually exclusive), spam pie
                for(int j = 0; j <= i; j++) {
                    //assign j rows and i-j cols to be all zero
                    //# of remaining cells = r*c - j*c - (i-j)*r + j*(i-j) = c(r-j) - (i-j)(r-j) = (c-i+j)(r-j)
                    //rely on precomputed coefficients 2^(remaining rows)(remaining columns)
                    if(j <= R && i-j <= C) {
                        ll x = ((ll)c[R][j] * c[C][i - j]) % mod;
                        sub = (sub + rem[R-j][C-(i-j)] * x * (i % 2 ? 1 : -1)) % mod;
                    }
                }
            }
            pr((rem[R][C]-sub+mod)%mod, nl);
        } else {
            ll tot = 1, sub = 0;
            for(int i = 0; i < 42; i++) {
                if((R*C) & (1LL << i)) tot = (tot*p[i]) % mod;
            }
            //use PIE with math: calculate valid matrices with d columns all zero (0 <= d <= C)
            //for each one, test all conditions with k columns all zero (0 <= k <= R)
            //the total sum is equal to (2^x + 1)^r, but remember that via PIE we need to add groups
            //with an odd # of conditions met while subtracting groups with an even # of conditions met
            //use the trick involving (2^x+1)^r and (2^x-1)^r to extract the sum with even r (the other group is the difference)
            for(int d = 0; d <= C; d++) {
                //calculate (2^x + 1)^R and (2^x - 1)^R mod m using fast exponentiation (x = C-d)
                ll s = 1, t = 1; exps[0][0] = (q[C-d]+1) % mod; exps[0][1] = (q[C-d]-1+mod) % mod;
                for(int i = 1; i < 42; i++) {
                    exps[i][0] = (exps[i-1][0]*exps[i-1][0]) % mod;
                    exps[i][1] = (exps[i-1][1]*exps[i-1][1]) % mod;
                }
                for(int i = 0; i < 42; i++) {
                    if(R & (1LL << i)) {
                        s = (s*exps[i][0]) % mod; t = (t*exps[i][1]) % mod;
                    }
                }
                //if d == 0, we overcounted the original one with k = 0 so correct the error
                ll even = ((s+t)*inv) % mod, actualEven = d == 0 ? (even-tot+mod)%mod : even;
                ll odd = (s-even+mod) % mod, dif = (odd-actualEven+mod) % mod;
                if(d%2 == 0) sub = (sub+dif*c[C][d]) % mod;
                else sub = (sub-dif*c[C][d]+mod) % mod;
            }
            pr((tot-sub+mod) % mod, nl);
        }
    }
}