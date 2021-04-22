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
const int MV = 1e5+1;

int n, l, r, y, ans[MV]; vector<pii> pts;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, l, r, y);
    for(int i = 0; i < n; i++)
    {
        double x, v, h; scan(x, v, h);
        double x1 = floor(x - (y*h)/v) + 1, x2 = ceil(x + (y*h)/v);
        pts.pb({(int)x1, 1}); pts.pb({(int)x2, -1});
    }
    sort(pts.begin(), pts.end()); pts.pb({INT_MAX, 0});
    int prev = INT_MIN, cnt = 0;
    for(pii p : pts)
    {
        ans[cnt] += max(min(r+1, p.first) - max(l, prev), 0);
        prev = p.first; cnt += p.second;
    }
    for(int i = 1; i <= n; i++) ans[i] += ans[i-1];
    for(int i = 0; i <= n; i++) print(ans[i], nl);
}