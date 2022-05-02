#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
// how many constraints are violated? 
int x, y, g, cx, cy;
// string -> list of names that this name must be with
// string -> list of names that this name must not be with
// note that hashmaps (or any other container) automatically initializes with nothing
unordered_map<string, vector<string>> together, apart;
void check_together(string s, string t) {
    // do s and t need to be together? if so, then the # violated goes down
    if(find(together[s].begin(), together[s].end(), t) != together[s].end()) cx--;
}
void check_apart(string s, string t) {
    // do s and t need to be apart? if so, then the # violated goes up
    if(find(apart[s].begin(), apart[s].end(), t) != apart[s].end()) cy++;
}
int main() {
    cin >> x;
    // read in all pairs (note that the problem states that each unordered pair appears at most once)
    for(int i = 1; i <= x; i++) {
        string s, t;
        cin >> s >> t;
        together[s].push_back(t); together[t].push_back(s);
    }
    // then for every 
    cin >> y;
    for(int i = 1; i <= y; i++) {
        string s, t;
        cin >> s >> t;
        apart[s].push_back(t); apart[t].push_back(s);
    }
    cx = x; cy = 0;
    // ans = # of requirements left/2
    cin >> g;
    for(int i = 1; i <= g; i++) {
        string s, t, u;
        cin >> s >> t >> u;
        // check requirements for s, t, u
        check_together(s, t); 
        check_together(t, u); 
        check_together(u, s); 
        check_apart(s, t); 
        check_apart(t, u); 
        check_apart(u, s); 
    }
    printf("%d\n", cx+cy);
}