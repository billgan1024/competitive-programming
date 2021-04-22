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
const int MV = 2e6+2;

ll n, a[MV], pre[MV], t1[MV], t2[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++)
    {
        scan(a[i]); pre[i] = pre[i-1] + a[i]; t1[i] = t1[i-1] + a[i]*i;
    }
    for(int i = n; i > 0; i--) t2[i] = t2[i+1] + a[i]*(n-i+1);
    for(int i = 1; i <= n; i++)
    {
        ll ans = 0; int cnt = n-i+1;
        if(cnt >= i)
        {
            int l = i-1, r = n-i+2;
            ans = t1[l] + t2[r] + i*(pre[r-1] - pre[l]);
        }
        else
        {
            int l = cnt, r = n-cnt+1;
            ans = t1[l] + t2[r] + cnt*(pre[r-1] - pre[l]);
        }
        print(ans, nl);
    }
}