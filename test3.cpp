#include <bits/stdc++.h>
using namespace std;

int n, a[100];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int l = (n-1)/2, r = l+1; 
    while(true) {
        if(l < 0) break;
        cout << a[l] << ' '; 
        if(r < n) cout << a[r] << ' ';
        l--; r++;
    }
}