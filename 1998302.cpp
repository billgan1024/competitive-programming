#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, double> point;

double n, ans; vector<point> points;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, t, x; i < n; i++)
    {
        scan(t, x); points.push_back({t, x});
    }
    sort(points.begin(), points.end());
    double pt = -1, px = -1;
    for(point p : points)
    {
        if(pt != -1)
        {
            ans = max(ans, abs(p.second-px)/(p.first-pt));
        }
        pt = p.first; px = p.second;
    }
    print(fixed, setprecision(6), ans);
}