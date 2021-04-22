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

ll n, m, a[MV], bit[MV], fbit[MV]; char c;
void update(ll x, ll v, ll b[])
{
    for(int j = x; j <= MV; j += j&-j) b[j] += v;
}
ll query(ll l, ll r, ll b[])
{
    ll rsum = 0, lsum = 0;
    for(int j = r; j > 0; j -= j&-j) rsum += b[j];
    for(int j = l-1; j > 0; j -= j&-j) lsum += b[j];
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
        scan(c); ll x, v, l, r;
        if(c == 'C')
        {
            scan(x, v); ll d = v-a[x]; update(x, d, bit); update(a[x], -1, fbit);
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