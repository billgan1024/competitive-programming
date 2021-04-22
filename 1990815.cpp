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

unordered_map<int, int> fa, fb; int a, b, ans = INT_MAX;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(a, b);
    while(a%2 == 0) { fa[2]++; a /= 2; }
    for (int i = 3; i <= sqrt(a); i += 2)
    {
        while (a%i == 0) { fa[i]++; a /= i; }
    }
    if(a > 2) fa[a]++;
    for(int j = 2; j <= b; j++)
    {
        int n = j;
        while (n % 2 == 0) { fb[2]++; n /= 2; }
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            while (n%i == 0) { fb[i]++; n /= i; }
        }
        if(n > 2) fb[n]++;
    }
    for(pii entry : fa)
    {
        int expA = entry.second, expB = fb[entry.first];
        ans = min(ans, expB/expA);
    }
    print(ans, nl);
}