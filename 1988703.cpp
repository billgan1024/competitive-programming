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

int n, q, grid[251][251][251]; ull ans, bit[251][251][251];

void update(int x, int y, int z, int l)
{
    ull d = l - grid[x][y][z]; grid[x][y][z] = l;
    for(int i = x; i <= n; i += i&-i)
    {
        for(int j = y; j <= n; j += j&-j)
        {
            for(int k = z; k <= n; k += k&-k) bit[i][j][k] += d;
        }
    }
}

ull sum(int x, int y, int z)
{
    ull s = 0;
    for(int i = x; i > 0; i -= i&-i)
    {
        for(int j = y; j > 0; j -= j&-j)
        {
            for(int k = z; k > 0; k -= k&-k) s += bit[i][j][k];
        }
    }
    return s;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, q);
    for(int i = 0; i < q; i++)
    {
        char cmd; int x1, y1, z1, l, x2, y2, z2; scan(cmd);
        if(cmd == 'C')
        {
            scan(x1, y1, z1, l); update(x1, y1, z1, l);
        }
        else
        {
            scan(x1, y1, z1, x2, y2, z2);
            ull v0 = sum(x2, y2, z2), v1 = sum(x1-1, y2, z2) + sum(x2, y1-1, z2) + sum(x2, y2, z1-1);
            ull v2 = sum(x1-1, y1-1, z2) + sum(x1-1, y2, z1-1) + sum(x2, y1-1, z1-1);
            ull v3 = sum(x1-1, y1-1, z1-1);
            ans += v0 - v1 + v2 - v3;
        }
    }
    print(ans);
}