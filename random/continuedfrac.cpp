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

int A[100], B[100], a[100], P[100], Q[100], d = 103;
int x = 10;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    A[0] = 0; B[0] = 1; a[0] = floor(sqrt(d)); P[0] = a[0]; Q[0] = 1;
    for(int i = 0; i < x; i++) {
        A[i+1] = a[i]*B[i]-A[i];
        B[i+1] = (d-A[i+1]*A[i+1])/B[i];
        a[i+1] = floor((sqrt(d)+A[i+1])/B[i+1]);
        if(i == 0) {
            P[i+1] = a[i+1]*P[i]+1; Q[i+1] = a[i+1]*Q[i];
        } else {

            P[i+1] = a[i+1]*P[i]+P[i-1]; Q[i+1] = a[i+1]*Q[i] + Q[i-1];
        }
    }

    pr("\\hline", nl);
    pr("$A_n$ & & &", sp); for(int i = 0; i <= x; i++) pr(A[i], sp, "&", sp); pr("\\\\", nl);
    pr("\\hline", nl);
     pr("$B_n$ & & &", sp);for(int i = 0; i <= x; i++) pr(B[i], sp, "&",  sp); pr("\\\\", nl);
    pr("\\hline", nl);
     pr("$a_n$ & & &", sp);for(int i = 0; i <= x; i++) pr(a[i], sp, "&", sp); pr("\\\\", nl);
    pr("\\hline", nl);
     pr("$P_n$ & 0 & 1 &", sp);for(int i = 0; i <= x; i++) pr(P[i], sp, "&", sp); pr("\\\\", nl);
    pr("\\hline", nl);
     pr("$Q_n$ & 1 & 0 &", sp);for(int i = 0; i <= x; i++) pr(Q[i], sp, "&", sp); pr("\\\\", nl);
    pr("\\hline", nl);
     pr("$P_n^2-dQ_n^2$ & & &", sp);for(int i = 0; i <= x; i++) pr(P[i]*P[i]-d*Q[i]*Q[i], sp, "&", sp); pr("\\\\", nl);
    pr("\\hline", nl);
}