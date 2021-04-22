#include <bits/stdc++.h>
using namespace std;
int k, x, t, ans, mp[4], p[21], freq[21];
int main()
{
    //mp stores 4 items on the menu
    cin.sync_with_stdio(0); cin.tie(0); cin >> k;
    for(int i = 1; i <= k; i++) cin >> p[i]; cin >> x;
    for(int i = 0; i < 4; i++) cin >> mp[i]; cin >> t;
    for(int i = 0, c; i < t; i++)
    {
        cin >> c; freq[c]++;
    }
    while(freq[mp[0]] > 0 || freq[mp[1]] > 0 || freq[mp[2]] > 0 || freq[mp[3]] > 0)
    {
        int cost = (freq[mp[0]] > 0)*p[mp[0]] + (freq[mp[1]] > 0)*p[mp[1]] + (freq[mp[2]] > 0)*p[mp[2]] + (freq[mp[3]] > 0)*p[mp[3]];
        if(x < cost) {
            ans += x;
            freq[mp[0]] -= freq[mp[0]] > 0; freq[mp[1]] -= freq[mp[1]] > 0;
            freq[mp[2]] -= freq[mp[2]] > 0; freq[mp[3]] -= freq[mp[3]] > 0;
        }
        else break;
    }
    for(int i = 1; i <= 20; i++)
    {
        ans += freq[i]*p[i];
    }
    cout << ans;
}