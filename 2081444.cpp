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

int a, b, c, d, e, f, x, y;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(a, b, c, d, e, f); x = 3*a+2*b+c; y = 3*d+2*e+f;
    if(x > y) print("A");
    else if(y > x) print("B");
    else print("T");
}