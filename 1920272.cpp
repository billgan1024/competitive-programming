#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); int n; cin >> n;
    double d, start[n], end[n]; double ans = 0;
    for(int i = 0; i < n; i++) { cin >> d; start[i] = d; }
    for(int i = 0; i < n; i++) { cin >> d; end[i] = d; }
    for(int i = 0; i < n; i++) ans += pow(start[i]-end[i], 2);
    ans = pow(ans, 0.5); cout << setprecision(15) << ans;
}