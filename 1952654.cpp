#include <bits/stdc++.h>
using namespace std;
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, w, ans, sum, a[701]; bool dp[245001];
int main()
{
    //dp[i]: if it is true that some subset of the array sums to i
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) { scan(a[i]); sum += a[i]; } w = sum/2; dp[0] = true;
    for(int i = 1; i <= n; i++)
    {
        for(int j = w; j >= a[i]; j--)
        {
            if(!dp[j]) dp[j] = dp[j-a[i]];
        }
    }
    for(int i = w; i >= 0; i--)
    {
        if(dp[i]) { ans = i; break; }
    }
    print(sum-2*ans);
}