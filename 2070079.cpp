#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<ll, ll> pll;
const int mod = 1e9+7;

int T, n; unordered_map<string, pll> dp; stack<string> f; stack<pll> val;
void reset()
{
    while(!f.empty()) f.pop(); while(!val.empty()) val.pop(); dp.clear();
}
int main()
{
    //basically memoize all of the functions, storing their end result as f(x) = mx+b
    cin.sync_with_stdio(0); cin.tie(0); scan(T);
    for(int t = 0; t < T; t++)
    {
        scan(n); dp.clear(); ll ans = 0;
        //maintain a stack for the current function being inspected and its m and b value
        for(int i = 0; i < n; i++)
        {
            string cmd, name; int x; scan(cmd);
            if(cmd == "ADD")
            {
                scan(x);
                if(f.empty()) ans = (ans + x) % mod;
                else val.top().second = (val.top().second + x) % mod;
            }
            else if(cmd == "SUB")
            {
                scan(x);
                if(f.empty()) ans = (ans - x + mod) % mod;
                else val.top().second = (val.top().second - x + mod) % mod;
            }
            else if(cmd == "MULT") {
                scan(x);
                if(f.empty()) ans = (ans * x) % mod;
                else
                {
                    val.top().first = (val.top().first * x) % mod;
                    val.top().second = (val.top().second * x) % mod;
                }
            }
            else if(cmd == "FUN")
            {
                scan(name); f.push(name); val.push({1, 0});
            }
            else if(cmd == "END")
            {
                dp[f.top()] = val.top(); f.pop(); val.pop();
            }
            else if(cmd == "CALL")
            {
                scan(name); int m = dp[name].first, b = dp[name].second;
                if(f.empty()) ans = (ans*m+b)%mod;
                else
                {
                    val.top().first = (val.top().first * m) % mod;
                    val.top().second = (val.top().second * m + b) % mod;
                }
            }
        }
        print(ans, nl);
    }
}