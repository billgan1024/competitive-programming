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
    for(int i = 1; i <= t; i++)
    {
        for(int j = b; j > 0; j--)
        {
            bool found = false;
            for(pii x : p[i])
            {
                if(j >= x.c && dp[j-x.c] != -1)
                {
                    if(!found) { dp[j] = x.v + dp[j-x.c]; found = true; }
                    else dp[j] = max(dp[j], x.v + dp[j-x.c]);
                }
            }
            if(!found) dp[j] = -1;
        }
        //for(int j = 1; j <= b; j++) print(dp[j], sp); print(nl);
    }
    for(int i = 1; i <= b; i++) ans = max(ans, dp[i]);
    print(dp[b]);
}