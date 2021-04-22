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

int n, x, y, z, dp[100001];
int main()
{
    //assume dp[0] = 1, i.e. you can get 1 free friend
    //then dp[i] = 0 -> you cannot split the whole bar
    //delete the free friend at the end :(
    cin.sync_with_stdio(0); cin.tie(0); scan(n, x, y, z); dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i >= x && dp[i-x]) dp[i] = max(dp[i], 1 + dp[i-x]);
        if(i >= y && dp[i-y]) dp[i] = max(dp[i], 1 + dp[i-y]);
        if(i >= z && dp[i-z]) dp[i] = max(dp[i], 1 + dp[i-z]);
    }
    print(dp[n]-1);
}