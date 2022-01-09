#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;

struct DP {
    vector<int> dp;
 
    DP() : dp({1}) {}
 
    void extend() {
        dp.push_back(dp.back());
    }
 
    int query(int i) {
        return i < (int) dp.size() ? dp[dp.size() - i - 1] : 0;
    }
 
    int size() {
        return (int) dp.size();
    }
 
    int& operator [] (int i) {
        return dp[dp.size() - i - 1];
    }
 
    void swap(DP &other) {
        dp.swap(other.dp);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, d; sc(n, d);
    vector<vector<int>> adj(n);
    for (int i=1; i<n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
 
    vector<DP> dp(n);
 
    auto dfs = [&] (auto &self, int u) -> void {
        for (int v : adj[u]) {
            self(self, v);
            dp[v].extend();
            if (dp[u].size() < dp[v].size())
                dp[u].swap(dp[v]);
            vector<int> ndp(dp[v].size());
            for (int j=0; j<dp[v].size(); j++)
                ndp[j] = max(dp[u].query(max(d - j, j)) + dp[v][j], dp[u][j] + dp[v].query(max(d - j, j)));
            for (int j=dp[v].size()-1; j>=0; j--) {
                if (j + 1 < dp[v].size())
                    ndp[j] = max(ndp[j], ndp[j+1]);
                dp[u][j] = max(dp[u][j], ndp[j]);
            }
        }
    };
 
    dfs(dfs, 0);
    cout << dp[0][0] << "\n";
 
    return 0;
}