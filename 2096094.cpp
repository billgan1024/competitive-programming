#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, t, st, p[1001], ans = INT_MAX;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, t);
    for(int i = 0, x; i < n; i++) { scan(x); p[i] = x; }
    p[n] = 0; sort(p, p+n+1); st = lower_bound(p, p+n+1, 0) - p;
    for(int i = max(st-t, 0); i+t <= n && i <= st; i++)
    {
        int j = i+t, di = abs(p[i]), dj = abs(p[j]);
        ans = min(ans, 2*min(di, dj) + max(di, dj));
    }
    print(ans);
}