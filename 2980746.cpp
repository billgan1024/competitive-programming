#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 2e6+1;

int n, a[MV], d[MV], ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++)
    {
        sc(a[i]); d[i] = a[i]-a[i-1];
    }
    //relevant array is d[2] to d[n]
    int sign = 0;
    for(int i = 2; i <= n; i++)
    {
        if(d[i] != 0)
        {
            if(d[i] < 0)
            {
                if(sign >= 0) { sign = -1; ans++; }
            }
            else
            {
                if(sign <= 0) { sign = 1; ans++; }
            }
        }
    }
    pr(ans+1);
}