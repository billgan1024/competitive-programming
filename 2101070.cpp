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
const int N = 100;

int n, a[N], dp[N][N], ans;
int m(int i) { return (i+n)%n; }
int f(int l, int r)
{
    if(l == r)
    {
        if(n % 2 == 0) return -a[l];
        else return a[l];
    }
    else if(dp[l][r] != INT_MIN) return dp[l][r];
    else
    {
        int len = r-l+1, ret; if(l > r) len += n;
        if(n % 2 == 0)
        {
            if(len % 2 == 0) ret = max(f(m(l+1), r) + a[l], f(l, m(r-1)) + a[r]);
            else ret = min(f(m(l+1), r) - a[l], f(l, m(r-1)) - a[r]);
        }
        else
        {
            if(len % 2 == 1) ret = max(f(m(l+1), r) + a[l], f(l, m(r-1)) + a[r]);
            else ret = min(f(m(l+1), r) - a[l], f(l, m(r-1)) - a[r]);
        }
        return dp[l][r] = ret;
    }
}
int solve(int st)
{
    return a[st] + f(m(st+1), m(st-1));
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        scan(a[i]); a[i] = (a[i] % 2 == 1);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) dp[i][j] = INT_MIN;
    }
    for(int i = 0; i < n; i++)
    {
        ans += solve(i) > 0;
    }
    print(ans);
}