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
const int MV = 5e5;

ll n, m, k; unordered_set<ll> pts; bool ans = true; unordered_map<ll, bool> vis;
void dfs(ll cur)
{
    if(!ans || cur < 0 || cur > n*m-1 || pts.find(cur) == pts.end() || vis[cur]) return;
    vis[cur] = true;
    if(cur < m || (cur % m) == m-1) { ans = false; return; }
    dfs(cur-m); dfs(cur+m);
    if(cur % m != 0) { dfs(cur-1); dfs(cur-m-1); dfs(cur+m-1); }
    if(cur % m != m-1) { dfs(cur+1); dfs(cur-m+1); dfs(cur+m+1); }
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, k);
    for(int i = 0, r, c; i < k; i++)
    {
        scan(r, c); pts.insert(m*(r-1) + c-1);
    }
    for(ll i = (n-1)*m; i < n*m; i++) dfs(i);
    for(ll i = 0; i < n*m; i += m) dfs(i);
    print(ans ? "YES" : "NO");
}