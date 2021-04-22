#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define a first
#define b second
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define gcd __gcd
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9;

int n, dp[2][1<<20]; vector<pii> p;
int main()
{
    //dp[i][subset]: # of ways for the first i intervals to cover a subset of 1...n-1
    //or greater, i is implicit (looped over)
    cin.sync_with_stdio(0); cin.tie(0); scan(n); p.pb({0, 0});
    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(gcd(i, j) == 1) p.pb({i, j-1});
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i < sz(p); i++)
    {
        dp[i%2][0] = 1 << i;
        int mask = ~(((1 << (p[i].b-p[i].a+1)) - 1) << p[i].a);
        for(int j = 2; j < (1 << n); j++)
        {
            dp[i%2][j] = (dp[(i-1)%2][j] + dp[(i-1)%2][j & mask]) % mod;
        }
    }
    print(dp[(sz(p)-1)%2][((1<<n)-1)^1]);
}