#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int del, ins, rep, dp[1001][1001]; string a, b;
int main()
{
    //dp[i][j] represents min cost for the first i letters of a and the first j letters of b
    cin.sync_with_stdio(0); cin.tie(0); scan(del, ins, rep, a, b);
    for(int i = 0; i <= sz(a); i++)
    {
        for(int j = 0; j <= sz(b); j++)
        {
            if(i == 0) dp[i][j] = ins*j;
            else if(j == 0) dp[i][j] = del*i;
            else
            {
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1] + rep, min(dp[i-1][j] + del, dp[i][j-1] + ins));
            }
        }
    }
    print(dp[sz(a)][sz(b)], nl);
}