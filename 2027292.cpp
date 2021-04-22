#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e6+1;

int n; vector<int> lis;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, x; i < n; i++)
    {
        scan(x);
        if(lis.empty() || x > lis.back()) lis.pb(x);
        else
        {
            int pos = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
            lis[pos] = x;
        }
    }
    print(sz(lis));
}