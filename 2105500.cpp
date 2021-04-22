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
const int MV = 1e6+1;

int n, q, dp[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, t, w; i < n; i++)
    {
        scan(t, w); dp[t] = max(dp[t], w);
    }
    for(int i = 1; i < MV; i++) dp[i] = max(dp[i], dp[i-1]);
    scan(q);
    for(int i = 0, t; i < q; i++)
    {
        scan(t); print(dp[t], nl);
    }
}