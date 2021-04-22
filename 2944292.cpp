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
typedef unsigned long long ll;
typedef pair<int, int> pii;
const int MV = 1e5+2;
const ll seed = 131;

//store a forward hash and reverse hash
string s; ll f[MV], r[MV], p[MV]; int ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(s); p[0] = 1;
    for(int i = 1; i <= sz(s); i++) { f[i] = f[i-1]*seed + s[i-1]; p[i] = p[i-1]*seed; }
    for(int i = sz(s); i > 0; i--) r[i] = r[i+1]*seed + s[i-1];
    for(int len = 1; len < sz(s); len++)
    {
        //check if s[1...i] is a palindrome
        ll h1 = f[len], h2 = r[1]-r[len+1]*p[len];
        if(h1 == h2)
        {
            for(int i = len+1; i <= sz(s); i++)
            {
                if(f[i]-f[i-len]*p[len] == h1) { ans = len; break; }
            }
        }
    }
    pr(ans);
}