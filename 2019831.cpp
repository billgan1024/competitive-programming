#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define l first
#define r second
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<ll, ll> p;

int n, m; vector<p> s;
bool check(ll sep)
{
    //checks if it is possible to arrange cows with a minimum separation
    int cur = 0; ll pos = s[cur].l;
    for(int i = 0; i < n-1; i++)
    {
        //place cow at pos, then check if the next cow can be placed
        //note that we only loop n-1 times
        pos += sep;
        //advance to the next patch if available (otherwise exit)
        while(s[cur].r < pos)
        {
            cur++; if(cur == m) return false;
        }
        //move pos into a valid position
        pos = max(pos, s[cur].l);
    }
    return true;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0; i < m; i++)
    {
        ll a, b; scan(a, b); s.push_back({a, b});
    }
    sort(s.begin(), s.end());
    //these parameters represent the minimum distance between two cows
    ll low = 1, high = 1e18, ans = 0;
    while(low <= high)
    {
        ll mid = (low+high)/2;
        if(check(mid))
        {
            ans = mid; low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    print(ans);
}