#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e6+1;

int n, t, k, v, a[MV], s[MV], ans; deque<int> q;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, t, k, v);
    for(int i = 0, x; i < v; i++)
    {
        scan(x); a[x]++;
    }
    //deque keeps track of added restaurants, sum keeps track of the number of restaurants in this block
    for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    for(int i = t; i > 0; i--)
    {
        if(s[t] + sz(q) >= k) break; if(a[i]) continue;
        q.push_front(i); ans++;
    }
    //transit to n
    for(int r = t+1; r <= n; r++)
    {
        int l = r-t+1;
        if(!q.empty() && q.front() < l) { q.pop_front(); }
        if(s[r] - s[l-1] + sz(q) < k) { q.pb(r); ans++; }
    }
    print(ans);
}