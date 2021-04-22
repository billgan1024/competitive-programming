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

int n, t, a[20], ans = INT_MAX;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, t);
    for(int i = 0, h; i < n; i++) { scan(h); a[i] = h; }
    for(int i = 1; i < pow(2, n); i++)
    {
        bitset<20> b(i); string s = b.to_string(); int cnt = 0;
        for(int j = 0; j < sz(s); j++)
        {
            if(s[20-j-1] == '1') cnt += a[j];
        }
        if(cnt >= t) ans = min(ans, cnt-t);
    }
    if(ans == INT_MAX) print(-1);
    else print(ans);
}