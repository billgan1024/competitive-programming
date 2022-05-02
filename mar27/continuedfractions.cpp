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

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, class cmp = less<T>> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const ll mod = 1e9+7;
const int maxN = 3e5+1;

//s[j][i] stores the product of [[a_k, 1], [1, 0]] as k ranges from i to i+2^j-1
int N, Q, a[maxN], s[19][maxN][2][2], ans[2][2];

// takes in a memory address of a 2d array 
// void left_mul(ll m[][2], ll n[][2]) {
//     //m = n * m
//     ll a = (n[0][0]*m[0][0] + n[0][1]*m[1][0]) % mod;
//     ll b = (n[0][0]*m[0][1] + n[0][1]*m[1][1]) % mod;
//     ll c = (n[1][0]*m[0][0] + n[1][1]*m[1][0]) % mod;
//     ll d = (n[1][0]*m[0][1] + n[1][1]*m[1][1]) % mod;
//     m[0][0] = a; m[0][1] = b; m[1][0] = c; m[1][1] = d;
// }

void right_mul(int m[][2], int n[][2]) {
    //m = m * n
    ll a = ((ll)m[0][0]*n[0][0] + (ll)m[0][1]*n[1][0]) % mod;
    ll b = ((ll)m[0][0]*n[0][1] + (ll)m[0][1]*n[1][1]) % mod;
    ll c = ((ll)m[1][0]*n[0][0] + (ll)m[1][1]*n[1][0]) % mod;
    ll d = ((ll)m[1][0]*n[0][1] + (ll)m[1][1]*n[1][1]) % mod;
    m[0][0] = a; m[0][1] = b; m[1][0] = c; m[1][1] = d;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); 
    // naive O(n^2) solution: use the fact that we can build any continued fraction of a_i =/= 0 (a_i are real) in linear time.
    // nlogn solution: notice how the naive reduction of a continued fraction already ensures that the numerator and denominator 
    // is reduced to lowest terms, and we just need to calculate a series of matrix multiplications for each query 
    // calculate (product of [[a_k, 1], [1, 0]] as k ranges from l to r-1) * [a_r, 1]
    // thus, use an O(nlogn) sparse table preprocessing trick to calculate matrix products in log(n) time (reduce everything mod 1e9+7)

    sc(N, Q); for(int i = 1; i <= N; i++) {
        sc(a[i]); 
        s[0][i][0][0] = a[i];
        s[0][i][0][1] = s[0][i][1][0] = 1; 
    }

    for(int j = 1; (1<<j) <= N; j++) {
        for(int i = 1; i+(1<<j)-1 <= N; i++) {
            copy(&s[j-1][i][0][0], &s[j-1][i][0][0]+4, &s[j][i][0][0]);
            right_mul(s[j][i], s[j-1][i+(1<<(j-1))]);
        }
    }

    for(int i = 0, l, r; i < Q; i++) {
        sc(l, r); 
        // ans stores the product of the continued fraction matrices from l to r-1
        ans[0][0] = ans[1][1] = 1; ans[0][1] = ans[1][0] = 0;
        int cur = l, p = 18; 
        while(cur < r) {
            if(cur+(1<<p)-1 < r) {
                right_mul(ans, s[p][cur]);
                cur += (1<<p);
            }
            p--;
        }
        pr(((ll)ans[0][0]*a[r] + (ll)ans[0][1]) % mod, sp, ((ll)ans[1][0]*a[r] + (ll)ans[1][1]) % mod, nl);
    }
}