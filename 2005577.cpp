#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e6+1; const ll A = 911382323, B = 972663749;

string s; ll p[MV], h[MV], b[MV]; int ans;
ll getPreHash(int l, int r)
{
    return ((h[r] - ((h[l-1]*p[r-l+1] % B) + B) % B) % B + B) % B;
}
ll getSufHash(int l, int r)
{
    return ((b[r] - ((b[l-1]*p[r-l+1] % B) + B) % B) % B + B) % B;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); p[0] = 1;
    for(int i = 1; i < MV; i++) p[i] = (p[i-1]*A)%B;
    for(int t = 0; t < 10; t++)
    {
        scan(s); ms(h); ms(b); int n = sz(s); ans = n-1;
        if(s[0] == s[1] || s[n-1] == s[n-2]) ans = n-2;
        for(int i = 1; i <= n; i++)
        {
            h[i] = (h[i-1]*A + s[i-1])%B;
        }
        for(int i = 1; i <= n; i++) b[i] = (b[i-1]*A + s[n-i])%B;
        for(int i = 2; i <= n-1; i++)
        {
            int dis = min(i-1, n-i);
            ll left = getPreHash(i-dis, i-1), right = getSufHash(n-i-dis+1, n-i);
            if(left == right)
            {
                ans = min(ans, abs(n-2*i+1));
            }
        }
        for(int i = 2; i <= n-2; i++)
        {
            //pretend that there are two roots: i and i+1
            if(s[i-1] != s[i]) continue;
            int dis = min(i-1, n-(i+1));
            ll left = getPreHash(i-dis, i-1), right = getSufHash(n-(i+1)-dis+1, n-(i+1));
            if(left == right)
            {
                ans = min(ans, abs(n-(i+1)-i+1));
            }
        }
        print(ans, nl);
    }
}