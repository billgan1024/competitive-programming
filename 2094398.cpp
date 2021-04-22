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

int n, c[4]; double dp[301][301][301];
double f(int c1, int c2, int c3)
{
    if(c1 == 0 && c2 == 0 && c3 == 0) return 0;
    if(dp[c1][c2][c3] > 0) return dp[c1][c2][c3];
    int t = c1+c2+c3; double ret = (double)n/t;
    if(c1 > 0) ret += f(c1-1, c2, c3)*c1/t;
    if(c2 > 0) ret += f(c1+1, c2-1, c3)*c2/t;
    if(c3 > 0) ret += f(c1, c2+1, c3-1)*c3/t;
    return dp[c1][c2][c3] = ret;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, x; i < n; i++)
    {
        scan(x); c[x]++;
    }
    print(fixed, setprecision(9), f(c[1], c[2], c[3]));
}