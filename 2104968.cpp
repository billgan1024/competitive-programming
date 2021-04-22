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
const int MV = 1e6+2;

int n, h[MV], s[MV], p[MV]; ll ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) { scan(h[i]); p[i] = max(p[i-1], h[i]); }
    for(int i = n; i > 0; i--) s[i] = max(s[i+1], h[i]);
    for(int i = 1; i <= n; i++) ans += min(p[i], s[i]) - h[i];
    print(ans);
}