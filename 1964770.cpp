#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

typedef long long ll;
int a, b, n; vector<int> pos = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(a, b, n);
    for(int i = 0, m; i < n; i++) { scan(m); pos.push_back(m); }
    sort(pos.begin(), pos.end());
    ll dp[pos.size()]; ms(dp); dp[0] = 1;
    for(int i = 1; i < pos.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            int d = pos[i]-pos[j];
            if(a <= d && d <= b) dp[i] += dp[j];
        }
    }
    print(dp[pos.size()-1], nl);
}