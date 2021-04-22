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

int r, l, a[29], cur; unordered_set<int> ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(r, l);
    for(int i = 0; i < r; i++)
    {
        //technically we flip all the rows (rightmost bit = leftmost bulb)
        //bitmask is fine since l < 8
        for(int j = 0, x; j < l; j++) { scan(x); a[i] |= (x << j); }
    }
    for(int i = r-1; i >= 0; i--)
    {
        cur ^= a[i]; ans.insert(cur);
    }
    print(sz(ans));
}