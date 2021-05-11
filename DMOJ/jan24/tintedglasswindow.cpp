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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int N, T; map<int, map<int, int>> ds; ll ans; map<int, int> s;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, T);
    for(int i = 0, xl, yt, xr, yb, t; i < N; i++) {
        sc(xl, yt, xr, yb, t);
        ds[yt][xl] += t; ds[yt][xr] -= t; ds[yb][xl] -= t; ds[yb][xr] += t;
    }
    //maintain a map that tracks point updates (i.e. the difference array)
    //the difference array is integrated vertically, and we perform the 'sum' operation horizontally to
    //obtain the set that represents the current row
    //when updating this map, add (vertical distance moved)(valid tinted area) to ans and
    //update the map
    //note: the first row/point in the row will never make it overcount since area/sum is always 0 initially
    //time complexity = n^2 since looping through the current aggregate set is O(n), looping through each row = O(n)
    int lastRow = 0, area = 0;
    for(auto p : ds) {
        //add tinted area from before
        ans += (ll)area*(p.first-lastRow);
        //update current column
        for(pii q : p.second) s[q.first] += q.second;
        //update tinted area
        area = 0; int pre = 0, sum = 0;
        for(pii q : s) {
            if(sum >= T) area += q.first-pre;
            pre = q.first; sum += q.second;
        }
        lastRow = p.first;
    }
    pr(ans, nl);
}