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

int n, st, ans, dp[2000][2000][2], s[2000]; pii p[2000];
int sum(int l, int r)
{
    if(l == 0) return s[r];
    return s[r]-s[l-1];
}
int dis(int i, int j) { return p[j].x - p[i].x; }
int main()
{
    //dp[i][j][k] = max energy remaining after eating pies [i, j] exclusively
    //-INF if impossible (you don't have enough energy) or undefined (you ate other pies not in [i, j])
    //k = end at i or end at j
    //then the max distance you can travel after eating pies [i, j] is sum[i, j] if and only if either
    //dp[i][j][0] or dp[i][j][1] != -INF, otherwise don't consider this interval
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++) { scan(p[i].x, p[i].d); }
    sort(p, p+n); s[0] = p[0].d; for(int i = 1; i < n; i++) s[i] = s[i-1] + p[i].d; ms(dp, -INF);
    for(int i = 0; i < n; i++)
    {
        if(p[i].x == 0) { st = i; break; }
    }
    dp[st][st][0] = dp[st][st][1] = p[st].d; ans = p[st].d;
    for(int len = 2; len <= n; len++)
    {
        for(int i = 0; i+len <= n; i++)
        {
            int j = i+len-1;
            //dp[i][j][0]
            if(dp[i+1][j][0] >= dis(i, i+1)) dp[i][j][0] = max(dp[i][j][0], dp[i+1][j][0] - dis(i, i+1) + p[i].d);
            if(dp[i+1][j][1] >= dis(i, j)) dp[i][j][0] = max(dp[i][j][0], dp[i+1][j][1] - dis(i, j) + p[i].d);
            //dp[i][j][1]
            if(dp[i][j-1][1] >= dis(j-1, j)) dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][1] - dis(j-1, j) + p[j].d);
            if(dp[i][j-1][0] >= dis(i, j)) dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][0] - dis(i, j) + p[j].d);
            if(dp[i][j][0] >= 0 || dp[i][j][1] >= 0) ans = max(ans, sum(i, j));
        }
    }
    print(ans);
}