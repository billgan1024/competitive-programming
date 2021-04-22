#pragma GCC optimize "Ofast"
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
const int MV = 1e6+1;

int n, a[MV], c[MV], ans;
int main()
{
    //c[i]: minimum element possible for a LIS of length i
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++) scan(a[i]);
    ans = 1; c[1] = a[1];
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > c[ans]) c[++ans] = a[i];
        else
        {
            int k = lower_bound(c+1, c+ans+1, a[i]) - c;
            c[k] = a[i];
        }
    }
    print(ans, nl);
}