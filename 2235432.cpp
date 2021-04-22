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
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k);
    //dp[i] = a[i] + best[q.front()]
    //best[i] = dp[i-1] - s[i]
    //sliding window is from i-k to i
    //base case is for the first k dp[i]: q.pb(0) ensures that taking all the elements
    //is an option (not just relying on the recurrence)
    q.pb(0);
    for(int i = 1; i <= n; i++)
    {
        sc(s[i]); s[i] += s[i-1];
        best[i] = dp[i-1] - s[i];
        if(!q.empty() && q.front() < i-k) q.pop_front();
        while(!q.empty() && best[i] >= best[q.back()]) q.pop_back();
        q.pb(i);
        dp[i] = s[i] + best[q.front()];
    }
    pr(dp[n]);
}