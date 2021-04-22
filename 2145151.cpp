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
const int MV = 3e5+2;

int n, pl[MV], pr[MV], sl[MV], sr[MV], ans = INT_MAX; bool a[MV]; string s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, s);
    for(int i = 1; i <= n; i++)
    {
        a[i] = s[i-1] == 'R'; pl[i] = pl[i-1] + !a[i]; pr[i] = pr[i-1] + a[i];
    }
    for(int i = n; i >= 1; i--)
    {
        sl[i] = sl[i+1] + !a[i]; sr[i] = sr[i+1] + a[i];
    }
    for(int i = 1; i <= n; i++) ans = min(ans, pl[i-1] + sr[i+1]);
    print(ans);
}