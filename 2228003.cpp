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
const int MV = 5e5;

int n, k, a[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(k);
    for(int i = 0; i < k; i++) sc(a[i]);
    sort(a, a+k); sc(n);
    for(int i = 0, x; i < n; i++)
    {
        sc(x); int cnt = lower_bound(a, a+k, x) - a;
        pr(x-cnt, nl);
    }
}