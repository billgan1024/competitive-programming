#include <bits/stdc++.h>
using namespace std;
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, m, ans; string s; unordered_set<string> items;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 0; i < n; i++)
    {
        scan(s); items.insert(s);
    }
    for(int i = 0, t; i < m; i++)
    {
        scan(t); bool ok = true;
        for(int i = 0; i < t; i++)
        {
            scan(s); if(items.find(s) == items.end()) ok = false;
        }
        if(ok) ans++;
    }
    print(ans);
}