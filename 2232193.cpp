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

int t, m; deque<string> q; string name, dir;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(t, m);
    for(int i = 0; i < t; i++)
    {
        sc(name, dir);
        if(dir == "in") q.pb(name);
        else
        {
            if(q.empty()) continue;
            if(q.back() == name) q.pop_back();
            else if(q.front() == name && m > 0) { q.pop_front(); m--; }
        }
    }
    while(!q.empty()) { pr(q.front(), nl); q.pop_front(); }
}