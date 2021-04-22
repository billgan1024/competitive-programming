#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MV = 1e6+1;
int n, k, num, a[MV], freq[MV]; ll ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k; for(int i = 1; i <= n; i++) cin >> a[i];
    for(int l = 1, r = 1; r <= n; r++)
    {
        if(freq[a[r]] == 0) num++; freq[a[r]]++;
        while(num == k)
        {
            ans += n-r+1; freq[a[l]]--; if(freq[a[l]] == 0) num--; l++;
        }
    }
    cout << ans << "\n";
}