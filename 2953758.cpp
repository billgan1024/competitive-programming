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

//although there can be up to O(3^n) time, n depends on the log factor of 10000
int n, m;
int f(int i, int j)
{
    if(!i || !j) return 0;
    int len = 1 << (31 - clz(min(i, j)));
    return 1 + f(i-len, len) + f(len, j-len) + f(i-len, j-len);
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        sc(n, m); pr(f(n, m), nl);
    }
}