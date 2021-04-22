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

int n, ans, p;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, x; i < n; i++)
    {
        scan(x); int c = x, mx = 0;
        for(int j = 2; j <= sqrt(x); j++)
        {
            if(x % j == 0)
            {
                mx = j; while(x % j == 0) x /= j;
            }
        }
        if(x != 1) mx = x;
        if(p < mx) { p = mx; ans = c; }
    }
    print(ans);
}