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

int n, q, a[MV], d[MV+1]; ll ans; vector<int> cnt;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, q);
    for(int i = 1; i <= n; i++) scan(a[i]); sort(a+1, a+n+1);
    for(int i = 0, l, r; i < q; i++)
    {
        scan(l, r); d[l]++; d[r+1]--;
    }
    for(int i = 1; i <= n; i++) { d[i] += d[i-1]; cnt.pb(d[i]); }
    sort(cnt.begin(), cnt.end());
    for(int i = 0; i < sz(cnt); i++) ans += (ll)cnt[i]*a[sz(cnt)-i];
    print(ans);
}