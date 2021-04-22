#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int MV = 3e3+1;

int n, m, a[MV][MV], cmd; ll bit[MV][MV][2];
void upd(int r, int c, int v)
{
    int type = (r+c)%2;
    for(int i = r; i <= n; i += i&-i)
    {
        for(int j = c; j <= m; j += j&-j) bit[i][j][type] += v;
    }
}
ll sum0(int r, int c)
{
    ll ret = 0;
    for(int i = r; i > 0; i -= i&-i)
    {
        for(int j = c; j > 0; j -= j&-j) ret += bit[i][j][0];
    }
    return ret;
}
ll sum1(int r, int c)
{
    ll ret = 0;
    for(int i = r; i > 0; i -= i&-i)
    {
        for(int j = c; j > 0; j -= j&-j) ret += bit[i][j][1];
    }
    return ret;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m);
    while(true)
    {
        sc(cmd);
        if(cmd == 0) return 0;
        else if(cmd == 1)
        {
            int r, c, x; sc(r, c, x);
            upd(r, c, x-a[r][c]); a[r][c] = x;
        }
        else
        {
            int r1, c1, r2, c2; sc(r1, c1, r2, c2);
            ll s0 = sum0(r2, c2) - sum0(r1-1, c2) - sum0(r2, c1-1) + sum0(r1-1, c1-1);
            ll s1 = sum1(r2, c2) - sum1(r1-1, c2) - sum1(r2, c1-1) + sum1(r1-1, c1-1);
            if((r1+c1)%2) pr(s1-s0, nl);
            else pr(s0-s1, nl);
        }
    }
}