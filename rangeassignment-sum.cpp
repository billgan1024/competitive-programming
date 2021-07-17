//a program to test whether range assignment queries with range max queries can be solved using simple lazy propagation
//apparently it works because using s[p] = v, d[p] = v still preserves the order in which operations are done, no matter
//the order of the operations sorted by node depth; the larger udpate simply overrides the other one.
//handle no assignment operation using a dummy value (in this case, we use 0)
//this was tested for range assignment for a max and sum segtree (it works lmao)
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
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 1<<18;

struct event { int x, amnt, id, pos; } pts[maxN];
bool c(event a, event b) { return a.x < b.x; } 

int T, N, ans, s[2*maxN], d[2*maxN], cmp[maxN][2], a[maxN];
//d[i] = pending range increment on the children of node i (if i is already a leaf node, this has no effect)
void push(int p, int len) {
    s[2*p] = len*d[p]; s[2*p+1] = len*d[p];
    d[2*p] = d[p];  d[2*p+1] = d[p];
    d[p] = 0;
}
void upd(int l, int r, int a, int b, int p, int v) {
    //enter recursion with the assumption that the node p is up-to-date
    //parent nodes: [1, maxN-1], leaf nodes: [maxN, 2*maxN-1]
    int len = b-a+1;
    if(l <= a && b <= r) { s[p] = len*v; d[p] = v; } 
    else if(b < l || r < a) return; //in both cases, exit the node with an up-to-date status
    else {
        //make sure the children are up-to-date when searching into them
        if(d[p] != 0) push(p, len/2); int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p, v); upd(l, r, mid+1, b, 2*p+1, v);
        //at the end, automatically recalculate the new maximum to maintain up-to-dateness in the path from
        //this node to the root since those nodes will be outdated
        //the children nodes will be up-to-date so use the values.
        s[p] = s[2*p] + s[2*p+1];
    }
}

//maintain up-to-dateness in the current node 
//you're not changing the values of any particular node, so you're just propagating lazy updates downward when necessary
int query(int l, int r, int a, int b, int p) {
    int len = b-a+1;
    if(l <= a && b <= r) return s[p];
    else if(b < l || r < a) return 0;
    else {
        if(d[p] != 0) push(p, len/2); int mid = (a+b)/2;
        return query(l, r, a, mid, 2*p)+query(l, r, mid+1, b, 2*p+1);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    flush;
    sc(N, T); pr("Array: "); for(int i = 1, x; i <= N; i++) {
        x = rand() % N + 1; upd(i, i, 1, maxN, 1, x); a[i] = x; pr(x, sp);
    }
    pr(nl);
    while(T--) {
        int l, r, v, c;
        c = rand() % 2;
        l = rand() % N + 1; r = rand() % N + 1; if(l > r) swap(l, r); v = rand() % N + 1; 
        if(c) {
            pr("Update ", l, sp, r, sp, v, ": ");
            upd(l, r, 1, maxN, 1, v); for(int i = l; i <= r; i++) a[i] = v;
            for(int i = 1; i <= N; i++) pr(a[i], sp);
            pr(nl);
        } else {
            pr("Query ", l, sp, r, ": ");
            int q = query(l, r, 1, maxN, 1);
            int sum = 0;
            for(int i = l; i <= r; i++) sum += a[i];
            pr(q, sp, sum, sp, q == sum ? "\u001b[32mAC" : "\u001b[31mWA", "\u001b[0m", nl);
        }
    }
}