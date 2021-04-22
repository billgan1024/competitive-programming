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
const ll A = 911382323, B = 972663749;

ll p[5001], h[5001]; string s; unordered_map<ll, int> longest;
unordered_set<ll> ans;
ll getSubHash(int l, int r)
{
    return ((h[r] - ((h[l-1]*p[r-l+1] % B) + B ) % B) % B + B )% B;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(s); p[0] = 1;

    for(int i = 1; i <= sz(s); i++)
    {
        p[i] = (p[i-1]*A)%B; h[i] = (h[i-1]*A + s[i-1])%B;
    }
    //i = length of section
    //j = phase shift of section
    //k = iterator of section
    for(int i = 1; i <= sz(s)/2; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            ll prev = -1; int cnt = 0;
            for(int k = j; k <= sz(s)-i+1; k += i)
            {
                ll sub = getSubHash(k, k+i-1);
                if(sub == prev)
                {
                    cnt++;
                    if(cnt > longest[sub])
                    {
                        longest[sub] = cnt;
                        ans.insert(getSubHash(k-i*cnt, k+i-1));
                    }
                }
                else cnt = 0;
                prev = sub;
            }
        }
    }
    print(sz(ans));
}