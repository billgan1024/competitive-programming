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

int n, k, r, a[MV], s[MV], ans; deque<int> q;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k, r);
    for(int i = 0, x; i < k; i++) { sc(x); a[x]++; }
    for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    //monotonic deque keeps track of the added cameras in each window
    for(int i = r; i > 0; i--)
    {
        if(s[r] + sz(q) >= 2) break; if(a[i]) continue;
        q.push_front(i); ans++;
    }
    for(int lft = 2, rit = r+1; rit <= n; lft++, rit++)
    {
        if(!q.empty() && q.front() < lft) q.pop_front();
        if(s[rit] - s[lft-1] + sz(q) < 2) { q.pb(rit); ans++; }
    }
    pr(ans, nl);
}