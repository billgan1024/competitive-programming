#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const ll mod = 1e9+7;

string s; ll cur[2][2] = {{0, 1}, {1, 1}}, mat[2][2] = {{0, 1}, {1, 1}}, ans[2] = {0, 1};
int main() {
    //[f(n), f(n+1)] = (transformation^n)*[0, 1]
    sc(s);
    for(int i = sz(s)-1; i >= 0; i--)
    {
        for(int j = 1; j <= 9; j++)
        {
            if(s[i]-'0' == j)
            {
                //apply transformation
                ll x = ans[0], y = ans[1];
                ans[0] = (cur[0][0]*x + cur[0][1]*y) % mod; ans[1] = (cur[1][0]*x + cur[1][1]*y) % mod;
            }
            //cur *= mat
            ll a = cur[0][0], b = cur[0][1], c = cur[1][0], d = cur[1][1];
            cur[0][0] = (mat[0][0]*a + mat[0][1]*c) % mod;
            cur[0][1] = (mat[0][0]*b + mat[0][1]*d) % mod;
            cur[1][0] = (mat[1][0]*a + mat[1][1]*c) % mod;
            cur[1][1] = (mat[1][0]*b + mat[1][1]*d) % mod;
        }
        mat[0][0] = cur[0][0]; mat[0][1] = cur[0][1]; mat[1][0] = cur[1][0]; mat[1][1] = cur[1][1];
    }
    pr(ans[0], nl);
}