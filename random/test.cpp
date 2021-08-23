#include <bits/stdc++.h>
using namespace std;

int n, z[7], w[7], ans = INT_MAX, totalWeight; 
//recursion except you pack all additional variables into each state instead of maintaining a global chain
//in general, avoid this when you're passing a vector around
//cur: current weight he is carrying
//pos: current floor
//tot: total stress incurred
//once you reach the end, simply take the minimum of the total weights
void f(vector<int> selected, int wt, int pos, int s) {
    if(selected.size() == n) ans = min(ans, s);
    else {
        for(int i = 0; i < n; i++) {
            if(find(selected.begin(), selected.end(), i) == selected.end()) {
                vector<int> tmp = selected;
                tmp.push_back(i);
                f(tmp, wt-w[i], z[i], s + (abs(pos-z[i])+1)*wt);
            }
        }
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> z[i] >> w[i]; 
        totalWeight += w[i];
    }
    vector<int> original;
    f(original, totalWeight, 101, 0);
    cout << ans;
}