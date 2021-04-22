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
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 2.5e7+2;

int n, m, q, ans[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, q);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int lb = i*j, rb = n*m - (n-i+1)*(m-j+1) + 1;
            ans[lb]++; ans[rb+1]--;
        }
    }
    for(int i = 1; i <= n*m; i++) ans[i] += ans[i-1];
    for(int i = 0, x; i < q; i++)
    {
        scan(x); print(ans[x], nl);
    }
}