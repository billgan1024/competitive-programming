#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e6+1;

int n, a[MV], dp[MV], ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) scan(a[i]); 
    dp[1] = 1; ans = 1; 
    for(int i = 2; i <= n; i++)
    {
        dp[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    print(ans);
}