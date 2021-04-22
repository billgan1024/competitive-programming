#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(a) sizeof(a)/sizeof(a[0])
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int h, v; ll ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(h, v); ans = (ll)h*(h-1)*v*(v-1)/4;
    for(int y = 1; y <= h; y++)
    {
        for(int x = 1; x <= v; x++)
        {
            int g = __gcd(x, y), my = y/g, mx = x/g;
            for(int r = y + mx, c = x + my; r <= h && c <= v; r += mx, c += my)
            {
                ans += (ll)(h-r)*(v-c);
            }
        }
    }
    print(ans);
}