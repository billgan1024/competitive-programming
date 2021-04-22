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
const ui MV = 1 << 20;

int n, m, dp[MV][50]; ui fail, dist[50], last[50]; string s;

int f(ui b, int i)
{
    if(b == 0) return 0;
    if(i == 0) return 1;
    if(dp[b][i] > 0) return dp[b][i];
    dp[b][i] = 1 + f((b ^ dist[i]) & b, i-1);
    if(!(b & last[i])) dp[b][i] = min(dp[b][i], f(b, i-1));
    return dp[b][i];
}

int main()
{
    //dp[subset][i] = the minimum # of testcases you need to take
    //if you only consider this current subset of ppl who failed and
    //you only consider the cases 1...i

    //dist: array showing the fail distribution (1 for failed test case)
    //fail: represents which contestants failed at least once (1 for failed at least once)
    //last: represents which contestants failed here first (will need this for dp)
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0; i < n; i++)
    {
        scan(s); bool first = false;
        for(int j = 0; j < m; j++)
        {
            //1 = WA, 0 = AC
            bool wrong = s[j] == 'X'; dist[j] += wrong << i;
            if(wrong && !first) { first = true; last[j] += 1 << i; }
        }
        fail += first << i;
    }
    if(fail == 0) print(1, nl, 1);
    else print(f(fail, m-1), nl);
}