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
const int MV = 3e3+1;

int h, w, n, a[MV][MV], sMin[MV][MV], sMax[MV][MV], ans = INT_MAX; deque<int> mn, mx;
int main()
{
    //sMin[r][c] stores the minimum of g[r][c], g[r-1][c], ... ,
    //sMax is the same
    cin.sync_with_stdio(0); cin.tie(0); sc(h, w, n);
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++) sc(a[i][j]);
    }
    //preprocess sliding windows
    for(int j = 1; j <= w; j++)
    {
        mn.clear(); mx.clear();
        for(int i = 1; i <= h; i++)
        {
            if(!mn.empty() && mn.front() <= i-n) mn.pop_front();
            if(!mx.empty() && mx.front() <= i-n) mx.pop_front();
            while(!mn.empty() && a[i][j] <= a[mn.back()][j]) mn.pop_back();
            while(!mx.empty() && a[i][j] >= a[mx.back()][j]) mx.pop_back();
            mn.pb(i); mx.pb(i);
            if(i >= n) { sMin[i][j] = a[mn.front()][j]; sMax[i][j] = a[mx.front()][j]; }
        }
    }
    for(int i = n; i <= h; i++)
    {
        mn.clear(); mx.clear();
        for(int j = 1; j <= w; j++)
        {
            if(!mn.empty() && mn.front() <= j-n) mn.pop_front();
            if(!mx.empty() && mx.front() <= j-n) mx.pop_front();
            while(!mn.empty() && sMin[i][j] <= sMin[i][mn.back()]) mn.pop_back();
            while(!mx.empty() && sMax[i][j] >= sMax[i][mx.back()]) mx.pop_back();
            mn.pb(j); mx.pb(j);
            if(j >= n) ans = min(ans, sMax[i][mx.front()] - sMin[i][mn.front()]);
        }
    }
    pr(ans);
}