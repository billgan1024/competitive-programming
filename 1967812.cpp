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

int n, k, notes[201], cnt[201], dp[20001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) scan(notes[i]); for(int i = 1; i <= n; i++) scan(cnt[i]); scan(k);
    fill(dp, dp+20001, 1e9); dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = k; j >= 0; j--)
        {
            for(int l = j-notes[i], c = 1; l >= 0; l -= notes[i], c++)
            {
                if(c > cnt[i]) break;
                dp[j] = min(dp[j], c + dp[l]);
            }
        }
    }
    print(dp[k]);
}