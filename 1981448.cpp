#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MV = 1e5+1;

int n, p[MV+1], cnt = 1; string c, a, b;
unordered_map<string, int> mp;

int parent_find(int x)
{
    if (p[x] != x)
    {
        p[x] = parent_find(p[x]);
    }
    return p[x];
}

bool connected(int x, int y) { return parent_find(x) == parent_find(y); }

void merge(int x, int y)
{
    if(!connected(x, y)) p[parent_find(x)] = parent_find(y);
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        scan(n); mp.clear(); cnt = 1; for(int i = 1; i <= MV; i++) p[i] = i;
        for(int i = 0; i < n; i++)
        {
            scan(c, a, b);
            if(mp.find(a) == mp.end()) { mp[a] = cnt; cnt++; }
            if(mp.find(b) == mp.end()) { mp[b] = cnt; cnt++; }
            if(c == "p") merge(mp[a], mp[b]);
            else print(connected(mp[a], mp[b]) ? "connected" : "not connected", nl);
        }
    }
}