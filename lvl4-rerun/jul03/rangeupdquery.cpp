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
const int maxN = 1<<20;

int N, Q; ll s[2][2*maxN], d[2][maxN], len[2][maxN];

void push(int i, int p, int a, int b) {
    if(d[i][p] != 0) {
        int mid = (a+b)/2;
        s[i][2*p] += d[i][p]*(len[i][mid]-len[i][a-1]); s[i][2*p+1] += d[i][p]*(len[i][b]-len[i][mid]); 
        if(2*p < maxN) { d[i][2*p] += d[i][p]; d[i][2*p+1] += d[i][p]; }
        d[i][p] = 0;
    }
}

//range update on either the constants or the first-order coefficients
//index 0 = constant, index 1 = first-order segtree
void upd(int i, int l, int r, int a, int b, int p, int v) {
    if(l <= a && b <= r) {
        s[i][p] += v*(len[i][b]-len[i][a-1]); if(p < maxN) d[i][p] += v; 
    } else if(b < l || r < a) return; 
    else {
        push(i, p, a, b);
        int mid = (a+b)/2;
        upd(i, l, r, a, mid, 2*p, v); upd(i, l, r, mid+1, b, 2*p+1, v);
        s[i][p] = min(s[i][2*p], s[i][2*p+1]);
    }
}

ll query(int i, int l, int r, int a, int b, int p) {
    if(l <= a && b <= r) return s[i][p];
    else if(b < l || r < a) return 0;
    else {
        push(i, p, a, b);
        int mid = (a+b)/2;
        return query(i, l, r, a, mid, 2*p) + query(i, l, r, mid+1, b, 2*p+1);
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, Q);
    //use the idea of maintaining a data structure tracking coefficient for every degree of the polynomial, for every index
    //then, compute the sum by finding the range sum of constants (sum of a[i]) and the range sum of first-degree coefficients*index 
    //(sum of a[i]*i)
    //notice that both of these ideas can be implemented using segment trees; for the one tracking sum of (a[i]*i), lazy propagation
    //can still be applied as long as u let d[i] = operation to perform +d[i]*i in the ranges of the children nodes; then you can use a prefix sum
    //to calculate any subarray sum of [1, 2, ..., n]
    //basically, the seg tree tracking sum of a[i]*i is exactly the same as the one tracking a[i], except it calculates the "length"
    //of the segments (the thing that is multiplied by d[i], the delayed operation) as the sum of i from l to r instead of the sum of 1 from l to r.
    for(int i = 1; i <= N; i++) {
        len[0][i] = i; len[1][i] = (ll)i*(i+1)/2;
    }
    for(int i = 0, cmd, l, r, a; i < Q; i++) {
        sc(cmd); 
        if(cmd == 1) {
            sc(l, r, a); upd(1, l, r, 1, maxN, 1, a); upd(0, l, r, 1, maxN, 1, -a*(l-1));
        } else {
            sc(l, r); pr(query(1, l, r, 1, maxN, 1) + query(0, l, r, 1, maxN, 1), nl);
        }
    }
}

