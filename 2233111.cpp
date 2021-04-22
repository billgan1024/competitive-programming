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

int n, k; ll s[MV], dp[MV], best[MV]; deque<ll> q;
int main()
{
    //dp[i]: max sum obtainable in the prefix a[1...i]
    //any max sum needs to have a contiguous sum of length 0-k at position i,
    //so dp[i] = max(a[i] - a[i-j] + dp[i-j-1])
    //dp[i] = a[i] + max(dp[i-j-1] - a[i-j])
    //this corresponds to maximizing dp[i-1] - a[i] so use a max deque on the array best[i] = dp[i-1] - a[i]
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k);
    for(int i = 1; i <= n; i++) { sc(s[i]); s[i] += s[i-1]; }
    for(int i = 1; i <= k; i++)
    {
        best[i] = dp[i-1] - s[i]; dp[i] = s[i];
        while(!q.empty() && best[i] >= best[q.back()]) q.pop_back();
        q.pb(i);
    }
    for(int i = k+1; i <= n; i++)
    {
        //dp[i] = max(best[i], ..., best[i-k]) + a[i] so the length of the window is k+1
        if(q.front() < i-k) q.pop_front();
        //update window
        best[i] = dp[i-1] - s[i];
        while(!q.empty() && best[i] >= best[q.back()]) q.pop_back();
        q.pb(i);
        dp[i] = s[i] + best[q.front()];
    }
    pr(dp[n]);
}