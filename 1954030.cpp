#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, ans; string a, b; vector<int> m;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, a, b);
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i]) m.push_back(i);
    }
    if(m.size() == 0) { print(0); return 0; }
    ans = 1;
    for(int i = 1; i < m.size(); i++)
    {
        if(m[i-1] != m[i]-1) ans++;
    }
    print(ans, nl);
}