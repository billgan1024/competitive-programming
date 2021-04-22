#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

typedef pair<int, int> pii;
typedef long long ll;
const int MM = 1e5, MV = 1e4;
int n, m = 1e9+7, cx[2*MV+1], cy[2*MV+1], lx[2*MV+1], ly[2*MV+1]; pii pts[MM];
ll ans, sx[2*MV+1], sy[2*MV+1];

bool cmp(pii p, pii q) { return p.first < q.first || (p.first == q.first && p.second < q.second); }

void calculate()
{
    sort(pts, pts+n, cmp); ms(sx); ms(sy); ms(cx); ms(cy); ms(lx); ms(ly);
    for(int i = 0; i < n; i++)
    {
        //lx[i]: highest y coordinate of the points with an x-coord of i
        //ly[i]: rightmost x coordinate of the points with a y coord of i
        //cx[i]: # of points with x coordinate i, this also represents the # of points which are BELOW the current point that is being processed
        //cy[i]: # of points with y coordinate i, this also represents the # of points which are TO THE LEFT of the current point that is being processed
        //sx[i]: represents (a+2b+3c+4d+...) it represents the sum of all heights (lines with the same x coord)
        //sy[i]: represents sum of all lengths (lines with the same y coord)
        int x = pts[i].first+MV, y = pts[i].second+MV;
        //this point has a new highest y coordinate, which means that it creates a new height that should be counted equal to the # of points below it
        //this new height is equal to the current y coord - highest y coord
        sx[x] += ((y-lx[x])*cx[x])%m; sx[x] %= m;
        //this point has the rightmost x coordinate, which means that it creates a new length that should be counted equal to the # of points to the left of it
        //this new length is equal to the current x coord - rightmost x coord
        sy[y] += ((x-ly[y])*cy[y])%m; sy[y] %= m;
        //we loop through every node and thus get every triangle which is rotated a certain way and rooted at this current point
        //we are essentially getting all lengths to the left * all lengths below, which is all the triangles rooted at this point with the legs to the left and below
        ans += (sx[x]*sy[y])%m; ans %= m;
        lx[x] = y; ly[y] = x; cx[x]++; cy[y]++;
    }
}

void rotate()
{
    for(int i = 0; i < n; i++) { swap(pts[i].first, pts[i].second); pts[i].second *= -1; }
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++) scan(pts[i].first, pts[i].second);
    for(int i = 0; i < 4; i++)
    {
        calculate(); rotate();
    }
    print(ans, nl);
}