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

int n, q, p[MV], pr[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, q);
    for(int i = 0; i < n; i++) { scan(p[i]); pr[i] = p[i]; }
    sort(p, p+n); sort(pr, pr+n, greater<int>());
    //lower bound on p = L, lower bound on p reverse = R
    for(int i = 0, l, r; i < q; i++)
    {
        scan(l, r);
        int rb = n - (lower_bound(pr, pr+n, r, greater<int>()) - pr) - 1, lb = lower_bound(p, p+n, l) - p;
        print(rb-lb+1, nl);
    }
}