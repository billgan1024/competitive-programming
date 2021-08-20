#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<ll, int> pii;

//maintain a min seg tree that supports range increment and range assignment
//then let d[] = <val, op> intention to increasing the subarray of the children nodes by val or setting it to val.
//u can see that the overall segment tree invariant
//(layer of up-to-date nodes, up-to-date nodes with pending lazy updates to the children, and out-of-date nodes) is still preserved
//because newer operations always take 'priority' over older operations, leaving you to perform future range updates correctly
const int maxN = 1<<17;
//d1[] = lazy array for range increment, d2[] = lazy array for range assignment (for the node's children)
//note that v is positive so d[] = 0 represents no update
int N, Q; ll s[2*maxN]; pii d[2*maxN];

void push(int p) {
    if(d[p].second == 1) {
        //range increment
        s[2*p] += d[p].first; s[2*p+1] += d[p].first;
        //stack on top of range assignment if there was one
        d[2*p].first += d[p].first; d[2*p+1].first += d[p].first;
        if(d[2*p].second == 0) d[2*p].second = 1; if(d[2*p+1].second == 0) d[2*p+1].second = 1; 
    } else {
        //range assignment
        s[2*p] = s[2*p+1] = d[2*p].first = d[2*p+1].first = d[p].first;
        d[2*p].second = d[2*p+1].second = 2;
    }
    d[p] = {0, 0};
}
void upd1(int l, int r, int a, int b, int p, int v) {
    //range increment
    if(l <= a && b <= r) {
        s[p] += v; d[p].first += v; if(d[p].second == 0) d[p].second = 1;
    } else if(b < l || r < a) return; 
    else {
        if(d[p].second != 0) push(p);
        int mid = (a+b)/2;
        upd1(l, r, a, mid, 2*p, v); upd1(l, r, mid+1, b, 2*p+1, v);
        s[p] = min(s[2*p], s[2*p+1]);
    }
}
void upd2(int l, int r, int a, int b, int p, int v) {
    //range assignment
    if(l <= a && b <= r) {
        s[p] = v; d[p].first = v; d[p].second = 2;
    } else if(b < l || r < a) return; 
    else {
        if(d[p].second != 0) push(p);
        int mid = (a+b)/2;
        upd2(l, r, a, mid, 2*p, v); upd2(l, r, mid+1, b, 2*p+1, v);
        s[p] = min(s[2*p], s[2*p+1]);
    }
}
ll query(int l, int r, int a, int b, int p) {
    if(l <= a && b <= r) return s[p];
    else if(b < l || r < a) return LLONG_MAX; 
    else {
        if(d[p].second != 0) push(p);
        int mid = (a+b)/2;
        return min(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1));
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, Q); 
    //default value in the max segtree is 0
    for(int i = 1, x; i <= N; i++) {
        sc(x); upd1(i, i, 1, maxN, 1, x);
    }
    for(int i = 1, c, l, r, v; i <= Q; i++) {
        sc(c); 
        if(c == 1) { //range increment
            sc(l, r, v); upd1(l, r, 1, maxN, 1, v);
        } else if(c == 2) { //range assignment
            sc(l, r, v); upd2(l, r, 1, maxN, 1, v);
        } else {
            sc(l, r); pr(query(l, r, 1, maxN, 1), nl);
        }
    }
}