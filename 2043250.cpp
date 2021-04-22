#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define x first
#define s second
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, r = INT_MAX, ans = 0; vector<pii> cows;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n); if(n <= 2) { print(1, nl); return 0; }
    for(int i = 0, xi, si; i < n; i++) { scan(xi, si); cows.pb({xi, si}); }
    sort(cows.begin(), cows.end()); int px = -1e4, ps = 0;
    for(pii c : cows)
    {
        if((c.s && !ps) || (!c.s && ps)) r = min(r, c.x-px-1);
        px = c.x; ps = c.s;
    }
    px = -1; ps = 0;
    for(pii c : cows)
    {
        //with the maximum radius, check if this cow is a new one that was originally infected
        if(c.s && (!ps || c.x-px > r)) ans++;
        px = c.x; ps = c.s;
    }
    print(ans, nl);
}