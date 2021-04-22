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
const int MV = 2e4;

int n, ans; pii p[2000]; unordered_set<int> x[40001], y[40001];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        scan(p[i].first, p[i].second); p[i].first += MV; p[i].second += MV;
        x[p[i].first].insert(p[i].second); y[p[i].second].insert(p[i].first);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int a = p[i].first, b = p[i].second, c = p[j].first, d = p[j].second;
            if(y[d].find(a) != y[d].end() && x[c].find(b) != x[c].end())
            {
                ans = max(ans, abs(c-a)*abs(d-b));
            }
        }
    }
    print(ans);
}