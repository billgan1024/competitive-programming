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
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef unsigned long long ll;
typedef pair<int, int> pii;
const ll A = 131;

//dp[string]: longest valid subsequence ending at this string
int n, ans; string s; unordered_map<ll, int> dp;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 0; i < n; i++)
    {
        sc(s); ll hl = 0, hr = 0, pw = 1; int best = 0;
        for(int j = 0; j < sz(s); j++)
        {
            //compare both forward hashes, if a match is found then check if dp[string] can
            //be calculated from a previous dp[string]
            hl = (hl * A) + s[j]; hr += pw * s[sz(s)-j-1]; pw *= A;
            if(hl == hr) best = max(best, dp[hl] + 1);
        }
        dp[hl] = best;
        ans = max(ans, dp[hl]);
    }
    pr(ans);
}