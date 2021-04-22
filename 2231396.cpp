#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n;
bool isPrime(int x)
{
    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        sc(n); int a = n-1, b = n+1;
        int ta = -1000, tb = 1000;
        bool found = false;
        while(a > 1)
        {
            if(isPrime(a))
            {
                if(!found) found = true; else { ta = a; break; }
            }
            a--;
        }
        found = false;
        while(b < 200)
        {
            if(isPrime(b))
            {
                if(!found) found = true; else { tb = b; break; }
            }
            b++;
        }
        if(tb-n <= n-ta) pr(tb, nl);
        else pr(ta, nl);
    }
}