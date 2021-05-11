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
const ll mod = 1e9+7;

//in the original matrix, a[i][j] = # of directed paths of length 1 from i to j so we can calculate the sum of ans[i][j] where
//ans[i][j] = # of directed paths of length k from i to j
//note that # of directed paths of length k from i to j = sum of (# of paths from i to k of length m)*(# of paths from k to j of length k-m)
//thus, given a matrix showing the paths of length x and one showing the paths of length y, u simply multiply them
//to get the matrix showing the paths of length x+y
//use binary exponentiation to compute the answer matrix quickly
ll n, k, a[64][50][50], ans[2][50][50], cnt;
//matrix multiplication: takes 3 references of 2d arrays and makes c = a*b (mod 1e9+7)
void mul(ll a[][50], ll b[][50], ll c[][50]) {
	for(int i = 0; i < 50; i++) {
		for(int j = 0; j < 50; j++) {
			c[i][j] = 0;
			for(int k = 0; k < 50; k++) c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod;
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0); sc(n, k);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) sc(a[0][i][j]);
	}
	//start off with the identity matrix
	for(int i = 0; i < n; i++) ans[0][i][i] = 1;

	int idx = 0;
	for(int i = 0; i < 64; i++) {
		if(i > 0) mul(a[i-1], a[i-1], a[i]);
		if(k & (1LL<<i)) {
			idx = !idx; mul(ans[!idx], a[i], ans[idx]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cnt = (cnt+ans[idx][i][j]) % mod;
	}
	pr(cnt, nl);
}