#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a = -21000000111LL, b = 1e9+9;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << (a % b + b) % b;
}