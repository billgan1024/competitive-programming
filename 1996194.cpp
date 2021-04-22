#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(a) sizeof(a)/sizeof(a[0])
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, k;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k);
    for(int i = 0; i < k; i++)
    {
        int s, t, r; scan(s, t, r);
        int rounds = n/(s*t); int totaltime = rounds*t; int breaktime = (rounds-1)*r;
        int rem = n % (s*t);
        if(rem != 0)
        {
            breaktime += r; totaltime += ceil(rem/(double)s);
        }
        print(totaltime + breaktime, nl);
    }
}