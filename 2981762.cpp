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
const int MV = 2e3+1;

int n, q, a[MV], ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, q);
    for(int i = 1; i <= n; i++) sc(a[i]);
    pr(2*n-2, nl);
    for(int i = 2; i <= n; i++)
    {
        //i = current element (first one to the right of the sorted prefix)
        if(a[i] > a[i-1])
        {
            //already sorted, move on
            pr(i-1, sp, i-1, nl);
            pr(i-1, sp, i-1, nl);
        }
        else
        {
            int idx = lower_bound(a+1, a+i, a[i]) - a;
            pr(idx, sp, i-1, nl); reverse(a+idx, a+i);
            pr(idx, sp, i, nl); reverse(a+idx, a+i+1);
        }
    }
}