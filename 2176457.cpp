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
const int MV = 2e5, mod = 1e9+7;

int n, m, a[MV], ans;
int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("input.out", "w", stdout);
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0; i < n; i++) scan(a[i]);
    sort(a, a+n);
    for(int i = 0; i < n; i++)
    {
        int idx = upper_bound(a, a+n, m-a[i]) - a;
        ans = (ans + max(idx-i-1, 0)) % mod;
    }
    print(ans);
}