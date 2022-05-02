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
const int MV = 1e6+1;
const ll seed1 = 131, mod1 = 1e9+9;
const ll seed2 = 31, mod2 = 1e9+7;

//find longest suffix of a that is a prefix of b
string a, b; ll ha1[MV], ha2[MV], hb1[MV], hb2[MV], p1[MV], p2[MV]; int ans;
ll hsh1(ll h[], int l, int r) { 
    return ((h[r]-h[l-1]*p1[r-l+1])%mod1+mod1)%mod1; 
}
ll hsh2(ll h[], int l, int r) { return ((h[r]-h[l-1]*p2[r-l+1])%mod2+mod2)%mod2; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(a, b); p1[0] = p2[0] = 1;
    for(int i = 1; i < MV; i++) {
        p1[i] = (p1[i-1] * seed1) % mod1;
        p2[i] = (p2[i-1] * seed2) % mod2;
    }
    for(int i = 1; i <= sz(a); i++) {
        ha1[i] = (ha1[i-1] * seed1 + a[i-1]) % mod1; 
        ha2[i] = (ha2[i-1] * seed2 + a[i-1]) % mod2; 
    }
    for(int i = 1; i <= sz(b); i++) {
        hb1[i] = (hb1[i-1] * seed1 + b[i-1]) % mod1; 
        hb2[i] = (hb2[i-1] * seed2 + b[i-1]) % mod2; 
    }
    for(int i = 1; i <= min(sz(a), sz(b)); i++)
    {
        //check if the last i chars of a and first i chars of b are equal
        if(hsh1(ha1, sz(a)-i+1, sz(a)) == hsh1(hb1, 1, i) && hsh2(ha2, sz(a)-i+1, sz(a)) == hsh2(hb2, 1, i)) ans = i;
    }
    pr(a + b.substr(ans));
}