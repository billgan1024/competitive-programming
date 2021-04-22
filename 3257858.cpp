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
const int maxN = 1e5+2;

string s; int n, a[26], b[26], ans;
int main() {
	sc(n, s); for(char c : s) b[c-'a']++;
	for(int i = 0; i < n; i++)
	{
		int idx = s[i]-'a';
		a[idx]++; b[idx]--; int cnt = 0;
		for(int j = 0; j < 26; j++)
		{
			if(a[j] > 0 && b[j] > 0) cnt++;
		}
		ans = max(ans, cnt);
	}
	pr(ans);
}