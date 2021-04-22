#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MV = 100001;

int n, m, a[MV]; ll bit[MV], fbit[MV]; char c;
void update(int x, int v, ll b[])
{
    for(int i = x; i < MV; i += i&-i) b[i] += v;
}
ll query(int l, int r, ll b[])
{
    ll rsum = 0, lsum = 0;
    for(int i = r; i > 0; i -= i&-i) rsum += b[i];
    for(int i = l-1; i > 0; i -= i&-i) lsum += b[i];
    return rsum-lsum;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 1; i <= n; i++)
    {
        scan(a[i]); update(i, a[i], bit); update(a[i], 1, fbit);
    }
    for(int i = 0; i < m; i++)
    {
        scan(c); int x, v, l, r;
        if(c == 'C')
        {
            scan(x, v); int d = v-a[x]; update(x, d, bit); update(a[x], -1, fbit);
            a[x] = v; update(a[x], 1, fbit);
        }
        else if(c == 'S')
        {
            scan(l, r); print(query(l, r, bit), nl);
        }
        else if(c == 'Q')
        {
            scan(v); print(query(1, v, fbit), nl);
        }
    }
}