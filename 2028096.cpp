#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int factors(int n)
{
    int r = 0;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) r++;
        while(n % i == 0) n /= i;
    }
    if(n != 1) r++;
    return r;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int i = 0, a; i < 5; i++)
    {
        scan(a); if(factors(a) == 3) print("valid", nl); else print("not", nl);
    }
}