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
const int MV = 5e5+1;

int n, a[MV], lft[MV], st[MV]; ll ans; stack<int> s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++) sc(a[i]);
    for(int i = n; i > 0; i--)
    {
        while(!s.empty() && a[i] > a[s.top()]) { lft[s.top()] = i; s.pop(); }
        s.push(i);
    }
    while(!s.empty()) { lft[s.top()] = 1; s.pop(); }
    //maintain a max stack tracking all people who can see to their right using an array
    //r represents the top of the stack
    //binary search on the lowest index person that person i can pair with 
    int r = 1; st[r] = 1;
    for(int i = 2; i <= n; i++)
    {
        int idx = lower_bound(st+1, st+r+1, lft[i]) - st;
        ans += r-idx+1;
        while(r > 0 && a[i] > a[st[r]]) { st[r] = 0; r--; }
        r++; st[r] = i;
    }
    pr(ans, nl);
}