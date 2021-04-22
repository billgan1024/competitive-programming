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

bool f(int x, int y) { return x > y; }
int n, q; vector<int> a;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, q);
    for(int i = 1, ai; i <= n; i++) { scan(ai); a.pb(ai); }
    for(int i = 0, v, l, r; i < q; i++)
    {
        scan(v, l, r);
        if(v == 1) sort(a.begin()+l-1, a.begin()+r);
        else sort(a.begin()+l-1, a.begin()+r, f);
    }
    for(int i = 0; i < sz(a); i++)
    {
        print(a[i]); if(i != sz(a)-1) print(sp);
    }
    print(nl);
}