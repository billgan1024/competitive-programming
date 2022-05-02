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

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, class cmp = less<T>> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

//use a segment tree tracking the frequency of every element in a range 
//then, use range assignments + range queries to determine the frequency of all the elements in a particular range
//i.e. u perform a range assignment = 0, then perform a range assignment = 1 in the target location
//since we also need to propagate a range set to 0 operation, the default value of d[i][p] = INF for no operation

const int maxN = 1<<17;

int N, M, K, s[21][2*maxN], d[21][2*maxN];
//inline can help speed up the push function. see here https://www.geeksforgeeks.org/inline-functions-cpp/
inline void push(int i, int p, int len) {
    s[i][2*p] = len*d[i][p]; s[i][2*p+1] = len*d[i][p];
    d[i][2*p] = d[i][p];  d[i][2*p+1] = d[i][p];
    d[i][p] = 1e9;
}
//range assignment
void upd(int i, int l, int r, int a, int b, int p, int v) {
    int len = b-a+1;
    if(l <= a && b <= r) { s[i][p] = len*v; d[i][p] = v; } 
    else if(b < l || r < a) return; 
    else {
        if(d[i][p] < 1e9) push(i, p, len/2); int mid = (a+b)/2;
        upd(i, l, r, a, mid, 2*p, v); upd(i, l, r, mid+1, b, 2*p+1, v);
        s[i][p] = s[i][2*p]+s[i][2*p+1];
    }
}

int query(int i, int l, int r, int a, int b, int p) {
    int len = b-a+1;
    if(l <= a && b <= r) return s[i][p];
    else if(b < l || r < a) return 0;
    else {
        if(d[i][p] < 1e9) push(i, p, len/2); int mid = (a+b)/2;
        return query(i, l, r, a, mid, 2*p)+query(i, l, r, mid+1, b, 2*p+1);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, M, K); ms(d, INF);
    //simply perform range assignments
    for(int i = 1, x; i <= N; i++) { sc(x); upd(x, i, i, 1, maxN, 1, 1); }
    for(int i = 1, l, r; i <= M; i++) {
        sc(l, r); 
        //obtain the frequency of each value, then clear that value in the range and assign them accordingly
        int cur = l;
        for(int j = 1, p; j <= K; j++) {
            sc(p); int cnt = query(p, l, r, 1, maxN, 1); 
            upd(p, l, r, 1, maxN, 1, 0); upd(p, cur, cur+cnt-1, 1, maxN, 1, 1);
            cur += cnt;
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(query(j, i, i, 1, maxN, 1)) { pr(j, sp); break; }
        }
    }
}