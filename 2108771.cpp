#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned int ui;

int n; double p[20][20], dp[2][1<<20];
int log2(int x) { return 32 - __builtin_clz(x) - 1; }
int main()
{
    //dp[i][j]: max probability if you only consider the first i ppl with j representing
    //the subset of the tasks (row i is flipped and overwritten each time)
    //tasks and people are 0-indexed
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) { scan(p[i][j]); p[i][j] /= 100; }
    }
    for(int i = 0; i < (1 << n); i++)
    {
        //base: if there is one person, take the highest probability out of the subset
        //missions will be arranged from right to left, from 0 to n-1
        //note that row i in the dp must be matched with a subset with i+1 elements (tasks)
        if(__builtin_popcount(i) != 1) continue;
        dp[0][i] = p[0][log2(i)];
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < (1 << n); j++)
        {
            if(__builtin_popcount(j) != i+1) continue;
            for(int k = 0; k < n; k++)
            {
                //simulate assigning mission k to person i
                if(j & (1 << k)) dp[i%2][j] = max(dp[i%2][j], p[i][k] * dp[(i-1)%2][j^(1<<k)]);
            }
        }
    }
    print(fixed, setprecision(6), 100*dp[(n-1)%2][(1<<n)-1]);
}