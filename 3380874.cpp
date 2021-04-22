#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("Ofast")
#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

double a, b, c, d, n, ans;
bool in(double val, double b1, double b2, double c1, double c2) {
    return val >= min(b1, b2) && val <= max(b1, b2) && val >= min(c1, c2) && val <= max(c1, c2);
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(a, b, c, d, n);
    for(int i = 0, k; i < n; i++) {
        sc(k); double px = 0, py = 0; bool flag = false;
        vector<pair<double, double>> pts;
        for(int j = 0; j < k; j++) { double x, y; sc(x, y); pts.pb({x, y}); }
        pts.pb({pts[0].first, pts[0].second});
        for(int j = 1; j < sz(pts) && !flag; j++) {
            double nx = pts[j].first, ny = pts[j].second, px = pts[j-1].first, py = pts[j-1].second;
            if(j == 0) { }
            if(j > 0) {
                //original equation: (d-b)x + (a-c)y = c(d-b) - d(c-a)
                //this equation: (ny-py)x + (px-nx)y = nx(ny-py) - ny(nx-px)
                // [(d-b)    (a-c) ] [x]
                // [(ny-py) (px-nx)] [y]
                double det = (d-b)*(px-nx) - (a-c)*(ny-py), tx = c*(d-b) - d*(c-a), ty = nx*(ny-py) - ny*(nx-px);
                if(det == 0) {
                    //parallel (distinct or coincident)
                    //check if the original point is on the line
                    if((ny-py)*a + (px-nx)*b == ty) {
                        //check if the parallel line segments touch
                        if(a-c == 0) {
                            //comparing y coords is necessary
                            if(!(min(ny, py) > max(b, d) || max(ny, py) < min(b, d))) flag = true;
                        } else {
                            //comparing x coords would suffice
                            if(!(min(nx, px) > max(a, c) || max(nx, px) < min(a, c))) flag = true;
                        }
                    }
                } else {
                    //find point of intersection
                    double x = ((px-nx)*tx - (a-c)*ty)/det, y = ((py-ny)*tx + (d-b)*ty)/det;
                    bool v1 = in(x, a, c, px, nx);
                    bool v2 = in(y, b, d, py, ny);
                    if(v1 && v2) flag = true;
                }
            }
        }
        ans += flag;
    }
    pr(ans, nl);
}