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
const int MV = 2e5+2;

int n, m, w = INT_MAX; ll d[MV], k;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, k); d[1] = m; d[n+1] = -m;
    for(int i = 0, a, b; i < m; i++)
    {
        scan(a, b); d[a]--; d[b+1]++;
    }
    for(int i = 1; i <= n+1; i++) d[i] += d[i-1];
    if(k == 0) { print(0); return 0; }
    int l = 1, r = 1; ll sum = d[1];
    while(true)
    {
        if(sum >= k)
        {
            w = min(w, r-l+1);
            sum -= d[l]; l++;
            if(l > r) { r++; sum += d[r]; }
        }
        else { r++; sum += d[r]; }
        if(r > n) break;
    }
    print(w == INT_MAX ? -1 : w);
}