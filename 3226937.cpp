#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
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
const int maxN = 1 << 17;
int N, M, seg[2*maxN];
//segtree of size maxN stores the tree nodes in indices [1, maxN-1] and leaf nodes in [maxN, 2*maxN-1]
void upd(int i, int v)
{
    int idx = i+maxN; seg[idx] = v;
    for(int p = idx/2; p != 0; p /= 2) seg[p] = min(seg[2*p], seg[2*p+1]);
}
int query(int p, int queryL, int queryR, int segL, int segR)
{
    if(segL >= queryL && segR <= queryR) return seg[p];
    else if(segR < queryL || segL > queryR) return INT_MAX;
    else
    {
        int mid = (segL+segR)/2;
        return min(query(2*p, queryL, queryR, segL, mid), query(2*p+1, queryL, queryR, mid+1, segR));
    }
}
int main() {
    //min segtree's 'zero' value is infinity since min(x, INF) = x
    ms(seg, INF);
    sc(N, M); for(int i = 0, x; i < N; i++) { sc(x); upd(i, x); }
    for(int m = 0; m < M; m++)
    {
        char cmd; int i, j, x;
        sc(cmd);
        if(cmd == 'M')
        {
            sc(i, x); upd(i, x);
        }
        else
        {
            sc(i, j); pr(query(1, i, j, 0, maxN-1), nl);
        }
    }
}