#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9+7, MV = 5e6+1;

int s, m, p[MV], ans; set<int> zeroes; string t;
int main()
{
    //set finds elements in log n time (indices are 0-indexed)
    p[0] = 1; for(int i = 1; i < MV; i++) p[i] = (p[i-1]*2) % mod;
    cin.sync_with_stdio(0); cin.tie(0); scan(s, m, t);
    for(int i = 1; i <= s; i++)
    {
        if(t[s-i] == '1') ans = (ans + p[i-1]) % mod;
        else zeroes.insert(s-i);
    }
    for(int i = 0, l, r; i < m; i++)
    {
        scan(l, r); l--; r--;
        if(zeroes.lower_bound(l) != zeroes.end())
        {
            int c = *zeroes.lower_bound(l);
            while(c <= r)
            {
                zeroes.erase(c); ans = (ans + p[s-c-1]) % mod;
                if(zeroes.upper_bound(c) == zeroes.end()) break;
                c = *zeroes.upper_bound(c);
            }
        }
        print(ans, nl);
    }
}