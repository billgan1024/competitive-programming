#include <bits/stdc++.h>
using namespace std;
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, c, p; string s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, c);
    for(int i = 0; i < n; i++)
    {
        scan(s, p);
        if(p > c) print(s, sp, "will advance", nl);
        else print(s, sp, "will not advance", nl);
    }
}