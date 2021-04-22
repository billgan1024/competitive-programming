#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n; double s, dp[15][1<<15], ans = 1e15, sx[15], sy[15], vx[15], vy[15];
double f(int cur, double time, int target)
{
    double cx, cy, tx = sx[target] + vx[target]*time, ty = sy[target] + vy[target]*time;
    if(cur == -1) { cx = 0; cy = 0; } else { cx = sx[cur] + vx[cur]*time; cy = sy[cur] + vy[cur]*time; }
    double dx = tx-cx, dy = ty-cy;
    double A = vx[target]*vx[target] + vy[target]*vy[target] - s*s;
    double B = 2*(dx*vx[target] + dy*vy[target]);
    double C = dx*dx + dy*dy;
    //t >= 0, so since A < 0, choose the negative side for the sqrt (only one soln there)
    return (-B - sqrt(B*B - 4*A*C))/(2*A);
}

int main()
{
    //f(i, mask): min time to catch squirrels in the mask, ending at squirrel i (i must be in the mask)
    //invalid states are never used so it's fine to keep them at 0
    //using the min time to arrive at a particular squirrel in a smaller subset, you can get the
    //current location of michael
    //larger subsets always depend on smaller subsets (valid dp)
    //O(n*2^n) states, O(n) time for each state, you're looking for min(dp[i][full mask])
    cin.sync_with_stdio(0); cin.tie(0); scan(n, s);
    for(int i = 0; i < n; i++) scan(sx[i], sy[i], vx[i], vy[i]);
    for(int mask = 1; mask < (1 << n); mask++)
    {
        for(int i = 0; i < n; i++)
        {
            //i is the ending squirrel (must be in the mask)
            if(!(mask & (1 << i))) continue;
            if(popcnt(mask) == 1)  dp[i][mask] = f(-1, 0, i);
            else
            {
                dp[i][mask] = 1e15;
                for(int j = 0; j < n; j++)
                {
                    //j is the previous squirrel (must be in the mask)
                    //apply appropriate transition to get the squirrels excluding i,
                    //ending at j, then going from j to i
                    if(!(mask & (1 << j)) || j == i) continue;
                    dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] +
                        f(j, dp[j][mask ^ (1 << i)], i));
                }
            }
        }
    }
    for(int i = 0; i < n; i++) ans = min(ans, dp[i][(1<<n)-1]);
    print(fixed, setprecision(15), ans, nl);
}