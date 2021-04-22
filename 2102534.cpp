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

int n; ll dp[64];
ll f(int n)
{
    if(dp[n] > 0 || n == 0) return dp[n];
    ll ret = 1;
    for(int i = n-2; i >= 0; i -= 2) ret += f(i);
    return dp[n] = ret;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    dp[0] = 1; print(f(n));
}