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
const int MV = 2e5+1;

int n, k; ll ans, a[MV]; deque<ll> q;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k);
    for(int i = 1; i <= n; i++) { sc(a[i]); a[i+n] = a[i]; }
    for(int i = 1; i <= 2*n; i++) a[i] += a[i-1];
    for(int l = 1, r = 1; r <= 2*n; r++)
    {
        //update sliding window range
        //note that sliding window is at [l, r] but has min of a[l-1] to a[r-1]
        if(!q.empty() && q.front() < l) q.pop_front();
        while(!q.empty() && a[q.back()-1] >= a[r-1]) q.pop_back();
        q.pb(r);
        //update answer with min sum in the window, then increase l if necessary
        ans = max(ans, a[r] - a[q.front()-1]);
        if(r-l+2 > k) l++;
    }
    pr(ans);
}