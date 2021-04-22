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

int n, a[100], dp[100], ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n); for(int i = 0; i < n; i++) scan(a[i]);
    dp[0] = 1; ans = 1;
    for(int i = 1; i < n; i++)
    {
        dp[i] = abs(a[i]-a[i-1]) <= 2 ? 1 + dp[i-1] : 1;
        ans = max(ans, dp[i]);
    }
    print(ans);
}