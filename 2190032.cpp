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

int r, c, ans, psa[401][401]; string s;
int sum(int r1, int c1, int r2, int c2) { return psa[r2][c2] - psa[r1-1][c2] - psa[r2][c1-1] + psa[r1-1][c1-1]; }
int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("input.out", "w", stdout);
    cin.sync_with_stdio(0); cin.tie(0); scan(r, c);
    for(int i = 1; i <= r; i++)
    {
        scan(s);
        for(int j = 1; j <= c; j++)
        {
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + (s[j-1] == 'X');
        }
    }
    for(int i = 1; i <= c; i++)
    {
        for(int j = i; j <= c; j++)
        {
            int len = j-i+1, width = 0;
            for(int k = 1; k <= r; k++)
            {
                if(!sum(k, i, k, j)) width++;
                else width = 0;
                if(width > 0) ans = max(ans, 2*(len+width) - 1);
            }
        }
    }
    print(ans);
}