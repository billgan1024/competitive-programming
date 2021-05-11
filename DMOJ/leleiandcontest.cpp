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
const int maxN = 262144;

//tree index: [1, maxN-1], array index: [maxN, 2*maxN-1]
//array is 0 indexed so the offset is maxN
ll n, m, q, seg[2*maxN], lazy[2*maxN];
void upd(int l, int r, int a, int b, int p, ll val)
{
	//l, r: update range, a, b: segment range (in the 0-indexed array)
	int len = b-a+1;
	if(lazy[p] != 0)
	{
		seg[p] += lazy[p]*len;
		if(a != b) { lazy[2*p] += lazy[p]; lazy[2*p+1] += lazy[p]; }
		lazy[p] = 0;
	}
	if(l <= a && b <= r) {
		seg[p] += val*len;
		if(a != b) { lazy[2*p] += val; lazy[2*p+1] += val; }
	}
	else if(b < l || a > r) return;
	else
	{
		int mid = (a+b)/2;
		upd(l, r, a, mid, 2*p, val); upd(l, r, mid+1, b, 2*p+1, val);
		seg[p] = seg[2*p] + seg[2*p+1];
	}
}
ll query(int l, int r, int a, int b, int p)
{
	int len = b-a+1;
	if(lazy[p] != 0)
	{
		seg[p] += lazy[p]*len;
		if(a != b) { lazy[2*p] += lazy[p]; lazy[2*p+1] += lazy[p]; }
		lazy[p] = 0;
	}
	if(l <= a && b <= r) return seg[p];
	else if(b < l || a > r) return 0;
	else
	{
		int mid = (a+b)/2;
		return query(l, r, a, mid, 2*p) + query(l, r, mid+1, b, 2*p+1);
	}
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
	sc(m, n, q);
	for(int i = 0, x; i < n; i++)
	{
		sc(x); upd(i, i, 0, maxN-1, 1, x);
	}
	for(int i = 0, cmd, l, r, x; i < q; i++)
	{
		sc(cmd);
		if(cmd == 1)
		{
			sc(l, r, x); upd(l-1, r-1, 0, maxN-1, 1, x);
		}
		else
		{
			sc(l, r);
			pr(query(l-1, r-1, 0, maxN-1, 1) % m, nl);
		}
	}
}