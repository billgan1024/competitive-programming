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

int n, dp[30], ans;
int main()
{
    //dp[j] = max subsequence if you only consider bit j AT the number that you are
    //currently iterating on (it propagates as you iterate through the numbers as iterator i)
    //the answer for dp[j] links with any previous dp[] that shares at least one bit with
    //the current number i
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, x; i < n; i++)
    {
        scan(x); int m = 0;
        for(int j = 0; j < 30; j++) { if(x & (1 << j)) m = max(m, dp[j]); }
        for(int j = 0; j < 30; j++) { if(x & (1 << j)) dp[j] = m+1; }
    }
    for(int i = 0; i < 30; i++) ans = max(ans, dp[i]);
    print(ans);
}