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
typedef unsigned int ui;
const int mod = 1e9+7;

int n, a[21][21], dp[1<<21];
int log2(int x) { return 32 - __builtin_clz(x) - 1; }
int main()
{
    //each choice for the last man -> woman corresponds to a unique collection of solutions,
    //should they exist
    //i (row): men, j (column): women
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) scan(a[i][j]);
    }
    for(int i = 1; i < (1 << n); i++)
    {
        int cnt = __builtin_popcount(i) - 1;
        if(cnt == 0) dp[i] = a[0][log2(i)];
        else
        {
            for(int j = 0; j < n; j++)
            {
                //simulate assigning the last man to woman j if it is possible
                if((i & (1 << j)) && a[cnt][j]) dp[i] = (dp[i] + dp[i^(1<<j)]) % mod;
            }
        }
    }
    print(dp[(1<<n)-1]);
}