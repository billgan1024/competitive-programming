#include <bits/stdc++.h>
using namespace std;
int test, n;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> test >> n;
    int a[n], b[n];
    for(int i = 0, s; i < n; i++)
    {
        cin >> s; a[i] = s;
    }
    for(int i = 0, s; i < n; i++)
    {
        cin >> s; b[i] = s;
    }
    sort(a, a+n); sort(b, b+n);
    if(test == 1)
    {
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += max(a[i], b[i]);
        }
        cout << ans;
    }
    else
    {
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += max(a[i], b[n-i-1]);
        }
        cout << ans;
    }
}