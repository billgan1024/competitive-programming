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

int n; double p[20][20], dp[1<<20];
int log2(int x) { return 32 - __builtin_clz(x) - 1; }
int main()
{
    //dp[i]: max probability if you consider the subset of missions represented by i taken
    //by the first sz(subset) people
    //O(N) transitions, O(2^N) states = O(N*2^N) time
    //key idea: we can use a simple for loop cuz each bitmask always relies on bitmasks
    //with lesser values since you are removing one bit for a comparison
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) { scan(p[i][j]); p[i][j] /= 100; }
    }
    for(int i = 1; i < (1 << n); i++)
    {
        int cur = __builtin_popcount(i)-1;
        if(cur == 0) dp[i] = p[0][log2(i)];
        else
        {
            for(int j = 0; j < n; j++)
            {
                //simulate person sz(i) taking a mission from the subset i
                if(i & (1 << j)) dp[i] = max(dp[i], p[cur][j] * dp[i^(1<<j)]);
            }
        }
    }
    print(fixed, setprecision(6), 100*dp[(1<<n)-1]);
}