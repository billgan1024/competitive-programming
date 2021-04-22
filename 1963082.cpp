#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, m, k, delta[100001], ans[100001], a[100], b[100]; bool vis[100001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m, k);
    //scan all m swaps which is the range a[i]...b[i]
    for(int i = 0; i < m; i++) scan(a[i], b[i]);
    for(int i = 1; i <= n; i++)
    {
        //delta[i] represents the POSITION of cow i after 1 routine (m swaps) (initially delta[i] = i before swapping)
        delta[i] = i;
        for(int j = 0; j < m; j++)
        {
            //swap once in the range a[j], b[j]
            if(a[j] <= delta[i] && delta[i] <= b[j]) delta[i] = a[j]+b[j]-delta[i];
        }
    }
    //ans[i] represents id of cow at position i
    for(int i = 1; i <= n; i++)
    {
        //if after one routine, cow i is still at position i, then the cycle has a length of 1 and cow i will always be in pos i
        if(delta[i] == i) { ans[i] = i; continue; }
        else if(vis[i]) continue;
        vector<int> cycle; int cur = i;
        while(true)
        {
            //determine this new cycle by repeatedly performing 1 routine of m swaps using the delta array
            //(only stop when cycle ends)
            if(cur == i && !cycle.empty()) break;
            //since delta[i] represents the position of cow i after 1 routine, traverse this cycle using delta[delta[delta[...delta[cur]]]] until cur reaches itself, i
            vis[cur] = true; cycle.push_back(cur); cur = delta[cur];
        }
        int rem = k % cycle.size();
        for(int j = 0; j < cycle.size(); j++)
        {
            int pos = (j + rem)%cycle.size();
            ans[cycle[pos]] = cycle[j];
        }
    }
    for(int i = 1; i <= n; i++) print(ans[i], nl);
}