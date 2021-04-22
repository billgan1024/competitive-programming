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

int n, k, a[MV], ans = -1; vector<int> rem[MV-1];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k);
    rem[0].push_back(0);
    for(int i = 1, a0; i <= n; i++)
    {
        scan(a0); a[i] = (a[i-1] + a0) % k; rem[a[i]].push_back(i);
    }
    //if two prefix sums si and sj have the same remainder, then sj-si is divisible by k
    //then the interval length is j-i since that represents the elements in indices [i+1, j]
    for(int i = 0; i < k; i++)
    {
        if(sz(rem[i]) >= 2) ans = max(ans, rem[i][sz(rem[i])-1]-rem[i][0]);
    }
    print(ans);
}