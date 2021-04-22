#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pr first
#define qt second
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int T, n, k, ans; unordered_map<string, map<int, int>> items; string s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(T);
    for(int t = 0; t < T; t++)
    {
        items.clear(); ans = 0; scan(n);
        for(int i = 0, m; i < n; i++)
        {
            scan(m);
            for(int j = 0, p, q; j < m; j++)
            {
                scan(s, p, q); items[s][p] += q;
            }
        }
        scan(k);
        for(int i = 0, d; i < k; i++)
        {
            scan(s, d); int prev = d;
            for(pii p : items[s])
            {
                d = max(0, prev-p.qt); ans += (prev-d)*p.pr;
                if(d == 0) break;
                prev = d;
            }
        }
        print(ans, nl);
    }
}