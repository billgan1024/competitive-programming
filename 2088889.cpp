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

int n, sum, a[10] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000}, d;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < 10; i++) sum += a[i];
    for(int i = 0, x; i < n; i++)
    {
        scan(x); sum -= a[x-1];
    }
    scan(d); double bet = sum/(10-n);
    print(d > bet ? "deal" : "no deal");
}