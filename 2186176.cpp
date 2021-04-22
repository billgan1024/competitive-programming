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

int h, w, n, ans, s[251][251];
int sum(int r1, int c1, int r2, int c2)
{
    return s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1];
}
int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("input.out", "w", stdout);
    cin.sync_with_stdio(0); cin.tie(0); scan(w, h, n);
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            scan(s[i][j]); s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
    for(int x = 1; x <= sqrt(n); x++)
    {
        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                ans = max(ans, sum(i, j, min(h, i+x-1), min(w, j+n/x-1)));
                ans = max(ans, sum(i, j, min(h, i+n/x-1), min(w, j+x-1)));
            }
        }
    }
    print(ans, nl);
}