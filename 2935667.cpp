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

int n, a[MV], ans = INT_MAX; ll m, sum;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m);
    for(int i = 0; i < n; i++) sc(a[i]);
    for(int l = 0, r = 0; r < n; r++)
    {
        sum += a[r];
        while(sum >= m)
        {
            ans = min(ans, r-l+1);
            sum -= a[l]; l++;
        }
    }
    pr(ans == INT_MAX ? -1 : ans);
}