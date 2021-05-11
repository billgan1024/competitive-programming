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
const int maxN = 1e5+1;

bool dp[maxN]; int n, k; vector<int> a;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
	sc(n, k); for(int i = 0, x; i < n; i++) { sc(x); a.pb(x); }
	for(int i = 1; i <= k; i++)
	{
		for(int x : a)
		{
			if(i-x >= 0) dp[i] |= !dp[i-x];
		}
	}
	pr(dp[k] ? "First" : "Second", nl);
}