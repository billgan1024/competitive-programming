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
const int maxN = 2.5e5+1, root = 5e2;

int n, m, a[maxN], s[root+1][10], lazy[root+1]; string t;

void clear(int p) {
    if(lazy[p] != 0) {
        for(int i = (p-1)*root+1; i <= p*root; i++) a[i] = (a[i] + lazy[p]) % 10; 
        lazy[p] = 0;
    }
}

void recalc(int p) {
    for(int i = 0; i < 10; i++) s[p][i] = 0;
    for(int i = (p-1)*root+1; i <= p*root; i++) s[p][a[i]]++;
}

void push (int p, int v) {
    int tmp[10]; 
    for(int i = 0; i < 10; i++) tmp[i] = s[p][(i-v+10)%10];
    copy(tmp, tmp+10, s[p]); lazy[p] += v;
}

void upd(int l, int r, int v) {
    //shift dials from [l, r] upwards by v
    //for the ends, clear the lazy update and update individual array values
    int x = ceil((double)l/root), y = ceil((double)r/root); clear(x); clear(y);
    for(int i = l; i <= min(r, x*root); i++) a[i] = (a[i]+v) % 10;
    if(x != y) {
        for(int i = r; i > (y-1)*root; i--) a[i] = (a[i]+v)%10;
    } 
    //just like segment tree updates, if you're updating the children nodes, make sure the parent nodes are also updated
    recalc(x); recalc(y);
    //update the middle blocks lazily by updating the frequencies and updating the lazy value which represents a pending update
    //to the block's children nodes (in this way, only one lazy value needs to be updated compared to the original seg tree implementation
    //which updated the lazy values of the children)
    for(int i = x+1; i < y; i++) push(i, v); 
}

int query(int l, int r) {
    //normal range sum query
    //at the ends, u need to push updates to the children before continuing to access the children nodes
    int ret = 0;
    int x = ceil((double)l/root), y = ceil((double)r/root); clear(x); clear(y);
    for(int i = l; i <= min(r, x*root); i++) ret += a[i];
    if(x != y) {
        for(int i = r; i > (y-1)*root; i--) ret += a[i]; 
    }
    for(int i = x+1; i < y; i++) {
        //for any block that lies completely in range, simply use its frequency values since they are always up to date
        for(int j = 0; j < 10; j++) ret += j*s[i][j];
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m, t);
    //cout.setf(ios::unitbuf);
    //sqrt data structure: maintain info about sqrt(n) blocks of elements of length sqrt(n) to allow for range updates
    //and range queries to be done in sqrt(n) time
    //for range updates, use a technique similar to lazy propagation: lazy[i] = pending update to shift the dials in that block
    //by that value (remember that they can stack)
    //total time complexity: msqrt(n) (which will be multiplied by the constant factor 10)
    //in the data structure, s[p] contains the frequency data relating to the section [(p-1)sqrt(n)+1, psqrt(n)] i.e. s[p][j] = # of js in that block
    //for a particular index i, the corresponding block index is ceil(i/root)
    for(int i = 1; i <= sz(t); i++) upd(i, i, t[i-1]-'0'); 
    for(int i = 1, a, b; i <= m; i++) {
        sc(a, b); pr(query(a, b), nl); upd(a, b, 1);
    }
}