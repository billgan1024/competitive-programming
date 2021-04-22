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
const int MV = 2e5+1;

int n, a[MV], b[MV], ans; vector<pii> lone, paired;
int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("input.out", "w", stdout);
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) scan(a[i]);
    for(int i = 1; i <= n; i++) scan(b[i]);

    for(int i = 1; i <= n; i++)
    {
        if(b[i] >= a[i]) lone.pb({b[i]-a[i], a[i]});
        else paired.pb({a[i]-b[i], b[i]});
    }

    sort(lone.begin(), lone.end()); sort(paired.begin(), paired.end());
    for(pii p : lone) ans += p.second;
    for(pii p : paired) ans += p.second;
    if(sz(paired) % 2)
    {
        int l = INT_MAX, p = INT_MAX;
        if(sz(lone) > 0) l = lone[0].first;
        if(sz(paired) > 0) p = paired[0].first;
        ans += min(l, p);
    }
    print(ans);
}