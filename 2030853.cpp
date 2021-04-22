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

int N, H; ll dp[5001][2]; npc a[5001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(N, H);
    for(int i = 1; i <= N; i++)
    {
        scan(a[i].g, a[i].h, a[i].q, a[i].t);
    }

    for(int i = 1; i <= N; i++)
    {
        //update the cells if we need to visit npc i this round (dp[j][1])
        for(int j = a[i].h; j <= H; j++) dp[j][1] = a[i].g + dp[j-a[i].h][0];
        for(int j = a[i].t + a[i].h; j <= H; j++) dp[j][1] = max(dp[j][1], a[i].q + dp[j-a[i].t][1]);
        //at the end, dp[j][0] stores the best answer for the first i items
        for(int j = 1; j <= H; j++) dp[j][0] = max(dp[j][0], dp[j][1]);
    }
    print(dp[H][0]);
}