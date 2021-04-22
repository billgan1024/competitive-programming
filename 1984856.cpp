#include <bits/stdc++.h>
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
const int MM = 131072;

int n, m, s[2*MM];
int main()
{
    //use a segment tree to process max queries in log n time (it has size 2*MM)
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0, a; i < MM; i++)
    {
        //build the segment tree using each obtained value (propagate max value upwards at every step)
        if(i < n) scan(a); else a = 0;
        int p = i+MM; s[p] = a;
        while(p % 2 == 1 && p != 1)
        {
            s[p/2] = max(s[p], s[p-1]); p /= 2;
        }
    }
    //for(int i = 1; i < 2*MM; i++) print(s[i], sp); print(nl);
    for(int i = 0, l, r, ans; i < m; i++)
    {
        //use the segment tree to process range queries
        scan(l, r); l += MM-1; r += MM-1; ans = INT_MIN;
        while(l <= r)
        {
            //if the parent of the l and r node is not in range, add their current node values
            //and shift them closer to each other
            //finally, ascend to the previous level (go to the parent nodes)
            if(l % 2 == 1) { ans = max(ans, s[l]); l++; }
            if(r % 2 == 0) { ans = max(ans, s[r]); r--; }
            l /= 2; r /= 2;
        }
        print(ans, nl);
    }
}