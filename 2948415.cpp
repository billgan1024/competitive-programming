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
const int MV = 1e5+1;

int n, r[MV], deg[MV]; set<pii> p;
int main()
{
    //set tracks the current potential supervisors
    //once a node gets two people to supervise, remove it from the set
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++) sc(r[i]);
    p.insert({r[1], 1});
    for(int i = 2; i <= n; i++)
    {
        auto it = p.lower_bound({r[i], i});
        if(it == p.begin()) { pr("NO", nl); return 0; }
        it--; pii s = *it;
        deg[s.second]++; if(deg[s.second] == 2) p.erase(it);
        p.insert({r[i], i});
    }
    pr("YES", nl);
}