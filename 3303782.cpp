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

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int maxN = 2e3+5, mod = 1e9+7;

//bit[i] has element indices 1 to i, sums are stored mod 1e9+7
int bit[maxN][maxN], ans, n;
void upd(int b, int x, int val)
{
	for(int i = x; i <= b; i += i&-i) { bit[b][i] += val; bit[b][i] %= mod; }
}
int sum(int b, int x)
{
	int ret = 0;
	for(int i = x; i > 0; i -= i&-i) { ret += bit[b][i]; ret %= mod; }
	return ret;
}
int main() {
	sc(n);
	for(int t = 0, cmd, r, c, x; t < n; t++)
	{
		sc(cmd, r, c, x);
		if(cmd == 1)
		{
			upd(r+c, c, x);
		}
		else
		{
			ans = (ans + sum(r+c, c+x) - sum(r+c, c-1) + mod) % mod;
		}
	}
	pr(ans, nl);
}