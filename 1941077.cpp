#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans, base = 131; string s; unordered_map<ll, int> dp;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s; ll pre = 0, suf = 0, pw = 1; int best = 1;
        for(int j = 0; j < s.size(); j++)
        {
            pre = pre*base + s[j]; suf = suf + s[s.size()-j-1] * pw;  pw *= base;
            if(pre == suf)
            {
                if(dp.find(pre) != dp.end()) best = max(best, dp[pre] + 1);
            }
        }
        dp[pre] = best;
    }
    for(auto i : dp) ans = max(ans, i.second);
    cout << ans;
}