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
const int MV = 150001;

int n, p[3] = {0, 1, 2}, a[3][MV], s[3][MV], dp[MV], ans = INT_MAX;
int sum(int l, int r) { return s[p[0]][l-1]-s[p[0]][0] + s[p[1]][r]-s[p[1]][l-1] + s[p[2]][n]-s[p[2]][r]; }
int main()
{
    //for every permutation of the ordering ABC:
    //dp[i] = best answer if you must end the B section at position i
    //then dp[i] = min(B's section is length 1 at i, dp[i-1] + swap c[i] with b[i])
    //this is because you need to take b[i] in both cases, so your only two options are to
    //take nothing, or, if you want to add to an array, it is optimal if you add it
    //to the B section ending at i-1 that gives the best answer
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scan(a[i][j]); s[i][j] = s[i][j-1] + a[i][j];
        }
    }
    do
    {
        ms(dp, 0); dp[2] = sum(2, 2); ans = min(ans, dp[2]);
        for(int i = 3; i < n; i++)
        {
            dp[i] = min(sum(i, i), dp[i-1] + a[p[1]][i] - a[p[2]][i]);
            ans = min(ans, dp[i]);
        }
    } while(next_permutation(p, p+3));
    print(ans, nl);
}