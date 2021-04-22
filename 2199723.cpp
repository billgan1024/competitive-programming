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
const int MV = 186738;

int n, q; double d[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, q);
    for(int i = 0; i < n; i++)
    {
        ll x, y; scan(x, y);
        d[i] = sqrt(x*x + y*y);
    }
    sort(d, d+n);
    for(int i = 0, r; i < q; i++)
    {
        scan(r);
        print(upper_bound(d, d+n, r) - d, nl);
    }
}