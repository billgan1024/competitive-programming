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
typedef pair<int, int> pii;
const int N = 1 << 17;
 
int n, m, a[N]; ll seg[2*N];
void build(int i, int l, int r)
{
    //i = node in segtree (1-indexed), [l, r] = range of that node in the original array (0-indexed)
    if(l == r) seg[i] = a[l];
    else
    {
        int mid = (l+r)/2;
        build(2*i, l, mid); build(2*i+1, mid+1, r);
        seg[i] = seg[2*i] + seg[2*i+1];
    }
}
void upd(int i, int v)
{
    seg[i+N] = v;
    for(int p = i+N >> 1; p; p >>= 1) seg[p] = seg[2*p] + seg[2*p+1];
}
ll sum(int l, int r)
{
    int x = l+N, y = r+N; ll ret = 0;
    for(; x <= y; x /= 2, y /= 2) {
        if(x % 2 == 1) {
            ret += seg[x++];
        }
        if(y % 2 == 0) {
            ret += seg[y--];
        }
    }
    return ret;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m);
    for(int i = 0; i < n; i++) sc(a[i]);
    build(1, 0, N-1);
    for(int i = 0, cmd, a, b; i < m; i++)
    {
        sc(cmd, a, b);
        if(cmd == 1) upd(a, b);
        else pr(sum(a, b-1), nl);
    }
}