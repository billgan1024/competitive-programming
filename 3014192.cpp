#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int MV = 3e3+1;

int n, m, s1[MV][MV], s2[MV][MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m);
    while(true)
    {
        int r, c, x; sc(r, c, x); if(r == 0 && c == 0 && x == 0) break;
        if((r+c) % 2) s1[r][c] += x; else s2[r][c] += x;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            s1[i][j] += s1[i-1][j] + s1[i][j-1] - s1[i-1][j-1];
            s2[i][j] += s2[i-1][j] + s2[i][j-1] - s2[i-1][j-1];
        }
    }
    while(true)
    {
        int r1, c1, r2, c2; sc(r1, c1, r2, c2); if(r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0) break;
        int sum1 = s1[r2][c2] - s1[r1-1][c2] - s1[r2][c1-1] + s1[r1-1][c1-1];
        int sum2 = s2[r2][c2] - s2[r1-1][c2] - s2[r2][c1-1] + s2[r1-1][c1-1];
        if((r1+c1) % 2) pr(sum1-sum2, nl); else pr(sum2-sum1, nl);
    }
}