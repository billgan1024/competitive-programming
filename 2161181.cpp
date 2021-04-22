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

int n; ll t[1<<20], a[40], m, ans;
int main()
{
    //meet in the middle lol
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0; i < n; i++) scan(a[i]);
    int h = n/2;
    for(int i = 0; i < (1 << h); i++)
    {
        ll s = 0;
        for(int j = 0; j < h; j++)
        {
            if(i & (1 << j)) s += a[j];
        }
        t[i] = s;
    }
    sort(t, t + (1 << h));
    for(int i = 0; i < (1 << (n-h)); i++)
    {
        ll s = 0;
        for(int j = 0; j < n-h; j++)
        {
            if(i & (1 << j)) s += a[j+h];
        }
        ans += upper_bound(t, t + (1 << h), m-s) - t;
    }
    print(ans);
}