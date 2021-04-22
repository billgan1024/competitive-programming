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
const int MV = 1e6+2;

int n; ll a[MV], m[MV], s[MV], ans;
ll sum(int l, int r) { return max(s[r]-s[l-1], 0LL); }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) { scan(a[i]); s[i] = s[i-1] + a[i]; }
    for(int i = n; i > 0; i--) m[i] = max(a[i], m[i+1]);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 0) continue; if(m[i+1] == 0) break;
        for(int j = i+1; j <= n; j++)
        {
            if(a[j] == m[i+1] || a[j] >= a[i])
            {
                ans += min(a[i], a[j])*(j-i-1) - sum(i+1, j-1);
                i = j-1; break;
            }
        }
    }
    print(ans);
}