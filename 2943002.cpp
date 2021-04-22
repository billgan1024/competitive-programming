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
typedef pair<ll, int> pii;
const int MV = 1e6+1;

//only track starting and ending times for linear complexity
//cnt[i]: how many people are using microwaves at a particular time (data point)
int n, m, t; pii p[MV]; vector<pii> cnt; ll ans; priority_queue<ll, vector<ll>, greater<ll>> r; queue<int> q;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m, t);
    for(int i = 0; i < m; i++) sc(p[i].first, p[i].second);
    sort(p, p+m); p[m] = {1e15, 0};
    //cur = current time, c = index of current person
    cnt.pb({0, 0});
    ll cur = p[0].first; int c = 0;
    while(c < m)
    {
        while(!r.empty() && r.top() == cur) r.pop();
        while(sz(r) < n && !q.empty()) { r.push(cur + q.front()); q.pop(); }
        if(cur == p[c].first)
        {
            if(sz(r) >= n) q.push(p[c].second);
            else r.push(cur + p[c].second);
        }
        cnt.pb({cur, sz(r)});
        if(r.empty() || r.top() > p[c+1].first) cur = p[++c].first;
        else cur = r.top();
    }
    //need a last data point for the case that all other windows are not suitable
    cnt.pb({1e15, 0}); ll cons = 0;
    for(int i = 1; i < sz(cnt); i++)
    {
        ll num = cnt[i].first-cnt[i-1].first;
        if(cnt[i-1].second < n) cons += num; else cons = 0;
        if(cons >= t) { pr(cnt[i].first-cons); break; }
    }
}