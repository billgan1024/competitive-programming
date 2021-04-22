#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

struct cmd
{
    int a, b;
};

bool cmp(cmd x, cmd y) { return x.a < y.a || (x.a == y.a && x.b < y.b); }

int n, in, h, m, d[10001], sum; vector<cmd> r;
int main()
{
    //difference = height diff from the tallest tower
    cin.sync_with_stdio(0); cin.tie(0); scan(n, in, h, m);
    for(int i = 0, a, b; i < m; i++)
    {
        scan(a, b); if(a > b) swap(a, b); r.push_back({a, b});
    }
    sort(r.begin(), r.end(), cmp);
    int pa = 0, pb = 0;
    for(cmd c : r)
    {
        if(c.a == pa && c.b == pb) continue;
        d[c.a+1]--; d[c.b]++;
        pa = c.a; pb = c.b;
    }
    for(int i = 1; i <= n; i++)
    {
        sum += d[i]; print(sum+h, nl);
    }
}