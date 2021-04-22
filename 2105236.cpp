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

int n, d[1501][1501], dp[1501][1501];
int f(int l, int r)
{
    //function returns the minimum distance to get either the left branch or right branch to n,
    //assuming that you already have a valid path from left...1...right, meaning that you already
    //visited 1 to max(left, right)
    //this dp is special because usually recursion starts from the largest range and reduces
    //subproblems, but this dp starts at the bottom and solves increasing intervals that are
    //technically closer to the end goal
    //note that just like top down recursion, this dp state transitions using the current l and r vals
    //also this is symmetric i.e. dp[l][r] = dp[r][l] but we can afford to calculate both since
    //the upper bound for # of dp cells is n^2
    if(l == n || r == n) return 0;
    if(dp[l][r] > 0) return dp[l][r];
    int next = max(l, r) + 1;
    return dp[l][r] = min(f(l, next) + d[r][next], f(next, r) + d[l][next]);
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) scan(d[i][j]);
    }
    print(f(1, 1));
}