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
typedef pair<int, int> pii;

const int maxN = 1<<18;

struct event { int x, amnt, id, pos; } pts[maxN];
bool c(event a, event b) { return a.x < b.x; } 

int T, N, ans, s[2 * maxN], d[maxN], intervals[maxN][2]; set<int> distinct;
void push(int p) {
    s[2*p] += d[p]; d[2*p] += d[p]; s[2*p+1] += d[p]; d[2*p+1] += d[p]; d[p] = 0;
}
void upd(int l, int r, int a, int b, int p, int v) {
    //enter recursion with the assumption that the node p is up-to-date
    //parent nodes: [1, maxN-1], leaf nodes: [maxN, 2*maxN-1]
    if(l <= a && b <= r) { s[p] += v; if(p < maxN) d[p] += v; } 
    else if(b < l || r < a) return; //in both cases, exit the node with an up-to-date status
    else {
        //make sure the children are up-to-date when searching into them
        push(p); int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p, v); upd(l, r, mid+1, b, 2*p+1, v);
        //at the end, automatically recalculate the new maximum to maintain up-to-dateness in the path from
        //this node to the root since those nodes will be outdated
        //the children nodes will be up-to-date so use the values.
        s[p] = max(s[2*p], s[2*p+1]);
    }
}

//maintain up-to-dateness in the current node 
//you're not changing the values of any particular node, so you're just propagating lazy updates downward when necessary
int query(int l, int r, int a, int b, int p) {
    if(l <= a && b <= r) return s[p];
    else if(b < l || r < a) return INT_MIN;
    else {
        push(p); int mid = (a+b)/2;
        return max(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1));
    }
}

int main() {
    sc(T);
   for(int t = 1; t <= T; t++) {
		sc(N); ms(s, 0); ms(d, 0); ms(pts, 0); ans = 0;
		//the easiest way to capture all important regions tracking # of overlapping segments (even at the edges)
		//is to pretend all points AND lines are array cells
		//then, you have an array of size 2N (segment tree of size 4N) to perform queries + updates on
		//maintain a map of lists to find the important points in the difference array to examine 
		for(int i = 0, a, b; i < N; i++) {
			sc(a, b); intervals[i][0] = 2*a; intervals[i][1] = 2*b+1; distinct.insert(2*a); distinct.insert(2*b+1); 
			pts[2*i] = {2*a, 1, i}; pts[2*i+1] = {2*b+1, -1, i}; //1 = entering, -1 = exiting
		} 
		sort(pts, pts+2*N, c);
    }
}