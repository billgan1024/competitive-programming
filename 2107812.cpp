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
typedef unsigned int ui;
typedef pair<int, int> pii;

int n, a[1000][1000], ans[1000];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) { scan(a[i][j]); ans[i] |= a[i][j]; ans[j] |= a[i][j]; }
    }
    for(int i = 0; i < n; i++) print(ans[i], sp);
}