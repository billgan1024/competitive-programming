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

int m, n, c[10], dp[101];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        scan(m, n); for(int i = 0; i < n; i++) scan(c[i]);
        ms(dp, INF); dp[0] = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i >= c[j]) dp[i] = min(dp[i], 1 + dp[i-c[j]]);
            }
        }
        print(dp[m], nl);
    }
}