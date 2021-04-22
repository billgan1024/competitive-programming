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
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, k, T, a[30];
//rightmost bit is n-1
void f(int cur, int cnt)
{
    if(cnt == k)
    {
        for(int i = 0; i < n; i++) print(a[i]); print(nl);
    }
    else
    {
        for(int i = cur+1; i < n-k+cnt+1; i++)
        {
            a[i] = true;
            f(i, cnt+1);
            a[i] = false;
        }
    }
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(T);
    for(int t = 0; t < T; t++)
    {
        scan(n, k);
        print("The bit patterns are", nl);
        f(-1, 0);
        print(nl);
    }
}