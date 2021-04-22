#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

ll n; int cnt;
int log2(ll x)
{
    return 64 - __builtin_clzll(x) - 1;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n); cnt = log2(n)+1;
    for(int i = 0; i < cnt; i++) print(1);
}