#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

typedef pair<int, int> pii;
vector<pii> pts; int n, ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, x, y; i < n; i++)
    {
        scan(x, y); pts.push_back({x, y});
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                int x0 = pts[i].first, y0 = pts[i].second;
                int x1 = pts[j].first, y1 = pts[j].second;
                int x2 = pts[k].first, y2 = pts[k].second;
                if(x0 == x1)
                {
                    int h = abs(y1-y0), w = -1;
                    if(y0 == y2) w = abs(x2-x0);
                    else if(y1 == y2) w = abs(x2-x1);
                    if(w != -1) ans = max(ans, h*w);
                }
                else if(x1 == x2)
                {
                    int h = abs(y2-y1), w = -1;
                    if(y1 == y0) w = abs(x1-x0);
                    else if(y2 == y0) w = abs(x2-x0);
                    if(w != -1) ans = max(ans, h*w);
                }
                else if(x0 == x2)
                {
                    int h = abs(y2-y0), w = -1;
                    if(y1 == y0) w = abs(x1-x0);
                    else if(y1 == y2) w = abs(x1-x2);
                    if(w != -1) ans = max(ans, h*w);
                }
            }
        }
    }
    print(ans, nl);
}