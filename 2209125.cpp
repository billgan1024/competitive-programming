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
const int MV = 3e6;

int n, k, a[MV]; deque<int> mn, mx; ll ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k);
    for(int i = 0; i < n; i++) scan(a[i]);
    int l = 0, r = 0;
    for(int l = 0, r = 0; r < n; r++)
    {
        while(!mx.empty() && a[r] >= a[mx.back()]) mx.pop_back();
        while(!mn.empty() && a[r] <= a[mn.back()]) mn.pop_back();
        mn.pb(r); mx.pb(r);
        while(a[mx.front()] - a[mn.front()] > k)
        {
            l++; if(mx.front() < l) mx.pop_front(); if(mn.front() < l) mn.pop_front();
        }
        ans += r-l+1;
    }
    print(ans);
}