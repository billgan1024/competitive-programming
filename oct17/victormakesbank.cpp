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
const ll mod = 1e9+7;

ll n, k, t, c, m[64][101][101], ans[72][101], tot;
int main() {
	cin.sync_with_stdio(0); cin.tie(0); sc(n, k, t, c);
	//the crabs at the beginning of month n can be entirely described using a t+1-dimensional vector
	//T_n = (A_n, b1_n, b2_n, ..., bt_n) describes the number of adults, babies which are 1 month away from becoming an adult,
	//T_(n+1) = (A_n+b1_n, b2_n, ..., bt_n, A_n*k)
	//desired matrix in the middle of n months = M^(n-1)(T_1) where T_1 = (C, 0, 0, ...)
	//a matrix can be found that transforms T_n into T_(n+1) so use fast exponentiation to find the final matrix (mod 1e9+7)
	//m[i] = M^(2^i)
	m[0][0][0] = 1; m[0][t][0] = k; for(int i = 1; i <= t; i++) m[0][i-1][i] = 1;
	for(int x = 1; x < 64; x++) {
		for(int i = 0; i <= t; i++) {
			for(int j = 0; j <= t; j++) {
				for(int k = 0; k <= t; k++) {
					m[x][i][j] = (m[x][i][j] + m[x-1][i][k]*m[x-1][k][j]) % mod;
				}
			}
		}
	}
	ans[0][0] = c; int idx = 0; n--;
	while(n > 0) {
		idx++;
		int x = 63-clzll(n);
		for(int i = 0; i <= t; i++) {
			for (int j = 0; j <= t; j++) ans[idx][i] = (ans[idx][i] + m[x][i][j] * ans[idx - 1][j]) % mod;
		}
		//don't forget to declare 1 as long long
		n -= 1LL<<x;
	}
	tot = (2*ans[idx][0]) % mod;
	for(int i = 1; i <= t; i++) tot = (tot+ans[idx][i]) % mod;
	pr(tot);
}