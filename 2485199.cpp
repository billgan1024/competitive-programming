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

int n, m, c, a[MV]; deque<int> mn, mx; vector<int> ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m, c);
    for(int i = 1; i <= n; i++)
    {
        sc(a[i]);
        while(!mn.empty() && a[i] <= a[mn.back()]) mn.pop_back();
        while(!mx.empty() && a[i] >= a[mx.back()]) mx.pop_back();
        mn.pb(i); mx.pb(i);
        if(mn.front() <= i-m) mn.pop_front();
        if(mx.front() <= i-m) mx.pop_front();
        if(i >= m && a[mx.front()] - a[mn.front()] <= c) ans.pb(i-m+1);
    }
    if(ans.empty()) pr("NONE", nl);
    else { for(int i : ans) pr(i, nl); }
}