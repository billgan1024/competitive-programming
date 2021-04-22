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

int n, k, a[16]; ll dp[1<<16][16];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k);
    for(int i = 0; i < n; i++) scan(a[i]);
    for(int mask = 1; mask < (1<<n); mask++)
    {
        if(popcnt(mask) == 1)
        {
            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i)) dp[mask][i] = 1;
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(i != j && (mask & (1 << j)))
                        {
                            if(abs(a[i] - a[j]) > k) dp[mask][i] += dp[mask ^ (1 << i)][j];
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += dp[(1<<n)-1][i];
    print(ans);
}