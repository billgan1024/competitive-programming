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

int n; string s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n); n++;
    int pos = 32 - clz(n);
    for(int i = 0; i < pos-1; i++)
    {
        if(n & (1 << i)) s = "7" + s;
        else s = "4" + s;
    }
    print(s);
}