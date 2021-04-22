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

int T, n; deque<int> q, q2, ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(T);
    for(int t = 1; t <= T; t++)
    {
        sc(n); bool v1 = true, v2 = true; q.clear(); ans.clear(); q2.clear();
        for(int i = 1, x; i <= n; i++) { sc(x); q.pb(x); q2.pb(x); }
        ans.pb(q.front()); q.pop_front();
        while(!q.empty())
        {
            if(q.front() == ans.front()-1)
            {
                ans.push_front(q.front()); q.pop_front();
            }
            else if(q.back() == ans.front()-1)
            {
                ans.push_front(q.back()); q.pop_back();
            }
            else if(q.front() == ans.back()+1)
            {
                ans.pb(q.front()); q.pop_front();
            }
            else if(q.back() == ans.back()+1)
            {
                ans.pb(q.back()); q.pop_back();
            }
            else
            {
                v1 = false; break;
            }
        }
        ans.clear(); ans.pb(q2.back()); q2.pop_back();
        while(!q2.empty())
        {
            if(q2.front() == ans.front()-1)
            {
                ans.push_front(q2.front()); q2.pop_front();
            }
            else if(q2.back() == ans.front()-1)
            {
                ans.push_front(q2.back()); q2.pop_back();
            }
            else if(q2.front() == ans.back()+1)
            {
                ans.pb(q2.front()); q2.pop_front();
            }
            else if(q2.back() == ans.back()+1)
            {
                ans.pb(q2.back()); q2.pop_back();
            }
            else
            {
                v2 = false; break;
            }
        }
        pr("Case #", t, ((v1 || v2) ? ": yes" : ": no"), nl);
    }
}