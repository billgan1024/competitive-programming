#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        ll x; scan(x);
        print(__builtin_popcountll(x) == 1 ? "T" : "F", nl);
    }
}