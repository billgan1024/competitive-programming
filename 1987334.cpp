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

int n, bit[1025][1025];

void update(int x, int y, int a)
{
    //update 2D BIT using pointers, this takes (log n)^2 time because of the 2D BIT
    for(int i = x; i <= n; i += i&-i)
    {
        for(int j = y; j <= n; j += j&-j)
        {
            bit[i][j] += a;
        }
    }
}

int sum(int x, int y)
{
    //get sum of a rectangle rooted at the origin
    int s = 0;
    for(int i = x; i > 0; i -= i&-i)
    {
        for(int j = y; j > 0; j -= j&-j)
        {
            s += bit[i][j];
        }
    }
    return s;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    while(true)
    {
        int cmd, x, y, a, l, b, r, t; scan(cmd);
        if(cmd == 0) scan(n);
        else if(cmd == 1)
        {
            scan(x, y, a); x++; y++; update(x, y, a);
        }
        else if(cmd == 2)
        {
            scan(l, b, r, t); l++; b++; r++; t++;
            print(sum(r, t) - sum(l-1, t) - sum(r, b-1) + sum(l-1, b-1), nl);
        }
        else if(cmd == 3) break;
    }
}