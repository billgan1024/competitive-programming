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
const int MV = (1 << 23) + 2;

int n, k, p[MV]; ll a[MV], dp[MV]; deque<int> q; stack<int> ans;
int main()
{
    //start at stone 0, go to stone n+1
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k);
    for(int i = 1; i <= n; i++) sc(a[i]);
    //dp[i]: min cost to jump to stone i = a[i] + min(dp[i-k]...dp[i-1])
    //p[i]: the stone that you came from in the optimal sequence of moves to reach square i
    for(int r = 1; r <= n+1; r++)
    {
        //calculate dp[r] and p[r], first update sliding window to [r-k, r-1]
        //you want to jump from a later square if two squares have the same dp value
        if(q.front() < r-k) q.pop_front();
        while(!q.empty() && dp[r-1] <= dp[q.back()]) q.pop_back();
        q.pb(r-1);
        dp[r] = a[r] + dp[q.front()]; p[r] = q.front();
    }
    pr(dp[n+1], nl);
    for(int i = p[n+1]; i != 0; i = p[i]) ans.push(i);
    while(!ans.empty()) { pr(ans.top(), sp); ans.pop(); }
}