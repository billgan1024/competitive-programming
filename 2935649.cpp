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
const int MV = 1e7+2;

int n, ans, d[MV];
int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("input.out", "w", stdout);
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, l, r; i < n; i++)
    {
        scan(l, r); d[l]++; d[r]--;
    }
    for(int i = 1; i < MV; i++)
    {
        d[i] += d[i-1]; ans = max(ans, d[i]);
    }
    print(ans);
}