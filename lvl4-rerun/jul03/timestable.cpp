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
const int mod = 1e9+7;

int C, R, M, x, y, w, h, n, r, c, dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, len[502][502];
ll a[4][502][502], g[502][502], sum[502][502];
void upd(int i, int v) {
    //use global variables
    a[i][y][x] += v; a[i][y][x+w] -= v;
    a[i][y+h][x] -= v; a[i][y+h][x+w] += v;
}
void dfs(int cr, int cc) {
    //do dfs on a directed acyclic graph (basically dp) by pretending the arrays to calcualte represent visited arrays
    //we can tell whether a cell has been visited or not by checking whether len[cr][cc] = 0
    if(len[cr][cc] > 0) return;
    //proceed to update the array values we want to compute (for this node)
    len[cr][cc] = 1; sum[cr][cc] = g[cr][cc]; 
    for(int i = 0; i < 4; i++) {
        int nr = cr+dir[i][0], nc = cc+dir[i][1];
        if(1 <= nr && nr <= R && 1 <= nc && nc <= C && g[nr][nc] > g[cr][cc]) {
            dfs(nr, nc);
            if(len[cr][cc] < 1+len[nr][nc]) {
                len[cr][cc] = 1+len[nr][nc]; sum[cr][cc] = g[cr][cc] + sum[nr][nc];
            } else if(len[cr][cc] == 1+len[nr][nc]) sum[cr][cc] = max(sum[cr][cc], g[cr][cc] + sum[nr][nc]);
        }
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(C, R, M);
    for(int i = 0; i < M; i++) {
        sc(x, y, w, h, n);
        upd(0, n); upd(1, -n*(x-1)); upd(2, -n*(y-1)); upd(3, n*(y-1)*(x-1));
    }
    //integrate all of the coefficient grids, then compute the actual value of each grid 
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            for(int k = 0; k < 4; k++) a[k][i][j] += a[k][i-1][j] + a[k][i][j-1] - a[k][i-1][j-1]; 
            g[i][j] = a[0][i][j]*i*j + a[1][i][j]*i + a[2][i][j]*j + a[3][i][j]; 
        }
    }
    sc(c, r); dfs(r, c); 
    pr(sum[r][c]%mod, nl);
}

//basically, every operation is just a range update on the 2nd order difference array
//then, integrate twice to recover the original array
//if d is the difference array, and a is the original array, then the goal is for a[i][j] = sum of all d[i][j] in the top-left rectangle
//you can loop from top to bottom and left to right,
//doing a[i][j] = d[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1], then simply collapse a into d by operating on the same array
//another way is to simply integrate each row, then integrate each column

//however, the above implementation is very messy because you would need extra space at the end of the array 
//an alternate way of thinking about this is as follows:
//for a 1D array, you can perform updates of the form '+= P(x)' where P(x) is a polynomial taking the array index 'x' as input
//you do this by maintaining an array of vector of coefficients (containing degree(P) elements) of length N
//then, any 'multi-degree' update can be converted into a polynomial update with respect to the index of the array
//thus, it suffices to do up to deg(P) range updates
//at the end, the values of the array is equal to the polynomial consisting of the vector of coefficients,
//evaluated at each index position, so simply integrate to obtain the original coefficients
//2d case: this is very similar to the 1d case, we just need to analyze the function dependent on two variables +upd(r, c) = +x*r*c
//observe that every update is just applying +x*u*v for 1<=u<=h, 1<=v<=w but you're actually performing this update starting at 
//some top-left corner (y, x)
//thus, every update is just applying +n(r-(y-1))*(c-(x-1)) for the actual cell locations (r, c) and we can turn that into
//4 range updates by maintaining a separate 2d difference array for every coefficient of the multivariable function
//(r*c, r, c, and the constant)
//at the end, integrate and compute the actual value using coefficients: a0(r*c) + a1(r) + a2(c) + a3
//notice that this actually works for any multivariable polynomial update, even with terms with different variables.

//then on the original array, note that we're asked to find the maximum sum (of node numbers) of the longest path in a directed acyclic graph
//do dp by computing two functions: len[i][j] = max length path from this node (in this case, it's better if we assume that
//the path length = number of cells visited), and sum[i][j] = maximum sum of node numbers of the max length path
//we're basically dfsing to calculate this pair of values (store it in an array), for EVERY node (throwback to https://dmoj.ca/problem/bts16p5, it was basically dp but we used a dfs-like implementation)

//total time complexity: O(M + RC)