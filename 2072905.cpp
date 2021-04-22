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

double a, b, c, d;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(a, b, c, d);
    double d0 = (a+b)/2.0, d1 = (a+c)/2.0, d2 = (a+d)/2.0;
    double d3 = (b+c)/2.0, d4 = (b+d)/2.0, d5 = (c+d)/2.0;
    double d6 = (a+b+c)/3.0, d7 = (a+b+d)/3.0, d8 = (a+c+d)/3.0, d9 = (b+c+d)/3.0, d10 = (a+b+c+d)/4.0;
    cout.precision(6);
    print(fixed, d0, nl, d1, nl, d2, nl, d3, nl, d4, nl, d5, nl, d6, nl, d7, nl, d8, nl, d9, nl, d10, nl);
}