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
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;

string s, ans = "{";
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(s);
    for(int i = 1; i < sz(s)-1; i++)
    {
        for(int j = i+1; j < sz(s); j++)
        {
            string a = s.substr(0, i), b = s.substr(i, j-i), c = s.substr(j);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            ans = min(ans, a+b+c);
        }
    }
    pr(ans);
}