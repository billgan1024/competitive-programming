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

int n, ans; bool c[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n); c[1] = true;
    for(int i = 2; i < MV; i++)
    {
        if(c[i]) continue;
        for(int j = 2*i; j < MV; j += i) c[j] = true;
    }
    for(int i = 0, x; i < n; i++)
    {
        scan(x); ans += !c[x];
    }
    print(ans);
}