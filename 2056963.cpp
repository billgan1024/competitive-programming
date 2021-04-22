#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, a[401], s[401], ans; bool dp[401][401];
int sum(int l, int r) { return s[r]-s[l-1]; }
int main()
{
    //dp[i][j] = true if the interval [i, j] can be combined into a riceball
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) { scan(a[i]); s[i] = s[i-1] + a[i]; }
    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = true; ans = max(ans, a[i]);
        if(i+1 <= n && a[i] == a[i+1]) { dp[i][i+1] = true; ans = max(ans, 2*a[i]); }
    }
    //by looping this way, it guarantees that we have already solved all intervals with lengths
    //less than this interval length, and the final answer is the maximum size interval that we can
    //compress into a riceball
    for(int len = 3; len <= n; len++)
    {
        for(int i = 1; i+len-1 <= n; i++)
        {
            int j = i+len-1;
            for(int k = i+1; k <= j; k++)
            {
                if(dp[i][k-1] && dp[k][j] && sum(i, k-1) == sum(k, j))
                {
                    dp[i][j] = true; ans = max(ans, sum(i, j)); break;
                }
            }
            if(dp[i][j]) continue;
            int k = i+1, l = j-1;
            while(k <= l)
            {
                if(sum(i, k-1) < sum(l+1, j)) k++;
                else if(sum(i, k-1) > sum(l+1, j)) l--;
                else if(dp[i][k-1] && dp[k][l] && dp[l+1][j])
                {
                    dp[i][j] = true; ans = max(ans, sum(i, j)); break;
                }
                else { k++; l--; }
            }
        }
    }
    print(ans);
}