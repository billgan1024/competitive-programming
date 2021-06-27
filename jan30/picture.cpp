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
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, class cmp = less<T>> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 5e3+5, maxC = 2e4+5;

//idea: use line sweep (sweep a vertical line from left to right) and maintain an array of vectors of points representing
//the start and end points of all vertical sides of rectangles
//use this to determine the number of 'active' points at any given stage i.e. points that will draw horizontal lines
//as you sweep across the grid
//complexity is O(n*(gridsize+n)) but the constant factor might make it too slow
//to speed this up, note that we can use pbds to only consider the locations where the # of overlapping rectangles
//changes (use a multiset tracking all active intervals [l, r]); now the time complexity is O(n^2logn)

int n, ans, bit[maxC][2]; multiset<int> s, t; map<int, vector<pii>> h[2], v[2];
void upd(int idx, int val, int c) {
    for(int i = idx; i < maxC; i += i&-i) bit[i][c] += val;
}
int query(int idx, int c) {
    int ret = 0;
    for(int i = idx; i > 0; i -= i&-i) ret += bit[i][c];
    return ret;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    //cout.setf(ios::unitbuf);
    for(int i = 0, a, b, c, d; i < n; i++) {
        sc(a, b, c, d); 
        v[0][a].pb({b, d}); v[1][c].pb({b, d});
        h[0][b].pb({a, c}); h[1][d].pb({a, c});
    }
    for(int i = -1e4; i <= 1e4; i++) {
        for(pii p : v[0][i]) {
            //set the end points (remember, s is just to track all positions where the # of overlapping rectangles could change)
            s.insert(p.first); s.insert(p.second); int pre = p.first; bool open = query(pre+1e4+1, 0) == 0;  
            for(auto it = s.upper_bound(p.first); it != s.end() && *it <= p.second; it++) {
                ans += open*(*it-pre); 
                pre = *it; open = query(pre+1e4+1, 0) == 0;
            }
            //shift indices since bit can only take positive indices
            upd(p.first+1e4+1, 1, 0); upd(p.second+1e4+1, -1, 0);
        }
        for(pii p : v[1][i]) {
            //note that the endpoints already exist
            int pre = p.first; bool open = query(pre+1e4+1, 0) == 1;  
            for(auto it = s.upper_bound(p.first); it != s.end() && *it <= p.second; it++) {
                ans += open*(*it-pre); 
                pre = *it; open = query(pre+1e4+1, 0) == 1;
            }
            upd(p.first+1e4+1, -1, 0); upd(p.second+1e4+1, 1, 0);
            s.erase(s.find(p.first)); s.erase(s.find(p.second));
        }

        for(pii p : h[0][i]) {
            //set the end points (remember, s is just to track all positions where the # of overlapping rectangles could change)
            t.insert(p.first); t.insert(p.second); int pre = p.first; bool open = query(pre+1e4+1, 1) == 0;  
            for(auto it = t.upper_bound(p.first); it != t.end() && *it <= p.second; it++) {
                ans += open*(*it-pre); 
                pre = *it; open = query(pre+1e4+1, 1) == 0;
            }
            upd(p.first+1e4+1, 1, 1); upd(p.second+1e4+1, -1, 1);
        }
        for(pii p : h[1][i]) {
            //note that the endpoints already exist
            int pre = p.first; bool open = query(pre+1e4+1, 1) == 1;  
            for(auto it = t.upper_bound(p.first); it != t.end() && *it <= p.second; it++) {
                ans += open*(*it-pre); 
                pre = *it; open = query(pre+1e4+1, 1) == 1;
            }
            upd(p.first+1e4+1, -1, 1); upd(p.second+1e4+1, 1, 1);
            t.erase(t.find(p.first)); t.erase(t.find(p.second));
        }
    }
    pr(ans, nl);
}