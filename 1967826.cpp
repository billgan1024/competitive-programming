#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, s, v[101], w[101], dp[30001]; string b;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        scan(s, n); ms(v); ms(w); ms(dp);
        for(int i = 1; i <= n; i++)
        {
            scan(b, v[i], w[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = s; j >= w[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            }
        }
        print(dp[s], nl);
    }
}