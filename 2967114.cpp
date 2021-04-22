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
const int MV = 5e4;

int n, q, mn[16][MV], mx[16][MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, q);
    for(int i = 0; i < n; i++) { sc(mn[0][i]); mx[0][i] = mn[0][i]; }
    for(int i = 1; i <= 15; i++)
    {
        for(int j = 0; j + (1 << i) <= n; j++)
        {
            int x = 1 << (i-1);
            mn[i][j] = min(mn[i-1][j], mn[i-1][j+x]);
            mx[i][j] = max(mx[i-1][j], mx[i-1][j+x]);
        }
    }
    for(int i = 0, a, b; i < q; i++)
    {
        sc(a, b); a--; b--; int x = 31 - clz(b-a+1), len = 1 << x;
        int hi = max(mx[x][a], mx[x][b-len+1]);
        int lo = min(mn[x][a], mn[x][b-len+1]);
        pr(hi-lo, nl);
    }
}