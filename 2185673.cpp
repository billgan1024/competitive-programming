#include <bits/stdc++.h>
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
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, m, k, q; ll a[5002][5002];
void sum()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++) a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }
}
int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("input.out", "w", stdout);
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, k);
    for(int i = 0, r1, c1, r2, c2; i < k; i++)
    {
        scan(r1, c1, r2, c2);
        a[r1][c1]++; a[r1][c2+1]--; a[r2+1][c1]--; a[r2+1][c2+1]++;
    }
    sum(); sum();
    scan(q);
    for(int i = 0, r1, c1, r2, c2; i < q; i++)
    {
        scan(r1, c1, r2, c2);
        print(a[r2][c2] - a[r1-1][c2] - a[r2][c1-1] + a[r1-1][c1-1], nl);
    }
}