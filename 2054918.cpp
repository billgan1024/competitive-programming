#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const ll A = 911382323, B = 972663749;

int n, dp[2001]; ll h[2001], p[2001], val; vector<ll> str[2001]; string s; vector<int> valid;
ll getHash(int l, int r)
{
    return ((h[r] - ((h[l-1]*p[r-l+1] % B) + B) % B) % B + B) % B;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n); p[0] = 1;
    for(int i = 1; i <= 2000; i++) p[i] = (p[i-1] * A) % B;
    for(int t = 0; t < n; t++)
    {
        scan(s); val = 0; if(sz(s) > 2000) continue;
        for(int i = 1; i <= sz(s); i++) val = (val*A + s[i-1]) % B;
        str[sz(s)].pb(val);
    }
    for(int t = 0; t < 10; t++)
    {
        scan(s); valid.clear(); valid.pb(0);
        for(int i = 1; i <= sz(s); i++)
        {
            //dp[i] = min(1 + dp[j], where the characters between j and h form a legal word)
            h[i] = (h[i-1] * A + s[i-1]) % B; dp[i] = 1e9;
            for(int j : valid)
            {
                int len = i-j;
                for(ll w : str[len])
                {
                    if(getHash(j+1, i) == w) dp[i] = min(dp[i], 1+dp[j]);
                }
            }
            if(dp[i] != 1e9) valid.pb(i);
        }
        print(dp[sz(s)]-1, nl);
    }
}