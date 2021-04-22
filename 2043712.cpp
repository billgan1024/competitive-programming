#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define name first
#define spd second
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int m, n, dp[101], t; string s; pair<string, int> ppl[101]; vector<unordered_set<string>> ans;
unordered_set<string> group;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(m, n);
    for(int i = 1; i <= n; i++)
    {
        scan(s, t); ppl[i] = {s, t};
    }
    //dp[i]: min time for the first i people to cross
    for(int i = 1; i <= n; i++)
    {
        int time = ppl[i].spd, j = i-1; dp[i] = INT_MAX;
        while(j >= max(i-m, 0))
        {
            dp[i] = min(dp[i], dp[j] + time); time = max(time, ppl[j].spd); j--;
        }
    }
    print("Total Time: ", dp[n], nl); int p = -1;
    //retrace the dp to find out the group members
    //if dp[i] - max time of group = dp[i-group.size], then this group is optimal
    int cur = n;
    while(true)
    {
        group.clear(); int j = cur-1, time = ppl[cur].spd;
        while(j >= max(cur-m, 0))
        {
            group.insert(ppl[j+1].name);
            if(dp[cur] - time == dp[j]) break;
            time = max(time, ppl[j].spd); j--;
        }
        ans.pb(group); cur = j; if(cur == 0) break;
    }
    for(int i = sz(ans)-1; i >= 0; i--)
    {
        auto b = ans[i];
        for(string p : b) print(p, sp); print(nl);
    }
}