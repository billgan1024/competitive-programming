#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
const int MV = 2e5+1;
const int seed = 131, seed2 = 67, mod = 1e9+9, mod2 = 1e9+7;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    size_t operator()(ll x) const { return x ^ RANDOM; }
};
gp_hash_table<ll, int, chash> f; int n; ll h[MV], h2[MV], ans; string s;
bool check(int len)
{
    f.clear(); ll p = 1, p2 = 1;
    for(int i = 1; i <= len; i++) { p = (p * seed) % mod; p2 = (p2 * seed2) % mod2; }
    for(int i = 1; i+len-1 <= n; i++)
    {
        //take both hashes mod 2^64 and mod 1e9+7 (remember both of them are in the correct range)
        ll hsh = (h[i+len-1]-(h[i-1]*p % mod) + mod) % mod;
        ll hsh2 = (h2[i+len-1]-(h2[i-1]*p2 % mod2) + mod2) % mod2;
        ll nxt = hsh << 32 | hsh2;
        f[nxt]++; if(f[nxt] == 2) return true;
    }
    return false;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, s);
    for(int i = 1; i <= n; i++)
    {
        h[i] = (h[i-1]*seed + s[i-1]-'a') % mod;
        h2[i] = (h2[i-1]*seed2 + s[i-1]-'a') % mod2;
    }
    //for(int i = 1; i <= n; i++) pr(h2[i], sp);
    int lo = 1, hi = n;
    while(lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(check(mid))
        {
            ans = mid; lo = mid+1;
        }
        else hi = mid-1;
    }
    pr(ans);
}