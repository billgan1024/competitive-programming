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
const int MV = 1 << 17;
 
int n, m, a[MV], N; pii seg[2*MV];
pii combine(pii x, pii y)
{
    if(x.first < y.first) return {x.first, x.second};
    else if(x.first > y.first) return {y.first, y.second};
    else return {x.first, x.second+y.second};
}
void build(int i, int l, int r)
{
    //i = node in segtree (1-indexed), [l, r] = range of that node in the original array (0-indexed)
    if(l == r) { seg[i].first = a[l]; seg[i].second = 1; }
    else
    {
        int mid = (l+r)/2;
        build(2*i, l, mid); build(2*i+1, mid+1, r);
        seg[i] = combine(seg[2*i], seg[2*i+1]);
    }
}
void upd(int i, int v)
{
    seg[i+N].first = v;
    for(int p = i+N >> 1; p; p >>= 1) seg[p] = combine(seg[2*p], seg[2*p+1]);
}
pii query(int i, int l, int r, int x, int y)
{
    //i = node in segtree, [l, r] = range of that node in the original array
    //[x, y] = original query
    if(l >= x && r <= y) return seg[i];
    else if(r < x || l > y) return {INT_MAX, 0};
    int mid = (l+r)/2;
    return combine(query(2*i, l, mid, x, y), query(2*i+1, mid+1, r, x, y));
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m);
    //ceil of 2^n
    N = 1 << (32 - clz(n) - !(n & (n-1)));
    for(int i = 0; i < n; i++) sc(a[i]);
    build(1, 0, N-1);
    for(int i = 0, cmd, a, b; i < m; i++)
    {
        sc(cmd, a, b);
        if(cmd == 1) upd(a, b);
        else
        {
            b--;
            pii ans = query(1, 0, N-1, a, b);
            pr(ans.first, sp, ans.second, nl);
        }
    }
}