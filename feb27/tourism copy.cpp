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
const int maxN = 1<<20;

int N, K, a[maxN][20], d[2*maxN]; deque<pii> c; ll s[2*maxN], dp[2*maxN]; 
void push(int p) {
    s[2*p] = dp[2*p] + d[p]; s[2*p+1] = dp[2*p+1] + d[p]; 
    d[2*p] = d[p]; d[2*p+1] = d[p]; 
    d[p] = 0;
}
void upd(int l, int r, int a, int b, int p, int v) {
    if(l <= a && b <= r) { s[p] = dp[p] + v; d[p] = v; }
    else if(b < l || r < a) return;
    else {
        if(d[p] != 0) push(p);
        int mid = (a+b)/2;
        upd(l, r, a, mid, 2*p, v); upd(l, r, mid+1, b, 2*p+1, v); 
        s[p] = max(s[2*p], s[2*p+1]);
    }
}
ll query(int l, int r, int a, int b, int p) {
    if(l <= a && b <= r) return s[p];
    else if(b < l || r < a) return LLONG_MIN;
    else {
        if(d[p] != 0) push(p);
        int mid = (a+b)/2;
        return max(query(l, r, a, mid, 2*p), query(l, r, mid+1, b, 2*p+1));
    }
} 
void dp_upd(int idx, ll v) {
    int p = idx+maxN; dp[p] += v; 
    for(int i = p/2; i > 0; i /= 2) dp[i] = max(dp[2*i], dp[2*i+1]);
}
int st_query(int x, int y) {
    int j = 31-clz(y-x+1);
    return max(a[x][j], a[y-(1<<j)+1][j]);
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, K); 
    for(int i = 1; i <= N; i++) sc(a[i][0]);
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i+(1<<j)-1 <= N; i++) a[i][j] = max(a[i][j-1], a[i+(1<<(j-1))][j-1]);
    }
    for(int d = 1; d <= ceil((double)N/K); d++) {
        int l = (d-1)*K+1, r = d*K;
        for(int i = l; i <= r; i++) {
            if(!c.empty() && c.front().second < max(i-K, 0)) c.pop_front();
            while(!c.empty() && c.back().first <= a[i][0]) c.pop_back();
            int pos = c.empty() ? max(i-K, 0) : c.back().second+1; c.pb({a[i][0], l-1});
            if(pos <= l-1) upd(pos, l-1, 0, maxN-1, 1, a[i][0]); 
            ll val = query(max(i-K, 0), l-1, 0, maxN-1, 1);
            dp_upd(i, val); if(i == N) { pr(dp[N+maxN]); return 0; }
            upd(i, i, 0, maxN-1, 1, i+1 > min(r, N) ? 0 : st_query(i+1, min(r, N)));
        }
        while(!c.empty()) c.pop_back();
        for(int i = l; i <= r; i++) c.pb({i+1 > r ? 0 : st_query(i+1, r), i});
    }
}