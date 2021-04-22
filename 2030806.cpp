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
    //dp[j][0] = max profit for j capacity (first i npcs) and you CANNOT visit npc i
    //dp[j][1] = max profit for j capacity (first i npcs) and you MUST visit npc i
    //since the dp implicitly tracks the previous row, propagate answers at the end because
    //the next npc does not care whether you visit npc i-1
    //thus we don't need to update dp[j][0] because by definition, we cannot visit npc i to fill dp[j][0]
    //but we need to update dp[j][1] because we must visit npc i so we need to check if visiting this
    //npc will improve our answers for the max profit for j capacity
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= H; j++) dp[j][1] = -1;
        for(int j = 1; j <= H; j++)
        {
            //visit this npc
            if(j >= a[i].h) dp[j][1] = max(dp[j][1], a[i].g + dp[j-a[i].h][0]);
            if(j >= a[i].t && dp[j-a[i].t][1] != -1) dp[j][1] = max(dp[j][1], a[i].q + dp[j-a[i].t][1]);
        }
        for(int j = 1; j <= H; j++) dp[j][0] = dp[j][1] = max(dp[j][0], dp[j][1]);
    }
    print(dp[H][1]);
}