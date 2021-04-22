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

int n, a[MV]; vector<int> p[2]; ll ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++) scan(a[i]); sort(a, a+n);
    for(int i = 0; i < n; i++) p[i%2].pb(a[i]);
    for(int i = 1; i < sz(p[0]); i++) { ll d = p[0][i]-p[0][i-1]; ans += d*d; }
    for(int i = 1; i < sz(p[1]); i++) { ll d = p[1][i]-p[1][i-1]; ans += d*d; }
    ll d = p[0][sz(p[0])-1] - p[1][sz(p[1])-1]; ans += d*d;
    d = p[0][0] - p[1][0]; ans += d*d;
    print(ans);
}