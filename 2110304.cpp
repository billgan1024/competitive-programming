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

int n, a, m, f[50], dp[1<<20]; string s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0; i < n; i++)
    {
        scan(s);
        for(int j = 0; j < m; j++)
        {
            int x = s[j] == 'X'; f[j] += x << i;
        }
    }
    for(int i = 1; i < (1 << n); i++)
    {
        dp[i] = INT_MAX;
        for(int j = 0; j < m; j++)
        {
            int cur = i & f[j];
            if(cur) dp[i] = min(dp[i], 1 + dp[cur ^ i]);
        }
        if(dp[i] == INT_MAX) dp[i] = 0;
    }
    if(dp[(1<<n)-1] == 0) { print(1, nl, 1, nl); return 0; }
    print(dp[(1<<n)-1], nl);
    int b = (1 << n) - 1;
    while(true)
    {
        bool flag = false;
        for(int i = 0; i < m; i++)
        {
            int cur = b & f[i];
            if(cur && 1 + dp[cur ^ b] == dp[b])
            {
                print(i+1, sp); b ^= cur; flag = true; break;
            }
        }
        if(!flag) break;
    }
    print(nl);
}