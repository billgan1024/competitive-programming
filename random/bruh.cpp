#include <bits/stdc++.h>
using namespace std;
int x, ans;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 51; i++) {
        cin >> x; ans += x;
    }
    cout << ans; 

}