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

int n, cnt = 1, ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n); bool found = false;
    for(int i = 0; i < n; i++)
    {
        if(found) { print(ans, nl); return 0; }
        for(int j = 0, a; j < n; j++)
        {
            scan(a);
            if(a != n*i+j+1) { found = true; ans++; }
            else if(found) { print(ans, nl); return 0; }
        }
    }
}