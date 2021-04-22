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
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, m, adj[18][18], dp[18][1<<18];
int f(int dest, int mask)
{
    if(dest == 0) return 0;
    if(dp[dest][mask] > 0) return dp[dest][mask];
    dp[dest][mask] = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(mask & (1 << i) && adj[i][dest] > 0)
        {
            dp[dest][mask] = max(dp[dest][mask], adj[i][dest] + f(i, mask ^ (1 << dest)));
        }
    }
    return dp[dest][mask];
}
int main()
{
    //f(dest, subset): longest path from 0 to dest if you are only allowed to travel on nodes
    //in the subset at most once, and dest must be the last node you visit
    //f(dest, subset) = -inf if dest is impossible to reach
    //O(n*2^n) states, O(n) time for each state -> O(n^2*2^n) complexity
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0, s, d, l; i < m; i++) { scan(s, d, l); adj[s][d] = l; }
    print(f(n-1, (1<<n)-1));
}