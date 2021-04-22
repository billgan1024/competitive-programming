#include <bits/stdc++.h>
#include <ostream>
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
const int mod = 1e6;

int n, dp[31][31][31];
int f(int r1, int r2, int r3)
{
    if(r1 == 0 && r2 == 0 && r3 == 0) return 1;
    if(dp[r1][r2][r3] > 0) return dp[r1][r2][r3];
    if(r1 == r2 && r2 == r3)
    {
        dp[r1][r2][r3] = (f(r1-1, r2-1, r3) + f(r1, r2-1, r3-1)) % mod;
        if(r1 >= 2) dp[r1][r2][r3] = (dp[r1][r2][r3] + f(r1-2, r2-2, r3-2)) % mod;
    }
    else
    {
        int m = max(r1, max(r2, r3));
        if(m == r1)
        {
            if(r1 >= 2) dp[r1][r2][r3] = f(r1-2, r2, r3);
            if(m == r2) dp[r1][r2][r3] = (dp[r1][r2][r3] + f(r1-1, r2-1, r3)) % mod;
        }
        else if(m == r2)
        {
            if(r2 >= 2) dp[r1][r2][r3] = f(r1, r2-2, r3);
            if(m == r1) dp[r1][r2][r3] = (dp[r1][r2][r3] + f(r1-1, r2-1, r3)) % mod;
            if(m == r3) dp[r1][r2][r3] = (dp[r1][r2][r3] + f(r1, r2-1, r3-1)) % mod;
        }
        else
        {
            if(r3 >= 2) dp[r1][r2][r3] = f(r1, r2, r3-2);
            if(m == r2) dp[r1][r2][r3] = (dp[r1][r2][r3] + f(r1, r2-1, r3-1)) % mod;
        }
    }
    return dp[r1][r2][r3];
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        scan(n); ms(dp, 0); if(n % 2 == 1) { print(0, nl); continue; }
        print(f(n, n, n), nl);
    }
}