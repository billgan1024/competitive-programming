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

string a, b;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(a, b); int ans = 0;
    for(int i = 0; i < sz(a); i++) ans += a[i] != b[i];
    print(ans == 1 ? "LARRY IS SAVED!" : "LARRY IS DEAD!");
}