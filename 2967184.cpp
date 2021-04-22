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
const int MV = 1e4+2;

int n, m, ans; short s[MV][MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m);
    for(int i = 0, x, y, w, h; i < m; i++)
    {
        sc(x, y, w, h); x++; y++; s[x][y]++; s[x+w][y]--; s[x][y+h]--; s[x+w][y+h]++;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
            ans += s[i][j] % 2 != 0;
        }
    }
    pr(ans);
}