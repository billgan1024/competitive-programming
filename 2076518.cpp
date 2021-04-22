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

ll n, m, s[200001], ans;
ll sum(int l, int r) { return s[r]-s[l-1]; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 1, a; i <= n; i++) { scan(a); s[i] = s[i-1] + a; }
    int ans = 0, l = 1, r = 1;
    while(r <= n)
    {
        if(sum(l, r) < m)
        {
            ans = max(ans, r-l+1);
            r++;
        }
        else
        {
            l++; if(l > r) r++;
        }
    }
    print(ans);
}