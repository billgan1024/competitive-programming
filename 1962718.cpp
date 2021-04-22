#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, k, a1, a2, b1, b2;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k); int ans[n+1];
    scan(a1, a2, b1, b2);
    //ans[i] = id of the cow at position i after k routines
    for(int i = 1; i <= n; i++)
    {
        if((a1 <= i && i <= a2) || (b1 <= i && i <= b2))
        {
            //determine the cycle that cow i is in and find the position of cow i after k routines
            vector<int> cycle; int cur = i;
            while(true)
            {
                if(cur == i && !cycle.empty()) break;
                cycle.push_back(cur);
                if(a1 <= cur && cur <= a2) cur = a1+a2-cur;
                if(b1 <= cur && cur <= b2) cur = b1+b2-cur;
            }
            //we know the complete cycle of positions that cow i can be in after any # of routines, so find the position that cow i will be in after k routines
            int pos = cycle[k % cycle.size()]; ans[pos] = i;
        }
        else ans[i] = i;
    }
    for(int i = 1; i <= n; i++) print(ans[i], nl);
}