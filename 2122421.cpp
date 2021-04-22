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
const int MV = 1e5+1;

int n, t, l, a[MV]; bool b;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, t); l = t;
    for(int i = 0, f, d; i < n; i++)
    {
        scan(f, d);
        if(d == -1) { l--; a[f]--; }
        else a[d]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == l) { print(i, sp); b = true; }
    }
    if(!b) print(-1);
}