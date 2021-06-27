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
const int MV = 2e5+1;
const ll A = 131, AMOD = 1e9+9;
const ll B = 31, BMOD = 1e9+7;

string n, s; ll h[MV], h2[MV], p[MV], p2[MV]; int f[26], w[26]; unordered_set<ll> ans;
//note that hashes are mod 2^64
ll hsh(int l, int r) { return (h[r] - ((h[l-1] * p[r-l+1]) % AMOD) + AMOD) % AMOD; }
ll hsh2(int l, int r) { return (h2[r] - ((h2[l-1] * p2[r-l+1]) % BMOD) + BMOD) % BMOD; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, s); p[0] = 1; p2[0] = 1;
    for(int i = 1; i <= sz(s); i++)
    {
        p[i] = (p[i-1] * A) % AMOD; p2[i] = (p2[i-1] * B) % BMOD;
        h[i] = (h[i-1] * A + s[i-1]) % AMOD;
        h2[i] = (h2[i-1] * B + s[i-1]) % BMOD;
    }
    for(char c : n) f[c-'a']++;
    for(int i = 1; i <= sz(s); i++)
    {
        w[s[i-1]-'a']++;
        if(i > sz(n))
        {
            w[s[i-sz(n)-1]-'a']--;
        }
        if(equal(begin(w), end(w), begin(f))) {
            ll t1 = hsh(i-sz(n)+1, i), t2 = hsh2(i-sz(n)+1, i);   
            ans.insert((t1 << 32)|t2);
        } 
    }
    pr(sz(ans));
}