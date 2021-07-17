#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxN = 2e5;

int n, q; ll d[maxN];
int main() {
    cin.sync_with_stdio(0); cin.tie(0); cin >> n >> q;
    for(int i = 0, x, y; i < n; i++) {
        cin >> x >> y; d[i] = (ll)x*x + (ll)y*y;
    }
    sort(d, d+n); //d[0] <= d[1] <= ... d[n-1]
    for(int i = 0, r; i < q; i++) {
        cin >> r;
        cout << upper_bound(d, d+n, (ll)r*r)-d << '\n';
    }
}