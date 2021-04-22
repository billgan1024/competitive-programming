#include <bits/stdc++.h>
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
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e5+4;

int n, t; ll cur[MV], d[3][MV];
int main()
{
    //cur: array for brute force updates
    //d[0]: first derivative, d[1]: second derivative, d[2]: third derivative
    cin.sync_with_stdio(0); cin.tie(0); scan(n, t);
    for(int i = 0, l, r; i < n; i++)
    {
        ll a, b, c;
        scan(l, r, a, b, c); ll len = r-l;
        if(len <= 2)
        {
            for(int j = l; j <= r; j++)
            {
                ll x = j-l;
                cur[j] += a*x*x + b*x + c;
            }
        }
        else
        {
            ll last = a*len*len + b*len + c;
            if(a == 0 && b == 0)
            {
                d[0][l] += c; d[0][r+1] -= c;
            }
            else if(a == 0)
            {
                d[1][l] += c; d[1][l+1] += b-c; d[1][r+1] -= last+b; d[1][r+2] += last;
            }
            else
            {
                d[2][l] += c; d[2][l+1] += a+b-2*c; d[2][l+2] += a-b+c;
                d[2][r+1] -= (2*len+1)*a + b + last;
                d[2][r+2] += 2*last + (2*len-1)*a + b;
                d[2][r+3] -= last;
            }
        }
    }
    for(int i = 2; i >= 0; i--)
    {
        for(int j = 2; j >= i; j--)
        {
            for(int k = 1; k <= t; k++) d[j][k] += d[j][k-1];
        }
    }
    for(int i = 1; i <= t; i++) print(cur[i] + d[0][i] + d[1][i] + d[2][i], sp);
}