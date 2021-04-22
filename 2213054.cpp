#include <bits/stdc++.h>
using namespace std;
#define INF 0x3fa
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e6;

//f[i]: frequency of value i so far (shifted)
int n, q, a[5001], f[2*MV+1]; ll dp[5001][5001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, q);
    for(int i = 1; i <= n; i++) sc(a[i]);
    //dp[l][r]: how many indices k exist (l < k < r) such that
    //a[l] + a[k] + a[r] = 0 (scan from left to right to get a prefix map of the occurence of a number in
    //the current range)
    for(int l = 1; l <= n; l++)
    {
        for(int r = l+2; r <= n; r++)
        {
            f[a[r-1] + MV]++;
            int val = -(a[l] + a[r]);
            if(0 <= val + MV && val + MV <= 2*MV) dp[l][r] = f[val + MV];
        }
        //reset the count
        for(int i = l+1; i < n; i++) f[a[i] + MV]--;
    }
    //sum up the dp array since a query asks for the sum of all dp[i][j]
    //such that l <= i < j <= R
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    }
    for(int i = 0, l, r; i < q; i++)
    {
        sc(l, r);
        pr(dp[r][r] - dp[l-1][r] - dp[r][l-1] + dp[l-1][l-1], nl);
    }
}