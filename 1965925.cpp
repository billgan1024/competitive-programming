#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, sum, e[100001], d[100001], dp[100001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) scan(d[i]); for(int i = 1; i <= n; i++) { scan(e[i]); sum += e[i]; d[i] -= e[i]; }
    //find max subset sum in d[i] with the constraint of not choosing 3 consecutive elements
    //dp[i]: max subset sum from the first i elements (1-indexed)
    dp[1] = max(0, d[1]); dp[2] = dp[1] + max(0, d[2]);
    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i-1], max(d[i] + dp[i-2], d[i] + d[i-1] + dp[i-3]));
    }
    print(sum + dp[n]);
}