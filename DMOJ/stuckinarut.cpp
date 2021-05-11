//
// Created by billg on 12/19/2020.
//

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
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

struct cow
{
    int x, y, id;
};
bool ncmp(cow p, cow q) { return p.x < q.x; }
bool ecmp(cow p, cow q) { return p.y < q.y; }
int n, ans[50]; bool eastBlocked[50];  vector<cow> north, east;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    sc(n);
    for(int i = 0; i < n; i++)
    {
        char c; int x, y; sc(c, x, y);
        if(c == 'N') north.pb({x, y, i}); else east.pb({x, y, i});
    }
    sort(north.begin(), north.end(), ncmp); sort(east.begin(), east.end(), ecmp);
    ms(ans, INF);
    for(cow c : north)
    {
        for(cow d : east)
        {
            if(eastBlocked[d.id]) continue;
            int vdis = d.y-c.y, hdis = c.x-d.x;
            if(vdis < 0 || hdis < 0) continue;
            //check if c blocks d or d blocks c or neither (POI of lines is (c.x, d.y)
            if(vdis == hdis) continue;
            else if(vdis > hdis)
            {
                //cow c got blocked
                ans[c.id] = vdis; break;
            }
            else
            {
                //cow d got blocked
                eastBlocked[d.id] = true; ans[d.id] = hdis;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(ans[i] > 1e9) pr("Infinity", nl);
        else pr(ans[i], nl);
    }
}