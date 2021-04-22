#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e5+1;

int n, f[MV], dp[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, a; i < n; i++)
    {
        scan(a); f[a] += a;
    }
    dp[1] = f[1];
    for(int i = 2; i <= n; i++) dp[i] = max(dp[i-1], f[i] + dp[i-2]);
    print(dp[n]);
}