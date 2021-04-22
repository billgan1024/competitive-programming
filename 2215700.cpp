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
const int MV = 1e6+2;

int n, m, j, a[MV], ans[MV]; deque<int> q;
int main()
{
    //start at square 0, can only jump up to square i+j, target is square n+1
    //ans[i]: min number of time needed to jump to square i (ans[0] = 0)
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m, j);
    ms(a, INF); a[0] = a[n+1] = 0;
    if(j == 0) { pr(-1); return 0; }
    for(int i = 0, p, t; i < m; i++) { sc(p, t); a[p] = t; }
    for(int l = 0, r = 0; r <= n; r++)
    {
        //ans[r+1] = max(a[r+1], min(a[r]...a[r-j+1]))
        //update sliding window
        while(!q.empty() && ans[r] <= ans[q.back()]) q.pop_back();
        q.pb(r); if(r-l+1 > j) l++;
        if(!q.empty() && q.front() < l) q.pop_front();
        ans[r+1] = max(ans[q.front()], a[r+1]);
    }
    pr(ans[n+1] > 1e9 ? -1 : ans[n+1]);
}