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

int a, b, c, d, ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(a, b, c, d);
    //check all partitions (only 3)
    ans = max(ans, min(a, b)*min(c, d));
    ans = max(ans, min(a, c)*min(b, d));
    ans = max(ans, min(a, d)*min(b, c));
    pr(ans);
}