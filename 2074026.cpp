#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define x first
#define d second
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, ans, dp[2000][2000][2], s[2000]; pii p[2000];
int sum(int l, int r)
{
    if(l == 0) return s[r];
    return s[r]-s[l-1];
}
int binarySearch(int l, int r)
{
    while(l <= r)
    {
        int mid = (l+r)/2;
        if (p[mid].x == 0) return mid;
        if (p[mid].x < 0) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int dis(int l, int r) { return p[r].x-p[l].x; }
int rem(int l, int r, int k)
{
    if(dp[l][r][k] == -1) return -1;
    return sum(l, r) - dp[l][r][k];
}
int main()
{
    //dp[i][j][0] = min distance travelled to visit pies i to j exclusively, ending at pie i
    //dp[i][j][1] = min distance travelled to visit pies i to j exclusively, ending at pie j
    //note that i and j will enclose the pie at zero 
    //it is -1 if impossible i.e. if you touch more pies than necessary or cannot touch pies i to j
    //without running out of fuel
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++) scan(p[i].x, p[i].d);
    sort(p, p+n); s[0] = p[0].d; for(int i = 1; i < n; i++) s[i] = s[i-1] + p[i].d;
    int o = binarySearch(0, n-1);
    dp[o][o][0] = dp[o][o][1] = 0; ans = p[o].d;

    for(int len = 1; len <= n; len++)
    {
        for(int i = 0; i+len <= n; i++)
        {
            int j = i+len-1;
            if(j < o || i > o) dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    for(int len = 2; len <= n; len++)
    {
        for(int i = max(o-len+1, 0); i <= o && i+len <= n; i++)
        {
            int j = i+len-1;
            if(j == o)
            {
                if(dis(i, i+1) <= rem(i+1, j, 0)) dp[i][j][0] = dp[i+1][j][0] + dis(i, i+1);
                else dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
            else if(i == o)
            {
                if(dis(j-1, j) <= rem(i, j-1, 1)) dp[i][j][1] = dp[i][j-1][1] + dis(j-1, j);
                else dp[i][j][1] = -1;
                dp[i][j][0] = -1;
            }
            else
            {
                dp[i][j][0] = dp[i][j][1] = INT_MAX;
                if(dis(i, i+1) <= rem(i+1, j, 0))
                    dp[i][j][0] = min(dp[i][j][0], dp[i+1][j][0] + dis(i, i+1));
                if(dis(i, j) <= rem(i+1, j, 1))
                    dp[i][j][0] = min(dp[i][j][0], dp[i+1][j][1] + dis(i, j));
                if(dis(j-1, j) <= rem(i, j-1, 1))
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + dis(j-1, j));
                if(dis(i, j) <= rem(i, j-1, 0))
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + dis(i, j));

                if(dp[i][j][0] == INT_MAX) dp[i][j][0] = -1;
                if(dp[i][j][1] == INT_MAX) dp[i][j][1] = -1;
            }
            if(dp[i][j][0] != -1 || dp[i][j][1] != -1) ans = max(ans, sum(i, j));
        }
    }
    print(ans, nl);
}