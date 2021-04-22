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
const int MV = 1e6;

int n, a[MV], ans[MV]; stack<int> s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 0; i < n; i++) sc(a[i]);
    for(int i = n; i >= 0; i--)
    {
        while(!s.empty() && a[i] > a[s.top()])
        {
            ans[s.top()] = s.top() - i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) { ans[s.top()] = s.top(); s.pop(); }
    for(int i = 0; i < n; i++) pr(ans[i], sp);
}