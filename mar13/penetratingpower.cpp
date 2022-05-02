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

int N, K, Q; ll s[2*maxN], d[2*maxN];
void push(int p) {
    s[2*p] += d[p]; s[2*p+1] += d[p];
    d[2*p] += d[p]; d[2*p+1] += d[p];
    d[p] = 0;
}
void upd(int l, int r, int a, int b, int p, int v) {
    if(l <= a && b <= r) { s[p] += v; d[p] += v; }
    else if(b < l || r < a) return;
    else {
        push(p);
        int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p, v); upd(l, r, mid+1, b, 2*p+1, v);
        s[p] = max(s[2*p], s[2*p+1]); 
    }
}
ll query(int l, int r, int a, int b, int p) {
    if(l <= a && b <= r) return s[p]; 
    else if(b < l || r < a) return LLONG_MIN;
    else {
        push(p);
        int mid = (a+b)/2;
        return max(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1));
    }
}
int main() {
    //maintain a max seg tree tracking leaf[i] = a[i]+a[i+1]+...+a[i+k-1]; then, the point update is simply equal to a range increment
    //(pretend that there are always generals between 0 and 200000, and assume that l <= r)
    cin.sync_with_stdio(0); cin.tie(0); sc(N, K, Q);
    for(int i = 0, c, p, v, l, r; i < Q; i++) {
        sc(c);
        if(c == 0) {
            sc(p, v);
            //if general p increases by value v, then the leaf nodes p-k+1, ..., p all get updated
            //also, p-K+1 is at least 1, although in the sample case, the out-of-bound range update can be safely done
            //because the segment outside of the desired range (with the negative index) won't be updated.
            if(K > 0) upd(p-K+1, p, 0, maxN-1, 1, v);
        } else {
            sc(l, r); pr(query(l, r, 0, maxN-1, 1), nl);
        }
    }
}