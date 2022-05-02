#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
const int MN = 1e6+1;
const ll MOD = 1e9+7;

int N, M, a[2][MN];
// number of lists that make the whole grid 'good'
// basically, a grid is good if and only if the cells in odd columns match and the cells in even columns match
ll pmod(ll x, ll y) {
    if(y == 0) return 1;
    else if(y % 2) return (x*pmod(x, y-1))%MOD;
    else {
        ll res = pmod(x, y/2);
        return (res*res)%MOD;
    }
}
ll soln (int i) {
    if(i <= M) return i-1;
    else return 2*M-i+1;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, M);
    for(int i = 1; i <= N; i++) sc(a[0][i]);
    for(int i = 1; i <= N; i++) sc(a[1][i]);
    ll odd = 0, even = 0; 
    // number of lists (in odd/even columns) that have the same value
    // then you just keep track of # of valid tuples for the first ? columns
    // if you consider a hypothetical array

    // 1 variable: can reach [x+1, x+M] with 1 variable each.
    // 2 variables: can reach [2, 2*M] with k-1 solutions to the equation a+b = k, a > 0, b > 0
    // now, we can count how many type-1 (or type-0) columns there are and narrow the range.
    // we also count how many type-2 variables there are such that we can determine what 
    // then you are tracking a shrinking interval each time, but we need to perform range multiply updates
    // this means that you are performing 
    int l = 2, r = 2*M; int type2 = 0;
    for(int i = 1; i <= N; i += 2) { 
        if(a[0][i] == 0 && a[1][i] == 0) type2++;
        else if(a[0][i] != 0 && a[1][i] != 0) {
            l = max(l, a[0][i] + a[1][i]); r = min(r, a[0][i] + a[1][i]);
        } else if(a[0][i] == 0) {
            l = max(l, a[1][i]+1); r = min(r, a[1][i]+M);
        } else if(a[1][i] == 0) {
            l = max(l, a[0][i]+1); r = min(r, a[0][i]+M);
        }
    }  
    for(int i = l; i <= r; i++) {
        // now use fast exponentiation to obtain the result
        odd = (odd + pmod(soln(i), type2)) % MOD;
    }
    l = 2, r = 2*M; type2 = 0;
    for(int i = 2; i <= N; i += 2) { 
        if(a[0][i] == 0 && a[1][i] == 0) type2++;
        else if(a[0][i] != 0 && a[1][i] != 0) {
            l = max(l, a[0][i] + a[1][i]); r = min(r, a[0][i] + a[1][i]);
        } else if(a[0][i] == 0) {
            l = max(l, a[1][i]+1); r = min(r, a[1][i]+M);
        } else if(a[1][i] == 0) {
            l = max(l, a[0][i]+1); r = min(r, a[0][i]+M);
        }
    }  
    for(int i = l; i <= r; i++) {
        // now use fast exponentiation to obtain the result
        even = (even + pmod(soln(i), type2)) % MOD;
    }
    pr((odd*even)%MOD, nl);
}
