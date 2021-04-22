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
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e5;

int R, C, g[100][100], dp[100][100], ans;
int f(int l, int r, int i)
{
    if(l == r) return g[i][l] * C;
    else if(dp[l][r] >= 0) return dp[l][r];
    int k = C - (r-l);
    dp[l][r] = max(g[i][l]*k + f(l+1, r, i), g[i][r]*k + f(l, r-1, i));
    return dp[l][r];
}
int main()
{
    //dp[l][r]: max score you can get if you were on turn c-len(board)+1
    //and the board was in the state l...r
    cin.sync_with_stdio(0); cin.tie(0); scan(R, C);
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++) scan(g[i][j]);
    }
    for(int i = 0; i < R; i++)
    {
        ms(dp, -INF); ans += f(0, C-1, i);
    }
    print(ans);
}