#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
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
const int MV = 1e4+1;

//total time complexity O(n*m)
//dp[n][m] = min # of squares to tile an n by m rectangle
//min value for dp[n][m] = 0
int n, m;
int f(int i, int j)
{
    if(!i || !j) return 0;
    int ret = 0;
    int len = 1 << (31 - clz(min(i, j)));
    ret = 1 + f(i-len, len) + f(len, j-len) + f(i-len, j-len);
    return ret;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        sc(n, m); pr(f(n, m), nl);
    }
}