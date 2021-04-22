#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(a) sizeof(a)/sizeof(a[0])
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

ll n, mod = 1e9+7, ans; ll dp[1000001];
int main()
{
    //dp[i][j]: # of ways to get j (1 <= j <= 1000000) using the first i powers of 2 (loop from i = 0 to 19 inclusive), row i is implicit
    //not knapsack problem, but it resembles a complete unbounded knapsack problem
    cin.sync_with_stdio(0); cin.tie(0); scan(n); fill(dp, dp+n+1, 1);
    for(int i = 1; i < 20; i++)
    {
        for(int j = pow(2, i); j <= n; j++)
        {
            //current item to update is item i, where item i has a value of 2^i
            //thus each dp[j] from 2^i to n can be formed by adding the number of ways to make dp[j-2^i] from the first i items
            //the dp row is propagated from left to right cuz you have an infinite # of object 2^i
            dp[j] += dp[j-(int)pow(2, i)]; dp[j] %= mod;
        }
    }
    print(dp[n]);
}