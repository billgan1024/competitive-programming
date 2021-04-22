#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, k, a1, a2, b1, b2; vector<vector<int>> cycles;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k); int ans[n+1];
    scan(a1, a2, b1, b2);
    //ans[i] = cow at position i after the k swaps
    for(int i = 1; i <= n; i++)
    {
        if((a1 <= i && i <= a2) || (b1 <= i && i <= b2))
        {
            //determine the cycle of this cow and find out the cow in position i after k actions
            vector<int> cycle; int cur = i;
            while(cycle.empty() || cur != i)
            {
                cycle.push_back(cur);
                if(a1 <= cur && cur <= a2) cur = a1+a2-cur;
                if(b1 <= cur && cur <= b2) cur = b1+b2-cur;
            }
            int pos = cycle[k % cycle.size()]; ans[pos] = i;
        }
        else ans[i] = i;
    }
    for(int i = 1; i <= n; i++) print(ans[i], nl);
}