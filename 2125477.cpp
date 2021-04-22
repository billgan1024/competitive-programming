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
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, a[15]; bool dp[1<<15];
bool valid(int i)
{
    //check if this subset is invalid
    vector<int> arr; int d = 0; bool v = true;
    for(int j = 0; j < n; j++) { if(i & (1 << j)) arr.pb(a[j]); }
    for(int j = 1; j < sz(arr); j++)
    {
        if(d == 0) d = arr[j]-arr[j-1];
        else if(d * (arr[j]-arr[j-1]) < 0) { v = false; break; }
    }
    return !v;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        for(int u = 0; u < 3; u++)
        {
            scan(n); for(int i = 0; i < n; i++) scan(a[i]); ms(dp, false);
            //dp[subset] = whether the current player wins if
            //they go first and both players play optimally
            //using only a subset of the n blocks
            for(int i = 1; i < (1 << n); i++)
            {
                if(popcnt(i) <= 2) continue;
                if(valid(i))
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(i & (1 << j)) dp[i] |= !dp[i ^ (1 << j)];
                    }
                }
            }
            print(dp[(1<<n)-1] ? "A" : "B");
        }
        print(nl);
    }
}