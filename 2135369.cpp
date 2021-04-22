#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, k, f[26]; ll ans; string s;
ll fact(int x) { return x == 0 ? 1 : x * fact(x-1); }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k, s);
    if(k == 0)
    {
        for(char c : s) f[c-'a']++; ans = fact(n);
        for(int i : f) ans /= fact(i);
    }
    else if(k == 1)
    {
        for(char c : s) { if(c != '*') f[c-'a']++; }
        for(int t = 0; t < 26; t++)
        {
            f[t]++; ll cnt = fact(n);
            for(int i : f) cnt /= fact(i);
            ans += cnt; f[t]--;
        }
    }
    else if(k == 2)
    {
        for(char c : s) { if(c != '*') f[c-'a']++; }
        for(int t = 0; t < 26; t++)
        {
            f[t]++;
            for(int u = t; u < 26; u++)
            {
                f[u]++; ll cnt = fact(n);
                for(int i : f) cnt /= fact(i);
                ans += cnt; f[u]--;
            }
            f[t]--;
        }
    }
    print(ans);
}