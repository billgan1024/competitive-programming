#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e3+1;
int n, m, k; ll p[MV], s[MV], v[MV], d[MV], c[MV], dp[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m, k);
    for(int i = 1; i <= n; i++) sc(p[i], s[i]);
    //for the 0/k knapsack part, split the deals into powers of 2 such that you can only use each one once
    //total time complexity is O(k*n^2log^2n) (roughly)
    for(int i = 1, t; i <= m; i++)
    {
        //v[i] = total value of the deal, d[i] = total cost of the deal, c[i] = deals available
        sc(v[i], t, d[i], c[i]); v[i] *= s[t];
    }
    //basically, dp[i] represents the max value using up to i dollars for all of the original n items
    //for each item try and improve dp[i] for all 1 <= i <= k by attempting to buy that item
    for(int i = 1; i <= n; i++)
    {
        for(int j = p[i]; j <= k; j++) dp[j] = max(dp[j], dp[j-p[i]] + s[i]);
    }
    //each deal can be split up into log n micro-deals
    //basically these microdeals can represent all amounts of the deal taken but they only take up
    //log n space
    //also, the max count of each micro-deal goes up to log n
    for(int cur = 1; cur <= m; cur++)
    {
        int lft = 31 - clz(c[cur]), cnt = 1;
        for(int i = lft-1; i > 0; i--)
        {
            ll val = v[cur] << i, cost = d[cur] << i;
            for(int j = k; j >= 0; j--)
            {
                for(int l = j-cost, num = 1; num <= cnt && l >= 0; num++, l -= cost)
                {
                    dp[j] = max(dp[j], dp[l] + val*num);
                }
            }
            if(c[cur] & (1 << i)) cnt++;
        }
        //finally, check the single deal
        if(c[cur] != 1) cnt += popcnt(c[cur]);
        for(int j = k; j >= 0; j--)
        {
            for(int l = j-d[cur], num = 1; num <= cnt && l >= 0; num++, l -= d[cur])
            {
                dp[j] = max(dp[j], dp[l] + v[cur]*num);
            }
        }
    }
    pr(dp[k]);
}