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
const int MV = 1e5+1;

int q, s[MV]; bool c[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(q);
    for(int i = 2; i < MV; i++)
    {
        if(!c[i])
        {
            s[i] = i; for(int j = 2*i; j < MV; j += i) c[j] = true;
        }
    }
    for(int i = 1; i < MV; i++) s[i] += s[i-1];
    for(int i = 0, a, b; i < q; i++)
    {
        sc(a, b); pr(s[b]-s[a-1], nl);
    }
}