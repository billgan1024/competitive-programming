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
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 2e5+1;

int n, a[MV], f[MV]; ll ans;
int main()
{
    //keep track of number of unique elements as well as the max freq of each element
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++) sc(a[i]);
    for(int cnt = 1; cnt*cnt <= n; cnt++)
    {
        ms(f, 0); unordered_set<int> overflow; int len = cnt*cnt, unique = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!f[a[i]]) unique++; f[a[i]]++; if(f[a[i]] == cnt+1) overflow.insert(a[i]);
            if(i >= len)
            {
                if(i-len != 0)
                {
                    f[a[i-len]]--;
                    if(!f[a[i-len]]) unique--;
                    if(f[a[i-len]] == cnt) overflow.erase(a[i-len]);
                }
                if(sz(overflow) == 0 && unique == cnt) ans++;
            }
        }
    }
    pr(ans, nl);
}