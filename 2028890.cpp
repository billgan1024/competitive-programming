#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, sum, w[31]; bool dp[15001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        //dp[j]: if it is possible to get a sum of j weight using the first i items (override, dp[0][0] = true)
        //we try to get the highest weight attainable that is <= sum/2 using a subset of weights
        scan(n); sum = 0; ms(dp); ms(w);
        for(int i = 1; i <= n; i++) { scan(w[i]); sum += w[i]; }
        int c = sum/2; dp[0] = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = c; j >= w[i]; j--)
            {
                if(dp[j-w[i]]) dp[j] = true;
            }
        }
        for(int i = c; i >= 0; i--)
        {
            if(dp[i]) { print(sum - 2*i, nl); break;}
        }
    }
}