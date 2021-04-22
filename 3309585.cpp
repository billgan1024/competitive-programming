#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll n, m[64][2][2], ans[2] = {0, 1}, mod = 1e9+7;
int main() {
	m[0][0][0] = 0; m[0][0][1] = m[0][1][0] = m[0][1][1] = 1;
	ans[0] = 0; ans[1] = 1; sc(n);
	if(n & 1) { ans[0] = 1; ans[1] = 1; }
	//[f(n), f(n+1)] = (transformation^n) * [0, 1]
	//the max is 10^19 so we need up to m[0]^(2^63)
	//m[n] stores transformation^(2^n)
 	for(int i = 1; i < 64; i++) {
 		ll a = m[i-1][0][0], b = m[i-1][0][1], c = m[i-1][1][0], d = m[i-1][1][1];
 		m[i][0][0] = (a*a + b*c) % mod;
 		m[i][0][1] = (a*b + b*d) % mod;
 		m[i][1][0] = (a*c + c*d) % mod;
 		m[i][1][1] = (b*c + d*d) % mod;
 		if(n & (1ULL << i))
		{
 			ll e = ans[0], f = ans[1];
 			ans[0] = (m[i][0][0]*e + m[i][0][1]*f) % mod;
 			ans[1] = (m[i][1][0]*e + m[i][1][1]*f) % mod;
		}
	}
 	pr(ans[0], nl);
}