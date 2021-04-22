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
const int MV = 1e6+1;

int j, a, ans; bool picked[MV]; char jerseys[MV];
int toSize(char c)
{
    if(c == 'S') return 1;
    else if(c == 'M') return 2;
    else if(c == 'L') return 3;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(j, a);
    for(int i = 1; i <= j; i++) scan(jerseys[i]);
    for(int i = 0; i < a; i++)
    {
        char s; int num;
        scan(s, num);
        if(picked[num]) continue;
        if(toSize(s) <= toSize(jerseys[num]))
        {
            ans++; picked[num] = true;
        }
    }
    print(ans);
}