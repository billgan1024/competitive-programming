#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, pair<int, int>> p;
const int MV = 2e5;

int n, q, a[MV], lo[MV], hi[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, q);
    for(int i = 0; i < n; i++) sc(a[i]);
    lo[n-1] = a[n-1]; hi[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--)
    {
        lo[i] = min(a[i], lo[i+1]); hi[i] = max(a[i], hi[i+1]);
    }
    reverse(hi, hi+n);
    for(int i = 0, l, e; i < q; i++)
    {
        //everything is zero indexed
        sc(l, e);
        int lft = lower_bound(lo, lo+n, l-e) - lo; lft = n-lft;
        int rit = upper_bound(hi, hi+n, l+e) - hi;
        pr(min(lft, rit), nl);
    }
}