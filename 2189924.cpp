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

int r, c, ans, h[401][401], v[401][401]; char g[401][401];
int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("input.out", "w", stdout);
    cin.sync_with_stdio(0); cin.tie(0); scan(r, c);
    for(int i = 1; i <= r; i++)
    {
        string s; scan(s);
        for(int j = 1; j <= c; j++) g[i][j] = s[j-1];
    }
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            h[i][j] = g[i][j] == '.' ? h[i][j-1] + 1 : 0;
        }
    }
    for(int j = 1; j <= c; j++)
    {
        for(int i = 1; i <= r; i++)
        {
            v[i][j] = g[i][j] == '.' ? v[i-1][j] + 1 : 0;
        }
    }
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(v[i][j] == 0) continue;
            int cur = 2*(v[i][j]+1) - 1;
            for(int k = j+1; k <= c; k++)
            {
                if(v[i][k] >= v[i][j]) cur += 2; else break;
            }
            for(int k = j-1; k > 0; k--)
            {
                if(v[i][k] >= v[i][j]) cur += 2; else break;
            }
            ans = max(ans, cur);
        }
    }
    for(int j = 1; j <= c; j++)
    {
        for(int i = 1; i <= r; i++)
        {
            if(h[i][j] == 0) continue;
            int cur = 2*(h[i][j]+1) - 1;
            for(int k = i+1; k <= r; k++)
            {
                if(h[k][j] >= h[i][j]) cur += 2; else break;
            }
            for(int k = i-1; k > 0; k--)
            {
                if(h[k][j] >= h[i][j]) cur += 2; else break;
            }
            ans = max(ans, cur);
        }
    }
    print(ans, nl);
}