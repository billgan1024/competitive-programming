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

int n, a, b, ans; unordered_set<int> s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, a, b);
    for(int i = 0, x; i < a; i++) { scan(x); s.insert(x); }
    ans = n;
    for(int i = 0, x; i < b; i++)
    {
        scan(x);
        if(s.find(x) != s.end()) ans--;
    }
    print(ans);
}