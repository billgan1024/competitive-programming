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
const ll seed = 131, MV = 1e6+1;

//find longest suffix of a that is a prefix of b
string a, b; ll ha[MV], hb[MV], p[MV]; int ans;
ll hsh(ll h[], int l, int r) { return h[r]-h[l-1]*p[r-l+1]; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(a, b); p[0] = 1;
    for(int i = 1; i <= sz(a); i++)
    {
        ha[i] = ha[i-1] * seed + a[i-1]; p[i] = p[i-1] * seed;
    }
    for(int i = 1; i <= sz(b); i++) hb[i] = hb[i-1] * seed + b[i-1];
    for(int i = 1; i <= min(sz(a), sz(b)); i++)
    {
        //check if the last i chars of a and first i chars of b are equal
        if(hsh(ha, sz(a)-i+1, sz(a)) == hsh(hb, 1, i)) ans = i;
    }
    pr(a + b.substr(ans));
}