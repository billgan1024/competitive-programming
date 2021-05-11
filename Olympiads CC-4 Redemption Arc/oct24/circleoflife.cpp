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
const int maxN = 1e5;

int n; ll t; bool dp[51][maxN]; string s;
int main() {
	cin.sync_with_stdio(0); cin.tie(0); sc(n, t, s);
	//our goal is to find dp[t][i], the state of cell i after t seconds
	//note that dp[i][t] = dp[t-1][i-1] ^ dp[t-1][i+1] = dp[t-2][i-2] ^ dp[t-2][i+2] (cancel like terms using the xor operation)
	//useful conjecture: dp[t][i]] = dp[t-2^k][i-2^k] ^ dp[t-2^k][i+2^k] for any k >= 0 (and reduce the indices mod n)
	//thus, to find the state of the board at time t, it suffices to find the state of the array at time t-1<<log2(t) in O(n) time per array created
	//since there are roughly O(logt) 1-bits, the total time complexity to build all of these arrays is O(nlogt)
	for(int i = 0; i < n; i++) dp[0][i] = s[i]-'0';
	int cnt = 0;
	//use a bottom-up approach to advance the array to the next level every time you encounter a 1-bit in t
	for(int i = 0; i < 50; i++) {
		if(t & (1LL<<i)) {
			cnt++; int mod = (1LL<<i) % n;
			//remember that to compute a+-b mod n, u need to reduce a, b by mod n,
			//then compute (a+b)%n or (a-b+n)%n to make sure the argument is always nonnegative
			for(int j = 0; j < n; j++) dp[cnt][j] = dp[cnt-1][(j-mod+n)%n] ^ dp[cnt-1][(j+mod)%n];
		}
	}
	for(int i = 0; i < n; i++) pr(dp[cnt][i]);
}