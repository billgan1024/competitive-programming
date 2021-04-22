#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e5;

int n, m, a[MV], st[MV][17];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0; i < n; i++) { scan(a[i]); st[i][0] = a[i]; }
    for(int j = 1; (1 << j) <= n; j++)
    {
        for(int i = 0; i + (1 << j)-1 < n; i++)
        {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i = 0, l, r; i < m; i++)
    {
        scan(l, r); l--; r--; int w = log2(r-l+1);
        print(max(st[l][w], st[r-(1 << w)+1][w]), nl);
    }
}