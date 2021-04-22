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

int G, n, a[7], h, t;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(G);
    for(int g = 0; g < G; g++)
    {
        scan(n); if(n == 0) { print("NOT LETHAL", nl); continue; }
        for(int i = 0; i < n; i++) scan(a[i]);
        scan(h, t); bool found = false;
        for(int i = 0; i < (1 << n); i++)
        {
            int dmg = 0, rem = 0;
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j)) dmg += a[j];
            }
            if(dmg >= t)
            {
                for(int j = 0; j < n; j++)
                {
                    if(~i & (1 << j)) rem += a[j];
                }
                if(rem >= h) { print("LETHAL", nl); found = true; break; }
            }
        }
        if(!found) print("NOT LETHAL", nl);
    }
}