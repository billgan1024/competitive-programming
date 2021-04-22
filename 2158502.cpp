#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define d first
#define v second
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
const int MV = 5e5, mod = 1e9+7;

int n, ans, sub; pii p[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        scan(p[i].v, p[i].d); ans = (ans + p[i].v) % mod; sub = (sub + p[i].d) % mod;
    }
    sort(p, p+n);
    if(n <= 2) { print(ans % mod); return 0; }
    sub = (sub - p[n-1].d + mod) % mod; sub = (sub - p[n-2].d + mod) % mod;
    for(int i = n-3; i >= 0; i--)
    {
        ans = (ans - sub + mod) % mod; sub = (sub - p[i].d + mod) % mod;
    }
    print(ans % mod);
}