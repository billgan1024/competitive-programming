// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int MV = 5e5;

//shift frequencies up by 500000
int n, q, a[MV+1]; pbds p[2*MV+1];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, q);
    for(int i = 1; i <= n; i++) p[MV].insert(i);
    for(int i = 0; i < q; i++)
    {
        int cmd, x, l, r, c; scan(cmd);
        if(cmd == 1)
        {
            scan(x); a[x]++; p[a[x]+MV].insert(x); p[a[x]+MV-1].erase(x);
        }
        else if(cmd == 2)
        {
            scan(x); a[x]--; p[a[x]+MV].insert(x); p[a[x]+MV+1].erase(x);
        }
        else
        {
            scan(l, r, c);
            print(p[c+MV].order_of_key(r+1) - p[c+MV].order_of_key(l), nl);
        }
    }
}