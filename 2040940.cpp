#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define v first
#define w second
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

struct npc
{
    ll g, h, q, t;
};

int N, H; ll dp[2][5001]; int g[5001], h[5001], q[5001], t[5001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(N, H);
    for(int i = 1; i <= N; i++)
    {
        scan(g[i], h[i], q[i], t[i]);
    }

    for(int i = 1; i <= N; i++)
    {
        //combine 0-1 knapsack with unlimited knapsack
        //0-1: loop left to right force the guy to visit npc, store in dp[1][j]
        //unlimited: only build unlimited visits for the current row cells that have definitely visited the npc, update dp[1][j] in linear time using
        //unlimited items (in the same row cuz you can repeatedly do the quest)
        //at the end, make dp[0][j] represent the best answers in the dp row for npc i (best value for the first i npcs, whether you visit this guy or not)
        for(int j = h[i]; j <= H; j++) dp[1][j] = dp[0][j-h[i]] + g[i];
        for(int j = h[i] + t[i]; j <= H; j++) dp[1][j] = max(dp[1][j], dp[1][j-t[i]] + q[i]);
        for(int j = 0; j <= H; j++) dp[0][j] = max(dp[0][j], dp[1][j]);
    }
    print(dp[0][H]);
}