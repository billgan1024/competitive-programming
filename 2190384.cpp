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

int n, m, k, ans, cnt, d[30002][1002];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, k);
    for(int i = 0, r, c, R, b; i < k; i++)
    {
        scan(c, r, R, b);
        //update circle centered at (r, c) with radius R
        for(int j = max(c-R, 1); j <= min(c+R, m); j++)
        {
            int x = j-c, top = max(1, (int)ceil(r - sqrt(R*R - x*x))), bot = min(n, (int)floor(r + sqrt(R*R - x*x)));
            d[top][j] += b; d[bot+1][j] -= b;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            d[j][i] += d[j-1][i];
            if(d[j][i] > ans) { ans = d[j][i]; cnt = 1; }
            else if(d[j][i] == ans) cnt++;
        }
    }
    print(ans, nl, cnt);
}