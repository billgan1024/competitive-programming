#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e6+1;

int n, k, a[MV], t[MV], pos[MV], maxTime, ans; bool c[MV]; stack<int> s;
void loop()
{
    for(int i = 1; i <= n; i++)
    {
        //push the player id currently at this chair
        if(pos[i]) s.push(pos[i]);
        if(c[i] && !s.empty())
        {
            //if there is a chair here then the person at the top of the stack gets it
            //remove the chair and the player after
            t[s.top()] = i - a[s.top()]; if(t[s.top()] < 0) t[s.top()] += n;
            c[i] = false; pos[a[s.top()]] = 0; s.pop();
        }
    }
}
int main()
{
    //c[i] = whether a chair exists at position i
    //a[i] = start pos of player i
    //t[i] = maxTime player i takes to go to a chair
    //pos[i] = the player id at position i (0 if none)
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k); ms(t, INF);
    for(int i = 1, x; i <= k; i++) { sc(x); c[x] = true; }
    for(int i = 1; i <= k+1; i++) { sc(a[i]); pos[a[i]] = i; }
    loop(); loop();
    for(int i = 1; i <= k+1; i++)
    {
        if(maxTime < t[i]) { ans = i; maxTime = t[i]; }
    }
    pr(ans);
}