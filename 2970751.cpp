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
typedef pair<int, pair<int, int>> p;
const int MV = 1e6+1;
const ll seed = 131;

string s, t; int ans; ll h1[MV], needle, pw;
ll hsh(int l, int r) { return h1[r]-h1[l-1]*pw; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(s, t); pw = 1;
    for(int i = 1; i <= sz(t); i++)
    {
        pw *= seed;
        needle *= seed; needle += t[i-1]-'a';
    }
    for(int i = 1; i <= sz(s); i++)
    {
        h1[i] = h1[i-1]*seed + s[i-1]-'a';
    }
    for(int i = sz(t); i <= sz(s); i++)
    {
        ll h = hsh(i-sz(t)+1, i);
        if(h == needle) ans++;
    }
    pr(ans);
}