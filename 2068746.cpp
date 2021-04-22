#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define c first
#define v second
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int t, n, b, dp[3001], ans; vector<pii> p[6];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(t, n);
    for(int i = 0, ci, vi, ti; i < n; i++)
    {
        scan(ci, vi, ti); p[ti].pb({ci, vi});
    }
    scan(b);
    //dp[i][j] = max profit for a valid configuration of a computer requiring 1 of each type from 1 to i
    //and with a budget of j (dp[i][j] = -1 if this is not possible)
    for(int i = 1; i <= t; i++)
    {
        for(int j = b; j > 0; j--)
        {
            bool found = false;
            for(pii x : p[i])
            {
                //EACH knapsack transition needs to select a part of type i, even though it may
                //decrease profits
                //if you cannot find a suitable previous slot, it means that dp[i][j] cannot be fulfilled
                //so block this slot (also means that future dp cells cannot use this one as a transition)
                if(j >= x.c && dp[j-x.c] != -1)
                {
                    if(!found) { dp[j] = x.v + dp[j-x.c]; found = true; }
                    else dp[j] = max(dp[j], x.v + dp[j-x.c]);
                }
            }
            if(!found) dp[j] = -1;
        }
    }
    print(dp[b]);
}