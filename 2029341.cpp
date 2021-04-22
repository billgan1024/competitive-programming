#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e6+2;

int n, m, j, p[MV], s[MV], t; vector<pii> mud; set<int> o; set<int, greater<int>> o2;

int pfind(int x)
{
    if(p[x] != x) p[x] = pfind(p[x]);
    return p[x];
}

bool merge(int x, int y)
{
    int fx = pfind(x), fy = pfind(y);
    if(fx != fy)
    {
        if(s[fx] < s[fy]) swap(fx, fy);
        s[fx] += s[fy];
        p[fy] = fx; return true;
    }
    return false;
}

bool connected(int x, int y) { return pfind(x) == pfind(y); }

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, j);
    for(int i = 0; i < n+2; i++) { p[i] = i; s[i] = 1; }
    for(int i = 0, pi, ti; i < m; i++)
    {
        scan(pi, ti); mud.pb({ti, pi});
    }
    sort(mud.begin(), mud.end());
    //start node is 0, end node is n+1
    if(j == n+1 || n == 0) { print(0); return 0; }
    else if(j == 0) { print(-1); return 0; }
    o.insert(0); o.insert(n+1); o2.insert(0); o2.insert(n+1);
    for(pii c : mud)
    {
        t = c.first; o.insert(c.second); o2.insert(c.second);
        int low = *o.lower_bound(c.second - j), high = *o2.lower_bound(c.second + j);
        merge(c.second, low); merge(c.second, high);
        if(connected(0, n+1)) { print(t); return 0; }
    }
    print(-1);
}