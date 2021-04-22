#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> freq; unordered_set<int> keys; int n, ans, num, len[4001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> n;
    for(int i = 0, l; i < n; i++)
    {
        cin >> l; keys.insert(l); freq[l]++;
    }
    for(int i = 2; i <= 4000; i++)
    {
        int count = 0;
        if(i % 2 == 0)
        {
            for(int x = 1; x < i/2; x++)
            {
                count += min(freq[x], freq[i-x]);
            }
            count += freq[i/2]/2;
        }
        else
        {
            for(int x = 1; x <= i/2; x++)
            {
                count += min(freq[x], freq[i-x]);
            }
        }
        len[i] = count;
    }
    for(int i = 2; i <= 4000; i++)
    {
        if(len[i] > ans) { ans = len[i]; num = 1; }
        else if(len[i] == ans) { num++; }
    }
    cout << ans << " " << num;
}