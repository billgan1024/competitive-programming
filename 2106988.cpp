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

int n, m, dp[MV][50]; ui mask, dist[50], last[50]; string s;

int f(ui b, int i)
{
    //no more players being considered
    if(b == 0) return 0;
    //final (case 0) with players still being considered, so u need to pick that one
    if(i == 0) return dp[b][i] = 1;
    if(dp[b][i] > 0) return dp[b][i];
    //key idea: once you take test case i, the players who failed here that are
    //currently being considered will be removed from
    //consideration. check to make sure that you have the option to skip case i by checking
    //if no players in the subset have their first failure here. then you can skip this case.
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
    //mask: represents which contestants failed at least once, dp[mask][m-1] represents the
    //final answer (we are only considering those who failed at least once)
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
        mask += first << i;
    }
    if(mask == 0) { print(1, nl, 1); return 0; }
    print(f(mask, m-1), nl);
    int cur = m-1;
    while(true)
    {
        //recall the set of test cases, find where this state's value comes from and
        //include case i accordingly (if you didnt skip case i and go to case i-1, just take case i)
        if(mask == 0) break;
        if(cur == 0) { print(1); break; }
        if(dp[mask][cur] != dp[mask][cur-1]) { print(cur+1, sp); mask = (mask ^ dist[cur]) & mask; }
        cur--;
    }
}