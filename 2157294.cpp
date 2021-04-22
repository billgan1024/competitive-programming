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
typedef pair<ll, ll> pll;
const ll MV = 1e6;

//use hashing for midpoint detection lol (dilate the grid by 2x to make the midpoints on lattice points)
int n, x[1000], y[1000]; ll ans; unordered_map<ll, vector<ll>> midpoints;
ll f(ll x, ll y) { return (4e6+1)*y + x; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++) { scan(x[i], y[i]); x[i] = 2*(x[i] + MV); y[i] = 2*(y[i] + MV); }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            ll mx = (x[i]+x[j])/2, my = (y[i]+y[j])/2, dx = x[i]-x[j], dy = y[i]-y[j];
            midpoints[f(mx, my)].pb(dx*dx + dy*dy);
        }
    }
    for(auto p : midpoints)
    {
        //get number of pairs of lines w/ the same length and midpoint
        for(int i = 0; i < sz(p.second); i++)
        {
            for(int j = i+1; j < sz(p.second); j++)
            {
                if(p.second[i] == p.second[j]) ans++;
            }
        }
    }
    print(ans);
}