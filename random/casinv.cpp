#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e6+1;

int N, r[maxN], c[maxN]; ll ans;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); cin >> N;
    for(int i = 1; i <= N; i++) cin >> c[i];
    for(int i = 1; i <= N; i++) cin >> r[i];
    sort(r+1, r+N+1); sort(c+1, c+N+1);
    for(int i = 1; i <= N; i++) {
        bool seen = false;
        for(int j = 1; j <= N; j++) {
            ans += min(r[i], c[j]);
            if(min(r[i], c[j]) == r[i]) seen = true;
        }
        if(!seen) { cout << -1; return 0; }
    }
    for(int i = 1; i <= N; i++) {
        bool seen = false;
        for(int j = 1; j <= N; j++) {
            if(min(c[i], r[j]) == c[i]) seen = true;
        }
        if(!seen) { cout << -1; return 0; }
    }
    cout << ans;
}