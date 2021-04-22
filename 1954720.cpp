#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, m, k, a1, a2, b1, b2; vector<vector<int>> state; vector<int> cur;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k, a1, a2, b1, b2);
    for(int i = 0; i <= n; i++) cur.push_back(i); state.push_back(cur);
    while(true)
    {
        reverse(cur.begin()+a1, cur.begin()+a2+1);
        reverse(cur.begin()+b1, cur.begin()+b2+1);
        if(cur == state[0]) break;
        state.push_back(cur);
    }
    vector<int> ans = state[k % state.size()];
    for(int i = 1; i <= n; i++) print(ans[i], nl);
}