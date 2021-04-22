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

int n, m, f[50], dp[1<<20]; string s;
int rec(int b)
{
    if(dp[b] >= 0) return dp[b];
    dp[b] = INT_MAX;
    for(int i = 0; i < m; i++)
    {
        int cur = b & f[i];
        //simulate taking this test case if someone under consideration failed here
        if(cur) dp[b] = min(dp[b], 1 + rec(cur ^ b));
    }
    if(dp[b] == INT_MAX) dp[b] = 0;
    return dp[b];
}
int main()
{
    //dp[subset] = answer if you consider a subset of the n contestants
    //test all possible ways to include a test case to remove the people who failed
    //subset & f[i] = people who failed test case i
    //ppl who failed case i ^ subset = remaining subset after you take case i
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m); ms(dp, -INF);
    for(int i = 0; i < n; i++)
    {
        scan(s);
        for(int j = 0; j < m; j++)
        {
            int x = s[j] == 'X'; f[j] |= x << i;
        }
    }
    print(max(rec((1<<n)-1), 1), nl);
}