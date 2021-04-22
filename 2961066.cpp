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
string s; ll f[MV], r[MV], p[MV]; int ans; vector<pair<ll, int>> ps;
bool check(int i)
{
    //check for the current prefix palindrome ps[i]
    int len = ps[i].second;
    for(int l = 2; l+len-1 <= sz(s); l++)
    {
        int r = l+len-1;
        if(f[r]-f[l-1]*p[len] == ps[i].first) return true;
    }
    return false;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(s); p[0] = 1;
    for(int i = 1; i <= sz(s); i++) { f[i] = f[i-1]*seed + s[i-1] - 'a'; p[i] = p[i-1]*seed; }
    for(int i = sz(s); i > 0; i--) r[i] = r[i+1]*seed + s[i-1] - 'a';
    //ps tracks palindrome hashes of the form (hash, length)
    for(int i = 1; i < sz(s); i++)
    {
        ll h1 = f[i], h2 = r[1]-r[i+1]*p[i];
        if(h1 == h2) ps.pb({h1, i});
    }
    //f(x): whether the prefix palindrome with length x appears at least twice
    //this is always true on the left side, then false on the right side because prefix palindromes
    //encapsulate each other (i.e. a longer prefix palindrome which appears >= 2 times will definitely make
    //all shorter prefix palindromes appear at least twice)
    //find the len which is on the left border on the 'true' side i.e. the longest prefix palindrome
    //that appears at least twice
    int lo = 0, hi = sz(ps) - 1;
    while(lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(check(mid))
        {
            ans = ps[mid].second; lo = mid+1;
        }
        else hi = mid-1;
    }
    pr(ans);
}