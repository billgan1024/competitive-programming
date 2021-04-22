#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int h, w, m = 1e9 + 7, dp[1001][1001]; string s;
int main()
{
    //dp[r][c]: # of ways to get from (1, 1) to (r, c)
    cin.sync_with_stdio(0); cin.tie(0); scan(h, w); dp[1][1] = 1;
    for(int r = 1; r <= h; r++)
    {
        scan(s);
        for(int c = 1; c <= w; c++)
        {
            if(s[c-1] == '#' || (r == 1 && c == 1)) continue;
            dp[r][c] = (dp[r-1][c] + dp[r][c-1])%m;
        }
    }
    print(dp[h][w]);
}