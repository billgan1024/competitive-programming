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

int r, c, dir[2][2] = {{1, 0}, {0, 1}}; string ans = "zzzzzzzzzzzzzzzzzzzz"; char g[20][20];
bool valid(int i, int j) { return i >= 0 && i < r && j >= 0 && j < c && g[i][j] != '#';}
void check(int i, int j)
{
    for(int d = 0; d < 2; d++)
    {
        if(valid(i - dir[d][0], j - dir[d][1])) continue;
        string s = ""; int cr = i, cc = j;
        while(valid(cr, cc))
        {
            s += g[cr][cc]; cr += dir[d][0]; cc += dir[d][1];
        }
        if(sz(s) >= 2) ans = min(ans, s);
    }
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(r, c);
    for(int i = 0; i < r; i++)
    {
        string s; sc(s);
        for(int j = 0; j < c; j++) g[i][j] = s[j];
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++) check(i, j);
    }
    pr(ans);
}