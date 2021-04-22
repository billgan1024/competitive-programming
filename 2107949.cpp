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
typedef unsigned int ui;

//count # of ways to pick a subset of ones because the two numbers are equal to all of the following:
//a = (a & b) | subset of (a ^ b), b = (a & b) | remaining elements of (a ^ b)
//here, elements refer to the 1s, 0s don't matter
int c, d, e;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(c, d, e);
    print((d | e) != c ? 0 : 1 << __builtin_popcount(e));
}