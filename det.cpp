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
const int MN = 501;
const ll MOD = 1e9+7;

// using row reduction, the determinant is equal to det(ref(A))swap(A)
int N, a[501][501]; ll ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 1; i <= N; i++) { 
        for(int j = 1; j <= N; j++) sc(a[i]);
    }
    // go through all the columns to row reduce (i represents the current row in which ur looking for a pivot)
    for(int i = 1, j = 1; j <= N; j++) {
        // find the first row with a nonzero entry
        int k = i;
        while(k <= N && a[k][j] == 0) k++;
        if(k <= N) {
            //swap row k with row i if i != k
            if(i != k) { swap(a[i], a[k]); ans = MOD-ans; }
            for(int nxt = i+1; nxt <= N; nxt++) clear()
        }
    }
    pr(ans, nl);
}